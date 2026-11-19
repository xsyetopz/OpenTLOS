#!/usr/bin/env python3
"""Extract ANB's C++ class model from symbol names and vtables.

Usage: classes.py <out.json>

Inputs: config/G6SE7D/{symbols.txt,splits.txt,tu_paths.tsv} and the original DOL.
Every mangled game/engine symbol is parsed with m2c's CodeWarrior demangler.
Per class the output records:
  methods  name, signature, address, TU, and whether a vtable slot holds it
  statics  static data members (`name__<class>`)
  vtable   slot function names in order (RTTI off: `[0, 0, slots...]`)
  base     inferred base class with "base_evidence":
           "ctor/dtor vtable stores": a __ct__ stores the base vtable then its own
             (a __dt__ the reverse), the strongest evidence short of source;
           "vtable prefix": otherwise, the class with the longest vtable whose every
             slot this class shares or overrides by name, and which implements at
             least one shared slot itself (siblings only share their parent's slots).
  vptr     offset where the class's own ctor stores its vtable pointer.
  owner    the TU defining most of the class's methods (header placement).
  size_max upper bound on sizeof from `new(N)` followed by the class's ctor, or
           from the smallest bounded derived class ("size_evidence").
Nothing here is verified against source; it is the evidence base for headers.
"""

from __future__ import annotations

import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(ROOT / "tools/tlos"))
sys.path.insert(0, "/Users/krystian/CodeProjects/xsyetopz/GodHand/tools/ext/m2c")
from dol import Dol  # noqa: E402
from m2c.demangle_codewarrior import CxxTerm, as_stringio, parse  # noqa: E402
from splits import Splits  # noqa: E402
from symbols import load  # noqa: E402

VERSION = "G6SE7D"
OWN = ("game", "engine")
PURE = "0x00000000"


def own_tus() -> set:
    rows = (l.split("\t") for l in (ROOT / "config" / VERSION / "tu_paths.tsv").read_text().splitlines()[1:])
    return {r[1] for r in rows if r[2] in OWN}


def qualified(name: str):
    """(class path, member name, demangled type) or None when not a class member."""
    try:
        sym = parse(name)
    except Exception:  # noqa: BLE001 - the demangler raises bare ValueError/AssertionError on C names
        sym = None
    parts = [str(q) for q in sym.name.qualified_name or []] if sym else []
    if len(parts) < 2:
        # Static data members mangle as `member__<class>` with no type, which the demangler misreads.
        m = re.match(r"^([A-Za-z_]\w*?)__((?:\d+|Q\d)\w+)$", name)
        cls = m and class_name(m.group(2))
        return (cls, m.group(1), "") if cls and not m.group(1).startswith("__") else None
    return "::".join(parts[:-1]), parts[-1], str(sym.type)


def class_name(mangled: str):
    """Demangled class path of a bare mangled class name (`22Foo`, `Q23Bar3Baz`), or None."""
    try:
        with as_stringio(mangled) as buf:
            term = CxxTerm.parse(buf)
            rest = buf.read()
    except Exception:  # noqa: BLE001
        return None
    return str(term) if term.kind == CxxTerm.Kind.QUALIFIED and not rest else None


VT_ADDI = re.compile(r"\taddi (r\d+), r\d+, __vt__(\w+)@l$")
STW = re.compile(r"\tstw (r\d+), (-?0x[0-9a-f]+|\d+)\((r\d+)\)$")


