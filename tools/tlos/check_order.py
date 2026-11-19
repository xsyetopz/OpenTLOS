#!/usr/bin/env python3
"""Report split ranges whose address order contradicts translation-unit order.

Usage: check_order.py <splits.txt>
"""
import re
import sys
from collections import defaultdict

order, per_sec, tu = {}, defaultdict(list), None
for line in open(sys.argv[1], encoding="utf-8"):
    m = re.match(r"^(\S.*):$", line.rstrip())
    if m and m.group(1) != "Sections":
        tu = m.group(1); order[tu] = len(order); continue
    m = re.match(r"^\s+(\S+)\s+start:(0x\w+) end:(0x\w+)", line)
    if m and tu:
        per_sec[m.group(1)].append((int(m.group(2), 16), order[tu], tu))
bad = 0
for sec, rows in per_sec.items():
    rows.sort()
    for a, b in zip(rows, rows[1:]):
        if b[1] < a[1]:
            bad += 1
            print(f"{sec}: {a[2]} @0x{a[0]:08X} precedes {b[2]} @0x{b[0]:08X}")
print(f"{bad} inversions")
