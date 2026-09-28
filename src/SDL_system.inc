{ SDL_system.inc -- 1-to-1 from SDL_system.h (SDL 3.4.16) }
{ OS handles that are not in this unit stay Pointer. }

type
  { tagMSG; do not use the Windows unit in SDL3.pas. }
  PSDL_WindowsMSG = Pointer;
  SDL_WindowsMessageHook = function(userdata: Pointer; msg: PSDL_WindowsMSG): Boolean; cdecl;

  SDL_X11EventHook = function(userdata: Pointer; xevent: Pointer): Boolean; cdecl;
  SDL_iOSAnimationCallback = procedure(userdata: Pointer); cdecl;
  SDL_RequestAndroidPermissionCallback = procedure(userdata: Pointer; permission: PUTF8Char; granted: Boolean); cdecl;

  { GDK handles. The real OS types are not declared in this unit. }
  XTaskQueueHandle = Pointer;
  PXTaskQueueHandle = ^XTaskQueueHandle;
  XUserHandle = Pointer;
  PXUserHandle = ^XUserHandle;

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
procedure SDL_SetX11EventHook(callback: SDL_X11EventHook; userdata: Pointer); cdecl;
  external SDL_LIB_NAME;
function SDL_SetLinuxThreadPriority(threadID: Sint64; priority: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetLinuxThreadPriorityAndPolicy(threadID: Sint64; sdlPriority: Integer; schedPolicy: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetiOSAnimationCallback(window: PSDL_Window; interval: Integer; callback: SDL_iOSAnimationCallback; callbackParam: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetiOSEventPump(enabled: Boolean); cdecl;
  external SDL_LIB_NAME;
function SDL_GetAndroidJNIEnv: Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAndroidActivity: Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAndroidSDKVersion: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_IsChromebook: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_IsDeXMode: Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SendAndroidBackButton; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAndroidInternalStoragePath: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAndroidExternalStorageState: Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAndroidExternalStoragePath: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAndroidCachePath: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_RequestAndroidPermission(permission: PUTF8Char; cb: SDL_RequestAndroidPermissionCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ShowAndroidToast(message: PUTF8Char; duration: Integer; gravity: Integer; xoffset: Integer; yoffset: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SendAndroidMessage(command: Uint32; param: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_OnApplicationDidChangeStatusBarOrientation; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGDKTaskQueue(outTaskQueue: PXTaskQueueHandle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGDKDefaultUser(outUserHandle: PXUserHandle): Boolean; cdecl;
  external SDL_LIB_NAME;
