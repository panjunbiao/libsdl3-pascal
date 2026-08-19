# gameloop

Delphi Win64 `.dproj`: fixed timestep, WASD / arrows / optional gamepad, generated checkerboard texture.

![gameloop example](../../docs/images/gameloop.png)

Put `SDL3.dll` 3.4.14 next to the executable. Open `gameloop.dproj` and add `libsdl3-pascal\src` to the search path, or:

```
dcc64 -U..\..\src -I..\..\src gameloop.dpr
```
