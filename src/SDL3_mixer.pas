unit SDL3_mixer;

{ Project options must not change record layout or the short-circuit
  tests in the inline helpers. }
{$IFDEF FPC}
  {$MODE OBJFPC}
  {$PACKRECORDS C}
{$ELSE}
  {$ALIGN 8}
{$ENDIF}

{$MINENUMSIZE 4}
{$Z4}
{$BOOLEVAL OFF}
{$EXTENDEDSYNTAX ON}

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

{$I SDL_mixer.impl.inc}

end.
