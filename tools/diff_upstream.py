#!/usr/bin/env python3
"""List functions added or removed in the bound SDL headers between two SDL refs.

Usage: python3 tools/diff_upstream.py <old-ref> <new-ref>
Example: python3 tools/diff_upstream.py release-3.4.16 release-3.4.18

Only function names are compared. Follow up with
`git -C <SDL clone> diff <old> <new> -- include/SDL3/` for structs, enums,
constants, and property strings.
"""
from __future__ import annotations

import re
import subprocess
import sys

import pins

DECL = re.compile(r"extern SDL_DECLSPEC\s+.+?\s+SDLCALL\s+(SDL_\w+)\s*\(", re.S)


def names(ref: str, header: str) -> set[str]:
    try:
        return set(DECL.findall(pins.header(pins.SDL, header, ref)))
    except subprocess.CalledProcessError:
        return set()  # header does not exist at this ref


def main() -> int:
    if len(sys.argv) != 3:
        print(__doc__.strip(), file=sys.stderr)
        return 2
    old, new = sys.argv[1], sys.argv[2]
    added, removed = [], []
    for header in pins.CORE_HEADERS:
        before, after = names(old, header), names(new, header)
        added += [(header, fn) for fn in sorted(after - before)]
        removed += [(header, fn) for fn in sorted(before - after)]
    print(f"ADDED {old} -> {new} ({len(added)}):")
    for header, fn in added:
        print(f"  {header}  {fn}")
    print(f"REMOVED {old} -> {new} ({len(removed)}):")
    for header, fn in removed:
        print(f"  {header}  {fn}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
