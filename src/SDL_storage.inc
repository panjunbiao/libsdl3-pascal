{ SDL_storage.inc -- 1-to-1 from SDL_storage.h }

type
  SDL_Storage = record
  end;
  PSDL_Storage = ^SDL_Storage;

  PSDL_StorageInterface = ^SDL_StorageInterface;
  SDL_StorageInterface = record
    version: Uint32;
    close: function(userdata: Pointer): Boolean; cdecl;
    ready: function(userdata: Pointer): Boolean; cdecl;
    enumerate: function(userdata: Pointer; path: PUTF8Char; callback: SDL_EnumerateDirectoryCallback; callback_userdata: Pointer): Boolean; cdecl;
    info: function(userdata: Pointer; path: PUTF8Char; info: PSDL_PathInfo): Boolean; cdecl;
    read_file: function(userdata: Pointer; path: PUTF8Char; destination: Pointer; length: Uint64): Boolean; cdecl;
    write_file: function(userdata: Pointer; path: PUTF8Char; const source: Pointer; length: Uint64): Boolean; cdecl;
    mkdir: function(userdata: Pointer; path: PUTF8Char): Boolean; cdecl;
    remove: function(userdata: Pointer; path: PUTF8Char): Boolean; cdecl;
    rename: function(userdata: Pointer; oldpath, newpath: PUTF8Char): Boolean; cdecl;
    copy: function(userdata: Pointer; oldpath, newpath: PUTF8Char): Boolean; cdecl;
    space_remaining: function(userdata: Pointer): Uint64; cdecl;
  end;

procedure SDL_INIT_INTERFACE(iface: PSDL_StorageInterface); overload;

function SDL_OpenTitleStorage(override_: PUTF8Char; props: SDL_PropertiesID): PSDL_Storage; cdecl;
  external SDL_LIB_NAME;
function SDL_OpenUserStorage(org, app: PUTF8Char; props: SDL_PropertiesID): PSDL_Storage; cdecl;
  external SDL_LIB_NAME;
function SDL_OpenFileStorage(path: PUTF8Char): PSDL_Storage; cdecl;
  external SDL_LIB_NAME;
function SDL_OpenStorage(const iface: PSDL_StorageInterface; userdata: Pointer): PSDL_Storage; cdecl;
  external SDL_LIB_NAME;
function SDL_CloseStorage(storage: PSDL_Storage): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_StorageReady(storage: PSDL_Storage): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetStorageFileSize(storage: PSDL_Storage; path: PUTF8Char; length: PUint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadStorageFile(storage: PSDL_Storage; path: PUTF8Char; destination: Pointer; length: Uint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteStorageFile(storage: PSDL_Storage; path: PUTF8Char; const source: Pointer; length: Uint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateStorageDirectory(storage: PSDL_Storage; path: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_EnumerateStorageDirectory(storage: PSDL_Storage; path: PUTF8Char; callback: SDL_EnumerateDirectoryCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RemoveStoragePath(storage: PSDL_Storage; path: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenameStoragePath(storage: PSDL_Storage; oldpath, newpath: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CopyStorageFile(storage: PSDL_Storage; oldpath, newpath: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetStoragePathInfo(storage: PSDL_Storage; path: PUTF8Char; info: PSDL_PathInfo): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetStorageSpaceRemaining(storage: PSDL_Storage): Uint64; cdecl;
  external SDL_LIB_NAME;
function SDL_GlobStorageDirectory(storage: PSDL_Storage; path, pattern: PUTF8Char; flags: SDL_GlobFlags; count: PInteger): PPUTF8Char; cdecl;
  external SDL_LIB_NAME;
