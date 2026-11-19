"""Render classes, templates, and free declarations of one header as C++ text."""

from __future__ import annotations

import re

from cxxtypes import K, CxxTerm, class_names, parse, render
from hmodel import Model, ctype, split_args, type_names

PURE = "0x00000000"


class Refs:
    """Names a header refers to: `complete` needs a definition, `named` a declaration."""

    def __init__(self):
        self.complete, self.named = set(), set()

    def sig(self, mangled: str) -> None:
        self.named |= class_names(parse(mangled).type)

    def ctype(self, typ: str) -> None:
        base = typ.split("[")[0].strip()
        (self.named if base.endswith("*") or base.endswith("&") else self.complete).update(type_names(base))


def member_name(cls: str, name: str) -> tuple[str, bool]:
    """C++ spelling of a mangled member name and whether it is a ctor/dtor."""
    short = cls.split("::")[-1].split("<", 1)[0]
    if name == "__ct":
        return short, True
    if name == "__dt":
        return "~" + short, True
    if name in CxxTerm.OPS:
        return "operator" + CxxTerm.OPS[name], False
    return name, name in (short, "~" + short)


def method_decl(model: Model, cls: str, m: dict, refs: Refs, ret: str | None = None) -> str:
    sym = parse(m["mangled"])
    terms = sym.type.terms
    const = bool(terms) and terms[0].kind == K.CONST
    t = type(sym.type)(terms=terms[1:] if const else terms)
    name, special = member_name(cls, m["name"])
    ret = "" if special else ret or model.rets.get(m["mangled"], "void")
    refs.sig(m["mangled"])
    refs.named |= type_names(ret)
    decl = render(t, name)
    decl = decl[len("void "):] if decl.startswith("void ") else decl
    head = f"{ret} " if ret else ""
    static = "static " if m.get("static") else ""
    return f"{'virtual ' if m.get('virtual') else static}{head}{decl}{' const' if const else ''};"


def pure_decl(model: Model, cls: str, slot: int, refs: Refs) -> str:
    """Pure virtual named after the first descendant that fills the slot."""
    fn = model.slot_fn(cls, slot)
    for o in model.classes.values():
        for m in o["methods"]:
            if fn and m["mangled"] == fn:
                return method_decl(model, cls, {**m, "virtual": True}, refs, model.slot_ret(cls, slot))[:-1] + " = 0;"
    return f"virtual void pure_slot{slot}() = 0;  // name unknown: no descendant fills this slot"


def class_body(model: Model, name: str, refs: Refs, nested: set) -> list[str]:
    c = model.classes[name]
    base = c.get("base")
    head = f"class {name}" + (f" : public {base}" if base else "")
    note = f"  // base: {c['base_evidence']}" if base and c.get("base_evidence") else ""
    lines = [f"{head} {{{note}", "public:"]
    for n in sorted(nested):
        full = f"{name}::{n}"
        if inlined(model, full):
            inner = class_body(model, full, refs, model.nested.get(full, set()))
            inner[0] = inner[0].replace(f"class {full}", f"class {n}", 1)
            lines += ["    " + l for l in inner]
        else:
            lines.append(f"    class {n};")
    data_at = len(lines)
    if base:
        refs.complete.add(base)
    by_mangled = {m["mangled"]: m for m in c["methods"]}
    base_slots = len(model.classes.get(base, {}).get("vtable") or []) if base else 0
    emitted, texts = set(), set()

    def add(text: str) -> None:
        if text not in texts:
            texts.add(text)
            lines.append("    " + text)

    for m in c["methods"]:
        if m["name"].startswith("@"):  # this-adjusting thunk of a secondary base: compiler-made
            emitted.add(m["mangled"])
    for i, slot in enumerate(c.get("vtable") or []):
        if slot in emitted:
            continue
        if slot in by_mangled:
            add(method_decl(model, name, by_mangled[slot], refs, model.slot_ret(name, i)))
            emitted.add(slot)
        elif slot == PURE and i >= base_slots:
            add(pure_decl(model, name, i, refs))
    for m in c["methods"]:
        if m["mangled"] not in emitted:
            add(method_decl(model, name, m, refs))
    for s in c["statics"]:
        typ = model.static_type(s)
        if typ:
            refs.ctype(typ)
        add(f"static {typ} {s['name']};" if typ else f"static u8 {s['name']}[{s['size']:#x}];")
    fields = sorted((int(o), f) for o, f in model.fields.get(name, {}).get("fields", {}).items())
    pos = model.sizeof(base) if base else 0
    vp = model.vptr_of(name)
    if vp is not None and not model.vptr_of(base) and vp >= pos:
        # This class introduces the vptr; MWCC places it at the first virtual
        # declaration, so data members before it are declared first. A vptr
        # inside the base's extent came from a higher ancestor whose own ctor
        # left no store to record.
        pre = fields_text(model, [x for x in fields if x[0] < vp], pos, vp, refs)
        lines[data_at:data_at] = pre
        pos = vp + 4
    lines += fields_text(model, fields, pos, None, refs)
    a = model.aligned.get(name)
    lines.append(f"}} __attribute__((aligned({a})));" if a else "};")
    return lines


