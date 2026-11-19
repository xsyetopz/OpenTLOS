#!/usr/bin/env python3
"""Clamp split ranges to DOL section bounds and drop empty ranges.

`dtk elf config` emits split ends that include the ELF's inter-section alignment
padding, which the DOL does not contain, and empty ranges for TUs without data in a
section. `dtk dol split` rejects both.

Usage: clamp_splits.py <dtk binary> <main.dol> <splits.txt>
"""

import re
import subprocess
import sys


def section_bounds(dtk: str, dol: str) -> dict:
    info = subprocess.run([dtk, "dol", "info", dol], capture_output=True, text=True, check=True).stdout
    bounds = {}
    for m in re.finditer(r"^\s*(\S+) \| (0x[0-9A-F]+)\s*\| (0x[0-9A-F]+)\s*\|", info, re.M):
        start, size = int(m.group(2), 16), int(m.group(3), 16)
        bounds.setdefault(m.group(1), (start, start + size))
    return bounds


def main() -> None:
    dtk, dol, path = sys.argv[1:4]
    bounds = section_bounds(dtk, dol)
    out, clamped, dropped = [], 0, 0
    for line in open(path, encoding="utf-8"):
        m = re.match(r"^(\s+)(\S+)(\s+)start:(0x[0-9A-Fa-f]+) end:(0x[0-9A-Fa-f]+)(.*)$", line.rstrip("\n"))
        if m and m.group(2) in bounds:
            start, end = int(m.group(4), 16), int(m.group(5), 16)
            sec_end = bounds[m.group(2)][1]
            if end > sec_end:
                end, clamped = sec_end, clamped + 1
            if end <= start:
                dropped += 1
                continue
            line = f"{m.group(1)}{m.group(2)}{m.group(3)}start:0x{start:08X} end:0x{end:08X}{m.group(6)}\n"
        out.append(line)
    open(path, "w", encoding="utf-8").writelines(out)
    print(f"clamped {clamped}, dropped {dropped}")


if __name__ == "__main__":
    main()
