#!/usr/bin/env python3
"""Merge m2c's per-TU inferred struct fields into one layout vote per class.

Usage: fields.py <m2c out root> <out.json> [--base <fields.json> --names <cnames.json>]

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

With `--base`, the root is a run that had the class model as context: m2c
then infers fields only into the context's padding, from the same
instructions, so each such field fills a gap in the base layout. Class and
type names come back from C spelling through `--names`.
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


def collect(root: Path) -> dict:
    """Per-class field votes of one m2c output tree."""
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
    return result


def fill_gaps(base: dict, extra: dict, names: dict) -> int:
    """Add `extra`'s fields at offsets `base` lacks and its TUs' votes elsewhere; returns fields added."""
    def cxx(text: str) -> str:
        return re.sub(r"\b\w+\b", lambda m: names.get(m.group(0), m.group(0)), text)

    added = 0
    for ccls, e in extra.items():
        b = base.setdefault(cxx(ccls), {"fields": {}, "tu_votes": {}})
        for off, f in e["fields"].items():
            new = set(f["tus"])
            if off in b["fields"]:
                # Same offset seen with context: the TU's vote joins, by type.
                old = b["fields"][off]
                new -= set(old["tus"])
                typ, n = cxx(f["type"][0]), len(new)
                if not n:
                    continue
                if typ == old["type"][0]:
                    old["type"][1] += n
                else:
                    old["alt"][typ] = old["alt"].get(typ, 0) + n
                old["tus"] = sorted({*old["tus"], *new})
            else:
                b["fields"][off] = {**f, "type": [cxx(f["type"][0]), f["type"][1]],
                                    "alt": {cxx(t): n for t, n in f["alt"].items()}}
                added += 1
            for tu in new:
                b["tu_votes"][tu] = b["tu_votes"].get(tu, 0) + 1
        b["fields"] = dict(sorted(b["fields"].items(), key=lambda x: int(x[0])))
    return added


def main() -> int:
    root, out = Path(sys.argv[1]), Path(sys.argv[2])
    opts = dict(zip(sys.argv[3::2], sys.argv[4::2]))
    result = collect(root)
    if "--base" in opts:
        base = json.loads(Path(opts["--base"]).read_text())
        names = json.loads(Path(opts["--names"]).read_text())
        print(f"{fill_gaps(base, result, names)} gap fields added")
        result = base
    out.write_text(json.dumps(result, indent=1))
    print(f"{len(result)} structs, {sum(len(v["fields"]) for v in result.values())} fields")
    return 0


if __name__ == "__main__":
    sys.exit(main())
