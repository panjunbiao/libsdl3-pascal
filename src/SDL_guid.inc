{ SDL_guid.inc -- 1-to-1 from SDL_guid.h }

type
  PSDL_GUID = ^SDL_GUID;
  SDL_GUID = record
    data: array[0..15] of Uint8;
  end;

procedure SDL_GUIDToString(guid: SDL_GUID; pszGUID: PUTF8Char; cbGUID: Integer); cdecl;
  external SDL_LIB_NAME;
function SDL_StringToGUID(pchGUID: PUTF8Char): SDL_GUID; cdecl;
  external SDL_LIB_NAME;
