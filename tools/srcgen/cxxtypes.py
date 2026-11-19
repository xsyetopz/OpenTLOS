"""Render CodeWarrior-mangled types as compilable C++ declarations.

m2c's demangler prints readable but not always declarable text (function
pointers come out as "void (*) (int) *"). This renders its parsed terms with a
proper declarator, so `PFP12MKInputEventPv_b` becomes `bool (*name)(MKInputEvent*, void*)`.
"""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, "/Users/krystian/CodeProjects/xsyetopz/GodHand/tools/ext/m2c")
from m2c.demangle_codewarrior import CxxTerm, CxxType, parse  # noqa: E402,F401

K = CxxTerm.Kind
BASE = {K.VOID: "void", K.BOOL: "bool", K.CHAR: "char", K.SHORT: "short", K.INT: "int", K.LONG: "long",
        K.LONG_LONG: "long long", K.WIDE_CHAR: "wchar_t", K.FLOAT: "float", K.DOUBLE: "double",
        K.LONG_DOUBLE: "long double", K.ELLIPSIS: "..."}


def qualname(term: CxxTerm) -> str:
    return "::".join(str(q) for q in term.qualified_name or [])


def render(t: CxxType, name: str = "") -> str:
    """C++ declaration of `name` with type `t` (abstract declarator when name is empty)."""
    d, prefix = name, []
    terms = t.terms
    for i, term in enumerate(terms):
        rest = terms[i + 1:]
        if term.kind == K.POINTER:
            d = "*" + d
        elif term.kind == K.REFERENCE:
            d = "&" + d
        elif term.kind == K.CONST:
            if rest and rest[0].kind in (K.POINTER, K.REFERENCE):
                d = " const " + d
            else:
                prefix.append("const")
        elif term.kind in (K.UNSIGNED, K.SIGNED):
            prefix.append(term.kind.name.lower())
        elif term.kind == K.ARRAY:
            d = (f"({d})" if d[:1] in "*&" else d) + f"[{term.array_dim}]"
        elif term.kind == K.FUNCTION:
            params = ", ".join(render(p) for p in term.function_params or []) or "void"
            inner = (f"({d})" if d[:1] in "*&" else d) + f"({params})"
            return render(term.function_return, inner) if term.function_return else f"void {inner}"
        elif term.kind == K.QUALIFIED:
            return " ".join([*prefix, qualname(term)]) + (" " + d if d else "")
        else:
            return " ".join([*prefix, BASE[term.kind]]) + (" " + d if d else "")
    return " ".join(prefix) + (" " + d if d else "")


def class_names(t: CxxType) -> set:
    """Every class name a type mentions, including inside function pointers."""
    out = set()
    for term in t.terms:
        if term.kind == K.QUALIFIED:
            out.add(qualname(term))
        elif term.kind == K.FUNCTION:
            for p in [*(term.function_params or []), *([term.function_return] if term.function_return else [])]:
                out |= class_names(p)
    return out


def by_value_classes(t: CxxType) -> set:
    """Classes the type embeds by value (needs a complete type in a field)."""
    if t.terms and t.terms[-1].kind == K.QUALIFIED and all(x.kind in (K.CONST, K.ARRAY) for x in t.terms[:-1]):
        return {qualname(t.terms[-1])}
    return set()
