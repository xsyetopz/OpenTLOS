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

from classes import qualified
from cxxtypes import K, parse, render
from hrender import member_name

# A mangled name may end in `>` (`AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>`).
TOKEN = re.compile(r"(?<![\w@])[A-Za-z_][\w<>,]*[\w>](?=\s*\(|\b)")
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


def int_ptr_arg(arg: str, typ: str) -> str:
    """An address argument cast to an `int *` or `unsigned int *` parameter."""
    bare = re.sub(r"^\((?:s32|u32) \*\) ?", "", arg)
    return f"({typ}) {bare}" if bare.startswith("&") and not bare.startswith("&&") else arg


class Symbol:
    """A parsed mangled name: owning class (or None), C++ member name, param kinds."""

    def __init__(self, mangled: str):
        sym = parse(mangled)
        quals = [str(q) for q in sym.name.qualified_name or []]
        terms = sym.type.terms
        self.is_func = bool(terms) and terms[-1].kind == K.FUNCTION
        self.cls = "::".join(quals[:-1]) or None
        self.raw = quals[-1] if quals else mangled
        if not self.is_func and not self.cls:
            static = qualified(mangled)  # `zero__9MKVector3`: the demangler loses the class
            if static:
                self.cls, self.raw = static[0], static[1]
        fn = terms[-1] if self.is_func else None
        params = [p for p in (fn.function_params or [])] if fn else []
        self.refs = [bool(p.terms) and p.terms[0].kind == K.REFERENCE for p in params]
        # m2c spells `int` as `s32`, which is `long` under MWCC, so `&s32` does not
        # convert to an `int *` parameter; the explicit cast emits no code.
        self.int_ptrs = [render(p) if render(p) in ("int *", "unsigned int *") else None for p in params]
        self.nparams = len([p for p in params if render(p) != "void"])
        if self.raw in OPERATORS:
            self.name = OPERATORS[self.raw]
        elif self.cls:
            self.name = member_name(self.cls, self.raw)[0]
        else:
            self.name = self.raw


class CallRewriter:
    """Rewrites a body given the model's virtual/static knowledge and the enclosing class."""

    def __init__(self, virtuals: set, statics: set, cls: str | None, ancestors: set, sret: dict | None = None):
        self.virtuals, self.statics, self.cls, self.ancestors = virtuals, statics, cls, ancestors
        self.sret = sret or {}  # mangled -> returned class; the first m2c argument is the destination
        self.dests: dict[str, str] = {}  # local -> class a struct-returning call stored into it
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
        if tok in self.sret and args:
            dest = args[0]
            target = dest[1:] if re.fullmatch(r"&[\w.>-]+", dest) else f"*({dest})"
            if re.fullmatch(r"&\w+", dest):
                self.dests[dest[1:]] = self.sret[tok]
            value = self.plain_call(tok, sym, args[1:])
            return value if dest == "NULL" else f"{target} = {value}"
        return self.plain_call(tok, sym, args)

    def plain_call(self, tok: str, sym: Symbol, args: list[str]) -> str:
        member = sym.cls and sym.raw not in OPERATORS and tok not in self.statics
        params = args[1:] if member else args
        params = [ref_arg(a) if i < len(sym.refs) and sym.refs[i] else a for i, a in enumerate(params)]
        params = [int_ptr_arg(a, sym.int_ptrs[i]) if i < len(sym.int_ptrs) and sym.int_ptrs[i] else a
                  for i, a in enumerate(params)]
        tail = f"({', '.join(params)})"
        if not member:
            return (f"{sym.cls}::" if sym.cls and sym.raw not in OPERATORS else "") + sym.name + tail
        obj = CAST.sub("", args[0]) if args else "this"
        qual = f"{sym.cls}::" if tok in self.virtuals else ""
        foreign = sym.cls != self.cls and sym.cls not in self.ancestors
        # `Deinit__Q28GameData9SaveStateFv((GameData__SaveState *) this)` calls a
        # member at offset 0, not a base method; the cast keeps it a member call.
        if obj == "this" and not (foreign and obj != args[0]):
            if not qual and foreign:
                qual = f"{sym.cls}::"
            return f"{qual}{sym.name}{tail}"
        if obj != args[0]:
            # m2c casts a receiver only when its own type for it differs, e.g. an
            # embedded member the field model typed `s32`; keep the cast so the
            # call still resolves.
            return f"({args[0]})->{qual}{sym.name}{tail}"
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


