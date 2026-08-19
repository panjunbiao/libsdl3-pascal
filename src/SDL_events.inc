{ SDL_events.inc -- event type enum, payload structs, function list. }

type
  SDL_EventType = (
    SDL_EVENT_FIRST = 0,
    SDL_EVENT_QUIT = $100,
    SDL_EVENT_TERMINATING,
    SDL_EVENT_LOW_MEMORY,
    SDL_EVENT_WILL_ENTER_BACKGROUND,
    SDL_EVENT_DID_ENTER_BACKGROUND,
    SDL_EVENT_WILL_ENTER_FOREGROUND,
    SDL_EVENT_DID_ENTER_FOREGROUND,
    SDL_EVENT_LOCALE_CHANGED,
    SDL_EVENT_SYSTEM_THEME_CHANGED,
    SDL_EVENT_DISPLAY_ORIENTATION = $151,
    SDL_EVENT_DISPLAY_ADDED,
    SDL_EVENT_DISPLAY_REMOVED,
    SDL_EVENT_DISPLAY_MOVED,
    SDL_EVENT_DISPLAY_DESKTOP_MODE_CHANGED,
    SDL_EVENT_DISPLAY_CURRENT_MODE_CHANGED,
    SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED,
    SDL_EVENT_DISPLAY_USABLE_BOUNDS_CHANGED,
    SDL_EVENT_WINDOW_SHOWN = $202,
    SDL_EVENT_WINDOW_HIDDEN,
    SDL_EVENT_WINDOW_EXPOSED,
    SDL_EVENT_WINDOW_MOVED,
    SDL_EVENT_WINDOW_RESIZED,
    SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED,
    SDL_EVENT_WINDOW_METAL_VIEW_RESIZED,
    SDL_EVENT_WINDOW_MINIMIZED,
    SDL_EVENT_WINDOW_MAXIMIZED,
    SDL_EVENT_WINDOW_RESTORED,
    SDL_EVENT_WINDOW_MOUSE_ENTER,
    SDL_EVENT_WINDOW_MOUSE_LEAVE,
    SDL_EVENT_WINDOW_FOCUS_GAINED,
    SDL_EVENT_WINDOW_FOCUS_LOST,
    SDL_EVENT_WINDOW_CLOSE_REQUESTED,
    SDL_EVENT_WINDOW_HIT_TEST,
    SDL_EVENT_WINDOW_ICCPROF_CHANGED,
    SDL_EVENT_WINDOW_DISPLAY_CHANGED,
    SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED,
    SDL_EVENT_WINDOW_SAFE_AREA_CHANGED,
    SDL_EVENT_WINDOW_OCCLUDED,
    SDL_EVENT_WINDOW_ENTER_FULLSCREEN,
    SDL_EVENT_WINDOW_LEAVE_FULLSCREEN,
    SDL_EVENT_WINDOW_DESTROYED,
    SDL_EVENT_WINDOW_HDR_STATE_CHANGED,
    SDL_EVENT_KEY_DOWN = $300,
    SDL_EVENT_KEY_UP,
    SDL_EVENT_TEXT_EDITING,
    SDL_EVENT_TEXT_INPUT,
    SDL_EVENT_KEYMAP_CHANGED,
    SDL_EVENT_KEYBOARD_ADDED,
    SDL_EVENT_KEYBOARD_REMOVED,
    SDL_EVENT_TEXT_EDITING_CANDIDATES,
    SDL_EVENT_SCREEN_KEYBOARD_SHOWN,
    SDL_EVENT_SCREEN_KEYBOARD_HIDDEN,
    SDL_EVENT_MOUSE_MOTION = $400,
    SDL_EVENT_MOUSE_BUTTON_DOWN,
    SDL_EVENT_MOUSE_BUTTON_UP,
    SDL_EVENT_MOUSE_WHEEL,
    SDL_EVENT_MOUSE_ADDED,
    SDL_EVENT_MOUSE_REMOVED,
    SDL_EVENT_JOYSTICK_AXIS_MOTION = $600,
    SDL_EVENT_JOYSTICK_BALL_MOTION,
    SDL_EVENT_JOYSTICK_HAT_MOTION,
    SDL_EVENT_JOYSTICK_BUTTON_DOWN,
    SDL_EVENT_JOYSTICK_BUTTON_UP,
    SDL_EVENT_JOYSTICK_ADDED,
    SDL_EVENT_JOYSTICK_REMOVED,
    SDL_EVENT_JOYSTICK_BATTERY_UPDATED,
    SDL_EVENT_JOYSTICK_UPDATE_COMPLETE,
    SDL_EVENT_GAMEPAD_AXIS_MOTION = $650,
    SDL_EVENT_GAMEPAD_BUTTON_DOWN,
    SDL_EVENT_GAMEPAD_BUTTON_UP,
    SDL_EVENT_GAMEPAD_ADDED,
    SDL_EVENT_GAMEPAD_REMOVED,
    SDL_EVENT_GAMEPAD_REMAPPED,
    SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN,
    SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION,
    SDL_EVENT_GAMEPAD_TOUCHPAD_UP,
    SDL_EVENT_GAMEPAD_SENSOR_UPDATE,
    SDL_EVENT_GAMEPAD_UPDATE_COMPLETE,
    SDL_EVENT_GAMEPAD_STEAM_HANDLE_UPDATED,
    SDL_EVENT_FINGER_DOWN = $700,
    SDL_EVENT_FINGER_UP,
    SDL_EVENT_FINGER_MOTION,
    SDL_EVENT_FINGER_CANCELED,
    SDL_EVENT_PINCH_BEGIN = $710,
    SDL_EVENT_PINCH_UPDATE,
    SDL_EVENT_PINCH_END,
    SDL_EVENT_CLIPBOARD_UPDATE = $900,
    SDL_EVENT_DROP_FILE = $1000,
    SDL_EVENT_DROP_TEXT,
    SDL_EVENT_DROP_BEGIN,
    SDL_EVENT_DROP_COMPLETE,
    SDL_EVENT_DROP_POSITION,
    SDL_EVENT_AUDIO_DEVICE_ADDED = $1100,
    SDL_EVENT_AUDIO_DEVICE_REMOVED,
    SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED,
    SDL_EVENT_SENSOR_UPDATE = $1200,
    SDL_EVENT_PEN_PROXIMITY_IN = $1300,
    SDL_EVENT_PEN_PROXIMITY_OUT,
    SDL_EVENT_PEN_DOWN,
    SDL_EVENT_PEN_UP,
    SDL_EVENT_PEN_BUTTON_DOWN,
    SDL_EVENT_PEN_BUTTON_UP,
    SDL_EVENT_PEN_MOTION,
    SDL_EVENT_PEN_AXIS,
    SDL_EVENT_CAMERA_DEVICE_ADDED = $1400,
    SDL_EVENT_CAMERA_DEVICE_REMOVED,
    SDL_EVENT_CAMERA_DEVICE_APPROVED,
    SDL_EVENT_CAMERA_DEVICE_DENIED,
    SDL_EVENT_RENDER_TARGETS_RESET = $2000,
    SDL_EVENT_RENDER_DEVICE_RESET,
    SDL_EVENT_RENDER_DEVICE_LOST,
    SDL_EVENT_PRIVATE0 = $4000,
    SDL_EVENT_PRIVATE1,
    SDL_EVENT_PRIVATE2,
    SDL_EVENT_PRIVATE3,
    SDL_EVENT_POLL_SENTINEL = $7F00,
    SDL_EVENT_USER = $8000,
    SDL_EVENT_LAST = $FFFF,
    SDL_EVENT_ENUM_PADDING = $7FFFFFFF
  );

