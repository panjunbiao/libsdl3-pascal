{ SDL_platform.inc -- 1-to-1 from SDL_platform.h }

function SDL_GetPlatform: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
