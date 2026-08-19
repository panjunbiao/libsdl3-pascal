{ SDL_error.inc -- 1-to-1 from SDL_error.h }
{ Skipped: SDL_SetErrorV (va_list). SDL_Unsupported / SDL_InvalidParamError are C macros. }

function SDL_SetError(fmt: PUTF8Char): Boolean; cdecl varargs;
  external SDL_LIB_NAME;
function SDL_OutOfMemory: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetError: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_ClearError: Boolean; cdecl;
  external SDL_LIB_NAME;
