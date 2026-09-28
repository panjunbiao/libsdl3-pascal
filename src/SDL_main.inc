{ SDL_main.inc -- 1-to-1 from SDL_main.h (SDL 3.4.16) }
{ C SDL_main rewrite macros stay out. Delphi apps call SDL_SetMainReady. }

type
  SDL_main_func = function(argc: Integer; argv: PPUTF8Char): Integer; cdecl;

procedure SDL_SetMainReady; cdecl;
  external SDL_LIB_NAME;
function SDL_RunApp(argc: Integer; argv: PPUTF8Char; mainFunction: SDL_main_func; reserved: Pointer): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_EnterAppMainCallbacks(argc: Integer; argv: PPUTF8Char; appinit: SDL_AppInit_func; appiter: SDL_AppIterate_func; appevent: SDL_AppEvent_func; appquit: SDL_AppQuit_func): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_RegisterApp(name: PUTF8Char; style: Uint32; hInst: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnregisterApp; cdecl;
  external SDL_LIB_NAME;
procedure SDL_GDKSuspendComplete; cdecl;
  external SDL_LIB_NAME;
