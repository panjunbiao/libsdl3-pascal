# Getting started

This library is a 1-to-1 C-to-Pascal mapping. Your program calls the SDL names (`SDL_Init`, `IMG_LoadTexture`, …). It does not wrap them in classes or Delphi `string` helpers.

First supported target: **Delphi 11+ Win64**.

## 1. Get the units

Clone or vendor [libsdl3-pascal](https://github.com/panjunbiao/libsdl3-pascal) and point the compiler at `src`:

- Delphi: Project → Options → Delphi Compiler → Search path → add `libsdl3-pascal\src` (needed for both `.pas` and `.inc`).
- Command line:

```
dcc64 "-Upath\to\libsdl3-pascal\src" "-Ipath\to\libsdl3-pascal\src" myapp.dpr
```

Quote each switch together with its path. `dcc64` ends a switch at `.`, so `-U..\..\src` is read as an empty search path plus a project named `..\..\src.dpr` (`F1026`).

`uses SDL3` for the core. Add `SDL3_image`, `SDL3_ttf`, and/or `SDL3_mixer` only if you call those APIs.

## 2. Ship the official DLLs

The units do not include binaries. From the repository root:

```
powershell -File tools\fetch-dlls.ps1
```

That downloads the pinned official Windows x64 zips, checks each one against the SHA-256 pinned in the script, and copies `SDL3.dll` next to each example. `examples/satellites` also gets `SDL3_image.dll`, `SDL3_ttf.dll`, `SDL3_mixer.dll`, and the optional decoder DLLs (PNG needs `libpng16-16.dll`). If an example already has a `Win64\Debug` or `Win64\Release` folder, the same files are copied there too.

One application directory, including the satellite DLLs:

```
powershell -File tools\fetch-dlls.ps1 -Dest path\to\your\exe\folder
```

The script copies each zip’s `LICENSE.txt` when you pass `-Dest` (`LICENSE.SDL3.txt`, and the satellite names). Keep those licenses if you redistribute the binaries. The downloaded zips stay in `.cache\dlls`. A cached zip that no longer matches its hash is downloaded again, and a download that does not match stops the script.

The same official releases, if you download them yourself:

| Unit | Pin | Download |
|---|---|---|
| `SDL3` | 3.4.16 | [SDL release-3.4.16](https://github.com/libsdl-org/SDL/releases/tag/release-3.4.16) |
| `SDL3_image` | 3.4.4 | [SDL_image release-3.4.4](https://github.com/libsdl-org/SDL_image/releases/tag/release-3.4.4) |
| `SDL3_ttf` | 3.2.2 | [SDL_ttf release-3.2.2](https://github.com/libsdl-org/SDL_ttf/releases/tag/release-3.2.2) |
| `SDL3_mixer` | 3.2.4 | [SDL_mixer release-3.2.4](https://github.com/libsdl-org/SDL_mixer/releases/tag/release-3.2.4) |

PNG also needs `libpng16-16.dll` from the image zip’s `optional` folder.

Do not mix a newer header pin with an older DLL. After the process starts:

```pascal
Linked := SDL_GetVersion;
if SDL_VERSIONNUM_MAJOR(Linked) <> SDL_MAJOR_VERSION then
  { refuse: different major }
else if Linked < SDL_VERSION then
  { refuse: older than this pin }
```

Use `IMG_Version` / `TTF_Version` / `MIX_Version` the same way against `SDL_IMAGE_VERSION` / `SDL_TTF_VERSION` / `SDL_MIXER_VERSION`. A newer 3.x DLL should run; this binding does not declare APIs added after the pins above.

## 3. First window

On Delphi Windows, call `SDL_SetMainReady` before `SDL_Init` (the `SDL_MAIN_HANDLED` model). Delphi already supplies `WinMain`.

```pascal
program hello;

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  Window: PSDL_Window;
  Event: SDL_Event;
  Running: Boolean;
begin
  SDL_SetMainReady;
  if not SDL_Init(SDL_INIT_VIDEO) then
    Halt(1);
  Window := SDL_CreateWindow('hello', 640, 480, 0);
  if Window = nil then
    Halt(1);
  Running := True;
  while Running do
  begin
    while SDL_PollEvent(@Event) do
      if Event.type_ = Uint32(SDL_EVENT_QUIT) then
        Running := False;
    SDL_Delay(16);
  end;
  SDL_DestroyWindow(Window);
  SDL_Quit;
end.
```

`examples/hello` is this program with a version check. `examples/draw` adds a renderer. `examples/gameloop` is the Win64 game-loop program. `examples/satellites` loads JPEG/PNG, draws Latin and Chinese, and loops an MP3.

## 4. Names and strings

Keep C identifiers. Reserved Pascal words get a trailing `_` (`type_` , `file_`, `string_`).

`const char *` is `PUTF8Char`. SDL_ttf expects UTF-8. A Delphi `UnicodeString` (including a UTF-8 `.dpr` with BOM) must be converted before the call:

```pascal
var
  Utf8: UTF8String;
begin
  Utf8 := UTF8String('你好，世界');
  TTF_CreateText(Engine, Font, PUTF8Char(Utf8), Length(Utf8));
end;
```

Do not write `UTF8String(#$E4#$BD#$A0…)`: `#$E4` is U+00E4, and `UTF8String()` encodes it again. See `examples/satellites/satellites.dpr` for a raw-byte version that does not depend on the source code page.

Functions with a C `...` parameter (`SDL_Log`, `SDL_SetError`, `SDL_snprintf`, …) are declared `cdecl varargs`, and the compiler does not convert the extra arguments. A Delphi string there is passed as UTF-16, so `SDL_Log('%s', 'text')` prints only `t`. Pass `PUTF8Char(UTF8String(S))` for `%s`. `Integer`, `Int64`, `Single`, and `Double` arguments arrive the way C expects them.

`SDL_INIT_INTERFACE` is overloaded on the pointer type (`PSDL_IOStreamInterface`, `PSDL_VirtualJoystickDesc`, `PSDL_StorageInterface`, `PTTF_TextEngine`). Pass a typed pointer, for example `SDL_INIT_INTERFACE(PSDL_IOStreamInterface(@Iface))`. With the default `{$T-}`, `@Iface` is an untyped `Pointer` and the call is ambiguous (`E2251`).

Set `SDL_HINT_*` constants from `SDL3` before `SDL_Init` when you need them.

## 5. Callbacks and threads

A callback is a `cdecl` routine with the C parameter list, such as `SDL_TimerCallback` or `SDL_AudioStreamCallback`. SDL calls some callbacks on its own threads: timers, audio stream callbacks, the function passed to `SDL_CreateThread`, and event watchers when another thread pushes an event.

- `SDL3` sets `IsMultiThread := True` when it is initialized. SDL starts threads with `CreateThread`, and the Delphi memory manager only locks its heap when that flag is set.
- Do not let an exception escape a callback. SDL's C code cannot handle it, so catch it inside the callback.
- Do not call VCL or FMX from those threads. `SDL_RunOnMainThread` runs a callback on the main thread.

## 6. What not to expect

- No classes, interfaces, or `string` wrappers.
- `SDL3_mixer` is the SDL3 `MIX_*` API, not SDL2 `Mix_*`.
- GPU, camera, haptic, and the other 3.4.16 headers are declared. A declaration for Android, iOS, or Metal is not a claim that those platforms run.
- `SDL_net`, Khronos GL/EGL dumps, and SDL’s C test headers are not part of this binding.
