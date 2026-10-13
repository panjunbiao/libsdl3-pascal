#!/usr/bin/env python3
"""Export the pinned headers into .cache/headers/<name>-<tag>/ and print the include folders.

Usage: python3 tools/export_headers.py [SDL SDL_image SDL_ttf SDL_mixer]

The C ABI oracle compiles against these folders, so its results always match
the pins, whatever branch the clones have checked out.
"""
from __future__ import annotations

import io
import subprocess
import sys
import tarfile

import pins

CACHE = pins.ROOT / ".cache" / "headers"


def export(upstream: pins.Upstream) -> str:
    repo = pins.clone_path(upstream)
    pins.check_pin(upstream, repo)
    target = CACHE / f"{upstream.name}-{upstream.tag}"
    if not (target / "include").exists():
        archive = subprocess.check_output(["git", "-C", str(repo), "archive", "--format=tar", upstream.tag, "include"])
        target.mkdir(parents=True, exist_ok=True)
        with tarfile.open(fileobj=io.BytesIO(archive)) as tar:
            tar.extractall(target, filter="data")
    return str(target / "include")


def main() -> int:
    names = sys.argv[1:] or ["SDL"]
    for name in names:
        if name not in pins.UPSTREAMS:
            print(f"unknown library {name}; expected one of {', '.join(pins.UPSTREAMS)}", file=sys.stderr)
            return 2
        print(export(pins.UPSTREAMS[name]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
