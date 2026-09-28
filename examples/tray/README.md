# tray

Put an icon in the notification area with `SDL_CreateTray`. The menu has a checkbox (`Pause color`) and a `Quit` button. The window color follows the checkbox. `SDL_UpdateTrays` runs once per frame.

Escape, the window close button, or the tray Quit entry ends the program.

## Build

Put `SDL3.dll` (3.4.14) next to the executable, or on `PATH`.

```
dcc64 -U..\..\src -I..\..\src tray.dpr
```
