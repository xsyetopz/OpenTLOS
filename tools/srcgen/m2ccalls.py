"""Rewrite m2c's mangled-symbol calls and references in one function body as C++.

m2c calls every function by its mangled name with `this` as the first
argument (`Message__8PlatformFP9MKMessage((Platform *) this, arg0)`). In C++
that is a member call: an unqualified one for non-virtual methods, and a
qualified `Platform::Message(arg0)` for a virtual method, because a direct
`bl` to a virtual method means the source named the class (devirtualized
calls are rare under MWCC). Reference parameters arrive as pointers, so
`&x` becomes `x` and any other pointer `p` becomes `*p`.
"""

from __future__ import annotations

import re

from cxxtypes import K, parse
from hrender import member_name

TOKEN = re.compile(r"(?<![\w@])[A-Za-z_][\w<>,]*\w(?=\s*\(|\b)")
CAST = re.compile(r"^\((?:const )?[\w:<>, ]+ \*+\) ?")
OPERATORS = {"__nw": "operator new", "__nwa": "operator new[]", "__dl": "operator delete", "__dla": "operator delete[]"}


def split_args(text: str) -> list[str]:
    out, depth, cur = [], 0, ""
    for ch in text:
        if ch in "([{":
            depth += 1
        elif ch in ")]}":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    return out + ([cur.strip()] if cur.strip() else [])


def close_paren(text: str, start: int) -> int:
    """Index of the `)` matching the `(` at `start`."""
    depth = 0
    for i in range(start, len(text)):
        if text[i] == "(":
            depth += 1
        elif text[i] == ")":
            depth -= 1
            if depth == 0:
                return i
    return -1


def ref_arg(arg: str) -> str:
    """A pointer argument passed to a reference parameter."""
    if arg.startswith("&") and not arg.startswith("&&"):
        return arg[1:]
    return f"*{arg}" if re.fullmatch(r"[\w.>-]+|\(.*\)", arg) else f"*({arg})"


class Symbol:
    """A parsed mangled name: owning class (or None), C++ member name, param kinds."""

    def __init__(self, mangled: str):
        sym = parse(mangled)
        quals = [str(q) for q in sym.name.qualified_name or []]
        terms = sym.type.terms
        self.is_func = bool(terms) and terms[-1].kind == K.FUNCTION
        self.cls = "::".join(quals[:-1]) or None
        self.raw = quals[-1] if quals else mangled
        fn = terms[-1] if self.is_func else None
        params = [p for p in (fn.function_params or [])] if fn else []
        self.refs = [bool(p.terms) and p.terms[0].kind == K.REFERENCE for p in params]
        if self.raw in OPERATORS:
            self.name = OPERATORS[self.raw]
        elif self.cls:
            self.name = member_name(self.cls, self.raw)[0]
        else:
            self.name = self.raw


class CallRewriter:
    """Rewrites a body given the model's virtual/static knowledge and the enclosing class."""

    def __init__(self, virtuals: set, statics: set, cls: str | None, ancestors: set):
        self.virtuals, self.statics, self.cls, self.ancestors = virtuals, statics, cls, ancestors
        self.cache: dict = {}

    def symbol(self, tok: str):
        if "__" not in tok.strip("_"):
            return None
        if tok not in self.cache:
            try:
                self.cache[tok] = Symbol(tok)
            except Exception:  # noqa: BLE001 - not a mangled name
                self.cache[tok] = None
        return self.cache[tok]

    def call(self, tok: str, sym: Symbol, args: list[str]) -> str:
        member = sym.cls and sym.raw not in OPERATORS and tok not in self.statics
        params = args[1:] if member else args
        params = [ref_arg(a) if i < len(sym.refs) and sym.refs[i] else a for i, a in enumerate(params)]
        tail = f"({', '.join(params)})"
        if not member:
            return (f"{sym.cls}::" if sym.cls and sym.raw not in OPERATORS else "") + sym.name + tail
        obj = CAST.sub("", args[0]) if args else "this"
        qual = f"{sym.cls}::" if tok in self.virtuals else ""
        if obj == "this":
            if not qual and sym.cls != self.cls and sym.cls not in self.ancestors:
                qual = f"{sym.cls}::"
            return f"{qual}{sym.name}{tail}"
        if obj.startswith("&") and re.fullmatch(r"&[\w.>-]+", obj):
            return f"{obj[1:]}.{qual}{sym.name}{tail}"
        if not re.fullmatch(r"[\w.>-]+", obj):
            obj = f"(({sym.cls} *) ({args[0]}))"
        return f"{obj}->{qual}{sym.name}{tail}"

    def rewrite(self, body: str) -> str:
        out, pos = [], 0
        for m in TOKEN.finditer(body):
            if m.start() < pos:
                continue
            tok = m.group(0)
            sym = self.symbol(tok)
            if not sym:
                continue
            j = m.end()
            while j < len(body) and body[j] == " ":
                j += 1
            out.append(body[pos:m.start()])
            if sym.is_func and j < len(body) and body[j] == "(":
                end = close_paren(body, j)
                args = [self.rewrite(a) for a in split_args(body[j + 1:end])]
                out.append(self.call(tok, sym, args))
                pos = end + 1
            else:
                # A function used as a value or a class-scope variable.
                amp = "&" if sym.is_func and sym.cls and tok not in self.statics else ""
                out.append(f"{amp}{sym.cls}::{sym.name}" if sym.cls else sym.name)
                pos = m.end()
        out.append(body[pos:])
        return "".join(out)
