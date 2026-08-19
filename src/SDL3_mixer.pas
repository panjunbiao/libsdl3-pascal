unit SDL3_mixer;

{$IFDEF FPC}
  {$MODE OBJFPC}
  {$PACKRECORDS C}
{$ENDIF}

{$MINENUMSIZE 4}
{$Z4}

interface

uses
  SDL3;

const
{$IFDEF MSWINDOWS}
  SDL_MIXER_LIB_NAME = 'SDL3_mixer.dll';
{$ELSE}
  {$IFDEF DARWIN}
  SDL_MIXER_LIB_NAME = 'libSDL3_mixer.dylib';
  {$ELSE}
    {$IFDEF MACOS}
  SDL_MIXER_LIB_NAME = 'libSDL3_mixer.dylib';
    {$ELSE}
  SDL_MIXER_LIB_NAME = 'libSDL3_mixer.so';
    {$ENDIF}
  {$ENDIF}
{$ENDIF}

{$I SDL_mixer.inc}

implementation

end.
