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

A function with a hand fix at `--fixes <root>/<stem>/<mangled>.cpp` takes
that text verbatim instead, so fixes survive regeneration; fence.py still
fences a fix that later stops compiling.
"""

from __future__ import annotations

import argparse
import json
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from asmdata import bindings, objects  # noqa: E402
from stackslots import resolve, slot_types  # noqa: E402
from cxxtypes import K, parse, render  # noqa: E402
from henums import HEADER as ENUM_HEADER, mentions, value_enums  # noqa: E402
from hmodel import Model, header_key, load_model, type_names  # noqa: E402
from hrender import member_name  # noqa: E402
from m2ccalls import CallRewriter, devirtualize, split_args, type_this_vcalls  # noqa: E402

FUNC = re.compile(r"^(?P<ret>[^\s/#].*?)\s*\b(?P<name>[A-Za-z_][\w<>,@$]*)\((?P<params>.*)\) \{$")
LOCAL_PROTO = re.compile(r"^(?P<ret>[^\s/#].*?)\s*\b(?P<name>[A-Za-z_][\w<>,@$]*)\((?P<params>.*)\);\s*/\* static \*/$")
LITERAL = re.compile(r"^static (f32|f64) (@\d+) = (.+?);.*$", re.M)
# m2c sizes pools in decimal or hex and prints bytes on one line or one per line.
STRING = re.compile(r"^static (?:const )?s8 (@stringBase\d+)\[(?:0x[0-9A-Fa-f]+|\d+)\] = \{\s*(.*?),?\s*\};[^\n]*$",
                    re.M | re.S)
UNTYPED = re.compile(r"^static M2C_UNK (@stringBase\d+);", re.M)
MANGLED_EXTERN = re.compile(r"^[^\n]*\b[\w<>,]+__[\w<>,]*[(;][^\n]*/\* extern \*/\n|^extern [^\n]*\b[\w<>,]*__[\w<>,]+[^\n]*;\n", re.M)
# `@N@name` is a this-adjusting thunk MWCC makes for a secondary base; not source.
THUNK = re.compile(r"^(?:/\* [^\n]*@\d+@[^\n]*\*/\n)?[^\n/]*(?<![\w@])@\d+@\w*\((?:[^\n]*\) \{\n.*?^\}\n|[^\n]*;[^\n]*\n)",
                   re.M | re.S)
TEMPLATE_FN = re.compile(r"^[A-Za-z_]\w*<")
UNPLACED = re.compile(r"\b(?:checked_cast|ui_cast|ui_cast_ptr|property_cast|property_cast_ptr|safe_delete|Clamp|Min|"
                      r"KDMath_Smooth|KDMath_CriticalDamp|KDMath_Dampen|ByteReverse|Endian|Model_RenderChunkGC)\s*<")


SDK_HEADERS = ["os", "gx", "dvd", "pad", "vi", "ai", "ar", "card", "ax", "mtx", "dsp", "exi", "si", "axfx", "mix"]
SDK_NAME = re.compile(r"\b(?:OS|GX|DVD|PAD|VI|AI|AR|ARQ|CARD|AX|PSMTX|PSVEC|PSQUAT|C_MTX|C_VEC|MTX|VEC|DSP|EXI|SI|MIX|Mtx|Vec|Quaternion)\w*\b")
# Prologue/epilogue of functions with over-aligned locals, which m2c leaves in the body.
ALIGNED_STACK = re.compile(r"^\s*\*\(sp \+ \(-0x[0-9A-Fa-f]+ - \(\(s32\) sp & 0x[0-9A-Fa-f]+\)\)\) = sp;\n"
                           r"|^[^\n]*\bM2C_FIELD\(sp, [^\n]*\bsaved_reg_\w+;\n|^[^\n]*\bsaved_reg_\w+ = [^\n]*\bsp\b[^\n]*;\n", re.M)


def sdk_index(include_root: Path) -> dict[str, str]:
    """{SDK identifier: `dolphin/<x>.h`} for names the converted code may use without a game header."""
    index = {}
    for h in SDK_HEADERS:
        root = include_root / "dolphin"
        for f in [root / f"{h}.h", *sorted((root / h).rglob("*.h"))] if (root / h).is_dir() else [root / f"{h}.h"]:
            if f.exists():
                for n in SDK_NAME.findall(f.read_text(errors="replace")):
                    index.setdefault(n, f"dolphin/{h}.h")
    return index


def free_functions(hdr_root: Path) -> dict[str, str]:
    """{free function name: header} from the generated headers' top-level prototypes."""
    out = {}
    for h in sorted(hdr_root.rglob("*.h")):
        for n in re.findall(r"^(?!typedef|#|//|class|struct|template)[A-Za-z_][^\n(;]*?\b(\w+)\(", h.read_text(), re.M):
            out.setdefault(n, h.relative_to(hdr_root).as_posix())
    return out


