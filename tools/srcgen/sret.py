"""Functions that return a class by value, proven from their asm.

MWCC returns a class through a hidden pointer passed in the first GPR, so
`MKVector3 Max(const MKVector3 &, const MKVector3 &)` reads r3 (the result)
and r4, r5 (the parameters). m2c's PPC backend does not model this (its MIPS
and ARM backends do), and calls lose their destination:
`MKVector__Ffff(1.0f, 1.0f, 1.0f);` before `KDRand_Vector(&sp88, &sp78)`.

A function returns a class when its body reads the GPR after its last
declared integer or pointer parameter (and `this`) before writing it. Variadic functions
are excluded: they spill every argument register. The class is the one
whose size equals the extent the body stores through that register: a
class operand first, else a vector (see `result_type`).
"""

from __future__ import annotations

import re
from pathlib import Path

from cxxtypes import K, parse, render
from mstatic import INSN, READS_FIRST, bodies, operands

FLOATS = {"float", "double", "const float", "const double"}
STORE = re.compile(r"^(st[bhw]|stfs|stfd|psq_st)u?$")
WIDTH = {"stb": 1, "sth": 2, "stw": 4, "stfs": 4, "stfd": 8, "psq_st": 8}
VECTORS = (0xC, 0x10)


def hidden_reg(mangled: str, statics: set = frozenset()) -> tuple[str, list[str], str | None] | None:
    """(GPR after the last parameter once r3 holds the result pointer, parameter types, class).

    A non-static member also passes `this`, in r4, so its parameters start at
    r5. Constructors and destructors return `this`, not a class. 64-bit
    parameters, which take an aligned GPR pair, are skipped.
    """
    try:
        sym = parse(mangled)
    except Exception:  # noqa: BLE001 - not a mangled name
        return None
    terms = sym.type.terms
    quals = [str(q) for q in sym.name.qualified_name or []]
    if not terms or terms[-1].kind != K.FUNCTION or not quals or quals[-1] in ("__ct", "__dt"):
        return None
    params = [render(p) for p in terms[-1].function_params or [] if render(p) != "void"]
    if any(p == "..." or "long long" in p for p in params) or mangled.endswith("e"):
        return None
    cls = "::".join(quals[:-1]) or None
    gprs = sum(p not in FLOATS for p in params) + (1 if cls and mangled not in statics else 0)
    return (f"r{3 + gprs}", params, cls) if gprs < 8 else None


def reads_first(body: list[str], reg: str) -> bool:
    """Whether straight-line code reads `reg` before a write, call or branch."""
    for line in body:
        m = INSN.match(line)
        if not m:
            continue
        op, regs = m.group(1), operands(m.group(2))
        if op.startswith("b"):
            return False
        if reg in regs:
            return bool(READS_FIRST.match(op)) or reg in regs[1:]
    return False


def store_extent(body: list[str]) -> int:
    """End of the highest store through the result pointer r3 or a `mr` copy of it."""
    end, regs = 0, {"r3"}
    for line in body:
        m = INSN.match(line)
        if not m:
            continue
        ops = operands(m.group(2))
        if m.group(1) == "mr" and len(ops) == 2 and ops[1] in regs:
            regs.add(ops[0])
        if not STORE.match(m.group(1)):
            continue
        dst = re.match(r"^\s*\w+,\s*(-?0x[0-9a-fA-F]+|-?\d+)\((r\d+)\)", m.group(2))
        if dst and dst.group(2) in regs:
            end = max(end, int(dst.group(1), 0) + WIDTH[m.group(1).rstrip("u")])
    return end


def result_type(model, params: list[str], extent: int, cls: str | None = None, op: bool = False) -> str | None:
    """The returned class: an operator's own class or an operand class `T` of
    `T f(const T &, ...)`, else a vector.

    A class reached only through a pointer parameter is an input, not the
    result (`MKFont_GetCharPos(MKFont *, ...)` stores a position). An extent
    of 0 means the stores go through a register the scan does not follow.
    MKVector3 is 0x10 with padding, as MKVector4 is: `MKVector(f32, f32, f32)`
    stores its three floats plus the padding as two doubles. Only four float
    parameters, one per lane, make the result an MKVector4.
    """
    operands_ = sorted({re.sub(r"^const |\s*&$", "", p).strip() for p in params if not p.endswith("*")})
    if op and cls in model.classes and extent == model.sizeof(cls):
        return cls  # `T T::operator*(float) const`; a getter of a 16-byte class still returns a vector
    for c in operands_:
        if c in model.classes and extent in (0, model.sizeof(c)):
            return c
    if extent not in VECTORS:
        return None
    return "MKVector4" if params.count("float") == 4 else "MKVector3"


def struct_returns(model, asm_root: Path) -> dict[str, str]:
    """Mangled function -> the class it returns through the hidden pointer."""
    out = {}
    for f in sorted(asm_root.rglob("*.s")):
        for name, body in bodies(f).items():
            hit = hidden_reg(name, model.statics)
            if not hit or not reads_first(body, hit[0]):
                continue
            out_t = result_type(model, hit[1], store_extent(body), hit[2], name.startswith("__"))
            if out_t:
                out[name] = out_t
    return out
