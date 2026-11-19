#!/usr/bin/env python3
"""Assign source directories to the basename-only translation units of a dtk splits.txt.

The ANB ELF records translation units as basenames (STT_FILE symbols) in link order.
Link order groups objects by library, so each contiguous region maps to one library:

  game code -> Dolphin SDK -> Runtime.PPCEABI.H -> MSL_C -> debugger stubs/EXI/SI/THP
  -> MetroTRK -> Krome engine

Region boundaries are given as the first TU name of each region. Directory names for
the Krome engine follow ty-decomp (an earlier Krome GameCube title): platform-neutral
files live in common/Source and GameCube ports (*_GC.cpp) in common/gc.

Usage: assign_paths.py <splits.txt in> <splits.txt out> <paths.tsv out>
"""

import re
import sys

# (first TU of region, region id) in link order.
REGIONS = [
    ("BootLogo_GC.cpp", "game"),
    ("PPCArch.c", "dolphin"),
    ("__mem.c", "runtime"),
    ("GCN_mem_alloc.c", "msl"),
    ("AmcExi2Stubs.c", "dbgsdk"),
    ("mainloop.c", "trk"),
    ("MWCriticalSection_gc.cpp", "trk"),
    ("Animation.cpp", "engine"),
]

DOLPHIN_PREFIX = [
    ("PPCArch", "base"), ("db", "db"), ("OS", "os"), ("__start", "os"),
    ("__ppc_eabi_init", "os"), ("axart", "axart"), ("mtx", "mtx"), ("dvd", "dvd"),
    ("fstload", "dvd"), ("vi", "vi"), ("Pad", "pad"), ("ai", "ai"), ("arq", "ar"),
    ("ar", "ar"), ("AX", "ax"), ("DSPCode", "ax"), ("mix", "mix"), ("dsp", "dsp"),
    ("CARD", "card"), ("GX", "gx"), ("texPalette", "support"), ("fileCache", "support"),
    ("List", "support"), ("string", "support"),
]

DBGSDK = {
    "AmcExi2Stubs.c": "dolphin/amcstubs", "odenotstub.c": "dolphin/odenotstub",
    "DebuggerDriver.c": "dolphin/OdemuExi2", "EXIBios.c": "dolphin/exi",
    "EXIUart.c": "dolphin/exi", "SIBios.c": "dolphin/si", "SISamplingRate.c": "dolphin/si",
    "THPDec.c": "dolphin/thp", "THPAudio.c": "dolphin/thp",
}

TRK_EXTRA = {
    "main.c": "TRK_MINNOW_DOLPHIN/ddh", "CircleBuffer.c": "TRK_MINNOW_DOLPHIN/utils",
    "main.c_1": "TRK_MINNOW_DOLPHIN/gdev", "MWTrace.c": "TRK_MINNOW_DOLPHIN/utils",
    "MWCriticalSection_gc.cpp": "TRK_MINNOW_DOLPHIN/utils",
}

MSL_MATH = re.compile(r"^(e_|k_|s_|w_|math_ppc)")


def real_name(tu: str) -> str:
    """dtk suffixes duplicate basenames with _N; strip it for the on-disk file name."""
    return re.sub(r"(\.\w+)_\d+$", r"\1", tu)


def directory(tu: str, region: str, after_trk_core: bool) -> str:
    name = real_name(tu)
    if region == "game":
        return "spyro/source"
    if region == "engine":
        return "common/gc" if re.search(r"_GC\.cpp$", name) else "common/Source"
    if region == "dolphin":
        for prefix, sub in DOLPHIN_PREFIX:
            if name.startswith(prefix):
                return f"dolphin/{sub}"
        raise SystemExit(f"unclassified Dolphin TU: {tu}")
    if region == "runtime":
        return "Runtime.PPCEABI.H"
    if region == "msl":
        if MSL_MATH.match(name):
            return "MSL_C/MSL_Common_Embedded/Math"
        if name in ("uart_console_io_gcn.c", "critical_regions.gamecube.c", "GCN_mem_alloc.c"):
            return "MSL_C/PPC_EABI/Src"
        return "MSL_C/MSL_Common/Src"
    if region == "dbgsdk":
        return DBGSDK[name]
    if region == "trk":
        if after_trk_core and tu in TRK_EXTRA:
            return TRK_EXTRA[tu]
        return "TRK_MINNOW_DOLPHIN/MetroTRK"
    raise SystemExit(f"unknown region {region}")


def main() -> None:
    src, dst, tsv = sys.argv[1:4]
    starts = dict(REGIONS)
    region = None
    after_trk_core = False
    out, rows = [], []
    for line in open(src, encoding="utf-8"):
        m = re.match(r"^(\S.*):$", line.rstrip("\n"))
        if m and m.group(1) != "Sections":
            tu = m.group(1)
            region = starts.get(tu, region)
            if tu == "UDP_Stubs.c":
                after_trk_core = True
            path = f"{directory(tu, region, after_trk_core)}/{real_name(tu)}"
            rows.append(f"{tu}\t{path}\t{region}")
            line = f"{path}:\n"
        out.append(line)
    if len(set(r.split("\t")[1] for r in rows)) != len(rows):
        raise SystemExit("path collision after assignment")
    open(dst, "w", encoding="utf-8").writelines(out)
    open(tsv, "w", encoding="utf-8").write("elf_tu\tpath\tregion\n" + "\n".join(rows) + "\n")
    print(f"{len(rows)} translation units assigned")


if __name__ == "__main__":
    main()
