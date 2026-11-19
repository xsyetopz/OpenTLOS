"""Dolphin SDK library definitions for the GameCube build (ANB).

Sources come from the dolsdk2004 decompilation of the 4/20/2004 SDK, the
closest available revision to ANB's Apr 5 / May 21 2004 SDK build stamps.
Objects and their library grouping follow config/<version>/tu_paths.tsv,
whose paths come from ANB's debug TU names.
"""

from pathlib import Path
from typing import Any, Callable, Dict, List

# Flags from the dolsdk2004 Makefile release rule. The SDK was built with its
# own flag set, so the game's cflags_base (which adds -fp_contract, -str reuse,
# and others) must not leak in.
CFLAGS = [
    "-nodefaults",
    "-proc gekko",
    "-fp hard",
    "-Cpp_exceptions off",
    "-enum int",
    "-warn pragmas",
    "-requireprotos",
    '-pragma "cats off"',
    "-O4,p",
    "-inline auto",
    "-D__GEKKO__",
    "-DSDK_REVISION=2",
    "-DRELEASE",
    "-I-",  # Lets <...> includes search the -i paths, as in the dolsdk2004 Makefile.
    "-i include",
    "-i include/libc",
    "-ir src/dolphin",
]

# Per-object flag overrides recorded in the dolsdk2004 Makefile.
CHAR_SIGNED_DIRS = {"dvd"}
CHAR_SIGNED_FILES = {"card/CARDOpen.c", "card/CARDRename.c", "mtx/mtx.c", "mtx/mtx44.c"}
OPT_OVERRIDES = {"exi/EXIBios.c": "-O3,p"}


def object_cflags(rel: str) -> List[str]:
    """Returns the full flag list for one SDK object path relative to src/dolphin."""
    flags = list(CFLAGS)
    signed = rel.split("/")[0] in CHAR_SIGNED_DIRS or rel in CHAR_SIGNED_FILES
    flags.append("-char signed" if signed else "-char unsigned")
    if rel.endswith(".cpp"):
        # ANB's debug info names __ppc_eabi_init.cpp, but the dolsdk2004 body is
        # C (it uses C++ keywords as identifiers in shared headers).
        flags.append("-lang=c")
    if rel in OPT_OVERRIDES:
        flags[flags.index("-O4,p")] = OPT_OVERRIDES[rel]
    return flags


def libs(version: str, Object: Callable, matching: set) -> List[Dict[str, Any]]:
    """Builds one library per SDK directory from the version's TU path table.

    `matching` holds the object paths verified byte-identical for `version`.
    """
    table = Path("config") / version / "tu_paths.tsv"
    if not table.exists():
        return []
    groups: Dict[str, List[Any]] = {}
    for line in table.read_text(encoding="utf-8").splitlines()[1:]:
        _, path, region = line.split("\t")[:3]
        if region != "dolphin":
            continue
        rel = path.removeprefix("dolphin/")
        groups.setdefault(rel.split("/")[0], []).append(
            Object(path in matching, path, cflags=object_cflags(rel))
        )
    return [
        {
            "lib": name,
            "mw_version": "GC/1.2.5n",
            "cflags": CFLAGS,
            "progress_category": "sdk",
            "objects": objects,
        }
        for name, objects in groups.items()
    ]
