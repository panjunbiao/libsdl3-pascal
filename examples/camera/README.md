# camera

Open the first camera with `SDL_OpenCamera` and copy each frame into a streaming texture. If no camera is connected, or permission is still pending, the window says so and stays open until you close it.

## Build

Put `SDL3.dll` (3.4.16) next to the executable, or on `PATH`. From the repository root, `powershell -File tools\fetch-dlls.ps1` downloads the official DLL into this folder.

```
dcc64 "-U..\..\src" "-I..\..\src" camera.dpr
```
