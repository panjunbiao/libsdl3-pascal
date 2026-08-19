{ SDL_cpuinfo.inc -- 1-to-1 from SDL_cpuinfo.h }

const
  SDL_CACHELINE_SIZE = 128;

function SDL_GetNumLogicalCPUCores: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCPUCacheLineSize: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_HasAltiVec: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasMMX: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasSSE: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasSSE2: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasSSE3: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasSSE41: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasSSE42: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasAVX: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasAVX2: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasAVX512F: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasARMSIMD: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasNEON: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasLSX: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasLASX: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSystemRAM: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSIMDAlignment: NativeUInt; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSystemPageSize: Integer; cdecl;
  external SDL_LIB_NAME;
