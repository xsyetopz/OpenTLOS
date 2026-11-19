#!/usr/bin/env python3
"""Merge m2c's per-TU inferred struct fields into one layout vote per class.

Usage: fields.py <m2c out root> <out.json>

m2c infers `unkNN` fields from how each TU accesses `this` and typed pointers.
One TU sees only part of a class, so every TU's guess is a vote:
  {class: {"fields": {offset: {"type": [type, votes], "alt": {other type: votes}, "tus": [voting TUs]}},
           "tu_votes": {asm TU path: fields inferred there}}}
A field's type is the most voted; disagreements stay in "alt" as evidence for
the per-TU fixers. M2C_UNK guesses carry no type and are dropped.

MWCC addresses neighbouring globals from one base register, and m2c then
reads them as fields of the first global's type (the statics after
`MKVector3::zero` become MKVector3 "fields" up to 0x408), and an 8-byte
struct copy reads `MKVector3::one` as two f64s. A field a TU uses as
`<global of that type>.unkNN` is therefore not that TU's vote; the TU's
other `->unkNN` uses may belong to any struct, so they cannot rescue it.
"""

from __future__ import annotations

import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

HEAD = re.compile(r"^typedef struct (\w+) \{$")
GLOBAL = re.compile(r"^(?:extern |static )?(?:const )?(\w+) (\w+)(?: = .*)?;", re.M)
FIELD = re.compile(r"^\s+/\* 0x([0-9A-F]+) \*/ (.+?) ?(\**)unk[0-9A-F]+((?:\[\w+\])*);\s+/\* inferred \*/")


def global_only(text: str, objs, off: int) -> bool:
    """The TU uses field `unk<off>` through a global object of the struct's type."""
    return bool(objs) and any(base in objs for base in re.findall(rf"(\w+)\.unk{off:X}\b", text))


def main() -> int:
    root, out = Path(sys.argv[1]), Path(sys.argv[2])
    votes: dict = defaultdict(lambda: defaultdict(Counter))
    tus: dict = defaultdict(lambda: defaultdict(set))
    for f in sorted(root.rglob("*.c")):
        cls = None
        text = f.read_text()
        objs = defaultdict(set)
        for typ, name in GLOBAL.findall(text):
            objs[typ].add(name)
        for line in text.splitlines():
            m = HEAD.match(line)
            if m:
                cls = m.group(1)
                continue
            if line.startswith("}"):
                cls = None
                continue
            m = FIELD.match(line) if cls else None
            if m and "M2C_UNK" not in m.group(2) and not global_only(text, objs.get(cls), int(m.group(1), 16)):
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
