#!/usr/bin/env python3
"""Convert m2c's C output for game/engine TUs into first-draft C++ sources.

Usage: cxxconv.py <classes.json> <fields.json> <m2c out root> <ctx.c> <cnames.json> <m2c ctx root> <asm root> <out root> [--prefix P ...] [--write-existing]

`<m2c out root>` is the context-free m2c run the model's votes come from;
`<m2c ctx root>` is m2c rerun with cctx.py's context, so its fields already
carry the headers' `unkXX` names. That second run is converted. Per TU this:
  * drops m2c's struct definitions (the headers define the classes) and the
    extern prototypes of mangled symbols (the headers declare them);
  * folds float literal pools (`@546`) and `@stringBase0` slices back into
    literals, reading untyped string pools from dtk's `<asm root>`;
  * turns each function into its C++ definition, `RET Class::Name(params)`,
    with `this` implicit, CodeWarrior's hidden dtor flag removed, and
    compiler-generated vptr stores, base/member ctor and dtor calls, and the
    dtor's delete dropped;
  * rewrites mangled calls as member/free calls (m2ccalls.py) and C names
    of nested/template classes (`A__B`) back to C++.
Unknown bits stay as m2c macros from <m2c_macros.h>, for the per-TU fixers.
Without `--write-existing` an existing source is left alone.
"""

from __future__ import annotations

import argparse
import json
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from asmdata import objects  # noqa: E402
from cxxtypes import K, parse, render  # noqa: E402
from hmodel import Model, header_key, load_model, type_names  # noqa: E402
from hrender import member_name  # noqa: E402
from m2ccalls import CallRewriter, split_args  # noqa: E402

FUNC = re.compile(r"^(?P<ret>[^\s/#].*?)\s*\b(?P<name>[A-Za-z_][\w<>,@$]*)\((?P<params>.*)\) \{$")
LOCAL_PROTO = re.compile(r"^(?P<ret>[^\s/#].*?)\s*\b(?P<name>[A-Za-z_][\w<>,@$]*)\((?P<params>.*)\);\s*/\* static \*/$")
LITERAL = re.compile(r"^static (f32|f64) (@\d+) = (.+?);.*$", re.M)
STRING = re.compile(r"^static (?:const )?s8 (@stringBase\d+)\[\d+\] = \{ (.*?) \};.*$", re.M)
UNTYPED = re.compile(r"^static M2C_UNK (@stringBase\d+);", re.M)
MANGLED_EXTERN = re.compile(r"^[^\n]*\b\w+__\w*[(;][^\n]*/\* extern \*/\n|^extern [^\n]*\b\w*__\w+[^\n]*;\n", re.M)


def drop_types(text: str) -> str:
    """Remove top-level struct/union/typedef blocks and warning comments."""
    out, depth, skipping = [], 0, False
    for line in text.splitlines(keepends=True):
        if not skipping and re.match(r"^(typedef )?(struct|union) [^;]*\{\s*$", line):
            skipping, depth = True, 0
        if skipping:
            depth += line.count("{") - line.count("}")
            if depth <= 0 and "}" in line:
                skipping = False
            continue
        if line.startswith("/* Warning:") or re.match(r"^typedef (struct|union) \w+ \w+;", line):
            continue
        out.append(line)
    return "".join(out)


def c_string(raw: bytes, off: int) -> str:
    """The NUL-terminated string at `off` as a C literal."""
    end = raw.index(b"\0", off) if b"\0" in raw[off:] else len(raw)
    s = raw[off:end].decode("latin-1")
    return '"' + s.replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n").replace("\t", "\\t") + '"'


