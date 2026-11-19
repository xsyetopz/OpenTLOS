#!/usr/bin/env python3
"""Serve the live ANB/TEN progress treemap and refresh it when the tree changes.

Usage: python3 tools/live/server.py [--port 8765] [--interval 5]

Open http://127.0.0.1:8765/ . The page polls progress.json every 3 s and flashes
newly matched or newly named functions. A watcher thread stats sources, the
per-version matching lists and the TEN symbol map every INTERVAL seconds; only
after a change it reconfigures, rebuilds and checks the ANB DOL, regenerates the
objdiff report, and rewrites build/live/progress.json. A failing step (the tree
caught mid-edit by a concurrent session) keeps the last good data and retries on
the next tick. Adapted from GodHand's tools/live.py.
"""

from __future__ import annotations

import argparse
import json
import subprocess
import sys
import threading
import time
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
LIVE = ROOT / "build/live"
ROUTES = {"/": ROOT / "tools/live/index.html", "/index.html": ROOT / "tools/live/index.html",
          "/progress.json": LIVE / "progress.json", "/status.json": LIVE / "status.json"}
PY = sys.executable
# The DOL check is informative, so its failure does not block the report.
STEPS = [([PY, "configure.py"], True), (["ninja", "build/G6SE7D/ok"], False),
         (["ninja", "build/G6SE7D/report.json"], True), ([PY, "tools/live/progress.py"], True)]


class Handler(SimpleHTTPRequestHandler):
    def translate_path(self, path: str) -> str:
        return str(ROUTES.get(path.split("?", 1)[0], LIVE / ".missing"))

    def end_headers(self) -> None:
        self.send_header("Cache-Control", "no-cache")  # revalidate via Last-Modified
        super().end_headers()

    def log_message(self, *a) -> None:
        pass


def snapshot() -> dict[str, float]:
    """mtimes of every input whose change can alter the progress data."""
    files = [*ROOT.joinpath("src").rglob("*.c*"), *ROOT.joinpath("src").rglob("*.h"),
             *ROOT.joinpath("include").rglob("*.h"), *ROOT.joinpath("config").rglob("matching.txt"),
             *ROOT.joinpath("config").rglob("anb_map.tsv"), *ROOT.joinpath("config/libs").glob("*.py")]
    snap = {}
    for f in files:
        try:
            snap[str(f)] = f.stat().st_mtime
        except OSError:
            pass
    return snap


def refresh() -> str | None:
    """Rebuilds progress.json; returns None on success, else why the tree is unsettled."""
    for cmd, required in STEPS:
        try:
            r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, timeout=1800)
        except (OSError, subprocess.TimeoutExpired) as e:
            return f"{cmd[-1]}: {e}"
        if r.returncode and required:
            lines = [l for l in (r.stdout + r.stderr).strip().splitlines() if not l.startswith("ninja:")]
            return f"{cmd[-1]}: {lines[-1][:300] if lines else 'failed'}"
    return None


def write_status(pending: str | None) -> None:
    LIVE.mkdir(parents=True, exist_ok=True)
    (LIVE / "status.json").write_text(json.dumps({"ok": pending is None, "message": pending or "", "t": time.time()}))


def watch(interval: float) -> None:
    """Refreshes on change; while a refresh fails, retries each tick until the tree settles."""
    last, pending = None, None
    while True:
        try:
            snap = snapshot()
            if snap != last or pending is not None:
                last = snap
                reason = refresh()
                last = snapshot()
                if reason is None:
                    print(f"live: refreshed {time.strftime('%H:%M:%S')}", flush=True)
                elif reason != pending:
                    print(f"live: waiting for tree to settle ({reason})", flush=True)
                write_status(reason)
                pending = reason
        except Exception as e:  # the watcher thread must outlive any single bad tick
            pending = f"{type(e).__name__}: {e}"
            print(f"live: tick error ({pending}); retrying", flush=True)
        time.sleep(interval)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--port", type=int, default=8765)
    ap.add_argument("--interval", type=float, default=5.0, help="seconds between change checks")
    args = ap.parse_args()
    try:
        srv = ThreadingHTTPServer(("127.0.0.1", args.port), Handler)
    except OSError as e:
        raise SystemExit(f"live: port {args.port} unavailable ({e.strerror}); pass --port N")
    threading.Thread(target=watch, args=(args.interval,), daemon=True).start()
    print(f"live: http://127.0.0.1:{args.port}/  (Ctrl-C to stop)", flush=True)
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        pass
    return 0


if __name__ == "__main__":
    sys.exit(main())
