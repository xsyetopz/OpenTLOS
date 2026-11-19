#!/usr/bin/env python3
"""Generate first-draft class headers for ANB's game and engine TUs.

Usage: headers.py <classes.json> <fields.json> <m2c out root> <ctx.c> <out root> [--write-existing]
                  [--inline-root DIR]

Each class goes into the header of its owner TU (`<out root>/<tu path>.h`, the
usual decomp convention; ANB keeps no header names). Templates, which have no
TU, get a header named after the template. A header holds:
  * includes for bases, by-value fields, nested and template uses; forward
    declarations otherwise; <dolphin.h> when an SDK type appears;
  * classes with base, virtual methods in vtable slot order, other methods,
    static members, and m2c-voted `unkXX` fields padded to their offsets;
  * the TU's global free functions and global variables;
  * `#include "unplaced_enums.h"` when it names an enum henums.py found;
  * with `--inline-root`, the classes' inline members from cxxconv.py's
    weak copies (inlines.py), defined after everything else.
See hmodel.py for how owners, sizes, and fields are inferred. Without
`--write-existing` an existing header is left alone, so hand-refined headers
are never overwritten.
"""

from __future__ import annotations

import argparse
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tlos"))
from cxxtypes import K, class_names, parse, render  # noqa: E402
from henums import HEADER, header, value_enums  # noqa: E402
from hmodel import Model, header_key, load_model, type_names  # noqa: E402
from hrender import Refs, class_body, header_order, inlined, template_body  # noqa: E402
from inlines import MARK, by_class  # noqa: E402
from splits import Splits  # noqa: E402
from symbols import load  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent.parent
VERSION = "G6SE7D"
GUARD = re.compile(r"[^A-Za-z0-9]")


def globals_by_tu(stems: dict) -> tuple[dict, dict]:
    """Global-scope free functions and data objects of each game/engine TU."""
    splits = Splits(str(ROOT / "config" / VERSION / "splits.txt"))
    tus = set(stems.values())
    free, data = defaultdict(list), defaultdict(list)
    for s in load(str(ROOT / "config" / VERSION / "symbols.txt")):
        if "scope:global" not in s.attrs:
            continue
        tu = splits.tu_at(s.section, s.addr)
        if tu not in tus:
            continue
        try:
            sym = parse(s.name) if "__" in s.name else None
        except Exception:  # noqa: BLE001 - the demangler raises bare errors on C names
            sym = None
        quals = [str(q) for q in sym.name.qualified_name] if sym and sym.name.qualified_name else []
        if s.kind == "function" and sym and len(quals) == 1 and sym.type.terms and sym.type.terms[-1].kind == K.FUNCTION:
            free[tu].append((s.name, quals[0], sym))
        elif s.kind == "object" and "__" not in s.name:
            data[tu].append(s)
    return free, data


def nested_names(model: Model, free: dict) -> dict:
    """Outer class -> inner names that must be declared inside it."""
    names = {n for n in model.classes if "::" in n}
    for c in model.classes.values():
        for m in c["methods"]:
            names |= {n for n in class_names(parse(m["mangled"]).type) if "::" in n}
    for f in model.fields.values():
        for v in f["fields"].values():
            names |= {n for n in type_names(v["type"][0]) if "::" in n}
    for items in free.values():
        for _, _, sym in items:
            names |= {n for n in class_names(sym.type) if "::" in n}
    out = defaultdict(set)
    for n in names:
        outer, _, inner = n.rpartition("::")
        if "<" not in n and "::" not in inner:
            out[outer].add(inner)
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("classes", type=Path)
    ap.add_argument("fields", type=Path)
    ap.add_argument("m2c_root", type=Path)
    ap.add_argument("ctx", type=Path)
    ap.add_argument("out_root", type=Path)
    ap.add_argument("--write-existing", action="store_true")
    ap.add_argument("--inline-root", type=Path)
    a = ap.parse_args()

    model = load_model(a.classes, a.fields, a.m2c_root, a.ctx)
    rets, globs, stems, sdk = model.rets, model.globs, model.stems, model.sdk
    free, data = globals_by_tu(stems)
    nested = model.nested = nested_names(model, free)

    inline = by_class(a.inline_root) if a.inline_root else {}
    owner_of = model.owner_map()
    enums = set(value_enums(model, a.ctx))
    (a.out_root / HEADER).parent.mkdir(parents=True, exist_ok=True)
    (a.out_root / HEADER).write_text(header(sorted(enums)))
    by_tu = defaultdict(list)
    for n, tu in owner_of.items():
        by_tu[tu].append(n)

    written = 0
    for tu in sorted(set(by_tu) | set(free) | set(data)):
        path = (a.out_root / tu.rsplit(".", 1)[0]).with_suffix(".h")
        if path.exists() and not a.write_existing:
            continue
        refs, body = Refs(), []
        for n in sorted(x for x in by_tu.get(tu, []) if x in model.templates):
            body += template_body(model, n, refs) + [""]
        for n in header_order(model, [x for x in by_tu.get(tu, []) if x not in model.templates and not inlined(model, x)]):
            body += class_body(model, n, refs, nested.get(n, set())) + [""]
        for mangled, name, sym in free.get(tu, []):
            refs.named |= class_names(sym.type) | type_names(rets.get(mangled, ""))
            decl = render(sym.type, name)
            decl = decl[len("void "):] if decl.startswith("void ") else decl
            body.append(f"{rets.get(mangled, 'void')} {decl};")
        for s in data.get(tu, []):
            typ = globs.get(s.name)
            if typ:
                refs.ctype(typ)
            body.append(f"extern {typ} {s.name};" if typ else f"extern u8 {s.name}[{s.size:#x}];")

        mine = set(by_tu.get(tu, []))
        for n in list(refs.named | refs.complete):  # template arguments need declaring too
            if "<" in n:
                refs.named |= {x for x in type_names(n.split("<", 1)[1]) if x not in model.templates}
        # Nested and template names cannot be forward-declared; include their header.
        need = refs.complete | {n for n in refs.named if "::" in n or "<" in n or n in model.templates}
        includes = sorted({owner_of[header_key(d)] for d in need if owner_of.get(header_key(d), tu) != tu})
        # Own classes too: a later class in this header may be named before its definition.
        fwd = sorted(n for n in refs.named | refs.complete | mine
                     if "::" not in n and "<" not in n and n not in model.templates and n not in sdk and n not in enums)
        uses_sdk = any(n in sdk for n in refs.named | refs.complete)
        guard = GUARD.sub("_", tu.rsplit(".", 1)[0]).upper() + "_H"
        text = [f"#ifndef {guard}", f"#define {guard}", "", "#include <dolphin.h>" if uses_sdk else "#include <dolphin/types.h>"]
        text += [f'#include "{i.rsplit(".", 1)[0]}.h"' for i in includes]
        text += [f'#include "{HEADER}"'] if enums & (refs.named | refs.complete) else []
        text += [""]
        text += [f"class {n};" for n in fwd] + ([""] if fwd else [])
        defs = [f"inline {fn}" for n in sorted(mine) for fn in inline.get(n, [])]
        # m2c-drafted inline bodies use M2C_* macros; TUs include them only after their headers.
        macros = ["#include <m2c_macros.h>", ""] if any("M2C_" in d for d in defs) else []
        text += body + ([MARK, "", *macros, *(d + "\n" for d in defs)] if defs else []) + [f"#endif  // {guard}", ""]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("\n".join(text))
        written += 1
    print(f"{written} headers and {HEADER} ({len(enums)} enums) written, {len(owner_of)} classes and templates placed")
    return 0


if __name__ == "__main__":
    sys.exit(main())
