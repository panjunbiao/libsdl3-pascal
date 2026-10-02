unit SDL3_image;

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
  SDL_IMAGE_LIB_NAME = 'SDL3_image.dll';
{$ELSE}
  {$IFDEF DARWIN}
  SDL_IMAGE_LIB_NAME = 'libSDL3_image.dylib';
  {$ELSE}
    {$IFDEF MACOS}
  SDL_IMAGE_LIB_NAME = 'libSDL3_image.dylib';
    {$ELSE}
  SDL_IMAGE_LIB_NAME = 'libSDL3_image.so';
    {$ENDIF}
  {$ENDIF}
{$ENDIF}

{$I SDL_image.inc}

implementation

{$I SDL_image.impl.inc}

end.
