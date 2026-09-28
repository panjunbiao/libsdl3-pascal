# gpu

Clear a window with `SDL_CreateGPUDevice` and a render pass. There are no shaders: the pass only clears the swapchain to a color that changes with `SDL_sin`.

Escape or close the window to quit. If no GPU backend can be created, the program prints `SDL_GetError` and exits.

## Build

Put `SDL3.dll` (3.4.14) next to the executable, or on `PATH`.

```
dcc64 -U..\..\src -I..\..\src gpu.dpr
```
