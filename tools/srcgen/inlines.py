"""Header inline member definitions recovered from weak copies.

MWCC emits a header inline out of line, as a weak symbol, in every TU that
does not inline it. cxxconv.py moves those copies into `<inline root>/<tu>.inl`;
this module picks one copy per member and groups them by class, so headers.py
can define them after the class like the original header did.
"""

from __future__ import annotations

import re
from collections import defaultdict
from pathlib import Path

MARK = "// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py)."

# `RET Cls::name(params) {` or `Cls::Cls(params) {` at column 0; templates excluded by `[\w:~]`.
DEF = re.compile(r"^(?:[^\s(][^(]*?\s\**)?(?P<cls>[A-Za-z_][\w:]*)::~?[A-Za-z_]\w*\((?P<params>.*)\)(?: const)? \{$")


def definitions(text: str) -> list[tuple[str, str]]:
    """(class, definition) for each non-template member definition in one .inl."""
    out, lines, i = [], text.split("\n"), 0
    while i < len(lines):
        m = DEF.match(lines[i])
        if not m:
            i += 1
            continue
        j = i + 1
        while j < len(lines) and lines[j] != "}":
            j += 1
        out.append((m.group("cls"), "\n".join(lines[i:j + 1])))
        i = j + 1
    return out


def by_class(inl_root: Path) -> dict[str, list[str]]:
    """Class -> its inline member definitions, one per signature, in a stable order."""
    seen, out = set(), defaultdict(list)
    for f in sorted(inl_root.rglob("*.inl")):
        for cls, fn in definitions(f.read_text()):
            sig = fn.split("\n", 1)[0]
            if sig not in seen:
                seen.add(sig)
                out[cls].append(fn)
    return out
