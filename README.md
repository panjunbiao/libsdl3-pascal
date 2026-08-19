# libsdl3-pascal

1-to-1 Pascal bindings for [Simple DirectMedia Layer 3](https://www.libsdl.org/) (Delphi and Free Pascal / Lazarus).

This library translates the SDL3 C API. It does not add classes, `string` helpers, or a game engine. Applications write `uses SDL3` and call the C names (`SDL_Init`, `SDL_CreateWindow`, …).

## Status

Phase 3: audio, timer, filesystem, iostream, gamepad/joystick, clipboard, and touch are translated. Header version pin: **SDL 3.5.0**.

See `examples/hello` for a window that polls until quit, and `examples/draw` for clear + filled rectangle (Escape or close to quit). See `tests/abi` for `SizeOf` checks (`SDL_Event` must be 128, `SDL_Surface` is 48 on Win64).

## Requirements

- Delphi 11+ (Win64 is the first supported target) or FPC 3.2+
- Official `SDL3.dll` / `libSDL3.dylib` / `libSDL3.so` from [libsdl.org](https://www.libsdl.org/) matching SDL 3.5

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
