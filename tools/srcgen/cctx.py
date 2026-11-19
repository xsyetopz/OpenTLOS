#!/usr/bin/env python3
"""Write the class model as C context for m2c, so its output speaks the headers' language.

Usage: cctx.py <classes.json> <fields.json> <m2c out root> <sdk ctx.c> <out ctx.c> <out names.json>

Without context every m2c TU invents its own `typedef struct Foo` and guesses
argument types. This context gives m2c, for every game/engine class:
  * a flattened C struct (ancestors' fields, the vptr as `__vptr` at its
    evidenced offset, then own fields) with the same `unkXX` names and offsets
    as the generated C++ headers;
  * a prototype for every method and free function, `this` first, references
    as pointers, return types from the previous m2c votes.
C cannot spell `A::B` or `T<U>`, so those become `A__B` and `T_U_`; the map
back to C++ goes to names.json for the C++ converter.
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from cxxtypes import K, parse, qualname, render  # noqa: E402
from hmodel import Model, ctype, load_model, type_names  # noqa: E402

C_BUILTIN = {"void", "char", "short", "int", "long", "float", "double", "signed", "unsigned", "bool", "wchar_t"}
PREAMBLE = "typedef unsigned char bool;\ntypedef unsigned short wchar_t;\n"


def cname(name: str) -> str:
    """C identifier for a C++ class name."""
    return re.sub(r"\W", "_", name.replace("::", "__").replace(", ", "_")).rstrip("_") + ("_" if "<" in name else "")


class CContext:
    def __init__(self, model: Model):
        self.model, self.names, self.used = model, {}, set()

    def qual(self, term) -> str:
        n = qualname(term)
        c = cname(n)
        self.used.add(c)
        if c != n:
            self.names[c] = n
        return c

    def ctype(self, typ: str) -> str:
        """m2c/C++ type string with class names made C identifiers."""
        typ = ctype(typ)
        self.used |= {cname(n) for n in type_names(typ)}
        for n in sorted(type_names(typ) | set(re.findall(r"\b\w+<[^>]*>", typ)), key=len, reverse=True):
            if cname(n) != n:
                self.names[cname(n)] = n
                self.used.add(cname(n))
                typ = typ.replace(n, cname(n))
        return typ

    def flat_fields(self, name: str) -> list:
        """(offset, type) of a class and its ancestors, vptr included, no overlaps."""
        m = self.model
        chain = [*reversed(m.ancestors(name)), name]
        out, vp = {}, m.vptr_of(name)
        for n in chain:
            for off, f in m.fields.get(n, {}).get("fields", {}).items():
                out.setdefault(int(off), f["type"][0])
        if vp is not None:
            out[vp] = "void *"
        rows, pos = [], 0
        for off in sorted(out):
            typ = ctype(out[off]) if off != vp else "void *"
            size = m.type_size(typ)
            if off < pos:
                continue
            base = typ.split("[")[0].strip()
            if not base.endswith("*") and any(not m.embeddable(n) or n in m.templates for n in type_names(base)):
                continue
            rows.append((off, typ))
            pos = off + size
        return rows

    def struct(self, name: str) -> tuple[list, set]:
        """C struct text and the class names it embeds by value."""
        m, cn = self.model, cname(name)
        lines, pos, embeds = [f"struct {cn} {{"], 0, set()
        for off, typ in self.flat_fields(name):
            if off > pos:
                lines.append(f"    char pad{pos:X}[0x{off - pos:X}];")
            arr = "".join(re.findall(r"\[\w+\]", typ))
            base = typ.split("[")[0].strip()
            if not base.endswith("*"):
                embeds |= type_names(base) & set(m.classes)
            field = "__vptr" if m.vptr_of(name) == off and base == "void *" else f"unk{off:X}"
            lines.append(f"    {self.ctype(base)} {field}{arr};")
            pos = off + m.type_size(typ)
        size = max(pos, m.classes[name].get("size_max") or 0, m.end(name))
        if size > pos or pos == 0:
            lines.append(f"    char pad{pos:X}[0x{max(size - pos, 1):X}];")
        lines.append("};")
        return lines, embeds

    def prototype(self, mangled: str, cls: str | None) -> str | None:
        if not re.fullmatch(r"[A-Za-z_]\w*", mangled):
            return None  # template symbols (`<`, `,`) are not C identifiers; m2c keeps its own guess
        try:
            sym = parse(mangled)
        except Exception:  # noqa: BLE001
            return None
        terms = sym.type.terms
        if not terms or terms[-1].kind != K.FUNCTION:
            return None
        fn = terms[-1]
        params = [render(p, "", self.qual, "*") for p in fn.function_params or []]
        params = [p for p in params if p != "void"]
        if cls:
            params.insert(0, f"{cname(cls)} *this")
        ret = self.ctype(self.model.rets.get(mangled, "void"))
        name = sym.name.qualified_name[-1] if sym.name.qualified_name else None
        if str(name) in ("__ct", "__dt"):
            ret = f"{cname(cls)} *"
            if str(name) == "__dt":
                params.append("short")  # CodeWarrior dtors take a hidden delete flag
        return f"{ret} {mangled}({', '.join(params) or 'void'});"


def order(model: Model, names: list, embeds: dict) -> list:
    done, out = set(), []

    def visit(n, stack=()):
        if n in done or n in stack:
            return
        for d in sorted(embeds.get(n, ())):
            if d != n:
                visit(d, (*stack, n))
        done.add(n)
        out.append(n)

    for n in names:
        visit(n)
    return out


def main() -> int:
    classes, fields, m2c_root, sdk_ctx, out, names_out = map(Path, sys.argv[1:7])
    model = load_model(classes, fields, m2c_root, sdk_ctx)
    cc = CContext(model)
    names = sorted(n for n in model.classes if n not in model.sdk)
    bodies, embeds = {}, {}
    for n in names:
        bodies[n], embeds[n] = cc.struct(n)
    text = [sdk_ctx.read_text(), PREAMBLE]
    for n in names:
        if cname(n) != n:
            cc.names[cname(n)] = n
        text.append(f"typedef struct {cname(n)} {cname(n)};")
    for n in order(model, names, embeds):
        text += bodies[n]
    protos = 0
    for n in names:
        for m in model.classes[n]["methods"]:
            if m["name"].startswith("@"):
                continue
            p = cc.prototype(m["mangled"], n)
            if p:
                text.append(p)
                protos += 1
    for mangled in sorted(model.rets):
        try:
            sym = parse(mangled)
        except Exception:  # noqa: BLE001
            continue
        if sym.name.qualified_name and len(sym.name.qualified_name) == 1:
            p = cc.prototype(mangled, None)
            if p:
                text.append(p)
                protos += 1
    # Names seen only in field types or signatures (no symbols of their own)
    # stay incomplete; m2c needs at least a declaration of each.
    known = {cname(n) for n in names} | model.sdk
    extra = sorted(n for n in cc.used if n not in known and n not in C_BUILTIN)
    at = text.index(PREAMBLE) + 1
    text[at:at] = [f"typedef struct {n} {n};" for n in extra]
    out.write_text("\n".join(text) + "\n")
    names_out.write_text(json.dumps(dict(sorted(cc.names.items())), indent=1))
    print(f"{len(names)} structs, {protos} prototypes, {len(cc.names)} renamed types")
    return 0


if __name__ == "__main__":
    sys.exit(main())
