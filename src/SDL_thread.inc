{ SDL_thread.inc -- 1-to-1 from SDL_thread.h }

type
  SDL_Thread = record
  end;
  PSDL_Thread = ^SDL_Thread;

  SDL_ThreadID = Uint64;
  PSDL_ThreadID = ^SDL_ThreadID;
  SDL_TLSID = SDL_AtomicInt;
  PSDL_TLSID = ^SDL_TLSID;

  SDL_ThreadPriority = (
    SDL_THREAD_PRIORITY_LOW,
    SDL_THREAD_PRIORITY_NORMAL,
    SDL_THREAD_PRIORITY_HIGH,
    SDL_THREAD_PRIORITY_TIME_CRITICAL
  );

  SDL_ThreadState = (
    SDL_THREAD_UNKNOWN,
    SDL_THREAD_ALIVE,
    SDL_THREAD_DETACHED,
    SDL_THREAD_COMPLETE
  );

  SDL_ThreadFunction = function(data: Pointer): Integer; cdecl;
  SDL_TLSDestructorCallback = procedure(value: Pointer); cdecl;

const
  SDL_PROP_THREAD_CREATE_ENTRY_FUNCTION_POINTER = 'SDL.thread.create.entry_function';
  SDL_PROP_THREAD_CREATE_NAME_STRING = 'SDL.thread.create.name';
  SDL_PROP_THREAD_CREATE_USERDATA_POINTER = 'SDL.thread.create.userdata';
  SDL_PROP_THREAD_CREATE_STACKSIZE_NUMBER = 'SDL.thread.create.stacksize';

{ C SDL_CreateThread is a macro around SDL_CreateThreadRuntime. }
function SDL_CreateThreadRuntime(fn: SDL_ThreadFunction; name: PUTF8Char; data: Pointer; pfnBeginThread, pfnEndThread: SDL_FunctionPointer): PSDL_Thread; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateThreadWithPropertiesRuntime(props: SDL_PropertiesID; pfnBeginThread, pfnEndThread: SDL_FunctionPointer): PSDL_Thread; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateThread(fn: SDL_ThreadFunction; name: PUTF8Char; data: Pointer): PSDL_Thread;
function SDL_CreateThreadWithProperties(props: SDL_PropertiesID): PSDL_Thread;
function SDL_GetThreadName(thread: PSDL_Thread): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCurrentThreadID: SDL_ThreadID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetThreadID(thread: PSDL_Thread): SDL_ThreadID; cdecl;
  external SDL_LIB_NAME;
function SDL_SetCurrentThreadPriority(priority: SDL_ThreadPriority): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_WaitThread(thread: PSDL_Thread; status: PInteger); cdecl;
  external SDL_LIB_NAME;
function SDL_GetThreadState(thread: PSDL_Thread): SDL_ThreadState; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DetachThread(thread: PSDL_Thread); cdecl;
  external SDL_LIB_NAME;
function SDL_GetTLS(id: PSDL_TLSID): Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_SetTLS(id: PSDL_TLSID; const value: Pointer; destructor_: SDL_TLSDestructorCallback): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_CleanupTLS; cdecl;
  external SDL_LIB_NAME;
