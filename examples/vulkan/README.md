# vulkan

Create a Vulkan window, load the Vulkan loader with `SDL_Vulkan_LoadLibrary`, and print the instance extensions from `SDL_Vulkan_GetInstanceExtensions`. This does not create a `VkInstance`.

`SDL_Metal_CreateView` is the same kind of platform glue on macOS. It is declared in `SDL3`, and this Win64 example does not call it.

The program exits with an error if `vulkan-1.dll` is not installed.

## Build

Put `SDL3.dll` (3.4.16) next to the executable, or on `PATH`. From the repository root, `powershell -File tools\fetch-dlls.ps1` downloads the official DLL into this folder.

```
dcc64 "-U..\..\src" "-I..\..\src" vulkan.dpr
```
