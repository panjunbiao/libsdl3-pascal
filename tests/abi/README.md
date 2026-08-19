# Pascal ABI checker

```
dcc64 -U..\..\src -I..\..\src abi.dpr
abi.exe
```

`SDL_Event` must be 128 bytes. Other sizes are the Win64 Delphi measurements; confirm against `libsdl3-pascal-dev/tools/abi-oracle`.
