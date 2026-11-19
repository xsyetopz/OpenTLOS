"""Rewrite dtk assembly into the form m2c's PowerPC front end expects.

m2c recognises a `bctr` jump table only when the table symbol's name starts with
"jtbl"/"jpt_"/"lbl_"/"jumptable_". spyro06.elf keeps MWCC's local names for
those tables ("@1187"), so each local object whose body is `.rel` entries is
renamed to `jumptable_<n>` throughout its file.

MWCC gives a function with 16- or 32-byte-aligned locals a realigning frame:

    clrlwi r11, r1, 28 / mr r12, r1 / subfic r11, r11, -S / stwux r1, r1, r11
    ... saves at X(r12) ...      lwz r10, 0(r1) ... restores at X(r10) ... mr r1, r10

m2c knows only `stwu r1, -S(r1)` frames, so it takes every local slot of these
497 game/engine functions for an incoming `arg_spN` parameter. Assuming an
already aligned r1 (padding 0), the frame is the plain S-byte one, so it is
rewritten to `stwu`/`addi` with r12/r10-relative offsets moved to r1 + S.
Only m2c's input changes; addresses stay in the comments, the build's asm
is untouched.
"""

import re

_OBJ = re.compile(r'^\.obj ("@\d+"), local$')
_INS = re.compile(r"^(/\*[^*]*\*/\s*)(\S+)\s*(.*)$")
_MEM = re.compile(r"(-?0x[0-9a-fA-F]+|-?\d+)\((r1[02])\)")


def jump_tables(lines: list) -> set:
    """Quoted local symbol names whose object body starts with a `.rel` entry."""
    found = set()
    for i, line in enumerate(lines[:-1]):
        m = _OBJ.match(line)
        if m and lines[i + 1].lstrip().startswith(".rel "):
            found.add(m.group(1))
    return found


def _ins(line: str) -> tuple:
    m = _INS.match(line)
    return (m.group(1), m.group(2), m.group(3)) if m else (None, None, None)


def _rebase(args: str, reg: str, size: int) -> str:
    return _MEM.sub(lambda m: f"{int(m.group(1), 0) + size:#x}(r1)" if m.group(2) == reg else m.group(0), args)


def aligned_frames(lines: list) -> list:
    """`lines` with MWCC's realigning prologues/epilogues rewritten as plain stwu frames."""
    out, i, size, base = list(lines), 0, None, None
    while i < len(out):
        pre, op, args = _ins(out[i])
        if op == "clrlwi" and args.replace(" ", "") in ("r11,r1,28", "r11,r1,27") and i + 3 < len(out):
            ops = [_ins(out[i + k]) for k in (1, 2, 3)]
            sub = re.fullmatch(r"r11,r11,(-0x[0-9a-fA-F]+)", ops[1][2].replace(" ", "")) if ops[1][1] == "subfic" else None
            if ops[0][1] == "mr" and ops[0][2].replace(" ", "") == "r12,r1" and sub \
                    and ops[2][1] == "stwux" and ops[2][2].replace(" ", "") == "r1,r1,r11":
                size = -int(sub.group(1), 0)
                out[i] = f"{pre}stwu r1, {-size:#x}(r1)"
                for k in (1, 2, 3):
                    out[i + k] = ops[k - 1][0] + "nop"
                base, i = "r12", i + 4
                continue
        if size is not None and op:
            if base == "r12" and (op.startswith("b") or args.replace(" ", "").startswith("r12,") and not op.startswith("st")):
                base = None  # prologue saves end at the first branch or r12 write
            if op == "lwz" and args.replace(" ", "") == "r10,0x0(r1)":
                out[i], base = pre + "nop", "r10"
            elif op == "mr" and args.replace(" ", "") == "r1,r10":
                out[i], base = f"{pre}addi r1, r1, {size:#x}", None
            elif base and f"({base})" in args:
                out[i] = f"{pre}{op} {_rebase(args, base, size)}"
        if out[i].startswith(".endfn"):
            size = base = None
        i += 1
    return out


def prepare(text: str) -> str:
    """Returns `text` with jump-table symbols renamed and aligned frames made plain for m2c."""
    lines = text.splitlines()
    tables = jump_tables(lines)
    text = "\n".join(aligned_frames(lines)) + ("\n" if text.endswith("\n") else "")
    if not tables:
        return text
    pat = re.compile("|".join(re.escape(t) for t in tables))
    return pat.sub(lambda m: "jumptable_" + m.group(0)[2:-1], text)