def vtable_store_pairs(asm_root: Path) -> tuple[Counter, dict]:
    """(base vtable, derived vtable) pairs from successive vtable stores to one slot.

    A ctor stores the base vtable into `this`, then its own (a dtor the reverse).
    Slots are keyed by base register and offset, so member objects whose ctors
    are inlined (a UIImage inside MarkerButtonGroup) form their own sequences.
    Also returns each class's vptr offset: where its own ctor stores its vtable.
    MWCC puts the vptr where the first virtual function is declared among the
    data members, so it is not always 0 (MKProp's is 0x44).
    """
    pairs: Counter = Counter()
    vptr: dict = defaultdict(Counter)
    for f in sorted(asm_root.glob("*/**/*.s")):
        cur, regs, slots = None, {}, defaultdict(list)
        for line in f.read_text().splitlines():
            if line.startswith(".fn "):
                cur, regs, slots = line[4:].split(",")[0], {}, defaultdict(list)
            elif line.startswith(".endfn"):
                if cur and cur.startswith(("__ct__", "__dt__")):
                    for vts in slots.values():
                        seq = [v for i, v in enumerate(vts) if i == 0 or vts[i - 1] != v]
                        if cur.startswith("__dt__"):
                            seq.reverse()
                        pairs.update(zip(seq, seq[1:]))
                cur = None
            elif cur:
                m = VT_ADDI.search(line)
                if m:
                    regs[m.group(1)] = m.group(2)
                    continue
                m = STW.search(line)
                if m and m.group(1) in regs:
                    slots[(m.group(3), m.group(2))].append(regs[m.group(1)])
                    if cur.startswith(f"__ct__{regs[m.group(1)]}F"):
                        vptr[regs[m.group(1)]][int(m.group(2), 0)] += 1
    return pairs, {k: v.most_common(1)[0][0] for k, v in vptr.items()}


NEW = re.compile(r"\tli r3, (0x[0-9a-fA-F]+|\d+)$")
CT = re.compile(r"\tbl __ct__(\w+?)F")


def alloc_sizes(asm_root: Path) -> dict:
    """Upper bound of each class's size from `new(size, file, line)` followed by its ctor.

    The bound is the smallest size seen: when a derived ctor is inlined, the call
    left after `new` is the base ctor, and the allocation is the derived size.
    """
    sizes: dict = {}
    for f in sorted(asm_root.glob("*/**/*.s")):
        lines = f.read_text().splitlines()
        for i, line in enumerate(lines):
            if "bl __nw__FUlPCci" not in line:
                continue
            n = next((int(m.group(1), 0) for b in reversed(lines[max(0, i - 8):i]) if (m := NEW.search(b))), None)
            for a in lines[i + 1:i + 14]:
                m = CT.search(a)
                if m:
                    cls = class_name(m.group(1))
                    if n and cls:
                        sizes[cls] = min(n, sizes.get(cls, n))
                    break
                if "\tbl " in a or "\tblr" in a:
                    break
    return sizes


ARRAY_CT = re.compile(r"\taddi r4, r\d+, __ct__(\w+?)F\w*@l$")
ARRAY_SIZE = re.compile(r"\tli r6, (0x[0-9a-fA-F]+|\d+)$")


def array_sizes(asm_root: Path) -> dict:
    """Exact class sizes from `__construct_array(p, ctor, dtor, size, n)` calls.

    The runtime steps through the array by r6, so r6 is sizeof the class
    whose ctor is in r4. Disagreeing sites drop the class.
    """
    sizes: dict = {}
    for f in sorted(asm_root.glob("*/**/*.s")):
        lines = f.read_text().splitlines()
        for i, line in enumerate(lines):
            if not re.search(r"\tbl __construct_(new_)?array$", line):
                continue
            # Arguments are set up after the previous call; scheduling can spread them out.
            start = i
            while start > max(0, i - 40) and not re.search(r"\tbl ", lines[start - 1]):
                start -= 1
            window = lines[start:i]
            cls = next((class_name(m.group(1)) for b in reversed(window) if (m := ARRAY_CT.search(b))), None)
            n = next((int(m.group(1), 0) for b in reversed(window) if (m := ARRAY_SIZE.search(b))), None)
            if cls and n:
                sizes[cls] = n if sizes.get(cls, n) == n else None
    return {k: v for k, v in sizes.items() if v}


