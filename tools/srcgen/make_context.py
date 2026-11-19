#!/usr/bin/env python3
"""Build the m2c C context: SDK and libc prototypes that game code calls.

Usage: make_context.py <out.c>

m2c knows argument types of C++ callees from their mangled names, but extern "C"
SDK/libc callees (strcpy, GXBegin, ...) need prototypes or m2c emits argless
calls. The context is include/dolphin.h plus include/libc headers, preprocessed
with clang, with Metrowerks extensions removed and array bounds that m2c's
constant folder cannot evaluate (sizeof expressions) replaced by 1. Those arrays
live inside SDK structs whose layout game code does not touch.
"""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
HEADERS = ["dolphin.h", "string.h", "stdio.h", "stdlib.h", "math.h", "ctype.h", "stdarg.h"]
DEFINES = ["__MWERKS__=0x4199", "__GEKKO__", "M2C", "__declspec(x)=", "__attribute__(x)=", "asm=", "__asm__="]


def main() -> int:
    out = Path(sys.argv[1])
    src = "".join(f"#include <{h}>\n" for h in HEADERS)
    cmd = ["clang", "-E", "-P", "-nostdinc", "-x", "c", "-", "-I", str(ROOT / "include"), "-I", str(ROOT / "include/libc"),
           *(f"-D{d}" for d in DEFINES)]
    text = subprocess.run(cmd, input=src, capture_output=True, text=True, check=True).stdout
    text = re.sub(r"\[([^\]\n]*sizeof[^\]\n]*)\]", "[1]", text)
    out.write_text(text)
    return 0


if __name__ == "__main__":
    sys.exit(main())
