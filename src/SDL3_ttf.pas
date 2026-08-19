unit SDL3_ttf;

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
  SDL_TTF_LIB_NAME = 'SDL3_ttf.dll';
{$ELSE}
  {$IFDEF DARWIN}
  SDL_TTF_LIB_NAME = 'libSDL3_ttf.dylib';
  {$ELSE}
    {$IFDEF MACOS}
  SDL_TTF_LIB_NAME = 'libSDL3_ttf.dylib';
    {$ELSE}
  SDL_TTF_LIB_NAME = 'libSDL3_ttf.so';
    {$ENDIF}
  {$ENDIF}
{$ENDIF}

{$I SDL_ttf.inc}

implementation

end.
