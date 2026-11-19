#!/usr/bin/env python3
"""Merge m2c's per-TU inferred struct fields into one layout vote per class.

Usage: fields.py <m2c out root> <out.json>

m2c infers `unkNN` fields from how each TU accesses `this` and typed pointers.
One TU sees only part of a class, so every TU's guess is a vote:
  {class: {"fields": {offset: {"type": [type, votes], "alt": {other type: votes}, "tus": [voting TUs]}},
           "tu_votes": {asm TU path: fields inferred there}}}
A field's type is the most voted; disagreements stay in "alt" as evidence for
the per-TU fixers. M2C_UNK guesses carry no type and are dropped.
"""

from __future__ import annotations

import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

HEAD = re.compile(r"^typedef struct (\w+) \{$")
FIELD = re.compile(r"^\s+/\* 0x([0-9A-F]+) \*/ (.+?) ?(\**)unk[0-9A-F]+((?:\[\w+\])*);\s+/\* inferred \*/")


def main() -> int:
    root, out = Path(sys.argv[1]), Path(sys.argv[2])
    votes: dict = defaultdict(lambda: defaultdict(Counter))
    tus: dict = defaultdict(lambda: defaultdict(set))
    for f in sorted(root.rglob("*.c")):
        cls = None
        for line in f.read_text().splitlines():
            m = HEAD.match(line)
            if m:
                cls = m.group(1)
                continue
            if line.startswith("}"):
                cls = None
                continue
            m = FIELD.match(line) if cls else None
            if m and "M2C_UNK" not in m.group(2):
                typ = (m.group(2) + " " + m.group(3)).strip() + m.group(4)
                off = int(m.group(1), 16)
                votes[cls][off][typ] += 1
                tus[cls][off].add(f.relative_to(root).with_suffix("").as_posix())
    result = {}
    for cls, offs in sorted(votes.items()):
        fields, tu_votes = {}, Counter()
        for off, c in sorted(offs.items()):
            (typ, n), *rest = c.most_common()
            fields[str(off)] = {"type": [typ, n], "alt": dict(rest), "tus": sorted(tus[cls][off])}
            tu_votes.update(tus[cls][off])
        result[cls] = {"fields": fields, "tu_votes": dict(tu_votes.most_common())}
    out.write_text(json.dumps(result, indent=1))
    print(f"{len(result)} structs, {sum(len(v["fields"]) for v in result.values())} fields")
    return 0


if __name__ == "__main__":
    sys.exit(main())
