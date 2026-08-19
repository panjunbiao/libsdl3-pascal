# libsdl3-pascal

1-to-1 Pascal bindings for [Simple DirectMedia Layer 3](https://www.libsdl.org/).

The first release targets **Delphi 11+ Win64**. Free Pascal / Lazarus and macOS / Android / iOS are planned later.

This library translates the SDL3 C API. It does not add classes, `string` helpers, or a game engine. Applications write `uses SDL3` and call the C names (`SDL_Init`, `SDL_CreateWindow`, …).

## Status

Phase 5: remaining 2D / 2.5D SDL3 headers are translated (threads, storage, dialogs, pen events, Windows `SDL_system` subset). Header version pin: **SDL 3.5.0**. First release is **Delphi 11+ Win64**.

See `examples/hello` for a window that polls until quit, and `examples/draw` for clear + filled rectangle (Escape or close to quit). See `tests/abi` for `SizeOf` checks (`SDL_Event` must be 128, `SDL_Surface` is 48 on Win64).

## Requirements

- Delphi 11+ Win64 (first supported target)
- Official `SDL3.dll` from [libsdl.org](https://www.libsdl.org/) matching SDL 3.5

On Delphi Windows, call `SDL_SetMainReady` before `SDL_Init`.

## Layout

```
src/SDL3.pas     main unit
src/SDL_*.inc    one include per C header
examples/hello   window + quit
examples/draw    clear + filled rectangle
tests/abi        SizeOf checks
```

## License

zlib — see [LICENSE](LICENSE). Same terms as SDL.
