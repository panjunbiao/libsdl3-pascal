# ABI checks

The binding is correct when it matches the C ABI of the pinned headers ([UPSTREAM.md](UPSTREAM.md)) on each platform it claims, and can call the official SDL binaries.

## Layers

1. **C ABI oracle** ([tools/abi-oracle](../tools/abi-oracle/README.md)): a small C program compiled against the pinned headers that prints `sizeof` and `offsetof` for the public structs the binding declares. Its output is the source of truth for layout on that platform.
2. **Pascal ABI checker** (`tests/abi`): a program using the units that checks the same sizes, and the offsets of fields that sit after padding. It stops at the first mismatch. `SizeOf(SDL_Event)` must be 128.
3. **Link and version**: `SDL_GetVersion` against the official binary for the pin. Refuse a different major version, or a runtime older than `SDL_VERSION` ([UPSTREAM.md](UPSTREAM.md)).
4. **Smoke tests**: `examples/hello` and `examples/draw` (init, window, quit, renderer clear and present). They catch `Boolean` vs `LongBool`, a missing `cdecl` on a callback, and a missing `SDL_SetMainReady`.
5. **Coverage**: every app-callable `SDL_DECLSPEC` in the pinned headers is declared or deliberately skipped (`python3 tools/check_coverage.py`).

A new platform or compiler is claimed only after layers 1–4 pass on it with an official SDL binary.

## Platform differences

- **Packing:** `SDL_begin_code.h` uses `#pragma pack(push,8)` on Win64 for MSVC. Clang and GCC (macOS, Linux) use natural alignment.
- **C `long`:** 32-bit on Win64, 64-bit on macOS and Linux (LP64).
- **Expected values in `tests/abi` today are the MSVC x64 layouts.** Supporting another platform means generating its values with the oracle and checking the Pascal side against those, not reusing the Win64 numbers.

## Hard cases

- `SDL_Event` size and field offsets (the usual Pascal binding bug).
- Enum size: `{$MINENUMSIZE 4}`.
- Project options: each unit pins `{$ALIGN 8}` (Delphi) or `{$PACKRECORDS C}` (Free Pascal), `{$MINENUMSIZE 4}`, `{$BOOLEVAL OFF}` and `{$EXTENDEDSYNTAX ON}`. Without them a project built with `{$A4}` gets 4-byte field alignment, and `{$B+}` makes the `nil` checks in the helpers dereference `nil`.
- Records are not `packed` unless the C header uses a packed attribute (rare).
- C `bool` → `Boolean`, never `LongBool`.
- Opaque handles are pointers (`PSDL_Window`), not records passed by value.
- Callbacks are `cdecl`.
- Delphi Windows apps call `SDL_SetMainReady` before `SDL_Init`.

## Adding a struct

When a header adds or changes a public struct:

1. Add `SHOW_SIZE` (and `SHOW_OFF` for fields after padding) to `tools/abi-oracle/oracle.c`.
2. Run the oracle on each claimed platform.
3. Add the matching `Check` / `CheckOffset` lines to `tests/abi/abi.dpr`.

Satellite structs (`IMG_*`, `TTF_*`, `MIX_*`) are checked in `tests/abi` only, because the oracle includes `SDL.h`.

## Deliberately unbound

| Header or function | Why |
|---|---|
| `SDL_opengl.h`, `SDL_opengl_glext.h`, GLES, `SDL_egl.h` | Khronos headers SDL vendors. `SDL_GL_*` is in `SDL_video` |
| `SDL_test_*` | SDL's C test harness |
| `SDL_oldnames.h` | SDL2 aliases; they collide with SDL3 names on a case-insensitive compiler |
| `SDL_intrin.h`, `SDL_dlopennote.h`, `SDL_begin_code.h`, `SDL_close_code.h`, `SDL_revision.h`, `SDL_main_impl.h` | Compiler, loader, and include plumbing |
| `va_list` functions | `SDL_SetErrorV`, `SDL_LogMessageV`, `SDL_IOvprintf`, `SDL_vsscanf`, `SDL_vsnprintf`, `SDL_vswprintf`, `SDL_vasprintf` |
| `SDL_notification.h`, `SDL_openxr.h` | Not in the 3.4.16 pin |
