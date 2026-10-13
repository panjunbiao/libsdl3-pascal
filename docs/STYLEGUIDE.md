# Binding style guide

The units must read as a literal C-to-Pascal mapping of SDL 3. Higher-level code (classes, `string` helpers, engines such as Lumina2D) belongs in separate projects that `uses SDL3`.

## Files

- One unit per C library: `SDL3.pas`, and optional satellites `SDL3_image.pas`, `SDL3_ttf.pas`, `SDL3_mixer.pas`. Applications write `uses SDL3` plus the satellites they need.
- One include per C header: `SDL_video.h` → `SDL_video.inc`. Satellite headers become `SDL_image.inc`, `SDL_ttf.inc`, `SDL_mixer.inc`. `SDL_textengine.inc` is included inside the type section of `SDL_ttf.inc`, because `TTF_Text` and `TTF_TextEngine` refer to each other.
- Includes live next to their unit and are pulled in from the `interface` section.
- Implementations of C inline helpers (`SDL_FORCE_INLINE`) go in `SDL_xxx.impl.inc`, included from `implementation`.
- Each unit has its own `SDL_*_LIB_NAME` `{$IFDEF}` split (`SDL3.dll`, `SDL3_image.dll`, …).
- No Pascal `string` or class API.

## Names

Keep C identifiers:

| C | Pascal |
|---|---|
| `SDL_Init` | `SDL_Init` |
| `SDL_EVENT_QUIT` | `SDL_EVENT_QUIT` |
| `SDL_INIT_VIDEO` | `SDL_INIT_VIDEO` |
| `SDL_Window` (opaque struct) | `SDL_Window = record end` |
| `SDL_Window *` | `PSDL_Window = ^SDL_Window` |
| `const char *` | `PUTF8Char` |
| `bool` | `Boolean` |
| `void *` | `Pointer` |
| `size_t` | `NativeUInt` |
| `Uint32` / `Sint32` / … | `Uint32` / `Sint32` / … (aliases of `Cardinal` / `Integer` / `Byte` / …). Do not write `Uint8 = UInt8`; Pascal type names are case-insensitive. |

Do not prefix types with `T` unless a collision forces it. Pascal reserved words get a trailing `_` (`type` → `type_`, `string` → `string_`, `label` → `label_`). When two C functions differ only by case, keep the existing declaration and bind the other with a trailing `_` plus `name`: math `SDL_log` is `SDL_log_` because `SDL_Log` is the logger.

## Calling convention and linking

```pascal
function SDL_Init(flags: SDL_InitFlags): Boolean; cdecl;
  external SDL_LIB_NAME;
```

- Every `SDLCALL` function and callback is `cdecl`.
- Library name:

```pascal
{$IFDEF MSWINDOWS}
  SDL_LIB_NAME = 'SDL3.dll';
{$ELSE}
  {$IFDEF DARWIN}
  SDL_LIB_NAME = 'libSDL3.dylib';
  {$ELSE}
    {$IFDEF MACOS}
  SDL_LIB_NAME = 'libSDL3.dylib';
    {$ELSE}
  SDL_LIB_NAME = 'libSDL3.so';
    {$ENDIF}
  {$ENDIF}
{$ENDIF}
```

Satellite units use the same split with `SDL_IMAGE_LIB_NAME`, `SDL_TTF_LIB_NAME`, and `SDL_MIXER_LIB_NAME`. Do not use the `Windows` unit in these units. OS handles that are not declared here (`MSG`, `JNIEnv`, `XTaskQueueHandle`) stay `Pointer`.

## ABI

- `{$MINENUMSIZE 4}` / `{$Z4}`: SDL enums are `int`-sized.
- C `bool` is 1-byte `Boolean`. Never `LongBool` (that was SDL2 `SDL_bool`).
- Records are **not** `packed`. On Win64, SDL uses 8-byte struct packing (`#pragma pack(push,8)`). Each unit pins `{$ALIGN 8}` (Delphi) / `{$PACKRECORDS C}` (Free Pascal) so a project's alignment option cannot change it. Confirm with the C oracle on every platform ([ABI.md](ABI.md)).
- Each unit also pins `{$BOOLEVAL OFF}` (the helpers rely on short-circuit `nil` tests) and `{$EXTENDEDSYNTAX ON}`.
- `SDL_Event` is a variant record with a 128-byte padding arm. `SizeOf(SDL_Event)` must be 128.
- Opaque C structs become empty records plus a pointer type.
- Callbacks are `cdecl` function types.

## Constants and macros

- `#define SDL_INIT_VIDEO 0x00000020u` → `SDL_INIT_VIDEO = $00000020;`
- Version macros (`SDL_VERSION`, `SDL_VERSION_ATLEAST`) become Pascal functions or typed constants in `SDL_version.inc`.
- Skip include guards, `SDL_begin_code.h` noise, and `SDL_oldnames.h`.

## Strings and varargs

- No conversion to `string` / `UnicodeString` / `UTF8String`.
- Variadic C functions (`SDL_Log`, `SDL_SetError`): bind the non-variadic form where one exists (`SDL_LogMessage`). Add `cdecl varargs` only where the compiler accepts it. The `va_list` variants stay unbound (see [ABI.md](ABI.md)).

## Entry point (Delphi on Windows)

Delphi supplies `WinMain`. Applications must call `SDL_SetMainReady` before `SDL_Init` (the `SDL_MAIN_HANDLED` model). Do not rewrite the process entry point. `SDL3` sets `IsMultiThread := True` in its `initialization` section: SDL starts threads with `CreateThread`, and the Delphi memory manager only locks its heap when that flag is set. `SDL_main.inc` also declares `SDL_RunApp`, `SDL_EnterAppMainCallbacks`, `SDL_RegisterApp`, `SDL_UnregisterApp`, and `SDL_GDKSuspendComplete`. The C `SDL_main` rewrite macros stay out.

## Language subset

Supported today: **Delphi 11+ on Windows x64**. Free Pascal and other platforms are in progress; see the open issues.

Write code both compilers accept: no inline variables, no Delphi-only attributes, `{$IFDEF FPC}` only when unavoidable. A platform or compiler is claimed only after its ABI check and smoke tests pass ([ABI.md](ABI.md)).

## Comments

Short notes are fine when Pascal cannot express a C idiom. Do not paste the SDL wiki into every declaration; point to https://wiki.libsdl.org/SDL3/ when a function needs explanation.

## Out of scope

- Classes, interfaces, exceptions wrapping `SDL_GetError`.
- Automatic `string` marshaling.
- Dynamic `LoadLibrary` wrappers.
- Shipping a custom SDL build. Use the official binaries from [libsdl.org](https://www.libsdl.org/).
