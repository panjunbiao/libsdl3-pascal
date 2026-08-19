{ SDL_stdinc.inc -- types only. CRT clones are out of the 2D core. }

type
  { Delphi type names are case-insensitive; do not alias Uint8 = UInt8. }
  Sint8 = ShortInt;
  Uint8 = Byte;
  Sint16 = SmallInt;
  Uint16 = Word;
  Sint32 = Integer;
  Uint32 = Cardinal;
  Sint64 = Int64;
  Uint64 = System.UInt64;
  SDL_Time = Sint64;

  PSint8 = ^Sint8;
  PUint8 = ^Uint8;
  PSint16 = ^Sint16;
  PUint16 = ^Uint16;
  PSint32 = ^Sint32;
  PUint32 = ^Uint32;
  PSint64 = ^Sint64;
  PUint64 = ^Uint64;
  PNativeUInt = ^NativeUInt;
  PPUint8 = ^PUint8;
  PPUTF8Char = ^PUTF8Char;
  PBoolean = ^Boolean;

  SDL_FunctionPointer = procedure; cdecl;

const
  SDL_MAX_SINT8 = Sint8($7F);
  SDL_MIN_SINT8 = Sint8(-128);
  SDL_MAX_UINT8 = Uint8($FF);
  SDL_MIN_UINT8 = Uint8(0);
  SDL_MAX_SINT16 = Sint16($7FFF);
  SDL_MIN_SINT16 = Sint16(-32768);
  SDL_MAX_UINT16 = Uint16($FFFF);
  SDL_MIN_UINT16 = Uint16(0);
  SDL_MAX_SINT32 = Sint32($7FFFFFFF);
  SDL_MIN_SINT32 = Sint32(-2147483647 - 1);
  SDL_MAX_UINT32 = Uint32($FFFFFFFF);
  SDL_MIN_UINT32 = Uint32(0);
