"""16-byte class copies that m2c splits into two `f64` moves, as one assignment.

MWCC copies an aligned 16-byte class (MKVector3 with its padding, MKVector4)
with two `lfd`/`stfd` pairs. m2c reads that as two double stores:

    sp350 = M2C_BITWISE(f64, sp270);
    sp358 = (f64) sp270.unk8;

`(f64) sp270.unk8` even converts the float at 8 instead of moving its bits.
Both lines are one copy `*(MKVector3 *) &sp350 = sp270;`, which MWCC
compiles to the same two pairs. Only a source whose declared class is 16
bytes is rewritten, and only when the second line reads its offset 8.
"""

from __future__ import annotations

import re

PAIR = re.compile(r"(?m)^(?P<ind>[ \t]+)(?P<dst>[^\n=;]+?) = M2C_BITWISE\(f64, (?P<src>\w+)\);\n"
                  r"(?P=ind)[^\n=;]+? = (?:\(f64\) )?(?P=src)\.unk8;\n")
FIELD = re.compile(r"^M2C_FIELD\((?P<obj>.+), f64 \*, (?P<off>\w+)\)$")


def target(dst: str, typ: str) -> str:
    """`dst`, an `f64` lvalue, as an lvalue of class `typ` at the same address."""
    m = FIELD.match(dst)
    if m:
        return f"M2C_FIELD({m.group('obj')}, {typ} *, {m.group('off')})"
    return f"*({typ} *) &{dst}"


def merge_copies(body: str, sizeof) -> str:
    """`body` with each split copy of a declared 16-byte local joined into one assignment."""
    decls = dict((n, t) for t, n in re.findall(r"(?m)^[ \t]+([A-Za-z_][\w:]*) (\w+);$", body))

    def one(m: re.Match) -> str:
        typ = decls.get(m.group("src"))
        if not typ or sizeof(typ) != 0x10:
            return m.group(0)
        return f"{m.group('ind')}{target(m.group('dst').strip(), typ)} = {m.group('src')};\n"

    return PAIR.sub(one, body)
