#!/usr/bin/env python3
"""Infer alignment of common BSS symbols from gaps in the original layout.

The linker lays out common symbols back to back, padding each one to its
alignment. The split objects carry the default alignment (4), so any gap before
a symbol means its real alignment is larger. This script assigns the smallest
power of two that reproduces the original address and records it as `align:N`
in symbols.txt. Gaps that no alignment of 64 or less explains are reported
instead of guessed.

Usage: infer_common_align.py <symbols.txt> <common_start hex> <section end hex>
"""

import re
import sys

SYM = re.compile(r"^(\S+) = \.bss:0x([0-9A-F]+); // (.*)$")


def align_up(value: int, align: int) -> int:
    return (value + align - 1) & ~(align - 1)


def main() -> None:
    path, start, end = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16)
    lines = open(path, encoding="utf-8").read().split("\n")
    entries = []
    for i, line in enumerate(lines):
        m = SYM.match(line)
        if not m or "type:label" in line:
            continue
        addr = int(m.group(2), 16)
        size = re.search(r"size:0x([0-9A-F]+)", line)
        if start <= addr < end and size:
            entries.append((addr, int(size.group(1), 16), i))
    entries.sort()
    changed, unexplained = 0, []
    prev_end = start
    for addr, size, i in entries:
        if addr > prev_end:
            align = next((a for a in (8, 16, 32, 64) if align_up(prev_end, a) == addr), None)
            if align is None:
                unexplained.append(f"0x{addr:08X} gap 0x{addr - prev_end:X}")
            else:
                line = re.sub(r" align:\d+", "", lines[i])
                lines[i] = re.sub(r"(scope:\w+)", rf"\1 align:{align}", line, count=1)
                changed += 1
        prev_end = max(prev_end, addr + size)
    open(path, "w", encoding="utf-8").write("\n".join(lines))
    print(f"{changed} alignments set; {len(unexplained)} unexplained gaps")
    for gap in unexplained:
        print("  " + gap)


if __name__ == "__main__":
    main()
