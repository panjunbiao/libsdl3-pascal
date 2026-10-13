# Upstream pins

The units are translated from the official SDL headers at fixed release tags. Pin **stable, even-numbered releases** only ([SDL versioning](https://wiki.libsdl.org/SDL3/README-versions)); odd minors such as 3.5.0 are development prereleases.

The machine-readable pins are in [`tools/pins.py`](../tools/pins.py). Keep this table and that file in step.

| Library | Unit | Tag | Commit | Runtime binary |
|---|---|---|---|---|
| [SDL](https://github.com/libsdl-org/SDL) | `SDL3` | `release-3.4.16` | `fa2c02bb6e21974a89ea9824bc53c9932abe5f9c` | `SDL3.dll` / `libSDL3.dylib` / `libSDL3.so` |
| [SDL_image](https://github.com/libsdl-org/SDL_image) | `SDL3_image` | `release-3.4.4` | `bec9134a26c7d0f31b36d6083c25296e04cabff5` | `SDL3_image.dll` |
| [SDL_ttf](https://github.com/libsdl-org/SDL_ttf) | `SDL3_ttf` | `release-3.2.2` | `a1ce3670aec736ecbf0936c43f2f0cc53aa61e5b` | `SDL3_ttf.dll` |
| [SDL_mixer](https://github.com/libsdl-org/SDL_mixer) | `SDL3_mixer` | `release-3.2.4` | `72a81869b45e249e8e67102db4e98dd2441f05a1` | `SDL3_mixer.dll` (`MIX_*`, not SDL2 `Mix_*`; requires SDL 3.4.0+) |

The Pascal `SDL_MAJOR_VERSION` / `SDL_MINOR_VERSION` / `SDL_MICRO_VERSION` constants in `src/SDL_version.inc` must match the SDL headers at the pin. `tools/fetch-dlls.ps1` downloads the official Win64 zips for the examples and checks each against a pinned SHA-256; update those hashes whenever a pin moves.

## Local clones

The tools read headers with `git show <tag>:<path>`, so a clone may have any branch checked out. They look for clones in this order:

1. an environment variable per library: `SDL_REPO`, `SDL_IMAGE_REPO`, `SDL_TTF_REPO`, `SDL_MIXER_REPO`;
2. `$SDL_CLONES/<name>`, if `SDL_CLONES` points at a folder holding all four clones;
3. sibling folders of this repository: `../SDL`, `../SDL_image`, `../SDL_ttf`, `../SDL_mixer`.

```
git clone https://github.com/libsdl-org/SDL ../SDL
git clone https://github.com/libsdl-org/SDL_image ../SDL_image
git clone https://github.com/libsdl-org/SDL_ttf ../SDL_ttf
git clone https://github.com/libsdl-org/SDL_mixer ../SDL_mixer
```

The tools need Python 3.12 or later and git.

## Runtime version check

`SDL_VERSION` is the compile-time pin. `SDL_GetVersion` is the loaded library. After the process starts:

```pascal
Linked := SDL_GetVersion;
if SDL_VERSIONNUM_MAJOR(Linked) <> SDL_MAJOR_VERSION then
  { refuse: different major }
else if Linked < SDL_VERSION then
  { refuse: older than the pin; exports or ABI may be missing }
```

A **newer** 3.4.x or later 3.x library is expected to work (SDL is backwards-compatible within a major). The binding does not claim newer APIs until the pin moves. An **older** library missing any imported symbol fails at load, before this check can run. Compare `IMG_Version` / `TTF_Version` / `MIX_Version` to the satellite pins the same way.

## Updating a pin

1. Fetch tags in the clone: `git -C ../SDL fetch --tags`.
2. List function changes in the bound headers:

   ```
   python3 tools/diff_upstream.py release-3.4.16 release-3.4.18
   ```

   Then review structs, enums, constants, and property strings:

   ```
   git -C ../SDL diff release-3.4.16 release-3.4.18 -- include/SDL3/
   ```

3. Update the matching `.inc` files. Add or remove declarations; do not keep newer-than-pin APIs.
4. Set the version constants in `src/SDL_version.inc`.
5. Update the tag and commit in `tools/pins.py` and in the table above.
6. Re-run the C ABI oracle on each claimed platform and update `tests/abi` ([ABI.md](ABI.md)).
7. Run `python3 tools/check_coverage.py` (0 missing).
8. Build and run `tests/abi` and the examples on each claimed platform.
9. Update the SHA-256 values in `tools/fetch-dlls.ps1`, and the pins in the README.
10. Tag a binding release when the repository should advertise the new pin. Binding versions are independent of SDL versions.

Patch releases (3.4.16 → 3.4.18) are usually a small header diff. A new even minor (3.4 → 3.6) is the same workflow with a larger diff. Satellites follow the same steps with their own clones and tags.
