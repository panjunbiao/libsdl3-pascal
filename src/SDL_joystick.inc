{ SDL_joystick.inc -- 1-to-1 from SDL_joystick.h }

type
  SDL_Joystick = record
  end;
  PSDL_Joystick = ^SDL_Joystick;

  SDL_JoystickID = Uint32;
  PSDL_JoystickID = ^SDL_JoystickID;

  SDL_JoystickType = (
    SDL_JOYSTICK_TYPE_UNKNOWN,
    SDL_JOYSTICK_TYPE_GAMEPAD,
    SDL_JOYSTICK_TYPE_WHEEL,
    SDL_JOYSTICK_TYPE_ARCADE_STICK,
    SDL_JOYSTICK_TYPE_FLIGHT_STICK,
    SDL_JOYSTICK_TYPE_DANCE_PAD,
    SDL_JOYSTICK_TYPE_GUITAR,
    SDL_JOYSTICK_TYPE_DRUM_KIT,
    SDL_JOYSTICK_TYPE_ARCADE_PAD,
    SDL_JOYSTICK_TYPE_THROTTLE,
    SDL_JOYSTICK_TYPE_COUNT
  );

  SDL_JoystickConnectionState = (
    SDL_JOYSTICK_CONNECTION_INVALID = -1,
    SDL_JOYSTICK_CONNECTION_UNKNOWN,
    SDL_JOYSTICK_CONNECTION_WIRED,
    SDL_JOYSTICK_CONNECTION_WIRELESS
  );

  PSDL_VirtualJoystickTouchpadDesc = ^SDL_VirtualJoystickTouchpadDesc;
  SDL_VirtualJoystickTouchpadDesc = record
    nfingers: Uint16;
    padding: array[0..2] of Uint16;
  end;

  PSDL_VirtualJoystickSensorDesc = ^SDL_VirtualJoystickSensorDesc;
  SDL_VirtualJoystickSensorDesc = record
    type_: SDL_SensorType;
    rate: Single;
  end;

  PSDL_VirtualJoystickDesc = ^SDL_VirtualJoystickDesc;
  SDL_VirtualJoystickDesc = record
    version: Uint32;
    type_: Uint16;
    padding: Uint16;
    vendor_id: Uint16;
    product_id: Uint16;
    naxes: Uint16;
    nbuttons: Uint16;
    nballs: Uint16;
    nhats: Uint16;
    ntouchpads: Uint16;
    nsensors: Uint16;
    padding2: array[0..1] of Uint16;
    button_mask: Uint32;
    axis_mask: Uint32;
    name: PUTF8Char;
    touchpads: PSDL_VirtualJoystickTouchpadDesc;
    sensors: PSDL_VirtualJoystickSensorDesc;
    userdata: Pointer;
    Update: procedure(userdata: Pointer); cdecl;
    SetPlayerIndex: procedure(userdata: Pointer; player_index: Integer); cdecl;
    Rumble: function(userdata: Pointer; low_frequency_rumble, high_frequency_rumble: Uint16): Boolean; cdecl;
    RumbleTriggers: function(userdata: Pointer; left_rumble, right_rumble: Uint16): Boolean; cdecl;
    SetLED: function(userdata: Pointer; red, green, blue: Uint8): Boolean; cdecl;
    SendEffect: function(userdata: Pointer; const data: Pointer; size: Integer): Boolean; cdecl;
    SetSensorsEnabled: function(userdata: Pointer; enabled: Boolean): Boolean; cdecl;
    Cleanup: procedure(userdata: Pointer); cdecl;
  end;

const
  SDL_JOYSTICK_AXIS_MAX = 32767;
  SDL_JOYSTICK_AXIS_MIN = -32768;
  SDL_HAT_CENTERED = $00;
  SDL_HAT_UP = $01;
  SDL_HAT_RIGHT = $02;
  SDL_HAT_DOWN = $04;
  SDL_HAT_LEFT = $08;
  SDL_HAT_RIGHTUP = SDL_HAT_RIGHT or SDL_HAT_UP;
  SDL_HAT_RIGHTDOWN = SDL_HAT_RIGHT or SDL_HAT_DOWN;
  SDL_HAT_LEFTUP = SDL_HAT_LEFT or SDL_HAT_UP;
  SDL_HAT_LEFTDOWN = SDL_HAT_LEFT or SDL_HAT_DOWN;
  SDL_PROP_JOYSTICK_CAP_MONO_LED_BOOLEAN = 'SDL.joystick.cap.mono_led';
  SDL_PROP_JOYSTICK_CAP_RGB_LED_BOOLEAN = 'SDL.joystick.cap.rgb_led';
  SDL_PROP_JOYSTICK_CAP_PLAYER_LED_BOOLEAN = 'SDL.joystick.cap.player_led';
  SDL_PROP_JOYSTICK_CAP_RUMBLE_BOOLEAN = 'SDL.joystick.cap.rumble';
  SDL_PROP_JOYSTICK_CAP_TRIGGER_RUMBLE_BOOLEAN = 'SDL.joystick.cap.trigger_rumble';

