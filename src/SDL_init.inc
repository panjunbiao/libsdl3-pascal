{ SDL_init.inc -- 1-to-1 from SDL_init.h }

type
  SDL_InitFlags = Uint32;

  SDL_AppResult = (
    SDL_APP_CONTINUE,
    SDL_APP_SUCCESS,
    SDL_APP_FAILURE
  );

  SDL_AppInit_func = function(appstate: PPointer; argc: Integer; argv: PPAnsiChar): SDL_AppResult; cdecl;
  SDL_AppIterate_func = function(appstate: Pointer): SDL_AppResult; cdecl;
  SDL_AppEvent_func = function(appstate: Pointer; event: PSDL_Event): SDL_AppResult; cdecl;
  SDL_AppQuit_func = procedure(appstate: Pointer; result_: SDL_AppResult); cdecl;
  SDL_MainThreadCallback = procedure(userdata: Pointer); cdecl;

const
  SDL_INIT_AUDIO = $00000010;
  SDL_INIT_VIDEO = $00000020;
  SDL_INIT_JOYSTICK = $00000200;
  SDL_INIT_HAPTIC = $00001000;
  SDL_INIT_GAMEPAD = $00002000;
  SDL_INIT_EVENTS = $00004000;
  SDL_INIT_SENSOR = $00008000;
  SDL_INIT_CAMERA = $00010000;

  SDL_PROP_APP_METADATA_NAME_STRING = 'SDL.app.metadata.name';
  SDL_PROP_APP_METADATA_VERSION_STRING = 'SDL.app.metadata.version';
  SDL_PROP_APP_METADATA_IDENTIFIER_STRING = 'SDL.app.metadata.identifier';
  SDL_PROP_APP_METADATA_CREATOR_STRING = 'SDL.app.metadata.creator';
  SDL_PROP_APP_METADATA_COPYRIGHT_STRING = 'SDL.app.metadata.copyright';
  SDL_PROP_APP_METADATA_URL_STRING = 'SDL.app.metadata.url';
  SDL_PROP_APP_METADATA_TYPE_STRING = 'SDL.app.metadata.type';

function SDL_Init(flags: SDL_InitFlags): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_InitSubSystem(flags: SDL_InitFlags): Boolean; cdecl; external SDL_LIB_NAME;
procedure SDL_QuitSubSystem(flags: SDL_InitFlags); cdecl; external SDL_LIB_NAME;
function SDL_WasInit(flags: SDL_InitFlags): SDL_InitFlags; cdecl; external SDL_LIB_NAME;
procedure SDL_Quit; cdecl; external SDL_LIB_NAME;
function SDL_IsMainThread: Boolean; cdecl; external SDL_LIB_NAME;
function SDL_RunOnMainThread(callback: SDL_MainThreadCallback; userdata: Pointer; wait_complete: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetAppMetadata(appname, appversion, appidentifier: PUTF8Char): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetAppMetadataProperty(name, value: PUTF8Char): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetAppMetadataProperty(name: PUTF8Char): PUTF8Char; cdecl; external SDL_LIB_NAME;
