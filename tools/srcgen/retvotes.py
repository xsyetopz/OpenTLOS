"""Return types recovered from where m2c passes a call's result.

m2c types `MKSceneManager::CreateProp` as returning `void *`, yet every one of
its call sites hands the result straight to `checked_cast<X, MKProp>(MKProp *)`.
A callee whose only parameter is a mangled class pointer fixes the argument's
type exactly, so such a call nested as the sole argument is evidence for the
inner function's return type. Without it, ~500 calls (CreateProp,
CreateInstance, PropResolver_Resolve, MKFont::Create) fail as `void *` to
class-pointer conversions.
"""

from __future__ import annotations

import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from cxxtypes import K, parse, render  # noqa: E402

NEST = re.compile(r"([\w<>,]+__\w+)\((\w+__\w+)\(")
CLASS_PTR = re.compile(r"^[A-Z]\w*\s*\*$")


def arg_returns(root: Path) -> dict:
    """Mangled function -> class-pointer type, when every nesting call site agrees."""
    votes = defaultdict(Counter)
    for f in root.rglob("*.c"):
        for outer, inner in NEST.findall(f.read_text()):
            try:
                t = parse(outer).type
            except Exception:  # noqa: BLE001 - the demangler raises bare errors on C names
                continue
            if not (t.terms and t.terms[-1].kind == K.FUNCTION) or len(t.terms[-1].function_params or []) != 1:
                continue
            typ = render(t.terms[-1].function_params[0])
            if CLASS_PTR.match(typ):
                votes[inner][typ] += 1
    return {k: next(iter(v)) for k, v in votes.items() if len(v) == 1}
