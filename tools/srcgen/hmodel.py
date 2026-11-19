"""Class model for header generation: types, field layouts, and header placement.

Inputs are classes.py's class model, fields.py's m2c field votes, and m2c's
per-TU output for return and global types (CodeWarrior manglings carry no
return types). Everything here is inference; headers.py marks it as such.
"""

from __future__ import annotations

import json
import re
from collections import Counter, defaultdict
from pathlib import Path

SIZES = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4, "f64": 8, "s64": 8, "u64": 8}
DEF = re.compile(r"^(?:static )?([\w ]+?[\s*]+)(\w+__\w*)\(.*\) \{$")
DECL = re.compile(r"^(?:extern |static )?([\w ]+?[\s*]+)([A-Za-z_]\w*)(?:\[[^\]]*\])?;")
SDK_TYPE = re.compile(r"^\}\s*(\w+)\s*;|^typedef [^{;]*?(\w+)\s*;", re.M)
KEYWORDS = {"return", "goto", "case", "else", "do"}
ROOT = Path(__file__).resolve().parent.parent.parent
VERSION = "G6SE7D"
TMPL_ARGS = re.compile(r"<(.*)>$")


def m2c_types(root: Path) -> tuple[dict, dict]:
    """Most-voted m2c return type per mangled function and type per global."""
    rets, globs = defaultdict(Counter), defaultdict(Counter)
    for f in root.rglob("*.c"):
        for line in f.read_text().splitlines():
            m = DEF.match(line)
            if m:
                rets[m.group(2)][m.group(1).strip()] += 1
                continue
            m = DECL.match(line)
            if m and "(" not in line and "M2C_UNK" not in m.group(1) and (m.group(1).split() or [""])[0] not in KEYWORDS:
                globs[m.group(2)][m.group(1).strip()] += 1
    clean = lambda t: "void" if "M2C_UNK" in t else ctype(t)  # noqa: E731
    return ({k: clean(v.most_common(1)[0][0]) for k, v in rets.items()},
            {k: ctype(v.most_common(1)[0][0]) for k, v in globs.items()})


def align(typ: str) -> int | None:
    """Natural alignment of a primitive or pointer type, else None (unknown)."""
    base = typ.split("[")[0].strip()
    return 4 if base.endswith("*") else SIZES.get(base)


def realign(off: int, v: dict) -> None:
    """Replace a field type that cannot sit at `off` under natural alignment.

    MWCC aligns every member naturally, so `s32` at Trap+0xD9 is m2c typing
    the `&this->unkD9` it passed to a call; the asm stores a byte there, and
    the s32 pushed every later Trap member 4 bytes off in all subclasses.
    The best-voted alternative that fits wins, else the widest unsigned
    type the offset allows.
    """
    a = align(v["type"][0])
    if not a or off % a == 0:
        return
    fits = [(n, t) for t, n in v["alt"].items() if (align(t) or 0) and off % align(t) == 0]
    if fits:
        n, t = max(fits)
        v["type"] = [t, n]
    else:
        v["type"] = ["u8" if off % 2 else "u16", v["type"][1]]


def ctype(typ: str) -> str:
    """m2c type with names C++ cannot spell (vtable structs, mangled templates) as void."""
    base = typ.split("[")[0]
    if "__" in base or re.search(r"<\d", base) or base.startswith("struct "):
        stars = base.count("*")
        return ("void " + "*" * stars).strip() + typ[len(base):] if stars else "u8" + typ[len(base):]
    return typ


def sdk_types(ctx: Path) -> set:
    """Type names the preprocessed SDK context defines (GXRenderModeObj, OSThread)."""
    return {a or b for a, b in SDK_TYPE.findall(ctx.read_text())}


def type_names(typ: str) -> set:
    """Class-like names a C type string mentions (uppercase-initial identifiers)."""
    return set(re.findall(r"\b[A-Z]\w*(?:::\w+)*", typ)) - {"M2C_UNK"}


def split_args(name: str) -> list:
    """Top-level template arguments of `Name<A, B<C>>`."""
    m = TMPL_ARGS.search(name)
    if not m:
        return []
    out, depth, cur = [], 0, ""
    for ch in m.group(1):
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
            continue
        depth += (ch == "<") - (ch == ">")
        cur += ch
    return [*out, cur.strip()]


def header_key(name: str) -> str:
    """The name whose header must be included to use `name` completely."""
    if "<" in name:
        return name.split("<", 1)[0]
    return name.split("::", 1)[0]


