"""TU-scoped fuzzy alignment of ANB and TEN functions.

Source files keep their function order across revisions, so once anchors place a
run of TEN functions inside one ANB translation unit, the remaining functions of
that run are paired by a monotonic (order-preserving) alignment that maximizes
summed similarity. Anchors are fixed points of the alignment.
"""

from collections import Counter, defaultdict

MIN_SIM = 1.2  # 468/483 string-anchored pairs vs 88/18226 same-TU decoys pass (match_ten.py --calibrate).


def bigrams(ops: list) -> Counter:
    return Counter(zip(ops, ops[1:]))


class Similarity:
    """Pairwise similarity using size, opcode bigrams, mapped callees, and strings."""

    def __init__(self, matcher):
        self.m = matcher
        self._bg = {}

    def _bigram(self, prog, addr):
        key = (id(prog), addr)
        if key not in self._bg:
            self._bg[key] = bigrams(prog.sig[addr].ops)
        return self._bg[key]

    def score(self, a: int, t: int) -> float:
        m = self.m
        sa, st = m.anb.by_addr[a].size, m.ten.by_addr[t].size
        ratio = min(sa, st) / max(sa, st)
        if ratio < 0.4:
            return 0.0
        ba, bt = self._bigram(m.anb, a), self._bigram(m.ten, t)
        inter = sum((ba & bt).values())
        union = sum((ba | bt).values()) or 1
        score = 0.5 * ratio + inter / union
        tcalls = set(m.ten.sig[t].calls)
        for x in set(m.anb.sig[a].calls):
            y = m.a2t.get(x)
            if y is not None:
                score += 0.5 if y in tcalls else -0.25
        sa_str, st_str = m.anb.strings[a], m.ten.strings[t]
        if sa_str or st_str:
            score += 1.5 * len(sa_str & st_str) / len(sa_str | st_str)
        return score


def segments(matcher, splits) -> list:
    """Returns (anb_tu, ten_lo, ten_hi) windows: anchor runs widened into unlabeled gaps."""
    labels = []
    for t, a in matcher.t2a.items():
        tu = splits.tu_at("text", a)
        if tu:
            labels.append((matcher.ten.index[t], tu))
    labels.sort()
    runs = []
    for idx, tu in labels:
        if runs and runs[-1][0] == tu:
            runs[-1][2] = idx
        else:
            runs.append([tu, idx, idx])
    out = []
    n = len(matcher.ten.funcs)
    for k, (tu, lo, hi) in enumerate(runs):
        left = runs[k - 1][2] + 1 if k else 0
        right = runs[k + 1][1] - 1 if k + 1 < len(runs) else n - 1
        out.append((tu, left, right, hi - lo))
    return out


def align(matcher, splits, anb_tu_funcs: dict) -> int:
    """Pairs unmatched functions inside each segment; returns the number accepted."""
    sim = Similarity(matcher)
    added = 0
    for tu, lo, hi, _ in sorted(segments(matcher, splits), key=lambda s: -s[3]):
        A = [a for a in anb_tu_funcs.get(tu, [])]
        T = [f.addr for f in matcher.ten.funcs[lo:hi + 1]]
        if not A or not T or len(A) * len(T) > 400_000:
            continue
        rows, cols = len(A), len(T)
        dp = [[0.0] * (cols + 1) for _ in range(rows + 1)]
        take = [[False] * (cols + 1) for _ in range(rows + 1)]
        for i in range(1, rows + 1):
            a = A[i - 1]
            ma = matcher.a2t.get(a)
            for j in range(1, cols + 1):
                t = T[j - 1]
                best = max(dp[i - 1][j], dp[i][j - 1])
                mt = matcher.t2a.get(t)
                if ma == t:
                    s = 100.0
                elif ma is None and mt is None:
                    s = sim.score(a, t)
                    s = s if s >= MIN_SIM else -1.0
                else:
                    s = -1.0
                if s > 0 and dp[i - 1][j - 1] + s > best:
                    best, take[i][j] = dp[i - 1][j - 1] + s, True
                dp[i][j] = best
        i, j = rows, cols
        while i and j:
            if take[i][j]:
                added += matcher.accept(A[i - 1], T[j - 1], "align")
                i, j = i - 1, j - 1
            elif dp[i - 1][j] >= dp[i][j - 1]:
                i -= 1
            else:
                j -= 1
    return added


def tu_function_lists(anb_funcs: list, splits) -> dict:
    """Maps each ANB TU to its function addresses in address order."""
    out = defaultdict(list)
    for f in anb_funcs:
        tu = splits.tu_at("text", f.addr)
        if tu:
            out[tu].append(f.addr)
    return out
