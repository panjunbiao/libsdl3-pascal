"""Pinned upstream releases and where to find their git clones.

Every tool reads headers with `git show <tag>:<path>`, so a clone may have any
branch checked out. Clones are looked up in this order:

1. an environment variable per library (`SDL_REPO`, `SDL_IMAGE_REPO`, ...),
2. `$SDL_CLONES/<name>` if `SDL_CLONES` points at a folder holding all clones,
3. a sibling folder of this repository (`../SDL`, `../SDL_image`, ...).

Clone with, for example: git clone https://github.com/libsdl-org/SDL ../SDL
"""
from __future__ import annotations

import os
import pathlib
import subprocess
import sys
from dataclasses import dataclass

ROOT = pathlib.Path(__file__).resolve().parent.parent
SRC = ROOT / "src"


@dataclass(frozen=True)
class Upstream:
    name: str          # folder and repository name, e.g. "SDL_image"
    env: str           # environment variable that overrides the clone path
    tag: str           # pinned release tag
    commit: str        # commit the tag points to (checked by the tools)
    include: str       # include folder inside the repository


SDL = Upstream("SDL", "SDL_REPO", "release-3.4.16", "fa2c02bb6e21974a89ea9824bc53c9932abe5f9c", "include/SDL3")
SDL_IMAGE = Upstream("SDL_image", "SDL_IMAGE_REPO", "release-3.4.4", "bec9134a26c7d0f31b36d6083c25296e04cabff5", "include/SDL3_image")
SDL_TTF = Upstream("SDL_ttf", "SDL_TTF_REPO", "release-3.2.2", "a1ce3670aec736ecbf0936c43f2f0cc53aa61e5b", "include/SDL3_ttf")
SDL_MIXER = Upstream("SDL_mixer", "SDL_MIXER_REPO", "release-3.2.4", "72a81869b45e249e8e67102db4e98dd2441f05a1", "include/SDL3_mixer")

UPSTREAMS = {u.name: u for u in (SDL, SDL_IMAGE, SDL_TTF, SDL_MIXER)}

# Core SDL headers the binding covers (one .inc each).
CORE_HEADERS = [
    "SDL_stdinc.h", "SDL_version.h", "SDL_error.h", "SDL_init.h", "SDL_main.h",
    "SDL_log.h", "SDL_hints.h", "SDL_properties.h", "SDL_rect.h", "SDL_pixels.h",
    "SDL_video.h", "SDL_events.h", "SDL_blendmode.h", "SDL_render.h",
    "SDL_keyboard.h", "SDL_mouse.h", "SDL_surface.h", "SDL_iostream.h",
    "SDL_timer.h", "SDL_audio.h", "SDL_filesystem.h", "SDL_gamepad.h",
    "SDL_joystick.h", "SDL_clipboard.h", "SDL_touch.h", "SDL_guid.h",
    "SDL_power.h", "SDL_sensor.h", "SDL_thread.h", "SDL_mutex.h", "SDL_atomic.h",
    "SDL_time.h", "SDL_messagebox.h", "SDL_dialog.h", "SDL_storage.h",
    "SDL_locale.h", "SDL_cpuinfo.h", "SDL_platform.h", "SDL_misc.h",
    "SDL_loadso.h", "SDL_assert.h", "SDL_asyncio.h", "SDL_pen.h", "SDL_system.h",
    "SDL_camera.h", "SDL_haptic.h", "SDL_hidapi.h", "SDL_process.h", "SDL_tray.h",
    "SDL_metal.h", "SDL_vulkan.h", "SDL_gpu.h",
]

# Satellite headers: library name -> header file.
SATELLITE_HEADERS = {
    "SDL_image": "SDL_image.h",
    "SDL_ttf": "SDL_ttf.h",
    "SDL_mixer": "SDL_mixer.h",
}

# Deliberately unbound core functions: the va_list variants.
CORE_SKIP = {
    "SDL_SetErrorV", "SDL_LogMessageV", "SDL_IOvprintf",
    "SDL_vsscanf", "SDL_vsnprintf", "SDL_vswprintf", "SDL_vasprintf",
}


def clone_path(upstream: Upstream) -> pathlib.Path:
    if os.environ.get(upstream.env):
        path = pathlib.Path(os.environ[upstream.env])
    elif os.environ.get("SDL_CLONES"):
        path = pathlib.Path(os.environ["SDL_CLONES"]) / upstream.name
    else:
        path = ROOT.parent / upstream.name
    if not (path / ".git").exists():
        sys.exit(
            f"No git clone of {upstream.name} at {path}.\n"
            f"Clone it with: git clone https://github.com/libsdl-org/{upstream.name} {path}\n"
            f"or set {upstream.env} (or SDL_CLONES) to an existing clone."
        )
    return path


def git(repo: pathlib.Path, *args: str) -> str:
    return subprocess.check_output(["git", "-C", str(repo), *args], text=True, encoding="utf-8", errors="replace")


def check_pin(upstream: Upstream, repo: pathlib.Path) -> None:
    """Fails if the tag is missing or no longer points at the recorded commit."""
    try:
        commit = git(repo, "rev-parse", f"{upstream.tag}^{{commit}}").strip()
    except subprocess.CalledProcessError:
        sys.exit(f"{repo} has no tag {upstream.tag}. Run: git -C {repo} fetch --tags")
    if commit != upstream.commit:
        sys.exit(f"{upstream.name} {upstream.tag} is {commit}, but tools/pins.py records {upstream.commit}.")


def header(upstream: Upstream, name: str, ref: str | None = None) -> str:
    """Text of one header at the pinned tag (or another ref)."""
    repo = clone_path(upstream)
    if ref is None:
        check_pin(upstream, repo)
        ref = upstream.tag
    return git(repo, "show", f"{ref}:{upstream.include}/{name}")