def drop_types(text: str) -> str:
    """Remove top-level struct/union/typedef blocks and warning comments."""
    out, depth, skipping, comment = [], 0, False, False
    for line in text.splitlines(keepends=True):
        if comment or line.startswith("/* Warning:"):
            comment = "*/" not in line
            continue
        if not skipping and re.match(r"^(typedef )?(struct|union) [^;]*\{\s*$", line):
            skipping, depth = True, 0
        if skipping:
            depth += line.count("{") - line.count("}")
            if depth <= 0 and "}" in line:
                skipping = False
            continue
        if re.match(r"^typedef (struct|union) \w+ \w+;", line):
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
    raws = {n: bytes(int(b, 0) & 0xFF for b in re.split(r",\s*", d)) for n, d in STRING.findall(text)}
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
    def __init__(self, model: Model, cnames: dict, owner_of: dict, sdk: dict, free: dict, fixes: Path | None = None):
        self.model, self.cnames, self.owner_of, self.sdk, self.free = model, cnames, owner_of, sdk, free
        self.fixes = fixes
        self.enum_ref = mentions(value_enums(model, model.ctx))
        headers = set(free.values()) | {o.rsplit(".", 1)[0] + ".h" for o in owner_of.values()}
        self.has_header = lambda stem: stem + ".h" in headers
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
        ret = self.model.decl_rets().get(mangled, ret)
        head = "" if special else ret + (" " if not ret.endswith("*") else "")
        qual = f"{cls}::" if cls else ""
        text = f"{head}{qual}{name}({', '.join(decl_params)}){' const' if const else ''} {body}"
        return text, names

    def convert(self, text: str, tu: str, pools: dict[str, bytes], binds: dict[str, str],
                slots: dict[str, dict[int, str]]) -> tuple[str, str]:
        """(TU source, header-inline functions) for one m2c output.

        Weak functions and local template instances are copies of header
        inlines that MWCC emitted into this TU; they belong in headers, so
        they are returned separately instead of being defined here.
        """
        text = fold_literals(drop_types(THUNK.sub("", text)), pools)
        text = MANGLED_EXTERN.sub("", text)
        # The 16-byte stack realignment MWCC emits for aligned locals is not source.
        text = ALIGNED_STACK.sub("", text)
        text = re.sub(r"^[^\n]*\b__ptmf_\w+\([^\n]*/\* extern \*/\n", "", text, flags=re.M)
        # Function-local statics are emitted as `name$NNN`.
        text = re.sub(r"\b(\w+)\$(\d+)\b", r"\1_\2", text)
        out, inline, used, lines, i = [], [], set(), text.split("\n"), 0
        while i < len(lines):
            p = LOCAL_PROTO.match(lines[i])
            if p and TEMPLATE_FN.match(p.group("name")):
                i += 1
                continue
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
            body = resolve("{\n" + "\n".join(lines[i + 1:j]) + "\n}", slots.get(m.group("name"), {}))
            fix = self.fixes / tu.rsplit(".", 1)[0] / (m.group("name") + ".cpp") if self.fixes else None
            if fix and fix.exists():
                fn, names = fix.read_text().strip(), set()
            else:
                if m.group("name") in self.method_cls:
                    body = type_this_vcalls(body, self.method_cls[m.group("name")], self.model.slot_fn)
                fn, names = self.function(m.group("ret"), m.group("name"), m.group("params"), body)
            if out and out[-1].startswith("/* ") and out[-1].endswith(" */"):
                out.pop()  # m2c's demangled-name comment repeats the signature
            name = m.group("name")
            if binds.get(name) == "weak" or (binds.get(name) == "local" and TEMPLATE_FN.match(name)):
                inline.append(fn)
            else:
                used |= names
                out.append(fn)
            i = j + 1
        body = devirtualize(self.cxx_names("\n".join(out)), self.model.slot_fn)
        body = re.sub(r"\n{3,}", "\n\n", body).strip() + "\n"
        code = re.sub(r'"(?:\\.|[^"\\])*"', '""', body)
        used |= {n for n in re.findall(r"\b([A-Z]\w*(?:::\w+)*?)(?=\s*\*|::|\s+\w+;)", code) if n in self.owner_of}
        stem = tu.rsplit(".", 1)[0]
        includes = sorted({self.owner_of[header_key(n)].rsplit(".", 1)[0] + ".h" for n in used
                           if header_key(n) in self.owner_of} - {stem + ".h"})
        if UNPLACED.search(code):
            includes.append("unplaced_templates.h")
        if self.enum_ref.search(code):
            includes.append(ENUM_HEADER)
        includes += sorted({self.sdk[n] for n in SDK_NAME.findall(code) if n in self.sdk})
        includes += sorted({self.free[n] for n in re.findall(r"\b(\w+)\s*\(", code)
                            if n in self.free and self.free[n] != stem + ".h"} - set(includes))
        own = [f'#include "{stem}.h"'] if self.has_header(stem) else []
        head = own + [f'#include "{i}"' for i in includes] + ["#include <m2c_macros.h>", ""]
        return "\n".join(head) + "\n" + body, self.cxx_names("\n\n".join(inline))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    for a in ("classes", "fields", "m2c_root", "ctx", "cnames", "src_root", "asm_root", "out_root"):
        ap.add_argument(a, type=Path)
    ap.add_argument("--prefix", nargs="*", default=["spyro", "common"])
    ap.add_argument("--write-existing", action="store_true")
    ap.add_argument("--hdr-root", type=Path, help="generated headers, for including free functions' headers")
    ap.add_argument("--inline-root", type=Path, help="where each TU's header-inline functions go, as <stem>.inl")
    ap.add_argument("--fixes", type=Path, help="hand-fixed functions, as <stem>/<mangled>.cpp")
    ap.add_argument("--m2c-votes", type=Path, help="m2c run with class context; upgrades untyped globals and returns (hmodel.m2c_types)")
    a = ap.parse_args()
    model = load_model(a.classes, a.fields, a.m2c_root, a.ctx, a.m2c_votes)
    conv = Converter(model, json.loads(a.cnames.read_text()), model.owner_map(),
                     sdk_index(Path(__file__).resolve().parents[2] / "include"),
                     free_functions(a.hdr_root) if a.hdr_root else {}, a.fixes)
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
        pools, binds, slots = (objects(asm), bindings(asm), slot_types(asm)) if asm.exists() else ({}, {}, {})
        source, inline = conv.convert(src.read_text(), tu, pools, binds, slots)
        out.write_text(source)
        if inline and a.inline_root:
            dest = a.inline_root / (stem + ".inl")
            dest.parent.mkdir(parents=True, exist_ok=True)
            dest.write_text(inline + "\n")
        written += 1
    print(f"{written} sources written")
    return 0


if __name__ == "__main__":
    sys.exit(main())
