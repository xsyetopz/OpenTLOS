"""Static member functions, proven from the asm of the method and its callers.

A mangled name does not record `static`, so the class model must prove it.
`this` shifts the integer parameters up one register, so with G integer or
pointer parameters the register r(3+G) holds the last one in a member and
nothing in a static method (`Texture::Find(const char *)` takes its name in
r3 and leaves r4 alone). Two tests apply to that register:

- the body never reads it before writing it;
- callers leave it alone before the `bl`. `MKHeap::Current()` is written
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

from cxxtypes import parse, render

INSN = re.compile(r"^/\* [0-9A-F]{8} [0-9A-F]{8}  [0-9A-F ]{11} \*/\t(\w+\.?)\s*(.*)$")
# The first operand of these is read, not written.
READS_FIRST = re.compile(r"^(st\w*|cmp\w*|mt\w*|tw\w*|dcb\w*|icbi)$")
CALLER_SHARE = 0.15
LOOKBACK = 12  # instructions searched before a `bl`, within its basic block


def operands(args: str) -> list[str]:
    """Register operands, `0x8(r3)` reduced to its base `r3`."""
    return [re.sub(r"^.*\((r\d+)\)$", r"\1", a.strip()) for a in args.split(",")]


def reads_r3(body: list[str], reg: str = "r3") -> bool:
    """Whether a function's straight-line asm reads `reg` before writing it.

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
        if reg in regs:
            # `lwz r3, 0x10(r3)` reads r3 as its base before writing it.
            return bool(READS_FIRST.match(op)) or reg in regs[1:]
    return False


def sets_r3(lines: list[str], at: int, reg: str = "r3") -> bool:
    """Whether the basic block before the `bl` at `lines[at]` writes `reg`."""
    for j in range(at - 1, max(at - 1 - LOOKBACK, -1), -1):
        m = INSN.match(lines[j])
        if not m or m.group(1).startswith("b"):
            return False
        regs = operands(m.group(2))
        if regs and regs[0] == reg and not READS_FIRST.match(m.group(1)):
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


def spare_reg(mangled: str) -> str | None:
    """r(3+G) for a method with G integer or pointer parameters; None past r10 or if unparsable."""
    try:
        fn = parse(mangled).type.terms[-1]
    except Exception:  # noqa: BLE001 - the demangler raises bare errors
        return None
    params = [render(p) for p in fn.function_params or []]
    if "..." in params:
        return None
    gprs = sum(p not in ("void", "float", "double") for p in params)
    return f"r{3 + gprs}" if gprs < 8 else None


def static_methods(classes: dict, asm_root: Path) -> set:
    """Mangled methods proven static (see module docstring)."""
    cand, cache = {}, {}
    for c in classes.values():
        for m in c["methods"]:
            if m.get("virtual") or m["name"] in ("__ct", "__dt") or not m.get("tu"):
                continue
            reg = spare_reg(m["mangled"])
            if not reg:
                continue
            tu = m["tu"].rsplit(".", 1)[0]
            if tu not in cache:
                path = asm_root / (tu + ".s")
                cache[tu] = bodies(path) if path.exists() else {}
            body = cache[tu].get(m["mangled"])
            if body is not None and not reads_r3(body, reg):
                cand[m["mangled"]] = reg
    total, setting = Counter(), Counter()
    for f in sorted(asm_root.rglob("*.s")):
        lines = f.read_text().splitlines()
        for i, line in enumerate(lines):
            m = INSN.match(line)
            if m and m.group(1) == "bl" and m.group(2).strip() in cand:
                name = m.group(2).strip()
                total[name] += 1
                setting[name] += sets_r3(lines, i, cand[name])
    return {n for n, t in total.items() if setting[n] <= CALLER_SHARE * t}
