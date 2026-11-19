"""Parse and query decomp-toolkit symbols.txt files."""

import re
from dataclasses import dataclass

LINE = re.compile(r"^(\S+) = \.?([\w$.]+):0x([0-9A-Fa-f]+); // ?(.*)$")


@dataclass
class Symbol:
    """One symbols.txt entry."""

    name: str
    section: str
    addr: int
    size: int
    kind: str
    attrs: str


def load(path: str) -> list:
    """Returns all symbols in file order."""
    out = []
    for line in open(path, encoding="utf-8"):
        m = LINE.match(line.rstrip("\n"))
        if not m:
            continue
        attrs = m.group(4)
        size = re.search(r"size:0x([0-9A-Fa-f]+)", attrs)
        kind = re.search(r"type:(\w+)", attrs)
        out.append(Symbol(
            m.group(1), m.group(2).lstrip("."), int(m.group(3), 16),
            int(size.group(1), 16) if size else 0, kind.group(1) if kind else "", attrs,
        ))
    return out


def functions(syms: list) -> list:
    """Returns sized function symbols sorted by address."""
    return sorted((s for s in syms if s.kind == "function" and s.size), key=lambda s: s.addr)


def is_auto_name(name: str) -> bool:
    """True for names dtk generates for unnamed symbols."""
    return bool(re.match(r"^(fn|lbl|jumptable|gap|@stringBase)_?[0-9A-F]+(_\w+)?$", name)) or name.startswith("@")
