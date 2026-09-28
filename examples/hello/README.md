# hello

Minimal Delphi Win64 program: `SDL_SetMainReady`, `SDL_Init(SDL_INIT_VIDEO)`, create a window, poll until quit.

## Build

Put `SDL3.dll` (3.4.16) next to the executable, or on `PATH`. From the repository root, `powershell -File tools\fetch-dlls.ps1` downloads the official DLL into this folder. Official binaries: https://github.com/libsdl-org/SDL/releases/tag/release-3.4.16

From the `src` directory on the compiler unit path:

```
dcc64 "-U..\..\src" "-I..\..\src" hello.dpr
```

Or add `libsdl3-pascal\src` to the Delphi project's search path and compile `hello.dpr`.
