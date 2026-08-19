# Getting started

This library is a 1-to-1 C-to-Pascal mapping. Your program calls the SDL names (`SDL_Init`, `IMG_LoadTexture`, …). It does not wrap them in classes or Delphi `string` helpers.

First supported target: **Delphi 11+ Win64**.

## 1. Get the units

Clone or vendor [libsdl3-pascal](https://github.com/panjunbiao/libsdl3-pascal) and point the compiler at `src`:

- Delphi: Project → Options → Delphi Compiler → Search path → add `libsdl3-pascal\src` (needed for both `.pas` and `.inc`).
- Command line:

```
dcc64 -Upath\to\libsdl3-pascal\src -Ipath\to\libsdl3-pascal\src myapp.dpr
```

`uses SDL3` for the core. Add `SDL3_image`, `SDL3_ttf`, and/or `SDL3_mixer` only if you call those APIs.

## 2. Ship the official DLLs

Download the matching official Windows x64 zips and put the DLLs next to your `.exe` (or on `PATH`):

| Unit | Pin | Download |
|---|---|---|
| `SDL3` | 3.4.14 | [SDL release-3.4.14](https://github.com/libsdl-org/SDL/releases/tag/release-3.4.14) |
| `SDL3_image` | 3.4.4 | [SDL_image release-3.4.4](https://github.com/libsdl-org/SDL_image/releases/tag/release-3.4.4) |
| `SDL3_ttf` | 3.2.2 | [SDL_ttf release-3.2.2](https://github.com/libsdl-org/SDL_ttf/releases/tag/release-3.2.2) |
| `SDL3_mixer` | 3.2.4 | [SDL_mixer release-3.2.4](https://github.com/libsdl-org/SDL_mixer/releases/tag/release-3.2.4) |

PNG also needs `libpng16-16.dll` from the image zip’s `optional` folder. Keep each zip’s `LICENSE.txt` with redistributed binaries.

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

`examples/hello` is this program with a version check. `examples/draw` adds a renderer. `examples/gameloop` is a Delphi Win64 `.dproj`. `examples/satellites` loads JPEG/PNG, draws Latin and Chinese, and loops an MP3.

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

Set `SDL_HINT_*` constants from `SDL3` before `SDL_Init` when you need them.

## 5. What not to expect

- No classes, interfaces, or `string` wrappers.
- No `SDL_gpu` / camera / haptic device APIs in this tag.
- `SDL3_mixer` is the SDL3 `MIX_*` API, not SDL2 `Mix_*`.
- GPU image loaders and the TTF GPU text engine are skipped (they need `SDL_GPUDevice`).
