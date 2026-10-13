#!/usr/bin/env python3
"""Check that every app-callable function in the pinned headers is declared in src/.

Compares `extern SDL_DECLSPEC` names (and `SDL_HINT_*` strings) in the pinned
SDL and satellite headers with the Pascal sources. Exits 1 if anything is
missing. Assistive only: a name being present does not prove its signature.

Usage: python3 tools/check_coverage.py
"""
from __future__ import annotations

import re

import pins

CORE_DECL = re.compile(r"extern SDL_DECLSPEC\s+.+?\s+SDLCALL\s+(SDL_\w+)\s*\(", re.S)
SATELLITE_DECL = re.compile(r"extern SDL_DECLSPEC\s+.+?\s*SDLCALL\s+(\w+)\s*\(", re.S)
HINT = re.compile(r'#define\s+(SDL_HINT_\w+)\s+"([^"]+)"')
HINT_PRIORITIES = {"SDL_HINT_DEFAULT", "SDL_HINT_NORMAL", "SDL_HINT_OVERRIDE"}


def pascal_text() -> str:
    files = sorted(pins.SRC.glob("SDL*.inc")) + sorted(pins.SRC.glob("SDL3*.pas"))
    return "\n".join(path.read_text(encoding="utf-8") for path in files)


def check_core(pas: str) -> list[tuple[str, str]]:
    missing, present, skipped = [], 0, 0
    for name in pins.CORE_HEADERS:
        for fn in sorted(set(CORE_DECL.findall(pins.header(pins.SDL, name)))):
            if fn in pins.CORE_SKIP:
                skipped += 1
            elif fn in pas:
                present += 1
            else:
                missing.append((name, fn))
    print(f"SDL {pins.SDL.tag}: present={present} skipped={skipped} missing={len(missing)}")
    return missing


def check_hints(pas: str) -> list[tuple[str, str]]:
    names = [n for n, _ in HINT.findall(pins.header(pins.SDL, "SDL_hints.h")) if n not in HINT_PRIORITIES]
    missing = [("SDL_hints.h", n) for n in names if f"{n} =" not in pas]
    print(f"SDL_HINT_*: present={len(names) - len(missing)} missing={len(missing)}")
    return missing


def check_satellites(pas: str) -> list[tuple[str, str]]:
    missing = []
    for lib, name in pins.SATELLITE_HEADERS.items():
        upstream = pins.UPSTREAMS[lib]
        names = sorted(set(SATELLITE_DECL.findall(pins.header(upstream, name))))
        lib_missing = [(lib, fn) for fn in names if fn not in pas]
        print(f"{lib} {upstream.tag}: present={len(names) - len(lib_missing)} missing={len(lib_missing)}")
        missing += lib_missing
    return missing


def main() -> int:
    pas = pascal_text()
    missing = check_core(pas) + check_hints(pas) + check_satellites(pas)
    for where, name in missing:
        print(f"MISSING  {where}  {name}")
    return 1 if missing else 0


if __name__ == "__main__":
    raise SystemExit(main())
