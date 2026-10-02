# draw

Minimal renderer program: `SDL_CreateWindowAndRenderer`, clear to a dark color, draw a filled rectangle with `SDL_RenderFillRect`, and quit on Esc or window close.

## Build

Put `SDL3.dll` (3.4.16) next to the executable, or on `PATH`. From the repository root, `powershell -File tools\fetch-dlls.ps1` downloads the official DLL into this folder. Official binaries: https://github.com/libsdl-org/SDL/releases/tag/release-3.4.16

From the `src` directory on the compiler unit path:

```
dcc64 "-U..\..\src" "-I..\..\src" draw.dpr
```

Or add `libsdl3-pascal\src` to the Delphi project's search path and compile `draw.dpr`.
