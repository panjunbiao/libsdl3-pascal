{ SDL_loadso.inc -- 1-to-1 from SDL_loadso.h }

type
  SDL_SharedObject = record
  end;
  PSDL_SharedObject = ^SDL_SharedObject;

function SDL_LoadObject(sofile: PUTF8Char): PSDL_SharedObject; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadFunction(handle: PSDL_SharedObject; name: PUTF8Char): SDL_FunctionPointer; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnloadObject(handle: PSDL_SharedObject); cdecl;
  external SDL_LIB_NAME;
