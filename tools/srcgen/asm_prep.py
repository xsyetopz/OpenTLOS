"""Rewrite dtk assembly into the form m2c's PowerPC front end expects.

m2c recognises a `bctr` jump table only when the table symbol's name starts with
"jtbl"/"jpt_"/"lbl_"/"jumptable_". spyro06.elf keeps MWCC's local names for
those tables ("@1187"), so each local object whose body is `.rel` entries is
renamed to `jumptable_<n>` throughout its file. Addresses and code are untouched.
"""

import re

_OBJ = re.compile(r'^\.obj ("@\d+"), local$')


def jump_tables(lines: list) -> set:
    """Quoted local symbol names whose object body starts with a `.rel` entry."""
    found = set()
    for i, line in enumerate(lines[:-1]):
        m = _OBJ.match(line)
        if m and lines[i + 1].lstrip().startswith(".rel "):
            found.add(m.group(1))
    return found


def prepare(text: str) -> str:
    """Returns `text` with jump-table symbols renamed for m2c."""
    lines = text.splitlines()
    tables = jump_tables(lines)
    if not tables:
        return text
    pat = re.compile("|".join(re.escape(t) for t in tables))
    return pat.sub(lambda m: "jumptable_" + m.group(0)[2:-1], text)
