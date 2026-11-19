"""Parse decomp-toolkit splits.txt files into per-section TU ranges."""

import bisect
import re


class Splits:
    """Translation-unit ranges of one splits.txt, queryable by address."""

    def __init__(self, path: str):
        self.ranges = {}  # section -> sorted [(start, end, tu)]
        self.order = []
        tu = None
        for line in open(path, encoding="utf-8"):
            head = re.match(r"^(\S.*):$", line.rstrip("\n"))
            if head:
                tu = None if head.group(1) == "Sections" else head.group(1)
                if tu:
                    self.order.append(tu)
                continue
            m = re.match(r"^\s+(\S+)\s+start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)", line)
            if m and tu:
                sec = m.group(1).lstrip(".")
                self.ranges.setdefault(sec, []).append((int(m.group(2), 16), int(m.group(3), 16), tu))
        for lst in self.ranges.values():
            lst.sort()
        self._starts = {s: [r[0] for r in lst] for s, lst in self.ranges.items()}

    def tu_at(self, section: str, addr: int):
        """Returns the TU containing `addr` in `section`, or None."""
        lst = self.ranges.get(section, [])
        i = bisect.bisect_right(self._starts.get(section, []), addr) - 1
        if i >= 0 and lst[i][0] <= addr < lst[i][1]:
            return lst[i][2]
        return None
