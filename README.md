# libsdl3-pascal

1-to-1 Pascal bindings for [Simple DirectMedia Layer 3](https://www.libsdl.org/).

**v1.1.0** binds SDL **3.4.14** plus optional satellites for **Delphi 11+ Win64**. Free Pascal / Lazarus and macOS / Android / iOS are planned later.

This library translates the C APIs. It does not add classes, `string` helpers, or a game engine. Applications write `uses SDL3` (and `SDL3_image` / `SDL3_ttf` / `SDL3_mixer` if needed) and call the C names (`SDL_Init`, `IMG_LoadTexture`, `TTF_OpenFont`, `MIX_PlayTrack`, …).

## Status

Header pins:

| Unit | Upstream | Pin | DLL |
|---|---|---|---|
| `SDL3` | [SDL](https://github.com/libsdl-org/SDL) | **3.4.14** | `SDL3.dll` |
| `SDL3_image` | [SDL_image](https://github.com/libsdl-org/SDL_image) | **3.4.4** | `SDL3_image.dll` |
| `SDL3_ttf` | [SDL_ttf](https://github.com/libsdl-org/SDL_ttf) | **3.2.2** | `SDL3_ttf.dll` |
| `SDL3_mixer` | [SDL_mixer](https://github.com/libsdl-org/SDL_mixer) | **3.2.4** | `SDL3_mixer.dll` (`MIX_*`, not SDL2 `Mix_*`) |

Supported target: **Delphi 11+ Win64**. GPU device APIs stay out (`SDL_CreateGPURenderer`, `IMG_LoadGPUTexture*`, TTF GPU text engine).

See `examples/hello` for a window that polls until quit, `examples/draw` for a filled rectangle, `examples/gameloop` for a Delphi Win64 `.dproj` (timestep, WASD/arrows, optional gamepad, generated texture), and `examples/satellites` for image / font / mixer smoke. See `tests/abi` for `SizeOf` checks (`SDL_Event` must be 128, `SDL_Surface` is 48 on Win64).

## Requirements

- Delphi 11+ Win64 (first supported target)
- Official `SDL3.dll` from [libsdl.org](https://www.libsdl.org/) matching [SDL 3.4.14](https://github.com/libsdl-org/SDL/releases/tag/release-3.4.14)
- For satellites, the matching official DLLs: [SDL_image 3.4.4](https://github.com/libsdl-org/SDL_image/releases/tag/release-3.4.4), [SDL_ttf 3.2.2](https://github.com/libsdl-org/SDL_ttf/releases/tag/release-3.2.2), [SDL_mixer 3.2.4](https://github.com/libsdl-org/SDL_mixer/releases/tag/release-3.2.4)

On Delphi Windows, call `SDL_SetMainReady` before `SDL_Init`.

After the DLLs load, compare `SDL_GetVersion` to `SDL_VERSION` (and `IMG_Version` / `TTF_Version` / `MIX_Version` to the matching `SDL_*_VERSION`). Refuse a different major, or a runtime older than the pin. A newer 3.x DLL should run; this binding does not declare APIs added after these pins.

`SDL_HINT_*` string constants are in `SDL3` (set them before `SDL_Init`).

## Layout

```
src/SDL3.pas          core unit
src/SDL3_image.pas    optional SDL_image
src/SDL3_ttf.pas      optional SDL_ttf
src/SDL3_mixer.pas    optional SDL_mixer
src/SDL_*.inc         one include per C header
examples/hello        window + quit
examples/draw         clear + filled rectangle
examples/gameloop     Delphi Win64 game-loop project
examples/satellites   JPEG/PNG + TTF + MP3 smoke
tests/abi             SizeOf checks
```

## License

zlib — see [LICENSE](LICENSE). Same terms as SDL. Example media and fonts have their own licenses; see `examples/satellites/CREDITS.md`.
