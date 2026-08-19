# Pascal ABI checker

```
dcc64 -U..\..\src -I..\..\src abi.dpr
abi.exe
```

`SDL_Event` must be 128 bytes. Satellite structs (`IMG_Animation` 32, `TTF_Text` 24, `TTF_SubString` 36, `MIX_StereoGains` 8, `MIX_Point3D` 12) are Win64 Delphi measurements; confirm against `libsdl3-pascal-dev/tools/abi-oracle`.
