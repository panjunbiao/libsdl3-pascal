# Agent brief

You are working on libsdl3-pascal: a literal 1-to-1 mapping of SDL 3's C API to Pascal. Read [CONTRIBUTING.md](CONTRIBUTING.md) first; this page is the short version.

## Rules

1. **Match the C headers at the pinned tags exactly.** Pins are in [tools/pins.py](tools/pins.py) and [docs/UPSTREAM.md](docs/UPSTREAM.md). Read headers with `git -C ../SDL show <tag>:include/SDL3/<header>`, never from whatever branch a clone has checked out.
2. **Keep C names, parameter order, and types** as mapped in [docs/STYLEGUIDE.md](docs/STYLEGUIDE.md). No classes, no `string` helpers, no wrappers, no APIs newer than the pin.
3. **Never claim a platform or compiler that has not passed its checks** ([docs/ABI.md](docs/ABI.md)): C ABI oracle, `tests/abi`, link and version check, smoke examples, on that platform with an official SDL binary.
4. **Do not trust layout from memory.** Struct sizes and offsets come from the C ABI oracle compiled on the target platform. Win64 numbers are not universal.
5. **Do not change project-option pins** at the top of each unit (`{$ALIGN 8}` / `{$PACKRECORDS C}`, `{$MINENUMSIZE 4}`, `{$BOOLEVAL OFF}`, `{$EXTENDEDSYNTAX ON}`) unless the task is about them.
6. **Drafted code is not done code.** Output of `tools/draft_decls.py` or your own drafts must be checked line by line against the header.

## Layout

| Path | Contents |
|---|---|
| `src/SDL3*.pas` | One unit per C library |
| `src/SDL_*.inc` | One include per C header; `*.impl.inc` for inline helpers |
| `tests/abi/` | Pascal ABI checker |
| `examples/` | Smoke programs and showcases |
| `tools/` | Pins, coverage check, upstream diff, header export, declaration drafts, C ABI oracle |
| `docs/` | Style guide, translation method, ABI checks, upstream pins, getting started |

## Commands

```
python3 tools/check_coverage.py                                  # 0 missing
python3 tools/diff_upstream.py <old-tag> <new-tag>               # function changes between SDL tags
python3 tools/export_headers.py SDL                              # pinned headers into .cache/headers/
clang -I .cache/headers/SDL-release-3.4.16/include tools/abi-oracle/oracle.c -o .cache/oracle && .cache/oracle
python3 tools/draft_decls.py funcs <header>                      # draft declarations, check by hand
```

Delphi on Windows: `dcc64 "-U..\..\src" "-I..\..\src" abi.dpr` in `tests/abi` (see each folder's README).

## Status

- **Supported:** Delphi 11+ on Windows x64, SDL 3.4.16 with SDL_image 3.4.4, SDL_ttf 3.2.2, SDL_mixer 3.2.4.
- **In progress or planned:** see the open issues (Free Pascal, macOS, Linux, Win32, mobile, newer pins).

## Done means

- The checks in [CONTRIBUTING.md](CONTRIBUTING.md#checks-before-a-pull-request) that apply to the change pass, on every platform the change claims.
- The pull request lists which checks ran where, and anything that could not be verified on the available machines.
