"""Krome engine and Spyro game library definitions (regions "engine" and "game").

Compiler evidence (tools/srcgen/cc_probe.py against ANB's split objects):
common/Source/Crc.cpp matches 100% in all three functions with GC/2.0-2.7 and
"-O4,s -use_lmw_stmw on"; GC/3.0a3+ and every -O4,p variant miss (unrolled
loops, _savegpr calls). GC/2.7 is chosen within the 2.x family because the
DOL links with the GC/2.7 linker; probes that separate 2.0-2.7 are still open.

Inlining is MWCC's default `-inline noauto`: the original LoadDone of
KDEnvParticleSystemDescriptor calls the 30-instruction CalculateEnvelope
defined before it out of line, which `-inline auto` would inline. Over all
ANB game/engine objects, noauto against auto gave 49 more 100% functions,
none lost, and fuzzy match up in 205 functions, down in 1.

"-fp_contract on" lets MWCC fuse multiply-add pairs into fmadds/fmsubs/fnmsubs,
which the original objects use throughout. "-str reuse,pool,readonly" merges
identical string literals into one pooled read-only block, as the original
.rodata/.data string layout does. Size-weighted function match over 943206
bytes of compiling game TUs (fpc/probe2.py): -fp_contract on 29.850%;
+ -str reuse 29.850%; + -str reuse,pool,readonly 31.098%; + -str readonly
30.252%. Per-TU deltas of the pooled variant ranged from -1.66 (MKHeap) to
+25.33 (NPCGuardian).
"""

from pathlib import Path
from typing import Any, Callable, Dict, List

MW_VERSION = "GC/2.7"

CFLAGS = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-fp_contract on",
    "-str reuse,pool,readonly",
    "-Cpp_exceptions off",
    "-RTTI off",
    "-O4,s",
    "-use_lmw_stmw on",
    "-inline noauto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-i include",
    "-i include/libc",
    "-i src",
]

REGIONS = ("engine", "game")


def libs(version: str, Object: Callable, matching: set) -> List[Dict[str, Any]]:
    """One library per region from the version's TU path table.

    `matching` holds the object paths verified byte-identical for `version`.
    """
    table = Path("config") / version / "tu_paths.tsv"
    if not table.exists():
        return []
    groups: Dict[str, List[Any]] = {r: [] for r in REGIONS}
    for line in table.read_text(encoding="utf-8").splitlines()[1:]:
        _, path, region = line.split("\t")[:3]
        if region in groups:
            groups[region].append(Object(path in matching, path))
    return [
        {
            "lib": region,
            "mw_version": MW_VERSION,
            "cflags": CFLAGS,
            "progress_category": region,
            "objects": objects,
        }
        for region, objects in groups.items()
        if objects
    ]