def inlined(model: Model, name: str) -> bool:
    """A nested class defined inside its outer class's body (same header)."""
    outer = name.rsplit("::", 1)[0]
    c, o = model.classes.get(name), model.classes.get(outer)
    return "::" in name and bool(c) and bool(o) and c.get("owner") == o.get("owner")


def fields_text(model: Model, fields: list, pos: int, stop, refs: Refs) -> list[str]:
    """Field lines from `pos`, padded to each offset; ends padded to `stop` if given."""
    lines = []
    for off, f in fields:
        typ = ctype(f["type"][0])
        if off < pos or (stop is not None and off + model.type_size(typ) > stop):
            continue
        arr = "".join(re.findall(r"\[\w+\]", typ))
        base_t = typ.split("[")[0].strip()
        # A template instantiation is judged as a whole: its bare template name
        # is no class, and its arguments may be used only through pointers.
        names = [base_t] if "<" in base_t and base_t in model.classes else type_names(base_t)
        if not base_t.endswith("*") and any(not model.embeddable(n) for n in names):
            continue  # by-value class that cannot be embedded; the padding covers it
        if off > pos:
            lines.append(f"    /* {pos:#05x} */ u8 pad{pos:X}[{off - pos:#x}];")
        refs.ctype(base_t)
        lines.append(f"    /* {off:#05x} */ {base_t.replace(' *', '*')} unk{off:X}{arr};")
        pos = off + model.type_size(typ)
    if stop is not None and stop > pos:
        lines.append(f"    /* {pos:#05x} */ u8 pad{pos:X}[{stop - pos:#x}];")
    return lines


def template_body(model: Model, tname: str, refs: Refs) -> list[str]:
    """One template definition from its instantiations, arguments replaced by T0..Tn.

    The instantiation with class-name arguments and the most methods is the
    pattern; members of other instantiations are merged in after substitution.
    """
    insts = model.templates[tname]["insts"]
    typed = [i for i in insts if all(a[:1].isupper() for a in split_args(i))] or insts
    pattern = max(typed, key=lambda i: (len(model.classes[i]["methods"]), i))
    params = [f"T{i}" for i in range(len(split_args(pattern)))]

    def subst(inst: str, text: str) -> str:
        for arg, p in sorted(zip(split_args(inst), params), key=lambda x: -len(x[0])):
            text = re.sub(rf"(?<![\w:]){re.escape(arg)}(?![\w])", p, text)
        # Inside the template, its own nested types and name need no qualification.
        own = f"{tname}<{', '.join(params)}>"
        return text.replace(own + "::", "").replace(own, tname)

    inner = Refs()
    nested = set()
    for inst in insts:
        for m in model.classes[inst]["methods"]:
            nested |= {x.rsplit("::", 1)[1] for x in class_names(parse(m["mangled"]).type) if x.startswith(inst + "::")}
    body = class_body(model, pattern, inner, nested)
    lines = [subst(pattern, l) for l in body]
    lines[0] = f"template <{', '.join('class ' + p for p in params)}>\n" + lines[0]
    # Instantiations can disagree on a member's return type (m2c typed each
    # copy separately); the first declaration of a signature wins.
    def key(l: str) -> str:
        m = re.search(r"(~?\w+\(.*)$", l)
        return m.group(1) if m else l

    seen = {key(l) for l in lines}
    for inst in insts:
        if inst == pattern or inst not in typed:
            continue
        extra = Refs()
        for l in class_body(model, inst, extra, set())[2:-1]:
            l = subst(inst, l)
            if key(l) not in seen and "/* 0x" not in l:
                seen.add(key(l))
                lines.insert(-1, l)
    args = set(split_args(pattern))
    for n in inner.named | inner.complete:
        if n not in args and not n.startswith(tname + "<"):
            refs.named.add(n)
    return lines


def header_order(model: Model, names: list) -> list:
    """Classes of one header ordered so outers, bases, and by-value fields come first."""
    names = sorted(names, key=lambda n: (n.count("::"), n))
    mine, done, out = set(names), set(), []

    def visit(n, stack=()):
        if n in done or n in stack:
            return
        c = model.classes[n]
        needs = {c.get("base"), n.rsplit("::", 1)[0]}
        for m in c["methods"]:  # nested types in signatures need their outer class defined
            needs |= {x.rsplit("::", 1)[0] for x in class_names(parse(m["mangled"]).type) if "::" in x}
        for f in model.fields.get(n, {}).get("fields", {}).values():
            if not f["type"][0].split("[")[0].strip().endswith("*"):
                needs |= type_names(f["type"][0])
        for d in sorted(x for x in needs if x in mine and x != n):
            visit(d, (*stack, n))
        done.add(n)
        out.append(n)

    for n in names:
        visit(n)
    return out
