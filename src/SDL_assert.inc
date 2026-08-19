{ SDL_assert.inc -- 1-to-1 from SDL_assert.h }
{ C macros SDL_assert / SDL_assert_release / SDL_assert_paranoid / SDL_assert_always
  and SDL_TriggerBreakpoint are skipped (static locals + compiler-specific break). }

type
  SDL_AssertState = (
    SDL_ASSERTION_RETRY,
    SDL_ASSERTION_BREAK,
    SDL_ASSERTION_ABORT,
    SDL_ASSERTION_IGNORE,
    SDL_ASSERTION_ALWAYS_IGNORE
  );

  PSDL_AssertData = ^SDL_AssertData;
  SDL_AssertData = record
    always_ignore: Boolean;
    trigger_count: Cardinal;
    condition: PUTF8Char;
    filename: PUTF8Char;
    linenum: Integer;
    function_: PUTF8Char;
    next: PSDL_AssertData;
  end;

  SDL_AssertionHandler = function(const data: PSDL_AssertData; userdata: Pointer): SDL_AssertState; cdecl;

function SDL_ReportAssertion(data: PSDL_AssertData; func, file_: PUTF8Char; line: Integer): SDL_AssertState; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetAssertionHandler(handler: SDL_AssertionHandler; userdata: Pointer); cdecl;
  external SDL_LIB_NAME;
function SDL_GetDefaultAssertionHandler: SDL_AssertionHandler; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAssertionHandler(puserdata: PPointer): SDL_AssertionHandler; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAssertionReport: PSDL_AssertData; cdecl;
  external SDL_LIB_NAME;
procedure SDL_ResetAssertionReport; cdecl;
  external SDL_LIB_NAME;
