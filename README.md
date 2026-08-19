# libsdl3-pascal

1-to-1 Pascal bindings for [Simple DirectMedia Layer 3](https://www.libsdl.org/) (Delphi and Free Pascal / Lazarus).

This library translates the SDL3 C API. It does not add classes, `string` helpers, or a game engine. Applications write `uses SDL3` and call the C names (`SDL_Init`, `SDL_CreateWindow`, …).

## Status

Early scaffolding. The 2D-core headers are stubbed; translation starts with foundation + video + events. Header version pin: **SDL 3.5.0**.

## Requirements

- Delphi 11+ (Win64 is the first supported target) or FPC 3.2+
- Official `SDL3.dll` / `libSDL3.dylib` / `libSDL3.so` from [libsdl.org](https://www.libsdl.org/) matching SDL 3.5

On Delphi Windows, call `SDL_SetMainReady` before `SDL_Init`.

## Layout

```
src/SDL3.pas     main unit
src/SDL_*.inc    one include per C header
examples/        sample programs (coming)
```

## License

zlib — see [LICENSE](LICENSE). Same terms as SDL.
