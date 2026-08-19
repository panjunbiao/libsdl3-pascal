{ SDL_hints.inc -- functions from SDL_hints.h }
{ Hint name string constants (SDL_HINT_*) are deferred; pass the C names as PUTF8Char. }

type
  SDL_HintPriority = (
    SDL_HINT_DEFAULT,
    SDL_HINT_NORMAL,
    SDL_HINT_OVERRIDE
  );

  SDL_HintCallback = procedure(userdata: Pointer; name, oldValue, newValue: PUTF8Char); cdecl;

function SDL_SetHintWithPriority(name, value: PUTF8Char; priority: SDL_HintPriority): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetHint(name, value: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ResetHint(name: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_ResetHints; cdecl;
  external SDL_LIB_NAME;
function SDL_GetHint(name: PUTF8Char): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetHintBoolean(name: PUTF8Char; default_value: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_AddHintCallback(name: PUTF8Char; callback: SDL_HintCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_RemoveHintCallback(name: PUTF8Char; callback: SDL_HintCallback; userdata: Pointer); cdecl;
  external SDL_LIB_NAME;