def main() -> int:
    out = Path(sys.argv[1])
    syms = load(str(ROOT / "config" / VERSION / "symbols.txt"))
    splits = Splits(str(ROOT / "config" / VERSION / "splits.txt"))
    dol = Dol(str(ROOT / "orig" / VERSION / "sys/main.dol"))
    tus = own_tus()
    by_addr = {s.addr: s.name for s in syms if s.kind == "function"}
    classes: dict = defaultdict(lambda: {"methods": [], "statics": [], "vtable": None})

    for s in syms:
        tu = splits.tu_at(s.section, s.addr)
        if tu not in tus:
            continue
        if s.name.startswith("__vt__"):
            words = dol.words(s.addr, s.size)
            cls = class_name(s.name[6:])
            if cls and words[:2] == (0, 0):
                classes[cls]["vtable"] = [by_addr.get(w, f"0x{w:08X}") for w in words[2:]]
                classes[cls]["vtable_tu"] = tu
            continue
        q = qualified(s.name)
        if not q:
            continue
        cls, member, typ = q
        if s.kind == "function":
            classes[cls]["methods"].append({"name": member, "mangled": s.name, "type": typ,
                                            "addr": f"0x{s.addr:08X}", "size": s.size, "tu": tu,
                                            "weak": "scope:weak" in s.attrs})
        else:
            classes[cls]["statics"].append({"name": member, "mangled": s.name, "size": s.size, "tu": tu})

    owner_of = {}
    for name, c in classes.items():
        # Weak methods are inline copies; the defining TU has the strong ones.
        votes = (Counter(m["tu"] for m in c["methods"] if not m["weak"])
                 or Counter(m["tu"] for m in c["methods"]) or Counter([c.get("vtable_tu")]))
        c["owner"] = votes.most_common(1)[0][0]
        owner_of[name] = c["owner"]
        slots = set(c["vtable"] or [])
        for m in c["methods"]:
            m["virtual"] = m["mangled"] in slots

    def member(slot: str) -> str:
        q = qualified(slot)
        return q[1] + q[2] if q else slot

    stored = {}
    pairs, vptr = vtable_store_pairs(ROOT / "build" / VERSION / "asm")
    for mangled, off in vptr.items():
        cls = class_name(mangled)
        if cls in classes:
            classes[cls]["vptr"] = off
    for (base, derived), _ in pairs.most_common():
        b, d = class_name(base), class_name(derived)
        if b and d and b != d and d not in stored:
            stored[d] = b
    for name, c in classes.items():
        mine = c["vtable"]
        if name in stored:
            c["base"], c["base_evidence"] = stored[name], "ctor/dtor vtable stores"
            continue
        if not mine:
            continue
        best = None
        for other, o in classes.items():
            theirs = o["vtable"]
            if other == name or not theirs or len(theirs) > len(mine):
                continue
            own = (qualified(a) for a, b in zip(theirs, mine) if a == b)
            # A zero slot is a pure virtual (CodeWarrior leaves it null), overridable by anything.
            if all(a == b or a == PURE or member(a) == member(b) for a, b in zip(theirs, mine)) and any(q and q[0] == other for q in own):
                if best is None or len(theirs) > len(classes[best]["vtable"]):
                    best = other
        if best:
            c["base"] = best
            c["base_evidence"] = "vtable prefix"

    for name, n in alloc_sizes(ROOT / "build" / VERSION / "asm").items():
        if name in classes:
            classes[name]["size_max"], classes[name]["size_evidence"] = n, "new+ctor"
    for name, n in array_sizes(ROOT / "build" / VERSION / "asm").items():
        if name in classes:
            classes[name]["size"] = classes[name]["size_max"] = n
            classes[name]["size_evidence"] = "__construct_array element size"
    # A base is never larger than any class derived from it.
    for name in list(classes):
        n, cur = classes[name].get("size_max"), classes[name].get("base")
        seen = {name}
        while n and cur in classes and cur not in seen:
            seen.add(cur)
            if classes[cur].get("size_max", n + 1) > n:
                classes[cur]["size_max"], classes[cur]["size_evidence"] = n, f"derived {name}"
            n, cur = classes[cur]["size_max"], classes[cur].get("base")

    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(dict(sorted(classes.items())), indent=1))
    based = sum(1 for c in classes.values() if c.get("base"))
    print(f"{len(classes)} classes, {sum(1 for c in classes.values() if c['vtable'])} with vtables, {based} with inferred base")
    return 0


if __name__ == "__main__":
    sys.exit(main())
