"""Compile one source with the game compiler and summarize mwcc's diagnostics."""

from __future__ import annotations

import shlex
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(ROOT / "config/libs"))
from krome import CFLAGS, MW_VERSION  # noqa: E402


def command(src: Path, out: Path, includes: list[Path], maxerrors: int) -> list[str]:
    """The mwcceppc command line: config/libs/krome.py's flags, `-i src` replaced by `includes`."""
    flags = [f for c in CFLAGS if not c.startswith(("-maxerrors", "-i src")) for f in shlex.split(c)]
    incs = [x for i in includes for x in ("-i", str(i))]
    return [str(ROOT / "build/tools/wibo"), str(ROOT / f"build/compilers/{MW_VERSION}/mwcceppc.exe"),
            *flags, "-maxerrors", str(maxerrors), *incs, "-c", str(src), "-o", str(out)]


def compile_one(src: Path, out: Path, includes: list[Path], maxerrors: int = 1, timeout: int = 120) -> tuple[int, str]:
    """(error count, first error as `file | message | source line`) for `src`; (0, "") on success."""
    try:
        p = subprocess.run(command(src, out, includes, maxerrors), capture_output=True, text=True,
                           timeout=timeout, cwd=ROOT)
    except subprocess.TimeoutExpired:
        return 1, "timeout"
    if p.returncode == 0:
        return 0, ""
    # mwcc reports "#      In: <file>", the source line, a caret line, then "#   <message>".
    lines = (p.stdout + p.stderr).splitlines()
    where = next((l.split("In:", 1)[1].strip().split("\\")[-1] for l in lines if l.startswith("#      In:")), "")
    caret = next((i for i, l in enumerate(lines) if l.startswith("#   Error:")), None)
    msg = lines[caret + 1].lstrip("# ").strip() if caret is not None and caret + 1 < len(lines) else "unknown"
    line = lines[caret - 1].split(":", 1)[-1].strip() if caret else ""
    count = max(1, sum(1 for l in lines if l.startswith("#   Error:")))
    return count, f"{where} | {msg} | {line}"
