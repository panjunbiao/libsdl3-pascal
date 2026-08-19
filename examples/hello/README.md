# hello

Minimal Delphi Win64 program: `SDL_SetMainReady`, `SDL_Init(SDL_INIT_VIDEO)`, create a window, poll until quit.

## Build

Put `SDL3.dll` (3.5.x) next to the executable, or on `PATH`. Official binaries: https://www.libsdl.org/

From the `src` directory on the compiler unit path:

```
dcc64 -U..\..\src hello.dpr
```

Or add `libsdl3-pascal\src` to the Delphi project's search path and compile `hello.dpr`.
