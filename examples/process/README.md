# process

Start `cmd.exe /c echo ...` with `SDL_CreateProcess`, read its stdout with `SDL_ReadProcess`, and measure that buffer with `SDL_strlen`. `SDL_free` releases the buffer.

## Build

Put `SDL3.dll` (3.4.16) next to the executable, or on `PATH`. From the repository root, `powershell -File tools\fetch-dlls.ps1` downloads the official DLL into this folder.

```
dcc64 "-U..\..\src" "-I..\..\src" process.dpr
```