procedure SDL_INIT_INTERFACE(desc: PSDL_VirtualJoystickDesc); overload;

procedure SDL_LockJoysticks; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnlockJoysticks; cdecl;
  external SDL_LIB_NAME;
function SDL_HasJoystick: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoysticks(count: PInteger): PSDL_JoystickID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickNameForID(instance_id: SDL_JoystickID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickPathForID(instance_id: SDL_JoystickID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickPlayerIndexForID(instance_id: SDL_JoystickID): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickGUIDForID(instance_id: SDL_JoystickID): SDL_GUID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickVendorForID(instance_id: SDL_JoystickID): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickProductForID(instance_id: SDL_JoystickID): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickProductVersionForID(instance_id: SDL_JoystickID): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickTypeForID(instance_id: SDL_JoystickID): SDL_JoystickType; cdecl;
  external SDL_LIB_NAME;
function SDL_OpenJoystick(instance_id: SDL_JoystickID): PSDL_Joystick; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickFromID(instance_id: SDL_JoystickID): PSDL_Joystick; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickFromPlayerIndex(player_index: Integer): PSDL_Joystick; cdecl;
  external SDL_LIB_NAME;
function SDL_AttachVirtualJoystick(const desc: PSDL_VirtualJoystickDesc): SDL_JoystickID; cdecl;
  external SDL_LIB_NAME;
function SDL_DetachVirtualJoystick(instance_id: SDL_JoystickID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_IsJoystickVirtual(instance_id: SDL_JoystickID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetJoystickVirtualAxis(joystick: PSDL_Joystick; axis: Integer; value: Sint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetJoystickVirtualBall(joystick: PSDL_Joystick; ball: Integer; xrel, yrel: Sint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetJoystickVirtualButton(joystick: PSDL_Joystick; button: Integer; down: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetJoystickVirtualHat(joystick: PSDL_Joystick; hat: Integer; value: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetJoystickVirtualTouchpad(joystick: PSDL_Joystick; touchpad, finger: Integer; down: Boolean;
  x, y, pressure: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SendJoystickVirtualSensorData(joystick: PSDL_Joystick; type_: SDL_SensorType; sensor_timestamp: Uint64;
  const data: PSingle; num_values: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickProperties(joystick: PSDL_Joystick): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickName(joystick: PSDL_Joystick): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickPath(joystick: PSDL_Joystick): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickPlayerIndex(joystick: PSDL_Joystick): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_SetJoystickPlayerIndex(joystick: PSDL_Joystick; player_index: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickGUID(joystick: PSDL_Joystick): SDL_GUID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickVendor(joystick: PSDL_Joystick): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickProduct(joystick: PSDL_Joystick): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickProductVersion(joystick: PSDL_Joystick): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickFirmwareVersion(joystick: PSDL_Joystick): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickSerial(joystick: PSDL_Joystick): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickType(joystick: PSDL_Joystick): SDL_JoystickType; cdecl;
  external SDL_LIB_NAME;
procedure SDL_GetJoystickGUIDInfo(guid: SDL_GUID; vendor, product, version, crc16: PUint16); cdecl;
  external SDL_LIB_NAME;
function SDL_JoystickConnected(joystick: PSDL_Joystick): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickID(joystick: PSDL_Joystick): SDL_JoystickID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetNumJoystickAxes(joystick: PSDL_Joystick): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetNumJoystickBalls(joystick: PSDL_Joystick): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetNumJoystickHats(joystick: PSDL_Joystick): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetNumJoystickButtons(joystick: PSDL_Joystick): Integer; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetJoystickEventsEnabled(enabled: Boolean); cdecl;
  external SDL_LIB_NAME;
function SDL_JoystickEventsEnabled: Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UpdateJoysticks; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickAxis(joystick: PSDL_Joystick; axis: Integer): Sint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickAxisInitialState(joystick: PSDL_Joystick; axis: Integer; state: PSint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickBall(joystick: PSDL_Joystick; ball: Integer; dx, dy: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickHat(joystick: PSDL_Joystick; hat: Integer): Uint8; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickButton(joystick: PSDL_Joystick; button: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RumbleJoystick(joystick: PSDL_Joystick; low_frequency_rumble, high_frequency_rumble: Uint16;
  duration_ms: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RumbleJoystickTriggers(joystick: PSDL_Joystick; left_rumble, right_rumble: Uint16;
  duration_ms: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetJoystickLED(joystick: PSDL_Joystick; red, green, blue: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SendJoystickEffect(joystick: PSDL_Joystick; const data: Pointer; size: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_CloseJoystick(joystick: PSDL_Joystick); cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickConnectionState(joystick: PSDL_Joystick): SDL_JoystickConnectionState; cdecl;
  external SDL_LIB_NAME;
function SDL_GetJoystickPowerInfo(joystick: PSDL_Joystick; percent: PInteger): SDL_PowerState; cdecl;
  external SDL_LIB_NAME;
