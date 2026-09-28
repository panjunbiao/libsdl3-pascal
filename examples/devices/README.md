# devices

Print the camera drivers (`SDL_GetNumCameraDrivers`), haptic devices, and HID devices. If a haptic device is present, it rumbles once for about half a second. The mouse is reported when `SDL_IsMouseHaptic` is true, and it is not rumble-tested.

No window. HID names are wide strings from `SDL_hid_device_info.product_string`.

## Build

Put `SDL3.dll` (3.4.16) next to the executable, or on `PATH`. From the repository root, `powershell -File tools\fetch-dlls.ps1` downloads the official DLL into this folder.

```
dcc64 "-U..\..\src" "-I..\..\src" devices.dpr
```
