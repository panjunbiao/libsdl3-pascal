{ SDL_atomic.inc -- 1-to-1 from SDL_atomic.h }

type
  PSDL_SpinLock = ^SDL_SpinLock;
  SDL_SpinLock = Integer;

  PSDL_AtomicInt = ^SDL_AtomicInt;
  SDL_AtomicInt = record
    value: Integer;
  end;

  PSDL_AtomicU32 = ^SDL_AtomicU32;
  SDL_AtomicU32 = record
    value: Uint32;
  end;

function SDL_TryLockSpinlock(lock: PSDL_SpinLock): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_LockSpinlock(lock: PSDL_SpinLock); cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnlockSpinlock(lock: PSDL_SpinLock); cdecl;
  external SDL_LIB_NAME;
procedure SDL_MemoryBarrierReleaseFunction; cdecl;
  external SDL_LIB_NAME;
procedure SDL_MemoryBarrierAcquireFunction; cdecl;
  external SDL_LIB_NAME;
procedure SDL_MemoryBarrierRelease;
procedure SDL_MemoryBarrierAcquire;
function SDL_CompareAndSwapAtomicInt(a: PSDL_AtomicInt; oldval, newval: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAtomicInt(a: PSDL_AtomicInt; v: Integer): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAtomicInt(a: PSDL_AtomicInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_AddAtomicInt(a: PSDL_AtomicInt; v: Integer): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_AtomicIncRef(a: PSDL_AtomicInt): Integer;
function SDL_AtomicDecRef(a: PSDL_AtomicInt): Boolean;
function SDL_CompareAndSwapAtomicU32(a: PSDL_AtomicU32; oldval, newval: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAtomicU32(a: PSDL_AtomicU32; v: Uint32): Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAtomicU32(a: PSDL_AtomicU32): Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_AddAtomicU32(a: PSDL_AtomicU32; v: Integer): Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_CompareAndSwapAtomicPointer(a: PPointer; oldval, newval: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAtomicPointer(a: PPointer; v: Pointer): Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAtomicPointer(a: PPointer): Pointer; cdecl;
  external SDL_LIB_NAME;
