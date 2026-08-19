# hello

Minimal Delphi Win64 program: `SDL_SetMainReady`, `SDL_Init(SDL_INIT_VIDEO)`, create a window, poll until quit.

## Build

Put `SDL3.dll` (3.4.14) next to the executable, or on `PATH`. Official binaries: https://github.com/libsdl-org/SDL/releases/tag/release-3.4.14

From the `src` directory on the compiler unit path:

```
dcc64 -U..\..\src hello.dpr
```

Or add `libsdl3-pascal\src` to the Delphi project's search path and compile `hello.dpr`.