class Model:
    """Classes with owners (header TUs), sizes, filtered fields, and templates."""

    def __init__(self, classes: dict, fields: dict, rets: dict, globs: dict, stems: dict):
        self.classes, self.fields, self.rets, self.globs = classes, fields, rets, globs
        self.stems = stems  # TU path without extension -> TU path
        self.size_cache: dict = {}
        self.sdk: set = set()  # SDK type names, set by the caller when known
        self.nested: dict = {}  # outer class -> inner names, set by the caller
        for name, f in fields.items():  # structs m2c saw that have no methods
            if name not in classes and "<" not in name:
                classes[name] = {"methods": [], "statics": [], "vtable": None, "owner": None}
        self.place_owners()
        self.templates = self.place_templates()
        self.filter_fields()

    def owner_map(self) -> dict:
        """Class or template name -> TU path whose header defines it."""
        out = {n: c["owner"] for n, c in self.classes.items() if "<" not in n and c.get("owner")}
        out |= {t: v["owner"] for t, v in self.templates.items()}
        return out

    def tu_path(self, stem: str):
        return self.stems.get(stem)

    def ancestors(self, name: str) -> list:
        out, cur = [], self.classes.get(name, {}).get("base")
        while cur in self.classes and cur not in out and cur != name:
            out.append(cur)
            cur = self.classes[cur].get("base")
        return out

    def all_bases(self, name: str) -> set:
        """Primary ancestors plus secondary bases (and their ancestors) along the chain."""
        out = set()
        for n in [name, *self.ancestors(name)]:
            for sec in self.classes.get(n, {}).get("secondary", {}):
                out |= {sec, *self.ancestors(sec)}
        return out | set(self.ancestors(name))

    def derives(self, name: str, base: str) -> bool:
        return base in self.ancestors(name)

    def votes(self, name: str) -> Counter:
        """TUs that touch the class: its methods plus m2c field inference."""
        c = Counter(self.fields.get(name, {}).get("tu_votes", {}))
        c.update(m["tu"].rsplit(".", 1)[0] for m in self.classes[name]["methods"])
        return c

    def place_owners(self) -> None:
        """Choose each class's header TU.

        The method vote (classes.py) fails for header-only classes: inline
        methods are emitted out of line wherever the optimizer declines to
        inline them, so MKVector3 gets "owned" by whichever game TU kept a copy.
        Overrides, strongest first:
          * a TU named after the class owns it (common/Source/MKVector3.cpp);
          * a class with only inline (weak) methods gets its own header;
          * a nested class lives in its outer class's header;
          * a class that engine (common/) TUs use lives in an engine header,
            because the engine is shared by both games and cannot include game headers.
        """
        by_base = {Path(tu).stem: tu for tu in self.stems.values()}
        for name, c in self.classes.items():
            if "<" in name:
                continue
            if "::" not in name and name in by_base:
                c["owner"] = by_base[name]
                continue
            votes = self.votes(name)
            if "::" not in name and c["methods"] and all(m.get("weak") for m in c["methods"]):
                # Header-only class (every method inline): no TU defines it, so it
                # gets a header named after it, in the engine when the engine uses it.
                top = next((t for t, _ in votes.most_common() if t.startswith("common/")), None) or votes.most_common(1)[0][0]
                c["owner"] = f"{top.rsplit('/', 1)[0]}/{name}.h"
                continue
            engine = [t for t, _ in votes.most_common() if t.startswith("common/") and self.tu_path(t)]
            if engine and not (c.get("owner") or "").startswith("common/"):
                c["owner"] = self.tu_path(engine[0])
            elif not c.get("owner"):
                c["owner"] = next((self.tu_path(t) for t, _ in votes.most_common() if self.tu_path(t)), None)
        for name, c in self.classes.items():
            outer = name.split("::", 1)[0]
            if "::" in name and "<" not in name and outer in self.classes and "<" not in outer:
                c["owner"] = self.classes[outer]["owner"]

    def place_templates(self) -> dict:
        """Template name -> {"insts": [...], "owner": pseudo TU of its header}.

        Templates have no TU of their own; their header is named after the
        template (`Goal.h`) beside the TUs that use it, in the engine when an
        engine TU instantiates it. A same-named TU, when present, wins.
        """
        out: dict = {}
        by_base = {Path(tu).stem: tu for tu in self.stems.values()}
        for name in self.classes:
            if "<" in name:
                out.setdefault(name.split("<", 1)[0], {"insts": []})["insts"].append(name)
        for tname, t in out.items():
            votes = Counter()
            for inst in t["insts"]:
                votes.update(self.votes(inst))
            engine = any(v.startswith("common/") for v in votes)
            top = next((v for v, _ in votes.most_common() if v.startswith("common/") or not engine), "spyro/source/x")
            t["owner"] = by_base.get(tname) or f"{top.rsplit('/', 1)[0]}/{tname}.h"
        return out

    def filter_fields(self) -> None:
        """Drop m2c fields that belong to derived classes.

        m2c attributes an access through a base pointer to the base type, so
        `MKProp` collects SteamTrain's 0xD10 field. A field goes when it lies
        past the class's allocation bound, or when only TUs owning strict
        descendants (and not the class itself) voted for it.

        m2c also unifies unrelated pointers with a class type, so one stray
        TU can add `MKVector3::unk394`. A field voted by a single TU that owns
        neither the class nor a descendant is dropped as such noise; the
        padding still covers its bytes.

        A base class without a proven size ends where its own TU's accesses
        end: m2c types an Enemy as the `Targetable *` a getter returns, so
        EnemyGoal TUs gave the Targetable mixin fields out to 0xB08, and every
        class embedding a CollisionObject (a Targetable) swallowed its
        derived classes' members.
        """
        owners = defaultdict(set)
        for name, c in self.classes.items():
            if c.get("owner"):
                for a in self.all_bases(name):
                    owners[a].add(c["owner"].rsplit(".", 1)[0])
        for name, f in self.fields.items():
            c = self.classes.get(name, {})
            limit = c.get("size_max")
            mine = (c.get("owner") or "").rsplit(".", 1)[0]
            desc = owners[name] - {mine}
            if not c.get("size") and desc:  # size_max is only an allocation upper bound
                own = [int(o) for o, v in f["fields"].items() if mine in v["tus"]]
                f["fields"] = {o: v for o, v in f["fields"].items() if mine in v["tus"] or int(o) <= max(own, default=0)}
            f["fields"] = {o: v for o, v in f["fields"].items()
                           if (limit is None or int(o) < limit) and not (desc and set(v["tus"]) <= desc)
                           and not (len(v["tus"]) == 1 and v["tus"][0] not in owners[name] | {mine})}

    def apply_sizes(self, sizes: dict) -> None:
        """Exact sizes proven from the asm (config class_sizes.tsv) cap each class.

        m2c unifies unrelated pointers with a value type, so `MKVector3`
        collects votes up to 0xB8 although `Max(const MKVector3&, ...)` copies
        exactly 0x10 bytes. Fields past a proven size go. MWCC also copies
        small structs with lfd/stfd pairs, so an f64 vote that competes with
        f32 at the same offset is such a copy and becomes f32. Misaligned
        votes are narrowed by `realign`.
        """
        for f in self.fields.values():
            for off, v in f["fields"].items():
                if v["type"][0] == "f64" and "f32" in v["alt"]:
                    v["type"] = ["f32", v["alt"]["f32"]]
                realign(int(off), v)
        for name, size in sizes.items():
            c = self.classes.get(name)
            if not c:
                continue
            c["size"] = c["size_max"] = size
            f = self.fields.get(name)
            if f:
                f["fields"] = {o: v for o, v in f["fields"].items() if int(o) + self.type_size(v["type"][0]) <= size}
        self.size_cache.clear()

    def vptr_of(self, name):
        """vptr offset of a polymorphic class: its own ctor's, else its nearest
        bounded relative's (the offset is inherited unchanged), else 0."""
        c = self.classes.get(name)
        if not c or not c.get("vtable") and not any(self.classes.get(a, {}).get("vtable") for a in self.ancestors(name)):
            return None
        for n in [name, *self.ancestors(name)]:
            if "vptr" in self.classes.get(n, {}):
                return self.classes[n]["vptr"]
        return self.desc_vptr().get(name, 0)

    def desc_vptr(self) -> dict:
        if not hasattr(self, "_desc_vptr"):
            self._desc_vptr = {}
            for n, c in self.classes.items():
                if "vptr" in c:
                    for a in self.ancestors(n):
                        self._desc_vptr.setdefault(a, c["vptr"])
        return self._desc_vptr

    def slot_ret(self, cls: str, slot: int) -> str | None:
        """One return type for a vtable slot across the hierarchy that shares it.

        m2c types each override from its own body, so overrides disagree
        (AnimProperty* vs KDScriptProperty*), which C++ rejects. Agreement wins;
        disagreeing pointers become `void *`; otherwise the most common type.
        """
        if not hasattr(self, "_slot_rets"):
            groups = defaultdict(Counter)
            for n, c in self.classes.items():
                for i, fn in enumerate(c.get("vtable") or []):
                    if fn != "0x00000000" and not fn.startswith("__dt__"):
                        groups[(self.slot_root(n, i), i)][self.rets.get(fn, "void")] += 1
            self._slot_rets = {}
            for k, votes in groups.items():
                if len(votes) == 1:
                    self._slot_rets[k] = next(iter(votes))
                elif all(t.endswith("*") for t in votes):
                    self._slot_rets[k] = "void *"
                else:
                    self._slot_rets[k] = votes.most_common(1)[0][0]
        return self._slot_rets.get((self.slot_root(cls, slot), slot))

    def static_type(self, s: dict) -> str | None:
        """Declared type of class static `s`, or None for `u8 name[size]`.

        m2c types a static it cannot place as its owning class by value, so a
        class type stays only if it fits the symbol's size.
        """
        typ = self.globs.get(s["mangled"])
        if typ in self.classes and (not self.embeddable(typ) or self.end(typ) > s["size"]):
            return None
        return typ

    def decl_rets(self) -> dict[str, str]:
        """Mangled virtual -> the return type its class declaration carries (slot_ret).

        Definitions must repeat it: m2c's per-function guess disagrees with the
        slot's shared type for 160 virtuals, a redeclaration error in C++.
        """
        if not hasattr(self, "_decl_rets"):
            self._decl_rets = {}
            for n, c in self.classes.items():
                own = {m["mangled"] for m in c["methods"]}
                for i, fn in enumerate(c.get("vtable") or []):
                    ret = self.slot_ret(n, i) if fn in own else None
                    if ret:
                        self._decl_rets.setdefault(fn, ret)
        return self._decl_rets

    def slot_fn(self, cls: str, slot: int) -> str | None:
        """Mangled function that names vtable `slot` of `cls`, or None.

        A pure slot (CodeWarrior leaves it null) takes the name of the first
        descendant that fills it, the same name its declaration gets.
        """
        vt = self.classes.get(cls, {}).get("vtable") or []
        if slot >= len(vt):
            return None
        if vt[slot] != "0x00000000":
            return vt[slot]
        for other, o in self.classes.items():
            ovt = o.get("vtable") or []
            if slot < len(ovt) and ovt[slot] != "0x00000000" and self.derives(other, cls):
                return ovt[slot]
        return None

    def slot_root(self, cls: str, slot: int) -> str:
        """Topmost ancestor (or the class itself) whose vtable has the slot."""
        root = cls
        for a in self.ancestors(cls):
            if len(self.classes[a].get("vtable") or []) > slot:
                root = a
        return root

    def embeddable(self, name: str) -> bool:
        """Whether a field may hold `name` by value: a known, non-abstract type.

        m2c guesses by-value fields from access patterns; an abstract class
        (null vtable slot) or an undefined one is a misguess there.
        """
        if name in self.sdk:
            return True
        c = self.classes.get(name)
        return bool(c) and "0x00000000" not in (c.get("vtable") or [])

    def end(self, name: str, seen=()) -> int:
        """Offset just past the class's last known field, bases included."""
        if name in self.size_cache:
            return self.size_cache[name]
        if name in seen:
            return 0
        c = self.classes.get(name, {})
        vp = self.vptr_of(name)
        best = self.end(c["base"], (*seen, name)) if c.get("base") else 0
        best = max(best, c.get("size") or 0)
        if vp is not None:
            best = max(best, vp + 4)
        for off, f in self.fields.get(name, {}).get("fields", {}).items():
            best = max(best, int(off) + self.type_size(f["type"][0], (*seen, name)))
        self.size_cache[name] = best
        return best

    def type_size(self, typ: str, seen=()) -> int:
        arr = 1
        for n in re.findall(r"\[(\d+)\]", typ):
            arr *= int(n)
        base = typ.split("[")[0].strip()
        if base.endswith("*"):
            return 4 * arr
        if base in SIZES:
            return SIZES[base] * arr
        return max(self.end(base, seen), 1) * arr


def load_model(classes: Path, fields: Path, m2c_root: Path, ctx: Path) -> Model:
    """Model of ANB's game and engine classes from the srcgen artifacts."""
    rows = [l.split("\t") for l in (ROOT / "config" / VERSION / "tu_paths.tsv").read_text().splitlines()[1:]]
    stems = {r[1].rsplit(".", 1)[0]: r[1] for r in rows if r[2] in ("game", "engine")}
    rets, globs = m2c_types(m2c_root)
    model = Model(json.loads(classes.read_text()), json.loads(fields.read_text()), rets, globs, stems)
    model.sdk, model.ctx = sdk_types(ctx), ctx
    proven = {n: c["size"] for n, c in model.classes.items() if c.get("size")}  # classes.py array probe
    sizes = ROOT / "config" / VERSION / "class_sizes.tsv"
    if sizes.exists():
        proven |= {r[0]: int(r[1], 0) for r in (l.split("\t") for l in sizes.read_text().splitlines()[1:]) if r[0]}
    model.apply_sizes(proven)
    return model
