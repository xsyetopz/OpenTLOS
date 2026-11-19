"""Static member functions, proven from the asm of the method and its callers.

A mangled name does not record `static`, so the class model must prove it.
Only parameterless methods can be told apart: a static method's first
parameter would arrive in r3 just as `this` does. Two tests apply:

- the body never reads r3 before writing it, so it does not use `this`;
- callers leave r3 alone before the `bl`. `MKHeap::Current()` is written
  to r3 before 72 of its 1865 calls (a leftover value the next call
  needs), and `Enemy::WasHit()` before 36 of 37. A method stays static
  when at most `CALLER_SHARE` of its calls set r3.

An empty non-static callback (`StateDeadExit`) passes the first test and
fails the second, which is why both are required.
"""

from __future__ import annotations

import re
from collections import Counter
from pathlib import Path

INSN = re.compile(r"^/\* [0-9A-F]{8} [0-9A-F]{8}  [0-9A-F ]{11} \*/\t(\w+\.?)\s*(.*)$")
# The first operand of these is read, not written.
READS_FIRST = re.compile(r"^(st\w*|cmp\w*|mt\w*|tw\w*|dcb\w*|icbi)$")
CALLER_SHARE = 0.15
LOOKBACK = 12  # instructions searched before a `bl`, within its basic block


def operands(args: str) -> list[str]:
    """Register operands, `0x8(r3)` reduced to its base `r3`."""
    return [re.sub(r"^.*\((r\d+)\)$", r"\1", a.strip()) for a in args.split(",")]


def reads_r3(body: list[str]) -> bool:
    """Whether a function's straight-line asm reads r3 before writing it.

    A call before any write passes r3 on, which counts as a read.
    """
    for line in body:
        m = INSN.match(line)
        if not m:
            continue
        op, regs = m.group(1), operands(m.group(2))
        if op in ("bl", "bctrl", "blrl"):
            return True
        if op == "blr":
            return False
        if "r3" in regs:
            # `lwz r3, 0x10(r3)` reads r3 as its base before writing it.
            return bool(READS_FIRST.match(op)) or "r3" in regs[1:]
    return False


def sets_r3(lines: list[str], at: int) -> bool:
    """Whether the basic block before the `bl` at `lines[at]` writes r3."""
    for j in range(at - 1, max(at - 1 - LOOKBACK, -1), -1):
        m = INSN.match(lines[j])
        if not m or m.group(1).startswith("b"):
            return False
        regs = operands(m.group(2))
        if regs and regs[0] == "r3" and not READS_FIRST.match(m.group(1)):
            return True
    return False


def bodies(asm: Path) -> dict[str, list[str]]:
    """Mangled name -> asm lines of each `.fn` in one file."""
    out, cur = {}, None
    for line in asm.read_text().splitlines():
        if line.startswith(".fn "):
            cur = line[4:].split(",")[0]
            out[cur] = []
        elif line.startswith(".endfn"):
            cur = None
        elif cur:
            out[cur].append(line)
    return out


def static_methods(classes: dict, asm_root: Path) -> set:
    """Mangled methods proven static (see module docstring)."""
    cand, cache = set(), {}
    for c in classes.values():
        for m in c["methods"]:
            if m.get("virtual") or m["name"] in ("__ct", "__dt") or not m.get("tu") or not m["mangled"].endswith("Fv"):
                continue
            tu = m["tu"].rsplit(".", 1)[0]
            if tu not in cache:
                path = asm_root / (tu + ".s")
                cache[tu] = bodies(path) if path.exists() else {}
            body = cache[tu].get(m["mangled"])
            if body is not None and not reads_r3(body):
                cand.add(m["mangled"])
    total, setting = Counter(), Counter()
    for f in sorted(asm_root.rglob("*.s")):
        lines = f.read_text().splitlines()
        for i, line in enumerate(lines):
            m = INSN.match(line)
            if m and m.group(1) == "bl" and m.group(2).strip() in cand:
                name = m.group(2).strip()
                total[name] += 1
                setting[name] += sets_r3(lines, i)
    return {n for n, t in total.items() if setting[n] <= CALLER_SHARE * t}