def fold_literals(text: str, pools: dict[str, bytes]) -> str:
    """Inline float pool constants and string slices.

    m2c declares a string pool it could not type as `static M2C_UNK @stringBaseN;`
    and indexes it as `&@stringBaseN + off`; those bytes come from `pools`.
    """
    floats = {}
    for typ, name, val in LITERAL.findall(text):
        floats[name] = val if typ == "f64" or val.endswith("f") else val + "f"
    text = LITERAL.sub("", text)
    raws = {n: bytes(int(b, 0) & 0xFF for b in d.split(", ")) for n, d in STRING.findall(text)}
    text = STRING.sub("", text)
    for n in UNTYPED.findall(text):
        if n in pools:
            raws[n] = pools[n]
            text = re.sub(rf"^static M2C_UNK {re.escape(n)};.*\n", "", text, flags=re.M)
    num = r"(0x[0-9A-Fa-f]+|\d+)"
    for name, raw in raws.items():
        e = re.escape(name)
        lit = lambda m, raw=raw: c_string(raw, int(m.group(1), 0))
        text = re.sub(rf"\(&?{e} \+ {num}\)|&?{e} \+ {num}",
                      lambda m, raw=raw: c_string(raw, int(m.group(1) or m.group(2), 0)), text)
        text = re.sub(rf"&{e}\[{num}\]", lit, text)
        text = re.sub(rf"&?{e}\b", c_string(raw, 0), text)
    for name in sorted(floats, key=len, reverse=True):
        text = re.sub(rf"{re.escape(name)}\b", floats[name], text)
    return re.sub(r"@(\w+)", r"lit_\1", text)


def unwrap_dtor(body: str) -> str:
    """Strip MWCC's dtor skeleton: the null check, the delete flag, `return this`."""
    body = re.sub(r"\n(\s*)if \(destroyFlag > 0\) \{\n\s*__dl__FPv\(this\);\n\s*\}", "", body)
    body = re.sub(r"\n\s*return this;", "", body)
    m = re.match(r"^\{\n    if \(this != NULL\) \{\n(.*)\n    \}\n\}$", body, re.S)
    if m:
        body = "{\n" + re.sub(r"(?m)^    ", "", m.group(1)) + "\n}"
    return body


def drop_generated(body: str, cls: str, ancestors: set) -> str:
    """Remove vptr stores and implicit base/member ctor and dtor calls."""
    lines = []
    for line in body.split("\n"):
        s = line.strip()
        if re.match(r"^this->__vptr = .*;$", s):
            continue
        m = re.match(r"^(?:\w+ = )?__(ct|dt)__(\w+?)\((?:\([^)]*\) ?)?&?this(?:->\w+(?:\[\d+\])?)?(?:, [^;]*)?\);$", s)
        if m:
            continue
        lines.append(line)
    return "\n".join(lines)


def params_of(sig: str) -> list[tuple[str, str]]:
    """(type, name) of m2c's parameter list."""
    out = []
    for p in split_args(sig):
        m = re.match(r"^(.*?)(\w+)$", p.strip())
        if m and p.strip() != "void":
            out.append((m.group(1).strip(), m.group(2)))
    return out