const
  SDL_EVENT_DISPLAY_FIRST = SDL_EVENT_DISPLAY_ORIENTATION;
  SDL_EVENT_DISPLAY_LAST = SDL_EVENT_DISPLAY_USABLE_BOUNDS_CHANGED;
  SDL_EVENT_WINDOW_FIRST = SDL_EVENT_WINDOW_SHOWN;
  SDL_EVENT_WINDOW_LAST = SDL_EVENT_WINDOW_HDR_STATE_CHANGED;

type
  SDL_CommonEvent = record
    type_: Uint32;
    reserved: Uint32;
    timestamp: Uint64;
  end;

  SDL_DisplayEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    displayID: SDL_DisplayID;
    data1: Sint32;
    data2: Sint32;
  end;

  SDL_WindowEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    data1: Sint32;
    data2: Sint32;
  end;

  SDL_KeyboardDeviceEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_KeyboardID;
  end;

  SDL_KeyboardEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    which: SDL_KeyboardID;
    scancode: SDL_Scancode;
    key: SDL_Keycode;
    mod_: SDL_Keymod;
    raw: Uint16;
    down: Boolean;
    repeat_: Boolean;
  end;

  SDL_TextEditingEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    text: PUTF8Char;
    start: Sint32;
    length: Sint32;
  end;

  SDL_TextEditingCandidatesEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    candidates: PPUTF8Char;
    num_candidates: Sint32;
    selected_candidate: Sint32;
    horizontal: Boolean;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
  end;

  SDL_TextInputEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    text: PUTF8Char;
  end;

  SDL_MouseDeviceEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_MouseID;
  end;

  SDL_MouseMotionEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    which: SDL_MouseID;
    state: SDL_MouseButtonFlags;
    x: Single;
    y: Single;
    xrel: Single;
    yrel: Single;
  end;

  SDL_MouseButtonEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    which: SDL_MouseID;
    button: Uint8;
    down: Boolean;
    clicks: Uint8;
    padding: Uint8;
    x: Single;
    y: Single;
  end;

  SDL_MouseWheelEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    which: SDL_MouseID;
    x: Single;
    y: Single;
    direction: SDL_MouseWheelDirection;
    mouse_x: Single;
    mouse_y: Single;
    integer_x: Sint32;
    integer_y: Sint32;
  end;

  SDL_JoyAxisEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
    axis: Uint8;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
    value: Sint16;
    padding4: Uint16;
  end;

  SDL_JoyBallEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
    ball: Uint8;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
    xrel: Sint16;
    yrel: Sint16;
  end;

  SDL_JoyHatEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
    hat: Uint8;
    value: Uint8;
    padding1: Uint8;
    padding2: Uint8;
  end;

  SDL_JoyButtonEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
    button: Uint8;
    down: Boolean;
    padding1: Uint8;
    padding2: Uint8;
  end;

  SDL_JoyDeviceEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
  end;

  SDL_JoyBatteryEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
    state: SDL_PowerState;
    percent: Integer;
  end;

  SDL_GamepadAxisEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
    axis: Uint8;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
    value: Sint16;
    padding4: Uint16;
  end;

  SDL_GamepadButtonEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
    button: Uint8;
    down: Boolean;
    padding1: Uint8;
    padding2: Uint8;
  end;

  SDL_GamepadDeviceEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
  end;

  SDL_GamepadTouchpadEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
    touchpad: Sint32;
    finger: Sint32;
    x: Single;
    y: Single;
    pressure: Single;
  end;

  SDL_GamepadSensorEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_JoystickID;
    sensor: Sint32;
    data: array[0..2] of Single;
    sensor_timestamp: Uint64;
  end;

  SDL_AudioDeviceEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    which: SDL_AudioDeviceID;
    recording: Boolean;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
  end;

  SDL_TouchFingerEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    touchID: SDL_TouchID;
    fingerID: SDL_FingerID;
    x: Single;
    y: Single;
    dx: Single;
    dy: Single;
    pressure: Single;
    windowID: SDL_WindowID;
  end;

  SDL_PinchFingerEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    scale: Single;
    windowID: SDL_WindowID;
  end;

  SDL_ClipboardEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    owner: Boolean;
    num_mime_types: Sint32;
    mime_types: PPUTF8Char;
  end;

  SDL_PenProximityEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    which: SDL_PenID;
  end;

  SDL_PenMotionEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    which: SDL_PenID;
    pen_state: SDL_PenInputFlags;
    x: Single;
    y: Single;
  end;

  SDL_PenTouchEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    which: SDL_PenID;
    pen_state: SDL_PenInputFlags;
    x: Single;
    y: Single;
    eraser: Boolean;
    down: Boolean;
  end;

  SDL_PenButtonEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    which: SDL_PenID;
    pen_state: SDL_PenInputFlags;
    x: Single;
    y: Single;
    button: Uint8;
    down: Boolean;
  end;

  SDL_PenAxisEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    which: SDL_PenID;
    pen_state: SDL_PenInputFlags;
    x: Single;
    y: Single;
    axis: SDL_PenAxis;
    value: Single;
  end;

  SDL_QuitEvent = record
    type_: SDL_EventType;
    reserved: Uint32;
    timestamp: Uint64;
  end;

  SDL_UserEvent = record
    type_: Uint32;
    reserved: Uint32;
    timestamp: Uint64;
    windowID: SDL_WindowID;
    code: Sint32;
    data1: Pointer;
    data2: Pointer;
  end;

  PSDL_Event = ^SDL_Event;
  SDL_Event = record
    case Integer of
      0: (type_: Uint32);
      1: (common: SDL_CommonEvent);
      2: (display: SDL_DisplayEvent);
      3: (window: SDL_WindowEvent);
      4: (kdevice: SDL_KeyboardDeviceEvent);
      5: (key: SDL_KeyboardEvent);
      6: (edit: SDL_TextEditingEvent);
      7: (edit_candidates: SDL_TextEditingCandidatesEvent);
      8: (text: SDL_TextInputEvent);
      9: (mdevice: SDL_MouseDeviceEvent);
      10: (motion: SDL_MouseMotionEvent);
      11: (button: SDL_MouseButtonEvent);
      12: (wheel: SDL_MouseWheelEvent);
      13: (jdevice: SDL_JoyDeviceEvent);
      14: (jaxis: SDL_JoyAxisEvent);
      15: (jball: SDL_JoyBallEvent);
      16: (jhat: SDL_JoyHatEvent);
      17: (jbutton: SDL_JoyButtonEvent);
      18: (jbattery: SDL_JoyBatteryEvent);
      19: (gdevice: SDL_GamepadDeviceEvent);
      20: (gaxis: SDL_GamepadAxisEvent);
      21: (gbutton: SDL_GamepadButtonEvent);
      22: (gtouchpad: SDL_GamepadTouchpadEvent);
      23: (gsensor: SDL_GamepadSensorEvent);
      24: (adevice: SDL_AudioDeviceEvent);
      26: (tfinger: SDL_TouchFingerEvent);
      27: (pinch: SDL_PinchFingerEvent);
      28: (clipboard: SDL_ClipboardEvent);
      29: (pproximity: SDL_PenProximityEvent);
      30: (ptouch: SDL_PenTouchEvent);
      31: (pmotion: SDL_PenMotionEvent);
      32: (pbutton: SDL_PenButtonEvent);
      33: (paxis: SDL_PenAxisEvent);
      34: (quit: SDL_QuitEvent);
      35: (user: SDL_UserEvent);
      255: (padding: array[0..127] of Uint8);
  end;

  SDL_EventAction = (
    SDL_ADDEVENT,
    SDL_PEEKEVENT,
    SDL_GETEVENT
  );

  SDL_EventFilter = function(userdata: Pointer; event: PSDL_Event): Boolean; cdecl;
  PSDL_EventFilter = ^SDL_EventFilter;

