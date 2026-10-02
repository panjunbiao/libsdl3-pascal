# camera

Open the first camera with `SDL_OpenCamera` and copy each frame into a streaming texture. If no camera is connected, or permission is still pending, the window says so and stays open until you close it.

A `nil` spec gets the camera's largest mode, whatever its frame rate, and on some webcams that mode runs at 2 fps. So the example reads `SDL_GetCameraSupportedFormats` and picks what a video call would use: 30 fps first, then the largest size up to 1280x720, then any format over MJPG, which `SDL_UpdateTexture` has to decode. `MinFps` and `MaxArea` set the target. The console shows SDL's choice and the mode used. The title bar shows how many frames per second are drawn.

Each pass draws only the newest frame, so the picture does not fall behind the camera, and vsync paces the loop. If the rate still drops in a dim room, the camera is lengthening its exposure; more light brings it back.

## Build

Put `SDL3.dll` (3.4.16) next to the executable, or on `PATH`. From the repository root, `powershell -File tools\fetch-dlls.ps1` downloads the official DLL into this folder.

```
dcc64 "-U..\..\src" "-I..\..\src" camera.dpr
```
