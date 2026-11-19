#!/usr/bin/env python3
"""Declare the free function templates whose instances the game TUs call.

Usage: tmplfuncs.py <asm root> <m2c ctx root> <out header>

Instances such as `checked_cast<P16SludgeDescriptor,16MKPropDescriptor>__FP16MKPropDescriptor`
are weak copies of a header template. Their mangled names give the template
arity and parameter types; CodeWarrior does not mangle free-function return
types, and m2c only knows whether r3 carries a value: a family whose
instances mostly return a value returns `T0` when `T0` is a pointer (the
`*_cast` shape), otherwise the most common m2c type; the rest return void.
The header that originally held each template is unknown, so all of them
go into one header named for that: `unplaced_templates.h`.
"""

from __future__ import annotations

import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from cxxtypes import class_names, parse, render  # noqa: E402

FN = re.compile(r'^\.fn "([A-Za-z_]\w*<[^"]*>__F[^"]*)", (?:weak|local)$', re.M)
DEF = re.compile(r"^(?:static )?(?P<ret>[^\s/#(][^(]*?)\s*\b(?P<name>[A-Za-z_]\w*<[^>(]*>__F\w*)\(", re.M)

SPELL = {"f32": "float", "f64": "double", "s32": "long", "u32": "unsigned long"}  # m2c spelling -> render()'s


def generic(text: str, args: list[str]) -> str:
    """`text` with each template argument's spelling replaced by `T<i>`, longest first."""
    for i in sorted(range(len(args)), key=lambda i: -len(args[i])):
        text = re.sub(rf"(?<![\w:]){re.escape(args[i])}(?![\w])", f"T{i}", text)
    return text


def main() -> int:
    asm_root, m2c_root, out = map(Path, sys.argv[1:4])
    names = sorted({n for f in asm_root.glob("*/**/*.s") for n in FN.findall(f.read_text())})
    rets: dict = defaultdict(list)
    for f in m2c_root.rglob("*.c"):
        for m in DEF.finditer(f.read_text()):
            rets[m.group("name")].append(m.group("ret").strip())
    families: dict = defaultdict(lambda: {"params": Counter(), "ret": Counter(), "arity": Counter(), "nontype": True})
    classes: set = set()
    for n in names:
        try:
            sym = parse(n)
        except Exception:  # noqa: BLE001 - names the demangler rejects stay undeclared
            continue
        q = sym.name.qualified_name
        if not q or len(q) != 1 or not q[0].template_params:
            continue
        args = [render(t) for t in q[0].template_params]
        for p in sym.type.terms[-1].function_params or []:
            classes |= {c for c in class_names(p) if re.fullmatch(r"\w+", c)}
        params = ", ".join(generic(render(p), args) for p in sym.type.terms[-1].function_params or []
                           if render(p) != "void")
        fam = families[q[0].name]
        fam["arity"][len(args)] += 1
        fam["nontype"] &= all(re.fullmatch(r"-?\d+", a) for a in args)
        fam["params"][(len(args), params)] += 1
        for r in rets.get(n, []):
            r = "void" if r in ("void", "M2C_UNK") else ("T0" if args[0].endswith("*") else generic(SPELL.get(r, r), args))
            fam["ret"][(len(args), r)] += 1
    lines = ["#ifndef UNPLACED_TEMPLATES_H", "#define UNPLACED_TEMPLATES_H", "",
             "// Free function templates whose original header is not yet known (tools/srcgen/tmplfuncs.py).", ""]
    lines += [f"class {c};" for c in sorted(classes)] + [""]
    for name, fam in sorted(families.items()):
        arity = fam["arity"].most_common(1)[0][0]
        params = next(p for (a, p), _ in fam["params"].most_common() if a == arity)
        ret = next((r for (a, r), _ in fam["ret"].most_common() if a == arity), "void")
        # Integer template arguments (`<0>`) are non-type parameters; their exact type is not mangled.
        tparams = ", ".join(f"{'int' if fam['nontype'] else 'class'} T{i}" for i in range(arity))
        lines.append(f"template <{tparams}> {ret} {name}({params});")
    lines += ["", "#endif  // UNPLACED_TEMPLATES_H", ""]
    out.write_text("\n".join(lines))
    print(f"{len(families)} function templates declared in {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