procedure SDL_PumpEvents; cdecl; external SDL_LIB_NAME;
function SDL_PeepEvents(events: PSDL_Event; numevents: Integer; action: SDL_EventAction; minType, maxType: Uint32): Integer; cdecl; external SDL_LIB_NAME;
function SDL_HasEvent(type_: Uint32): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_HasEvents(minType, maxType: Uint32): Boolean; cdecl; external SDL_LIB_NAME;
procedure SDL_FlushEvent(type_: Uint32); cdecl; external SDL_LIB_NAME;
procedure SDL_FlushEvents(minType, maxType: Uint32); cdecl; external SDL_LIB_NAME;
function SDL_PollEvent(event: PSDL_Event): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_WaitEvent(event: PSDL_Event): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_WaitEventTimeout(event: PSDL_Event; timeoutMS: Sint32): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_PushEvent(event: PSDL_Event): Boolean; cdecl; external SDL_LIB_NAME;
procedure SDL_SetEventFilter(filter: SDL_EventFilter; userdata: Pointer); cdecl; external SDL_LIB_NAME;
function SDL_GetEventFilter(filter: PSDL_EventFilter; userdata: PPointer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_AddEventWatch(filter: SDL_EventFilter; userdata: Pointer): Boolean; cdecl; external SDL_LIB_NAME;
procedure SDL_RemoveEventWatch(filter: SDL_EventFilter; userdata: Pointer); cdecl; external SDL_LIB_NAME;
procedure SDL_FilterEvents(filter: SDL_EventFilter; userdata: Pointer); cdecl; external SDL_LIB_NAME;
procedure SDL_SetEventEnabled(type_: Uint32; enabled: Boolean); cdecl; external SDL_LIB_NAME;
function SDL_EventEnabled(type_: Uint32): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_RegisterEvents(numevents: Integer): Uint32; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowFromEvent(const event: PSDL_Event): PSDL_Window; cdecl; external SDL_LIB_NAME;
function SDL_GetEventDescription(const event: PSDL_Event; buf: PUTF8Char; buflen: Integer): Integer; cdecl; external SDL_LIB_NAME;
