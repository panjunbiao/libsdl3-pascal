{ SDL_asyncio.inc -- 1-to-1 from SDL_asyncio.h }

type
  SDL_AsyncIO = record
  end;
  PSDL_AsyncIO = ^SDL_AsyncIO;

  SDL_AsyncIOQueue = record
  end;
  PSDL_AsyncIOQueue = ^SDL_AsyncIOQueue;

  SDL_AsyncIOTaskType = (
    SDL_ASYNCIO_TASK_READ,
    SDL_ASYNCIO_TASK_WRITE,
    SDL_ASYNCIO_TASK_CLOSE
  );

  SDL_AsyncIOResult = (
    SDL_ASYNCIO_COMPLETE,
    SDL_ASYNCIO_FAILURE,
    SDL_ASYNCIO_CANCELED
  );

  PSDL_AsyncIOOutcome = ^SDL_AsyncIOOutcome;
  SDL_AsyncIOOutcome = record
    asyncio: PSDL_AsyncIO;
    type_: SDL_AsyncIOTaskType;
    result_: SDL_AsyncIOResult;
    buffer: Pointer;
    offset: Uint64;
    bytes_requested: Uint64;
    bytes_transferred: Uint64;
    userdata: Pointer;
  end;

function SDL_AsyncIOFromFile(file_, mode: PUTF8Char): PSDL_AsyncIO; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAsyncIOSize(asyncio: PSDL_AsyncIO): Sint64; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadAsyncIO(asyncio: PSDL_AsyncIO; ptr: Pointer; offset, size: Uint64; queue: PSDL_AsyncIOQueue; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteAsyncIO(asyncio: PSDL_AsyncIO; ptr: Pointer; offset, size: Uint64; queue: PSDL_AsyncIOQueue; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CloseAsyncIO(asyncio: PSDL_AsyncIO; flush: Boolean; queue: PSDL_AsyncIOQueue; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateAsyncIOQueue: PSDL_AsyncIOQueue; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyAsyncIOQueue(queue: PSDL_AsyncIOQueue); cdecl;
  external SDL_LIB_NAME;
function SDL_GetAsyncIOResult(queue: PSDL_AsyncIOQueue; outcome: PSDL_AsyncIOOutcome): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WaitAsyncIOResult(queue: PSDL_AsyncIOQueue; outcome: PSDL_AsyncIOOutcome; timeoutMS: Sint32): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SignalAsyncIOQueue(queue: PSDL_AsyncIOQueue); cdecl;
  external SDL_LIB_NAME;
function SDL_LoadFileAsync(file_: PUTF8Char; queue: PSDL_AsyncIOQueue; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
