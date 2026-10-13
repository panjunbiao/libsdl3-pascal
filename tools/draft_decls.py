#!/usr/bin/env python3
"""Print first-draft Pascal declarations for one pinned SDL header.

Usage:
  python3 tools/draft_decls.py funcs SDL_video.h
  python3 tools/draft_decls.py defines SDL_video.h SDL_WINDOW_

Assistive only. The output is a starting point that must be checked by hand
against the header and docs/STYLEGUIDE.md; it gets unions, callbacks,
varargs, and many pointer types wrong. Committed Pascal is the source of truth.
"""
from __future__ import annotations

import re
import sys

import pins

TYPE_MAP = {
    "void": None,
    "bool": "Boolean",
    "int": "Integer",
    "float": "Single",
    "double": "Double",
    "const char *": "PUTF8Char",
    "char *": "PUTF8Char",
    "void *": "Pointer",
    "const void *": "Pointer",
    "size_t *": "PNativeUInt",
    "size_t": "NativeUInt",
}
SCALAR_POINTERS = {"char": "PUTF8Char", "int": "PInteger", "float": "PSingle", "bool": "PBoolean"}
RESERVED = {"begin", "end", "type", "result", "string", "file", "label", "mod", "repeat", "function", "unit", "set", "out"}


def map_type(c_type: str) -> str | None:
    c_type = " ".join(c_type.replace("SDL_PRINTF_FORMAT_STRING ", "").split())
    if c_type in TYPE_MAP:
        return TYPE_MAP[c_type]
    c_type = c_type.replace("const ", "")
    if c_type in TYPE_MAP:
        return TYPE_MAP[c_type]
    if c_type.endswith(" *"):
        inner = c_type[:-2].strip()
        if inner in SCALAR_POINTERS:
            return SCALAR_POINTERS[inner]
        mapped = map_type(inner)
        return "P" + (mapped or inner)
    return c_type


def funcs(header: str) -> None:
    text = re.sub(r",\s*\n\s*", ", ", pins.header(pins.SDL, header))
    pattern = re.compile(r"extern SDL_DECLSPEC\s+(.+?)\s+SDLCALL\s+(SDL_\w+)\s*\((.*?)\)\s*;", re.S)
    for match in pattern.finditer(text):
        ret, name, args = " ".join(match.group(1).split()), match.group(2), match.group(3).strip()
        params = []
        varargs = "..." in args
        args = args.replace(", ...", "").replace("...", "")
        if args and args != "void":
            for arg in filter(None, (a.strip() for a in args.split(","))):
                parts = arg.split()
                param = parts[-1]
                stars = len(param) - len(param.lstrip("*"))
                param = param.lstrip("*")
                if param.lower() in RESERVED:
                    param += "_"
                params.append(f"{param}: {map_type(' '.join(parts[:-1]) + ' *' * stars)}")
        plist = "; ".join(params)
        conv = " cdecl varargs" if varargs else " cdecl"
        result = map_type(ret)
        if result is None:
            print(f"procedure {name}({plist});{conv}; external SDL_LIB_NAME;")
        else:
            print(f"function {name}({plist}): {result};{conv}; external SDL_LIB_NAME;")


def defines(header: str, prefix: str) -> None:
    pattern = re.compile(rf"#define\s+({prefix}\w+)\s+(.+)")
    for match in pattern.finditer(pins.header(pins.SDL, header)):
        value = match.group(2).split("/**")[0].strip()
        value = re.sub(r"(?<=[0-9a-fA-F])[uU]+\b", "", value)
        if value.startswith("0x"):
            value = "$" + value[2:]
        print(f"  {match.group(1)} = {value};")


def main() -> int:
    if len(sys.argv) >= 3 and sys.argv[1] == "funcs":
        funcs(sys.argv[2])
    elif len(sys.argv) >= 4 and sys.argv[1] == "defines":
        defines(sys.argv[2], sys.argv[3])
    else:
        print(__doc__.strip(), file=sys.stderr)
        return 2
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
