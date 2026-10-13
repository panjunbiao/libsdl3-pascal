# Contributing

libsdl3-pascal is a literal 1-to-1 mapping of SDL 3's C API to Pascal. Contributions are welcome when they keep it that way: the same names, the same types, the same layout as the C headers at the pinned SDL release, and nothing on top.

## Before you start

- Read the [style guide](docs/STYLEGUIDE.md) and the [translation method](docs/TRANSLATION.md).
- Check the [open issues](https://github.com/panjunbiao/libsdl3-pascal/issues) for planned work: new platforms and compilers, pin updates, satellites.
- Clone the SDL repositories next to this one ([docs/UPSTREAM.md](docs/UPSTREAM.md#local-clones)); the tools read headers from them.

## What fits

- Fixes where a declaration does not match the pinned header.
- Pin updates to a newer stable SDL release ([docs/UPSTREAM.md](docs/UPSTREAM.md#updating-a-pin)).
- New platforms or compilers, with their ABI check and smoke tests ([docs/ABI.md](docs/ABI.md)).
- Examples that show the binding, not frameworks built on it.

## What does not fit

- Classes, `string` helpers, exceptions, or other wrappers. Build those in a separate project that `uses SDL3`.
- APIs newer than the pinned headers.
- Claims about a platform or compiler that has not passed its checks.

## Checks before a pull request

Run what applies to your change:

| Change | Check |
|---|---|
| Any declaration | `python3 tools/check_coverage.py` reports 0 missing |
| A struct or its fields | The C ABI oracle and `tests/abi` agree on every claimed platform ([docs/ABI.md](docs/ABI.md)) |
| Anything in `src/` | `tests/abi`, `examples/hello`, and `examples/draw` build and run on every claimed platform |
| A pin update | The full [pin update workflow](docs/UPSTREAM.md#updating-a-pin) |

Supported today: Delphi 11+ on Windows x64. Build commands are in [docs/GETTING-STARTED.md](docs/GETTING-STARTED.md) and each test or example folder.

## Commits and pull requests

- Commit subjects are full sentences that say what changed and why, for example "Pin the units to SDL 3.4.16 and fetch official example DLLs."
- One topic per pull request. Describe which checks you ran and on which platforms.

## Agents

This repository is also developed by AI coding agents, through pull requests that a maintainer reviews. [AGENTS.md](AGENTS.md) is their brief; it points to the same documents and rules as this file.

## License

By contributing you agree that your contributions are licensed under the [zlib license](LICENSE), the same terms as SDL.
