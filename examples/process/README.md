# process

Start `cmd.exe /c echo ...` with `SDL_CreateProcess`, read its stdout with `SDL_ReadProcess`, and measure that buffer with `SDL_strlen`. `SDL_free` releases the buffer.

## Build

Put `SDL3.dll` (3.4.14) next to the executable, or on `PATH`.

```
dcc64 -U..\..\src -I..\..\src process.dpr
```
