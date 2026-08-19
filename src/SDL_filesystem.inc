{ SDL_filesystem.inc -- 1-to-1 from SDL_filesystem.h }

type
  SDL_Folder = (
    SDL_FOLDER_HOME,
    SDL_FOLDER_DESKTOP,
    SDL_FOLDER_DOCUMENTS,
    SDL_FOLDER_DOWNLOADS,
    SDL_FOLDER_MUSIC,
    SDL_FOLDER_PICTURES,
    SDL_FOLDER_PUBLICSHARE,
    SDL_FOLDER_SAVEDGAMES,
    SDL_FOLDER_SCREENSHOTS,
    SDL_FOLDER_TEMPLATES,
    SDL_FOLDER_VIDEOS,
    SDL_FOLDER_COUNT
  );

  SDL_PathType = (
    SDL_PATHTYPE_NONE,
    SDL_PATHTYPE_FILE,
    SDL_PATHTYPE_DIRECTORY,
    SDL_PATHTYPE_OTHER
  );

  PSDL_PathInfo = ^SDL_PathInfo;
  SDL_PathInfo = record
    type_: SDL_PathType;
    size: Uint64;
    create_time: SDL_Time;
    modify_time: SDL_Time;
    access_time: SDL_Time;
  end;

  SDL_GlobFlags = Uint32;

  SDL_EnumerationResult = (
    SDL_ENUM_CONTINUE,
    SDL_ENUM_SUCCESS,
    SDL_ENUM_FAILURE
  );

  SDL_EnumerateDirectoryCallback = function(userdata: Pointer; dirname, fname: PUTF8Char): SDL_EnumerationResult; cdecl;

const
  SDL_GLOB_CASEINSENSITIVE = $00000001;

function SDL_GetBasePath: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetPrefPath(org, app: PUTF8Char): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetUserFolder(folder: SDL_Folder): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateDirectory(path: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_EnumerateDirectory(path: PUTF8Char; callback: SDL_EnumerateDirectoryCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RemovePath(path: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenamePath(oldpath, newpath: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CopyFile(oldpath, newpath: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetPathInfo(path: PUTF8Char; info: PSDL_PathInfo): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GlobDirectory(path, pattern: PUTF8Char; flags: SDL_GlobFlags; count: PInteger): PPUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCurrentDirectory: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
