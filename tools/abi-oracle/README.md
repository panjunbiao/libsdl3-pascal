# C ABI oracle

`oracle.c` prints `sizeof` and `offsetof` for the SDL types the binding declares, compiled against the pinned SDL headers with the platform's C compiler. Its output is the source of truth for struct layout on that platform; `tests/abi` must agree with it.

No SDL library is linked; only the headers are needed.

## Run

Export the pinned headers first (see [docs/UPSTREAM.md](../../docs/UPSTREAM.md) for where the SDL clone is looked up):

```
python3 tools/export_headers.py SDL
```

It prints the include folder, for example `.cache/headers/SDL-release-3.4.16/include`.

macOS and Linux (Clang or GCC):

```
clang -I .cache/headers/SDL-release-3.4.16/include tools/abi-oracle/oracle.c -o .cache/oracle
.cache/oracle
```

Windows x64 (MSVC, from a "x64 Native Tools" prompt):

```
cl /I .cache\headers\SDL-release-3.4.16\include tools\abi-oracle\oracle.c /Fe.cache\oracle.exe
.cache\oracle.exe
```

Compare the output with the values in `tests/abi/abi.dpr`. Layouts differ between platforms: Win64 uses MSVC's `#pragma pack(push,8)` from `SDL_begin_code.h`, while Clang and GCC use natural alignment, and C `long` is 32-bit on Win64 but 64-bit on macOS and Linux. Run the oracle on every platform the binding claims.

The oracle includes only `SDL.h`. Satellite structs (`IMG_*`, `TTF_*`, `MIX_*`) are checked in `tests/abi` only.
