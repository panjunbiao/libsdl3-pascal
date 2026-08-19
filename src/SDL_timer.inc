{ SDL_timer.inc -- 1-to-1 from SDL_timer.h }

type
  SDL_TimerID = Uint32;
  SDL_TimerCallback = function(userdata: Pointer; timerID: SDL_TimerID; interval: Uint32): Uint32; cdecl;
  SDL_NSTimerCallback = function(userdata: Pointer; timerID: SDL_TimerID; interval: Uint64): Uint64; cdecl;

const
  SDL_MS_PER_SECOND = 1000;
  SDL_US_PER_SECOND = 1000000;
  SDL_NS_PER_SECOND = Uint64(1000000000);
  SDL_NS_PER_MS = 1000000;
  SDL_NS_PER_US = 1000;

function SDL_SECONDS_TO_NS(S: Uint64): Uint64;
function SDL_NS_TO_SECONDS(NS: Uint64): Uint64;
function SDL_MS_TO_NS(MS: Uint64): Uint64;
function SDL_NS_TO_MS(NS: Uint64): Uint64;
function SDL_US_TO_NS(US: Uint64): Uint64;
function SDL_NS_TO_US(NS: Uint64): Uint64;

function SDL_GetTicks: Uint64; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTicksNS: Uint64; cdecl;
  external SDL_LIB_NAME;
function SDL_GetPerformanceCounter: Uint64; cdecl;
  external SDL_LIB_NAME;
function SDL_GetPerformanceFrequency: Uint64; cdecl;
  external SDL_LIB_NAME;
procedure SDL_Delay(ms: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DelayNS(ns: Uint64); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DelayPrecise(ns: Uint64); cdecl;
  external SDL_LIB_NAME;
function SDL_AddTimer(interval: Uint32; callback: SDL_TimerCallback; userdata: Pointer): SDL_TimerID; cdecl;
  external SDL_LIB_NAME;
function SDL_AddTimerNS(interval: Uint64; callback: SDL_NSTimerCallback; userdata: Pointer): SDL_TimerID; cdecl;
  external SDL_LIB_NAME;
function SDL_RemoveTimer(id: SDL_TimerID): Boolean; cdecl;
  external SDL_LIB_NAME;
