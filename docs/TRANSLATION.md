# Translation method

Units are **hand-written** from the official C headers at the pinned tags ([UPSTREAM.md](UPSTREAM.md)). `SDL3.pas` is not generated with Chet, c2pas, or a custom parser.

## Why not a generator

Generators fail exactly where a binding must be right: unions, packing, enum size, C `bool`, callbacks, and header macros. A generator would also become a second project. Draft tools may produce a first pass; the committed Pascal is what ships, and it is checked by hand.

## Per-header workflow

1. Read the C header at the pinned tag, for example `git -C ../SDL show release-3.4.16:include/SDL3/SDL_video.h`.
2. Write or update `src/SDL_video.inc`.
3. Convert syntax only. Keep C names, parameter order, and types ([STYLEGUIDE.md](STYLEGUIDE.md)).
4. Skip include guards and `SDL_begin_code.h` / `SDL_close_code.h`. Bind `SDL_stdinc` exports except the `va_list` variants. On Win64, C `long` is `Integer`; check other platforms with the oracle.
5. Turn `SDL_FORCE_INLINE` helpers into Pascal functions in `SDL_xxx.impl.inc`.
6. Rename C identifiers that are Pascal reserved words by appending `_` (`type` → `type_`, `mod` → `mod_`, `repeat` → `repeat_`, `file` → `file_`, `result` → `result_`, `string` → `string_`).
7. Skip a C macro when its name collides with a type on case-insensitive Pascal (for example `SDL_PIXELTYPE()` vs `SDL_PixelType`), and note the skip in a comment.
8. Run `python3 tools/check_coverage.py`: every app-callable `SDL_DECLSPEC` must be declared, or listed as a deliberate skip in `tools/pins.py`.
9. Add every new public struct to the C ABI oracle and to `tests/abi` ([ABI.md](ABI.md)).

## Assistive tools

These help, but do not write the binding:

- `tools/check_coverage.py`: declared vs. pinned function names.
- `tools/diff_upstream.py`: function names added or removed between two SDL tags.
- `tools/draft_decls.py`: first-draft declarations for one header, to be checked by hand.
- `tools/abi-oracle/oracle.c`: `sizeof` / `offsetof` from the C compiler.

## Source of truth

The committed Pascal is the source of truth. Anything drafted by a tool, a script, or an AI agent is audited against the header and this guide before it is committed.
