{ SDL_mouse.inc -- 1-to-1 from SDL_mouse.h }

type
  SDL_MouseID = Uint32;
  PSDL_MouseID = ^SDL_MouseID;

  SDL_Cursor = record
  end;
  PSDL_Cursor = ^SDL_Cursor;

  SDL_SystemCursor = (
    SDL_SYSTEM_CURSOR_DEFAULT,
    SDL_SYSTEM_CURSOR_TEXT,
    SDL_SYSTEM_CURSOR_WAIT,
    SDL_SYSTEM_CURSOR_CROSSHAIR,
    SDL_SYSTEM_CURSOR_PROGRESS,
    SDL_SYSTEM_CURSOR_NWSE_RESIZE,
    SDL_SYSTEM_CURSOR_NESW_RESIZE,
    SDL_SYSTEM_CURSOR_EW_RESIZE,
    SDL_SYSTEM_CURSOR_NS_RESIZE,
    SDL_SYSTEM_CURSOR_MOVE,
    SDL_SYSTEM_CURSOR_NOT_ALLOWED,
    SDL_SYSTEM_CURSOR_POINTER,
    SDL_SYSTEM_CURSOR_NW_RESIZE,
    SDL_SYSTEM_CURSOR_N_RESIZE,
    SDL_SYSTEM_CURSOR_NE_RESIZE,
    SDL_SYSTEM_CURSOR_E_RESIZE,
    SDL_SYSTEM_CURSOR_SE_RESIZE,
    SDL_SYSTEM_CURSOR_S_RESIZE,
    SDL_SYSTEM_CURSOR_SW_RESIZE,
    SDL_SYSTEM_CURSOR_W_RESIZE,
    SDL_SYSTEM_CURSOR_CONTEXT_MENU,
    SDL_SYSTEM_CURSOR_HELP,
    SDL_SYSTEM_CURSOR_CELL,
    SDL_SYSTEM_CURSOR_VERTICAL_TEXT,
    SDL_SYSTEM_CURSOR_ALIAS,
    SDL_SYSTEM_CURSOR_COPY,
    SDL_SYSTEM_CURSOR_NO_DROP,
    SDL_SYSTEM_CURSOR_GRAB,
    SDL_SYSTEM_CURSOR_GRABBING,
    SDL_SYSTEM_CURSOR_COL_RESIZE,
    SDL_SYSTEM_CURSOR_ROW_RESIZE,
    SDL_SYSTEM_CURSOR_ALL_SCROLL,
    SDL_SYSTEM_CURSOR_ZOOM_IN,
    SDL_SYSTEM_CURSOR_ZOOM_OUT,
    SDL_SYSTEM_CURSOR_COUNT
  );

  SDL_MouseWheelDirection = (
    SDL_MOUSEWHEEL_NORMAL,
    SDL_MOUSEWHEEL_FLIPPED
  );

  PSDL_CursorFrameInfo = ^SDL_CursorFrameInfo;
  SDL_CursorFrameInfo = record
    surface: PSDL_Surface;
    duration: Uint32;
  end;

  SDL_MouseButtonFlags = Uint32;

  SDL_MouseMotionTransformCallback = procedure(userdata: Pointer; timestamp: Uint64;
    window: PSDL_Window; mouseID: SDL_MouseID; x, y: PSingle); cdecl;

const
  SDL_BUTTON_LEFT = 1;
  SDL_BUTTON_MIDDLE = 2;
  SDL_BUTTON_RIGHT = 3;
  SDL_BUTTON_X1 = 4;
  SDL_BUTTON_X2 = 5;
  SDL_BUTTON_LMASK = $00000001;
  SDL_BUTTON_MMASK = $00000002;
  SDL_BUTTON_RMASK = $00000004;
  SDL_BUTTON_X1MASK = $00000008;
  SDL_BUTTON_X2MASK = $00000010;

function SDL_HasMouse: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetMice(count: PInteger): PSDL_MouseID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetMouseNameForID(instance_id: SDL_MouseID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetMouseFocus: PSDL_Window; cdecl;
  external SDL_LIB_NAME;
function SDL_GetMouseState(x, y: PSingle): SDL_MouseButtonFlags; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGlobalMouseState(x, y: PSingle): SDL_MouseButtonFlags; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRelativeMouseState(x, y: PSingle): SDL_MouseButtonFlags; cdecl;
  external SDL_LIB_NAME;
procedure SDL_WarpMouseInWindow(window: PSDL_Window; x, y: Single); cdecl;
  external SDL_LIB_NAME;
function SDL_WarpMouseGlobal(x, y: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRelativeMouseTransform(callback: SDL_MouseMotionTransformCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetWindowRelativeMouseMode(window: PSDL_Window; enabled: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetWindowRelativeMouseMode(window: PSDL_Window): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CaptureMouse(enabled: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateCursor(const data, mask: PUint8; w, h, hot_x, hot_y: Integer): PSDL_Cursor; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateColorCursor(surface: PSDL_Surface; hot_x, hot_y: Integer): PSDL_Cursor; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateAnimatedCursor(frames: PSDL_CursorFrameInfo; frame_count, hot_x, hot_y: Integer): PSDL_Cursor; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateSystemCursor(id: SDL_SystemCursor): PSDL_Cursor; cdecl;
  external SDL_LIB_NAME;
function SDL_SetCursor(cursor: PSDL_Cursor): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCursor: PSDL_Cursor; cdecl;
  external SDL_LIB_NAME;
function SDL_GetDefaultCursor: PSDL_Cursor; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyCursor(cursor: PSDL_Cursor); cdecl;
  external SDL_LIB_NAME;
function SDL_ShowCursor: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HideCursor: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CursorVisible: Boolean; cdecl;
  external SDL_LIB_NAME;
