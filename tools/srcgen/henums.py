"""Enum types that ANB's mangled names pass by value but the class model lacks.

MWCC mangles an enum parameter exactly like a class (`17MKCollisionMode`), so
the demangler cannot tell them apart. A name passed by value that never
appears as a class (no vtable, no methods, no fields, no nested names) is an
enum: under PPC EABI a by-value struct travels as a pointer, while these
arrive in a GPR as plain integers and are stored or shifted as such (e.g.
LinkInformation stored straight from r6, MaterialIndex used as a shift count).

C++03 cannot forward-declare an enum, and the original headers are unknown,
so every such enum is defined once in `unplaced_enums.h` as `enum X {};`. No
enumerators are invented; under `-enum int` the type is int-sized regardless.
Fixers move an enum to its real header once evidence places it.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tlos"))
from cxxtypes import K, by_value_classes, class_names, parse  # noqa: E402
from symbols import load  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent.parent
VERSION = "G6SE7D"
HEADER = "unplaced_enums.h"


def value_enums(model, ctx: Path) -> list[str]:
    """Sorted names passed by value in some ANB signature that are not classes, templates, or SDK types.

    `ctx` is the SDK C context; its tags (`enum _GXTexMapID`) are SDK types too.
    """
    byval, scopes = set(), set()
    for s in load(str(ROOT / "config" / VERSION / "symbols.txt")):
        if "__" not in s.name:
            continue
        try:
            sym = parse(s.name)
        except Exception:  # noqa: BLE001 - the demangler raises bare errors on C names
            continue
        if sym.name.qualified_name and len(sym.name.qualified_name) > 1:
            scopes.add(str(sym.name.qualified_name[0]))
        if sym.type.terms and sym.type.terms[-1].kind == K.FUNCTION:
            for p in sym.type.terms[-1].function_params or []:
                byval |= by_value_classes(p)
            for n in class_names(sym.type):
                scopes |= {n.split("::")[0]} if "::" in n else set()
    known = set(model.classes) | set(model.templates) | set(model.sdk) | scopes
    known |= {n.split("::")[0] for n in model.classes}
    known |= set(re.findall(r"\b(?:enum|struct|union)\s+(\w+)", ctx.read_text()))
    return sorted(n for n in byval if "::" not in n and "<" not in n and n not in known)


def header(names: list[str]) -> str:
    """Text of unplaced_enums.h."""
    body = [f"enum {n} {{}};" for n in names]
    return "\n".join(["#ifndef UNPLACED_ENUMS_H", "#define UNPLACED_ENUMS_H", "",
                      "// Enums passed by value whose original header is not yet known (tools/srcgen/henums.py).", "",
                      *body, "", "#endif  // UNPLACED_ENUMS_H", ""])


def mentions(names: list[str]):
    """Regex matching any of the enum names as a whole word."""
    return re.compile(r"\b(?:" + "|".join(map(re.escape, names)) + r")\b") if names else re.compile(r"(?!)")
