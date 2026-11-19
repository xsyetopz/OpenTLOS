"""Make m2c's implicit C conversions explicit where MWCC's C++ rejects them.

m2c writes C, where `T *p = (void *) q;`, `s8 *p = (u8 *) q;` and
`int *p = 0x80001234;` convert implicitly. C++ requires a cast. A cast
between pointers, or between a pointer and a 32-bit integer, emits no code,
and an arithmetic cast is the conversion C would have applied anyway, so the
explicit cast keeps the draft's meaning and its code.

Only whole-statement conversions are rewritten, where MWCC's error line is
`lhs = rhs;`, `T x = rhs;` or `return rhs;`: there the target type in the
message is the type of the whole right-hand side. A conversion inside a call
argument names one argument of several, so it stays an error and is fenced.
"""

from __future__ import annotations

import re
from pathlib import Path

CONV = re.compile(r"^illegal implicit conversion from '(?P<src>[^']+)' to '(?P<dst>[^']+)'$")
ARITH = {"char", "signed char", "unsigned char", "short", "unsigned short", "int", "unsigned int",
         "long", "unsigned long", "long long", "unsigned long long", "float", "double", "bool"}
RETURN = re.compile(r"^(?P<head>\s*return )(?P<rhs>.+);$")


def scalar(typ: str) -> bool:
    """Pointer, array or arithmetic: a type a C-style cast converts without a constructor."""
    t = re.sub(r"^const |^volatile ", "", typ.strip())
    if "::*" in t:
        return False  # member pointers convert only between related classes
    return t.endswith(("*", "]")) or t in ARITH


def mixes_float(a: str, b: str) -> bool:
    """A pointer meeting a float: m2c mistyped one side, and a cast would hide it.

    `temp_f31 = &arg1;` (a float register given an address) compiles under
    MWCC once cast, into code that cannot be the original.
    """
    ptr = lambda t: t.strip().endswith(("*", "]"))  # noqa: E731
    flt = lambda t: re.sub(r"^const ", "", t.strip()) in ("float", "double")  # noqa: E731
    return (ptr(a) and flt(b)) or (flt(a) and ptr(b))


def assignment(line: str) -> tuple[str, str] | None:
    """(head through `= `, rhs) when `line` is one top-level assignment statement."""
    if not line.rstrip().endswith(";"):
        return None
    depth = 0
    for i, ch in enumerate(line):
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        elif ch == '"':
            return None  # strings may hold ` = `; such lines are left alone
        elif depth == 0 and line.startswith(" = ", i) and line[i - 1:i] not in ("=", "!", "<", ">"):
            return line[:i + 3], line[i + 3:].rstrip()[:-1]
    return None


def cast_line(line: str, dst: str) -> str | None:
    """`line` with its whole right-hand side cast to `dst`, or None if not applicable."""
    m = RETURN.match(line.rstrip())
    head, rhs = (m.group("head"), m.group("rhs")) if m else (assignment(line) or (None, None))
    if head is None or rhs.startswith(f"({dst}) "):
        return None  # already cast once: the error lies elsewhere in the statement
    return f"{head}({dst}) ({rhs});"


def fix_casts(src: Path, errs: list[tuple[str, int, str]], after: str | None = None) -> int:
    """Rewrite each fixable conversion error of `src`; returns lines changed.

    With `after`, only lines below the line equal to it are touched (a
    header's inline section).
    """
    lines = src.read_text().split("\n")
    floor = lines.index(after) if after in lines else -1
    done = 0
    for f, n, msg in errs:
        m = CONV.match(msg)
        if f != src.name or not m or n - 1 <= floor or n > len(lines):
            continue
        if not (scalar(m.group("src")) and scalar(m.group("dst"))) or mixes_float(m.group("src"), m.group("dst")):
            continue
        new = cast_line(lines[n - 1], m.group("dst"))
        if new:
            lines[n - 1], done = new, done + 1
    if done:
        src.write_text("\n".join(lines))
    return done
