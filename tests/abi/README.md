# Pascal ABI checker

```
dcc64 "-U..\..\src" "-I..\..\src" abi.dpr
abi.exe
```

The program checks `SizeOf` for the fixed-width types and the public structs,
and the offsets of a few fields that sit after padding (`SDL_Surface.pixels`,
`SDL_DropEvent.source`, `TTF_TextData.layout` and others). The expected values
are the MSVC x64 layouts of the pinned SDL 3.4.16, SDL_image 3.4.4, SDL_ttf
3.2.2 and SDL_mixer 3.2.4 headers; `SDL_Event` must be 128 bytes. The program
exits with code 1 at the first mismatch.
