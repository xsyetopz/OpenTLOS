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


_PS = {
    "ps_add": "fadd", "ps_sub": "fsub", "ps_mul": "fmul", "ps_div": "fdiv",
    "ps_muls0": "fmul", "ps_muls1": "fmul", "ps_madd": "fmadd", "ps_madds0": "fmadd",
    "ps_madds1": "fmadd", "ps_msub": "fmsub", "ps_nmadd": "fnmadd", "ps_nmsub": "fnmsub",
    "ps_mr": "fmr", "ps_neg": "fneg", "ps_abs": "fabs", "ps_nabs": "fnabs",
}
_CR = {"lt": "0", "gt": "1", "eq": "2"}
_SAVE = re.compile(r"(f(?:1[4-9]|2\d|3[01])),\s*(0x[0-9a-fA-F]+)\(r1\)")


def _callee_save(lines: list, i: int, op: str, args: str) -> bool:
    """Whether `psq_l`/`psq_st` at `i` is half of MWCC's paired save of a callee-saved FPR."""
    m = _SAVE.match(args)
    if not m:
        return False
    twin = "stfd" if op == "psq_st" else "lfd"
    near = [_ins(lines[k]) for k in (i - 1, i + 1) if 0 <= k < len(lines)]
    return any(o == twin and a.startswith(m.group(1) + ",") for _, o, a in near)


def paired_singles(lines: list) -> list:
    """`lines` with Gekko paired-single code lowered to scalar ops m2c decodes.

    m2c has no paired-single model: `psq_l` becomes an error expression, `psq_st`
    is dropped and every `ps_*` op is unknown, so the inlined MKVector3 arithmetic
    loses its stores and later reads name undeclared `spN` locals. Lowering keeps
    only lane ps0 (pairs read as f64), which makes the draft compile; the vector
    source still has to be restored by hand. `cror eq, lt|gt, eq` is spelled in
    the numeric form m2c's fcmpo/cror pattern matches. Callee-saved FPR pair
    saves (`stfd fN` next to `psq_st fN`) become `nop` because the `stfd` already
    carries the save.
    """
    out = list(lines)
    for i, line in enumerate(out):
        pre, op, args = _ins(line)
        if not op:
            continue
        a = [x.strip() for x in args.split(",")]
        if op in ("psq_l", "psq_st") and len(a) == 4:
            out[i] = pre + ("nop" if _callee_save(out, i, op, args)
                            else f"{'lfd' if op == 'psq_l' else 'stfd'} {a[0]}, {a[1]}")
        elif op in ("psq_lx", "psq_stx") and len(a) == 5:
            out[i] = f"{pre}{'lfdx' if op == 'psq_lx' else 'stfdx'} {', '.join(a[:3])}"
        elif op in _PS:
            out[i] = f"{pre}{_PS[op]} {args}"
        elif op in ("ps_merge00", "ps_merge01", "ps_merge10", "ps_merge11") and len(a) == 3:
            out[i] = f"{pre}fmr {a[0]}, {a[1]}"
        elif op in ("ps_sum0", "ps_sum1") and len(a) == 4:
            out[i] = f"{pre}fadd {a[0]}, {a[1]}, {a[3]}"
        elif op == "cror" and len(a) == 3 and all(x in _CR for x in a):
            out[i] = f"{pre}cror {', '.join(_CR[x] for x in a)}"
    return out


def prepare(text: str) -> str:
    """Returns `text` with jump-table symbols renamed and aligned frames and paired-single code made plain for m2c."""
    lines = text.splitlines()
    tables = jump_tables(lines)
    text = "\n".join(paired_singles(aligned_frames(lines))) + ("\n" if text.endswith("\n") else "")
    if not tables:
        return text
    pat = re.compile("|".join(re.escape(t) for t in tables))
    return pat.sub(lambda m: "jumptable_" + m.group(0)[2:-1], text)
