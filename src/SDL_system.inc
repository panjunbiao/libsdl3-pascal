{ SDL_system.inc -- Windows subset + portable helpers from SDL_system.h }
{ Skipped: X11, Linux, iOS, Android, GDK (first release is Delphi Win64). }

type
  { tagMSG; do not use the Windows unit in SDL3.pas. }
  PSDL_WindowsMSG = Pointer;
  SDL_WindowsMessageHook = function(userdata: Pointer; msg: PSDL_WindowsMSG): Boolean; cdecl;

  SDL_Sandbox = (
    SDL_SANDBOX_NONE = 0,
    SDL_SANDBOX_UNKNOWN_CONTAINER,
    SDL_SANDBOX_FLATPAK,
    SDL_SANDBOX_SNAP,
    SDL_SANDBOX_MACOS
  );

procedure SDL_SetWindowsMessageHook(callback: SDL_WindowsMessageHook; userdata: Pointer); cdecl;
  external SDL_LIB_NAME;
function SDL_GetDirect3D9AdapterIndex(displayID: SDL_DisplayID): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetDXGIOutputInfo(displayID: SDL_DisplayID; adapterIndex, outputIndex: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_IsTablet: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_IsTV: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSandbox: SDL_Sandbox; cdecl;
  external SDL_LIB_NAME;
procedure SDL_OnApplicationWillTerminate; cdecl;
  external SDL_LIB_NAME;
procedure SDL_OnApplicationDidReceiveMemoryWarning; cdecl;
  external SDL_LIB_NAME;
procedure SDL_OnApplicationWillEnterBackground; cdecl;
  external SDL_LIB_NAME;
procedure SDL_OnApplicationDidEnterBackground; cdecl;
  external SDL_LIB_NAME;
procedure SDL_OnApplicationWillEnterForeground; cdecl;
  external SDL_LIB_NAME;
procedure SDL_OnApplicationDidEnterForeground; cdecl;
  external SDL_LIB_NAME;
