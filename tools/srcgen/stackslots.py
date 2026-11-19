"""Resolve m2c's undeclared `unkspX` stack reads into the local that contains them.

m2c names a stack access `unkspX` when offset X falls inside a local it typed
with a different shape: the `y` of an MKVector3 at sp8 that m2c saw only as
an 8-byte `f64 sp8` reads as `unkspC`. It never declares `unkspX`, so the
draft fails to compile. The access is rewritten as a typed read at the same
address, `(*(f32 *) ((u8 *) &sp8 + 0x4))`, with the type taken from the
instruction that touches X(r1) in dtk's assembly. Offsets with no enclosing
declared local or no typed access stay as they are.
"""

from __future__ import annotations

import re
from pathlib import Path

from asmdata import FN

_ACCESS = re.compile(r"^/\*[^*]*\*/\s*(l[bhwf][az]?|lf[sd]|st[bhw]|stf[sd])\s+[rf]\d+,\s*(0x[0-9a-fA-F]+)\(r1\)")
_TYPE = {"lbz": "u8", "stb": "u8", "lhz": "u16", "lha": "s16", "sth": "u16", "lwz": "s32", "stw": "s32",
         "lfs": "f32", "stfs": "f32", "lfd": "f64", "stfd": "f64"}
_DECL = re.compile(r"^\s+[^;=()]*?\bsp([0-9A-F]+)(?:\[[^\]]*\])?;$", re.M)
_UNK = re.compile(r"\bunksp([0-9A-F]+)\b")


def slot_types(asm: Path) -> dict[str, dict[int, str]]:
    """{function: {r1 offset: C type}} from each function's first typed access per offset.

    Loads win over stores because a store's width may come from a wider value
    the source truncated.
    """
    out: dict[str, dict[int, str]] = {}
    slots: dict[int, str] | None = None
    loads: set[int] = set()
    for line in asm.read_text().splitlines():
        m = FN.match(line)
        if m:
            slots, loads = out.setdefault(m.group(1) or m.group(2), {}), set()
            continue
        a = _ACCESS.match(line) if slots is not None else None
        if not a or a.group(1) not in _TYPE:
            continue
        off, load = int(a.group(2), 16), a.group(1).startswith("l")
        if off not in loads and (load or off not in slots):
            slots[off] = _TYPE[a.group(1)]
        if load:
            loads.add(off)
    return out


def resolve(body: str, slots: dict[int, str]) -> str:
    """`body` with each `unkspX` inside a declared `spY` read through spY's address."""
    locals_ = sorted(int(y, 16) for y in _DECL.findall(body))

    def sub(m: re.Match) -> str:
        x = int(m.group(1), 16)
        base = max((y for y in locals_ if y < x), default=None)
        if base is None or x not in slots:
            return m.group(0)
        return f"(*({slots[x]} *) ((u8 *) &sp{base:X} + {x - base:#x}))"

    return _UNK.sub(sub, body)
