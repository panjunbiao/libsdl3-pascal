unit SDL3_ttf;

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

{$I SDL_ttf.impl.inc}
{$I SDL_textengine.impl.inc}

end.
