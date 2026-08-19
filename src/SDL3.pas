unit SDL3;

{$IFDEF FPC}
  {$MODE OBJFPC}
  {$PACKRECORDS C}
{$ENDIF}

{$MINENUMSIZE 4}
{$Z4}

interface

const
{$IFDEF MSWINDOWS}
  SDL_LIB_NAME = 'SDL3.dll';
{$ELSE}
  {$IFDEF DARWIN}
  SDL_LIB_NAME = 'libSDL3.dylib';
  {$ELSE}
    {$IFDEF MACOS}
  SDL_LIB_NAME = 'libSDL3.dylib';
    {$ELSE}
  SDL_LIB_NAME = 'libSDL3.so';
    {$ENDIF}
  {$ENDIF}
{$ENDIF}

{ Include files mirror SDL3 C headers. The first translated include should
  start a type or const section so it is not parsed as part of SDL_LIB_NAME. }
{$I SDL_stdinc.inc}
{$I SDL_version.inc}
{$I SDL_error.inc}
{$I SDL_properties.inc}
{$I SDL_hints.inc}
{$I SDL_log.inc}
{$I SDL_bits.inc}
{$I SDL_endian.inc}
{$I SDL_cpuinfo.inc}
{$I SDL_platform.inc}
{$I SDL_atomic.inc}
{$I SDL_rect.inc}
{$I SDL_pixels.inc}
{$I SDL_blendmode.inc}
{$I SDL_iostream.inc}
{$I SDL_surface.inc}
{$I SDL_video.inc}
{$I SDL_scancode.inc}
{$I SDL_keycode.inc}
{$I SDL_keyboard.inc}
{$I SDL_mouse.inc}
{$I SDL_guid.inc}
{$I SDL_power.inc}
{$I SDL_sensor.inc}
{$I SDL_joystick.inc}
{$I SDL_gamepad.inc}
{$I SDL_touch.inc}
{$I SDL_pen.inc}
{$I SDL_audio.inc}
{$I SDL_events.inc}
{$I SDL_init.inc}
{$I SDL_main.inc}
{$I SDL_timer.inc}
{$I SDL_time.inc}
{$I SDL_filesystem.inc}
{$I SDL_storage.inc}
{$I SDL_clipboard.inc}
{$I SDL_locale.inc}
{$I SDL_misc.inc}
{$I SDL_loadso.inc}
{$I SDL_assert.inc}
{$I SDL_thread.inc}
{$I SDL_mutex.inc}
{$I SDL_messagebox.inc}
{$I SDL_dialog.inc}
{$I SDL_asyncio.inc}
{$I SDL_system.inc}
{$I SDL_render.inc}

implementation

{$I SDL_stdinc.impl.inc}
{$I SDL_version.impl.inc}
{$I SDL_bits.impl.inc}
{$I SDL_endian.impl.inc}
{$I SDL_atomic.impl.inc}
{$I SDL_rect.impl.inc}
{$I SDL_pixels.impl.inc}
{$I SDL_iostream.impl.inc}
{$I SDL_surface.impl.inc}
{$I SDL_video.impl.inc}
{$I SDL_keycode.impl.inc}
{$I SDL_joystick.impl.inc}
{$I SDL_timer.impl.inc}
{$I SDL_audio.impl.inc}
{$I SDL_thread.impl.inc}
{$I SDL_storage.impl.inc}

end.
