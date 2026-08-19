# libsdl3-pascal

1-to-1 Pascal bindings for [Simple DirectMedia Layer 3](https://www.libsdl.org/).

**v1.0.0** binds SDL **3.4.14** for **Delphi 11+ Win64**. Free Pascal / Lazarus and macOS / Android / iOS are planned later.

This library translates the SDL3 C API. It does not add classes, `string` helpers, or a game engine. Applications write `uses SDL3` and call the C names (`SDL_Init`, `SDL_CreateWindow`, …).

## Status

First public release: **v1.0.0**. Header pin: **SDL 3.4.14**. Supported target: **Delphi 11+ Win64**.

See `examples/hello` for a window that polls until quit, `examples/draw` for a filled rectangle, and `examples/gameloop` for a Delphi Win64 `.dproj` (timestep, WASD/arrows, optional gamepad, generated texture). See `tests/abi` for `SizeOf` checks (`SDL_Event` must be 128, `SDL_Surface` is 48 on Win64).

## Requirements

- Delphi 11+ Win64 (first supported target)
- Official `SDL3.dll` from [libsdl.org](https://www.libsdl.org/) matching [SDL 3.4.14](https://github.com/libsdl-org/SDL/releases/tag/release-3.4.14)

On Delphi Windows, call `SDL_SetMainReady` before `SDL_Init`.

After the DLL loads, compare `SDL_GetVersion` to `SDL_VERSION`. Refuse a different major, or a runtime older than this pin (`3.4.14`). A newer 3.x DLL should run; this binding does not declare APIs added after 3.4.14.

## Layout

```
src/SDL3.pas     main unit
src/SDL_*.inc    one include per C header
examples/hello     window + quit
examples/draw      clear + filled rectangle
examples/gameloop  Delphi Win64 game-loop project
tests/abi          SizeOf checks
```

## License

zlib — see [LICENSE](LICENSE). Same terms as SDL.
