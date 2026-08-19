{ SDL_log.inc -- 1-to-1 from SDL_log.h }
{ Skipped: SDL_LogMessageV (va_list). }

type
  SDL_LogCategory = (
    SDL_LOG_CATEGORY_APPLICATION,
    SDL_LOG_CATEGORY_ERROR,
    SDL_LOG_CATEGORY_ASSERT,
    SDL_LOG_CATEGORY_SYSTEM,
    SDL_LOG_CATEGORY_AUDIO,
    SDL_LOG_CATEGORY_VIDEO,
    SDL_LOG_CATEGORY_RENDER,
    SDL_LOG_CATEGORY_INPUT,
    SDL_LOG_CATEGORY_TEST,
    SDL_LOG_CATEGORY_GPU,
    SDL_LOG_CATEGORY_RESERVED2,
    SDL_LOG_CATEGORY_RESERVED3,
    SDL_LOG_CATEGORY_RESERVED4,
    SDL_LOG_CATEGORY_RESERVED5,
    SDL_LOG_CATEGORY_RESERVED6,
    SDL_LOG_CATEGORY_RESERVED7,
    SDL_LOG_CATEGORY_RESERVED8,
    SDL_LOG_CATEGORY_RESERVED9,
    SDL_LOG_CATEGORY_RESERVED10,
    SDL_LOG_CATEGORY_CUSTOM
  );

  SDL_LogPriority = (
    SDL_LOG_PRIORITY_INVALID,
    SDL_LOG_PRIORITY_TRACE,
    SDL_LOG_PRIORITY_VERBOSE,
    SDL_LOG_PRIORITY_DEBUG,
    SDL_LOG_PRIORITY_INFO,
    SDL_LOG_PRIORITY_WARN,
    SDL_LOG_PRIORITY_ERROR,
    SDL_LOG_PRIORITY_CRITICAL,
    SDL_LOG_PRIORITY_COUNT
  );

  SDL_LogOutputFunction = procedure(userdata: Pointer; category: Integer; priority: SDL_LogPriority; message: PUTF8Char); cdecl;
  PSDL_LogOutputFunction = ^SDL_LogOutputFunction;

procedure SDL_SetLogPriorities(priority: SDL_LogPriority); cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetLogPriority(category: Integer; priority: SDL_LogPriority); cdecl;
  external SDL_LIB_NAME;
function SDL_GetLogPriority(category: Integer): SDL_LogPriority; cdecl;
  external SDL_LIB_NAME;
procedure SDL_ResetLogPriorities; cdecl;
  external SDL_LIB_NAME;
function SDL_SetLogPriorityPrefix(priority: SDL_LogPriority; prefix: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_Log(fmt: PUTF8Char); cdecl varargs;
  external SDL_LIB_NAME;
procedure SDL_LogTrace(category: Integer; fmt: PUTF8Char); cdecl varargs;
  external SDL_LIB_NAME;
procedure SDL_LogVerbose(category: Integer; fmt: PUTF8Char); cdecl varargs;
  external SDL_LIB_NAME;
procedure SDL_LogDebug(category: Integer; fmt: PUTF8Char); cdecl varargs;
  external SDL_LIB_NAME;
procedure SDL_LogInfo(category: Integer; fmt: PUTF8Char); cdecl varargs;
  external SDL_LIB_NAME;
procedure SDL_LogWarn(category: Integer; fmt: PUTF8Char); cdecl varargs;
  external SDL_LIB_NAME;
procedure SDL_LogError(category: Integer; fmt: PUTF8Char); cdecl varargs;
  external SDL_LIB_NAME;
procedure SDL_LogCritical(category: Integer; fmt: PUTF8Char); cdecl varargs;
  external SDL_LIB_NAME;
procedure SDL_LogMessage(category: Integer; priority: SDL_LogPriority; fmt: PUTF8Char); cdecl varargs;
  external SDL_LIB_NAME;
function SDL_GetDefaultLogOutputFunction: SDL_LogOutputFunction; cdecl;
  external SDL_LIB_NAME;
procedure SDL_GetLogOutputFunction(callback: PSDL_LogOutputFunction; userdata: PPointer); cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetLogOutputFunction(callback: SDL_LogOutputFunction; userdata: Pointer); cdecl;
  external SDL_LIB_NAME;