VCALL = re.compile(r"\(\*\((?P<ret>[^()]*?) ?\(\*\*\)\((?P<cls>[\w:<>, ]+?) \*[^;]*?\)\)\(\(s8\*\)\((?P<obj>[^()]*?)->__vptr\) \+ \((?P<off>0x[0-9A-Fa-f]+|\d+)\)\)\)\(")

VFIELD = re.compile(r"M2C_FIELD\((?P<obj>[^()]*?)(?P<acc>->|\.)__vptr, (?P<ret>[^()]*?) ?\(\*\*\)\((?P<cls>[\w:<>, ]+?) \*[^;]*?\), (?P<off>0x[0-9A-Fa-f]+|\d+)\)\(")


THIS_VFIELD = re.compile(r"M2C_FIELD\(this->__vptr, (?P<ret>[^()]*?) ?\(\*\*\)\((?P<params>[^()]*)\), "
                         r"(?P<off>0x[0-9A-Fa-f]+|\d+)\)\(")


def type_this_vcalls(body: str, cls: str, slot_fn=None) -> str:
    """Retype `this`'s vtable calls in a method of `cls` to take `cls *`.

    m2c types the receiver from register use, often as M2C_UNK or a wrong
    pointer, but a call on `this` with `this` as first argument dispatches
    through the enclosing method's class. m2c also drops r3 when it still
    holds `this` from entry (`li r4, 0x2a; lwz r12, 0(r3); ...; bctrl`
    prints as `(0x2A)`). When the slot's function takes as many explicit
    parameters as m2c printed arguments, `this` is the missing first one.
    """
    out, pos = [], 0
    for m in THIS_VFIELD.finditer(body):
        if m.start() < pos:
            continue
        end = close_paren(body, m.end() - 1)
        if end < 0:
            continue
        inner = body[m.end():end]
        args = split_args(inner) if inner.strip() else []
        params = split_args(m.group("params")) if m.group("params").strip() else []
        if args and args[0] == "this":
            params = params[1:]
        else:
            i = (int(m.group("off"), 0) - 8) // 4
            fn = slot_fn(cls, i) if slot_fn and i >= 0 else None
            try:
                want = Symbol(fn).nparams if fn else None
            except Exception:  # noqa: BLE001 - slot holds a non-method
                want = None
            if want is None and (args or params):
                continue  # unknown slot: only the bare `()` call is certain
            if want is not None and len(args) != want:
                continue  # r3 holds another object
            args, params = ["this", *args], params[:len(args)]
        sig = ", ".join([f"{cls} *", *params])
        out += [body[pos:m.start()], f"M2C_FIELD(this->__vptr, {m.group('ret')} (**)({sig}), {m.group('off')})({', '.join(args)})"]
        pos = end + 1
    return "".join(out) + body[pos:]


def devirtualize(body: str, slot_fn) -> str:
    """Turn m2c's vtable-slot calls back into virtual member calls.

    MWCC vtables hold the RTTI pointer and this-offset first, so slot `i`
    sits at 8 + 4*i; `slot_fn(class, i)` names the slot's function. Calls
    whose class or slot is unknown stay as they are.
    """
    out, pos = [], 0
    for m in sorted([*VCALL.finditer(body), *VFIELD.finditer(body)], key=lambda m: m.start()):
        if m.start() < pos:
            continue
        i = (int(m.group("off"), 0) - 8) // 4
        fn = slot_fn(m.group("cls").strip(), i) if i >= 0 else None
        if not fn:
            continue
        end = close_paren(body, m.end() - 1)
        if end < 0:
            continue
        try:
            sym = Symbol(fn)
        except Exception:  # noqa: BLE001 - slot holds a non-method (pure virtual stub)
            continue
        args = split_args(body[m.end():end])[1:]
        args = [ref_arg(a) if k < len(sym.refs) and sym.refs[k] else a for k, a in enumerate(args)]
        obj = m.group("obj")
        call = f"{sym.name}({', '.join(args)})"
        acc = m.groupdict().get("acc") or "->"
        out += [body[pos:m.start()], call if obj == "this" else f"{obj}{acc}{call}"]
        pos = end + 1
    return "".join(out) + body[pos:]
