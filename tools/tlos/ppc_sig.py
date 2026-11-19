"""Relocation-insensitive signatures of PowerPC functions.

Two builds of the same function differ in branch targets, absolute addresses
(lis/addi pairs) and small-data offsets (r2/r13), but not in instruction shape.
Masking those fields yields a hash that matches across executables. The same pass
recovers call targets and referenced addresses for call-graph and data matching.
"""

import hashlib
import struct
from dataclasses import dataclass, field

# D-form opcodes whose 16-bit immediate can encode an address low half:
# addi, ori, and the integer/float loads and stores (lwz..stfdu).
ADDR_LO_OPS = {14, 24} | set(range(32, 56))
# D-form opcodes that write a GPR destination, invalidating a pending lis value.
GPR_WRITE_OPS = {7, 8, 10, 11, 12, 13, 14, 15, 20, 21, 23, 24, 25, 28, 29,
                 32, 33, 34, 35, 40, 41, 42, 43, 46}


@dataclass
class FuncSig:
    """Masked hash plus extracted call and data references of one function."""

    exact: str
    shape: str
    calls: list = field(default_factory=list)
    refs: list = field(default_factory=list)
    ops: list = field(default_factory=list)


def sign16(v: int) -> int:
    return v - 0x10000 if v & 0x8000 else v


def small_data_bases(words: tuple) -> dict:
    """Finds r2/r13 values set by `lis rN,hi; ori/addi rN,rN,lo` in __init_registers."""
    hi, bases = {}, {}
    for w in words:
        op, rd, ra, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op == 15 and ra == 0:
            hi[rd] = imm << 16
        elif op == 24 and rd in hi and ra == rd:  # ori: rA is the destination
            bases[rd] = hi[rd] | imm
        elif op == 14 and ra in hi and rd == ra:
            bases[rd] = (hi[rd] + sign16(imm)) & 0xFFFFFFFF
    return {r: v for r, v in bases.items() if r in (2, 13)}


def signature(addr: int, words: tuple, sda: dict) -> FuncSig:
    """Builds the signature of the function at `addr` with the given instruction words."""
    masked, shape, calls, refs = [], [], [], []
    hi = {}
    full = {}  # Registers holding a complete address (pool bases, after lis+addi).
    for i, w in enumerate(words):
        op = w >> 26
        rd, ra, imm = (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        m = w
        # Offsets from a full-address register are not relocations, so they stay
        # in the hash; they are still recorded as references for string matching.
        if op in ADDR_LO_OPS and op != 24 and ra in full and ra not in hi:
            refs.append((full[ra] + sign16(imm)) & 0xFFFFFFFF)
        if op == 31 and ((w >> 1) & 0x3FF) == 444 and rd == ((w >> 11) & 31):  # mr rA,rS
            if rd in full:
                full[ra] = full[rd]
            else:
                full.pop(ra, None)
        elif op == 14 and ra in hi:
            full[rd] = (hi[ra] + sign16(imm)) & 0xFFFFFFFF
        elif op == 14 and ra in sda:
            full[rd] = (sda[ra] + sign16(imm)) & 0xFFFFFFFF
        elif op in GPR_WRITE_OPS or op == 31:
            full.pop(ra if op in (24, 25, 28, 29) else rd, None)
        if op == 18:
            li = w & 0x03FFFFFC
            li = li - 0x04000000 if li & 0x02000000 else li
            target = (li if w & 2 else addr + 4 * i + li) & 0xFFFFFFFF
            if w & 1 or not addr <= target < addr + 4 * len(words):
                calls.append(target)
                m = w & 0xFC000003
        elif op == 15 and ra == 0:
            hi[rd] = imm << 16
            m = w & 0xFFFF0000
        elif op in ADDR_LO_OPS:
            base_reg = rd if op == 24 else ra
            if base_reg in sda:
                refs.append((sda[base_reg] + sign16(imm)) & 0xFFFFFFFF)
                m = w & 0xFFFF0000
            elif base_reg in hi:
                lo = imm if op == 24 else sign16(imm)
                refs.append((hi[base_reg] + lo) & 0xFFFFFFFF)
                m = w & 0xFFFF0000
        if op in GPR_WRITE_OPS and not (op == 15 and ra == 0):
            hi.pop(ra if op in (24, 25, 28, 29) else rd, None)
        elif op == 31:
            hi.pop(rd, None)
            hi.pop(ra, None)
        masked.append(m)
        shape.append(op if op != 31 else 0x100 | ((w >> 1) & 0x3FF))
    return FuncSig(
        hashlib.blake2b(struct.pack(f">{len(masked)}I", *masked), digest_size=12).hexdigest(),
        hashlib.blake2b(struct.pack(f">{len(shape)}H", *shape), digest_size=12).hexdigest(),
        calls, refs, shape,
    )
