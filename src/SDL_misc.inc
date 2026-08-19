{ SDL_misc.inc -- 1-to-1 from SDL_misc.h }

function SDL_OpenURL(url: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