class Converter:
    def __init__(self, model: Model, cnames: dict, owner_of: dict):
        self.model, self.cnames, self.owner_of = model, cnames, owner_of
        self.virtuals, self.statics, self.method_cls = set(), set(), {}
        for n, c in model.classes.items():
            for m in c["methods"]:
                self.method_cls[m["mangled"]] = n
                if m.get("virtual"):
                    self.virtuals.add(m["mangled"])
                if m.get("static"):
                    self.statics.add(m["mangled"])

    def cxx_names(self, text: str) -> str:
        for c in sorted(self.cnames, key=len, reverse=True):
            text = re.sub(rf"\b{re.escape(c)}\b", self.cnames[c], text)
        return text

    def function(self, ret: str, mangled: str, sig: str, body: str) -> tuple[str, set]:
        """C++ definition of one m2c function and the classes it names."""
        try:
            sym = parse(mangled)
        except Exception:  # noqa: BLE001 - C symbol
            sym = None
        quals = [str(q) for q in sym.name.qualified_name or []] if sym else []
        cls = "::".join(quals[:-1]) or None
        params = params_of(sig)
        if cls and params and params[0][1] == "this":
            params = params[1:]
        names = {cls} if cls else set()
        if not sym or not sym.type.terms or sym.type.terms[-1].kind != K.FUNCTION:
            return f"{ret} {mangled}({sig}) {body}", names
        terms = sym.type.terms
        const = terms[0].kind == K.CONST
        fn = terms[-1]
        raw = quals[-1]
        special = raw in ("__ct", "__dt")
        ancestors = set(self.model.ancestors(cls)) if cls else set()
        decl_params = []
        for i, p in enumerate(fn.function_params or []):
            if render(p) == "void":
                continue
            name = params[i][1] if i < len(params) else f"arg{i}"
            decl_params.append(render(p, name))
            if p.terms and p.terms[0].kind == K.REFERENCE:
                body = re.sub(rf"\b{name}->", f"{name}.", body)
                body = re.sub(rf"\*{name}\b", name, body)
                body = re.sub(rf"(?<![\w.&]){name}\b(?![.\w])", f"&{name}", body)
                body = body.replace(f"&{name}.", f"{name}.")
        decl_params = [d for d in decl_params if d != "void"]
        if raw == "__dt":
            body = unwrap_dtor(body)
        if special and cls:
            body = drop_generated(body, cls, ancestors)
        body = CallRewriter(self.virtuals, self.statics, cls, ancestors).rewrite(body)
        name = member_name(cls, raw)[0] if cls else quals[-1]
        head = "" if special else ret + (" " if not ret.endswith("*") else "")
        qual = f"{cls}::" if cls else ""
        text = f"{head}{qual}{name}({', '.join(decl_params)}){' const' if const else ''} {body}"
        return text, names

    def convert(self, text: str, tu: str, pools: dict[str, bytes]) -> str:
        text = fold_literals(drop_types(text), pools)
        text = MANGLED_EXTERN.sub("", text)
        out, used, lines, i = [], set(), text.split("\n"), 0
        while i < len(lines):
            p = LOCAL_PROTO.match(lines[i])
            if p:
                # A local function used before its definition: the source forward-declared it.
                # Methods are declared by their class header instead.
                fn, names = self.function(p.group("ret"), p.group("name"), p.group("params"), "")
                if "::" not in fn.split("(", 1)[0]:
                    out.append("static " + fn.rstrip() + ";")
                    used |= names
                i += 1
                continue
            m = FUNC.match(lines[i])
            if not m:
                out.append(lines[i])
                i += 1
                continue
            j = i + 1
            while j < len(lines) and lines[j] != "}":
                j += 1
            body = "{\n" + "\n".join(lines[i + 1:j]) + "\n}"
            fn, names = self.function(m.group("ret"), m.group("name"), m.group("params"), body)
            used |= names
            if out and out[-1].startswith("/* ") and out[-1].endswith(" */"):
                out.pop()  # m2c's demangled-name comment repeats the signature
            out.append(fn)
            i = j + 1
        body = self.cxx_names("\n".join(out))
        body = re.sub(r"\n{3,}", "\n\n", body).strip() + "\n"
        code = re.sub(r'"(?:\\.|[^"\\])*"', '""', body)
        used |= {n for n in re.findall(r"\b([A-Z]\w*(?:::\w+)*?)(?=\s*\*|::|\s+\w+;)", code) if n in self.owner_of}
        stem = tu.rsplit(".", 1)[0]
        includes = sorted({self.owner_of[header_key(n)].rsplit(".", 1)[0] + ".h" for n in used
                           if header_key(n) in self.owner_of} - {stem + ".h"})
        head = [f'#include "{stem}.h"'] + [f'#include "{i}"' for i in includes] + ["#include <m2c_macros.h>", ""]
        return "\n".join(head) + "\n" + body


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    for a in ("classes", "fields", "m2c_root", "ctx", "cnames", "src_root", "asm_root", "out_root"):
        ap.add_argument(a, type=Path)
    ap.add_argument("--prefix", nargs="*", default=["spyro", "common"])
    ap.add_argument("--write-existing", action="store_true")
    a = ap.parse_args()
    model = load_model(a.classes, a.fields, a.m2c_root, a.ctx)
    conv = Converter(model, json.loads(a.cnames.read_text()), model.owner_map())
    written = 0
    for stem, tu in sorted(model.stems.items()):
        if not any(stem.startswith(p + "/") for p in a.prefix):
            continue
        src = a.src_root / (stem + ".c")
        out = a.out_root / tu
        if not src.exists() or (out.exists() and not a.write_existing):
            continue
        out.parent.mkdir(parents=True, exist_ok=True)
        asm = a.asm_root / (stem + ".s")
        out.write_text(conv.convert(src.read_text(), tu, objects(asm) if asm.exists() else {}))
        written += 1
    print(f"{written} sources written")
    return 0


if __name__ == "__main__":
    sys.exit(main())
