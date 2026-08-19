{ SDL_mutex.inc -- 1-to-1 from SDL_mutex.h. Clang thread-safety attrs are skipped. }

type
  SDL_Mutex = record
  end;
  PSDL_Mutex = ^SDL_Mutex;

  SDL_RWLock = record
  end;
  PSDL_RWLock = ^SDL_RWLock;

  SDL_Semaphore = record
  end;
  PSDL_Semaphore = ^SDL_Semaphore;

  SDL_Condition = record
  end;
  PSDL_Condition = ^SDL_Condition;

  SDL_InitStatus = (
    SDL_INIT_STATUS_UNINITIALIZED,
    SDL_INIT_STATUS_INITIALIZING,
    SDL_INIT_STATUS_INITIALIZED,
    SDL_INIT_STATUS_UNINITIALIZING
  );

  PSDL_InitState = ^SDL_InitState;
  SDL_InitState = record
    status: SDL_AtomicInt;
    thread: SDL_ThreadID;
    reserved: Pointer;
  end;

function SDL_CreateMutex: PSDL_Mutex; cdecl;
  external SDL_LIB_NAME;
procedure SDL_LockMutex(mutex: PSDL_Mutex); cdecl;
  external SDL_LIB_NAME;
function SDL_TryLockMutex(mutex: PSDL_Mutex): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnlockMutex(mutex: PSDL_Mutex); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyMutex(mutex: PSDL_Mutex); cdecl;
  external SDL_LIB_NAME;
function SDL_CreateRWLock: PSDL_RWLock; cdecl;
  external SDL_LIB_NAME;
procedure SDL_LockRWLockForReading(rwlock: PSDL_RWLock); cdecl;
  external SDL_LIB_NAME;
procedure SDL_LockRWLockForWriting(rwlock: PSDL_RWLock); cdecl;
  external SDL_LIB_NAME;
function SDL_TryLockRWLockForReading(rwlock: PSDL_RWLock): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_TryLockRWLockForWriting(rwlock: PSDL_RWLock): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnlockRWLock(rwlock: PSDL_RWLock); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyRWLock(rwlock: PSDL_RWLock); cdecl;
  external SDL_LIB_NAME;
function SDL_CreateSemaphore(initial_value: Uint32): PSDL_Semaphore; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroySemaphore(sem: PSDL_Semaphore); cdecl;
  external SDL_LIB_NAME;
procedure SDL_WaitSemaphore(sem: PSDL_Semaphore); cdecl;
  external SDL_LIB_NAME;
function SDL_TryWaitSemaphore(sem: PSDL_Semaphore): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WaitSemaphoreTimeout(sem: PSDL_Semaphore; timeoutMS: Sint32): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SignalSemaphore(sem: PSDL_Semaphore); cdecl;
  external SDL_LIB_NAME;
function SDL_GetSemaphoreValue(sem: PSDL_Semaphore): Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateCondition: PSDL_Condition; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyCondition(cond: PSDL_Condition); cdecl;
  external SDL_LIB_NAME;
procedure SDL_SignalCondition(cond: PSDL_Condition); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BroadcastCondition(cond: PSDL_Condition); cdecl;
  external SDL_LIB_NAME;
procedure SDL_WaitCondition(cond: PSDL_Condition; mutex: PSDL_Mutex); cdecl;
  external SDL_LIB_NAME;
function SDL_WaitConditionTimeout(cond: PSDL_Condition; mutex: PSDL_Mutex; timeoutMS: Sint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ShouldInit(state: PSDL_InitState): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ShouldQuit(state: PSDL_InitState): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetInitialized(state: PSDL_InitState; initialized: Boolean); cdecl;
  external SDL_LIB_NAME;
