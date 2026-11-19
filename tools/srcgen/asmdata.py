"""Raw bytes of data objects in dtk's disassembly, for literals m2c could not type."""

from __future__ import annotations

import re
from pathlib import Path

# Quoted names may hold commas (`checked_cast<A,B>__F...`); bare names cannot.
FN = re.compile(r'^\.fn (?:"([^"]+)"|([^\s",]+)), (\w+)$', re.M)
OBJ = re.compile(r'^\.obj "?([^",]+)"?, \w+$')
WIDTH = {".byte": 1, ".2byte": 2, ".4byte": 4}


def objects(asm: Path, prefix: str = "@stringBase") -> dict[str, bytes]:
    """{name: bytes} for each `.obj` whose name starts with `prefix`.

    dtk emits string pools as big-endian `.4byte`/`.2byte`/`.byte` runs with
    `.L_` labels inside; labels and other directives carry no data.
    """
    out, name, buf = {}, None, bytearray()
    for line in asm.read_text().splitlines():
        s = line.strip()
        m = OBJ.match(s)
        if m:
            name, buf = (m.group(1), bytearray()) if m.group(1).startswith(prefix) else (None, None)
            continue
        if name is None:
            continue
        if s.startswith(".endobj"):
            out[name] = bytes(buf)
            name = None
            continue
        op, _, args = s.partition(" ")
        if op in WIDTH:
            for v in args.split(","):
                buf += int(v.strip(), 0).to_bytes(WIDTH[op], "big")
    return out


def bindings(asm: Path) -> dict[str, str]:
    """{function name: `global`/`local`/`weak`} from dtk's `.fn` lines."""
    return {q or bare: bind for q, bare, bind in FN.findall(asm.read_text())}
