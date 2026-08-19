# satellites

Win64 smoke for the optional satellite units: load a JPEG and a PNG, draw Latin and Chinese with the renderer text engine, loop a short MP3. Not an engine.

## Build

Put these official DLLs next to the executable (or on `PATH`):

- `SDL3.dll` 3.4.14
- `SDL3_image.dll` 3.4.4 (PNG also needs `optional/libpng16-16.dll`)
- `SDL3_ttf.dll` 3.2.2
- `SDL3_mixer.dll` 3.2.4 (MP3 is built into this pin)

Keep `assets/` next to the exe. `SDL_GetBasePath` resolves those files.

```
dcc64 -U..\..\src -I..\..\src satellites.dpr
```

Or add `libsdl3-pascal\src` to the Delphi search path. Escape or close the window to quit.

See [CREDITS.md](CREDITS.md) for media and font licenses.
