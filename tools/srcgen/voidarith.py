"""Make m2c's byte arithmetic on `void *` valid C++.

m2c writes an offset from an untyped pointer as `p + 0x30`, which C (as a
GNU extension) reads as a byte offset and C++ rejects as "illegal type".
When `p` is known to be `void *` (a local or parameter declared so, or a
`this->unkX` field the model types `void *`) the left operand is cast to
`(u8 *)`, which compiles to the same add. A dereference `*(p + n)` is left
alone: through `u8 *` it would read one byte instead of the original width.
"""

from __future__ import annotations

import re

_DECL = re.compile(r"\bvoid \*(\w+)(?=[;,)])")
_FIELD = re.compile(r"this->(unk([0-9A-F]+))\b")


def void_fields(model, cls: str | None) -> set[str]:
    """`unkX` names of `cls`'s and its ancestors' fields typed `void *`."""
    if not cls:
        return set()
    out = set()
    for c in [cls, *model.ancestors(cls)]:
        for off, f in model.fields.get(c, {}).get("fields", {}).items():
            if f["type"][0] == "void *":
                out.add(f"unk{int(off):X}")
    return out


def byte_offsets(text: str, fields: set[str]) -> str:
    """`text` (one function, signature included) with `void *` operands of `+`/`-` cast to `u8 *`."""
    names = set(_DECL.findall(text)) | {f"this->{f}" for f in fields}
    if not names:
        return text
    alt = "|".join(re.escape(n) for n in sorted(names, key=len, reverse=True))
    pat = re.compile(rf"(?<![\w.>&*])(\*\()?({alt})(?![\w\[(.]|->) ?([+-]) ?(?![=+-])")
    return pat.sub(lambda m: m.group(0) if m.group(1) else f"((u8 *) {m.group(2)}) {m.group(3)} ", text)
