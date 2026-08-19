unit SDL3_image;

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

end.
