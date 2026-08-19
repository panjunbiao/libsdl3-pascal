{ SDL_endian.inc -- 1-to-1 from SDL_endian.h (inlines). Win64 is little-endian. }

const
  SDL_LIL_ENDIAN = 1234;
  SDL_BIG_ENDIAN = 4321;
  SDL_BYTEORDER = SDL_LIL_ENDIAN;
  SDL_FLOATWORDORDER = SDL_LIL_ENDIAN;

function SDL_Swap16(x: Uint16): Uint16;
function SDL_Swap32(x: Uint32): Uint32;
function SDL_Swap64(x: Uint64): Uint64;
function SDL_SwapFloat(x: Single): Single;
function SDL_Swap16LE(x: Uint16): Uint16;
function SDL_Swap32LE(x: Uint32): Uint32;
function SDL_Swap64LE(x: Uint64): Uint64;
function SDL_SwapFloatLE(x: Single): Single;
function SDL_Swap16BE(x: Uint16): Uint16;
function SDL_Swap32BE(x: Uint32): Uint32;
function SDL_Swap64BE(x: Uint64): Uint64;
function SDL_SwapFloatBE(x: Single): Single;
