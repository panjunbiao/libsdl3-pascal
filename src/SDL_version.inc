{ SDL_version.inc -- 1-to-1 from SDL_version.h }

const
  SDL_MAJOR_VERSION = 3;
  SDL_MINOR_VERSION = 4;
  SDL_MICRO_VERSION = 14;
  SDL_VERSION = SDL_MAJOR_VERSION * 1000000 + SDL_MINOR_VERSION * 1000 + SDL_MICRO_VERSION;

function SDL_VERSIONNUM(major, minor, patch: Integer): Integer;
function SDL_VERSIONNUM_MAJOR(version: Integer): Integer;
function SDL_VERSIONNUM_MINOR(version: Integer): Integer;
function SDL_VERSIONNUM_MICRO(version: Integer): Integer;
function SDL_VERSION_ATLEAST(X, Y, Z: Integer): Boolean;

function SDL_GetVersion: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRevision: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
