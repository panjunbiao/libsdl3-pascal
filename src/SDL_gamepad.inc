{ SDL_gamepad.inc -- 1-to-1 from SDL_gamepad.h }

type
  SDL_Gamepad = record
  end;
  PSDL_Gamepad = ^SDL_Gamepad;

  SDL_GamepadType = (
    SDL_GAMEPAD_TYPE_UNKNOWN = 0,
    SDL_GAMEPAD_TYPE_STANDARD,
    SDL_GAMEPAD_TYPE_XBOX360,
    SDL_GAMEPAD_TYPE_XBOXONE,
    SDL_GAMEPAD_TYPE_PS3,
    SDL_GAMEPAD_TYPE_PS4,
    SDL_GAMEPAD_TYPE_PS5,
    SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_PRO,
    SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_LEFT,
    SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_RIGHT,
    SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_PAIR,
    SDL_GAMEPAD_TYPE_GAMECUBE,
    SDL_GAMEPAD_TYPE_STEAM,
    SDL_GAMEPAD_TYPE_COUNT
  );

  SDL_GamepadButton = (
    SDL_GAMEPAD_BUTTON_INVALID = -1,
    SDL_GAMEPAD_BUTTON_SOUTH,
    SDL_GAMEPAD_BUTTON_EAST,
    SDL_GAMEPAD_BUTTON_WEST,
    SDL_GAMEPAD_BUTTON_NORTH,
    SDL_GAMEPAD_BUTTON_BACK,
    SDL_GAMEPAD_BUTTON_GUIDE,
    SDL_GAMEPAD_BUTTON_START,
    SDL_GAMEPAD_BUTTON_LEFT_STICK,
    SDL_GAMEPAD_BUTTON_RIGHT_STICK,
    SDL_GAMEPAD_BUTTON_LEFT_SHOULDER,
    SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER,
    SDL_GAMEPAD_BUTTON_DPAD_UP,
    SDL_GAMEPAD_BUTTON_DPAD_DOWN,
    SDL_GAMEPAD_BUTTON_DPAD_LEFT,
    SDL_GAMEPAD_BUTTON_DPAD_RIGHT,
    SDL_GAMEPAD_BUTTON_MISC1,
    SDL_GAMEPAD_BUTTON_RIGHT_PADDLE1,
    SDL_GAMEPAD_BUTTON_LEFT_PADDLE1,
    SDL_GAMEPAD_BUTTON_RIGHT_PADDLE2,
    SDL_GAMEPAD_BUTTON_LEFT_PADDLE2,
    SDL_GAMEPAD_BUTTON_TOUCHPAD,
    SDL_GAMEPAD_BUTTON_MISC2,
    SDL_GAMEPAD_BUTTON_MISC3,
    SDL_GAMEPAD_BUTTON_MISC4,
    SDL_GAMEPAD_BUTTON_MISC5,
    SDL_GAMEPAD_BUTTON_MISC6,
    SDL_GAMEPAD_BUTTON_COUNT
  );

  SDL_GamepadButtonLabel = (
    SDL_GAMEPAD_BUTTON_LABEL_UNKNOWN,
    SDL_GAMEPAD_BUTTON_LABEL_A,
    SDL_GAMEPAD_BUTTON_LABEL_B,
    SDL_GAMEPAD_BUTTON_LABEL_X,
    SDL_GAMEPAD_BUTTON_LABEL_Y,
    SDL_GAMEPAD_BUTTON_LABEL_CROSS,
    SDL_GAMEPAD_BUTTON_LABEL_CIRCLE,
    SDL_GAMEPAD_BUTTON_LABEL_SQUARE,
    SDL_GAMEPAD_BUTTON_LABEL_TRIANGLE
  );

  SDL_GamepadAxis = (
    SDL_GAMEPAD_AXIS_INVALID = -1,
    SDL_GAMEPAD_AXIS_LEFTX,
    SDL_GAMEPAD_AXIS_LEFTY,
    SDL_GAMEPAD_AXIS_RIGHTX,
    SDL_GAMEPAD_AXIS_RIGHTY,
    SDL_GAMEPAD_AXIS_LEFT_TRIGGER,
    SDL_GAMEPAD_AXIS_RIGHT_TRIGGER,
    SDL_GAMEPAD_AXIS_COUNT
  );

  SDL_GamepadCapSenseType = (
    SDL_GAMEPAD_CAPSENSE_INVALID = -1,
    SDL_GAMEPAD_CAPSENSE_LEFT_STICK,
    SDL_GAMEPAD_CAPSENSE_RIGHT_STICK,
    SDL_GAMEPAD_CAPSENSE_LEFT_GRIP,
    SDL_GAMEPAD_CAPSENSE_RIGHT_GRIP,
    SDL_GAMEPAD_CAPSENSE_COUNT
  );

  SDL_GamepadBindingType = (
    SDL_GAMEPAD_BINDTYPE_NONE = 0,
    SDL_GAMEPAD_BINDTYPE_BUTTON,
    SDL_GAMEPAD_BINDTYPE_AXIS,
    SDL_GAMEPAD_BINDTYPE_HAT
  );

  SDL_GamepadBindingAxis = record
    axis: Integer;
    axis_min: Integer;
    axis_max: Integer;
  end;

  SDL_GamepadBindingHat = record
    hat: Integer;
    hat_mask: Integer;
  end;

  SDL_GamepadBindingInput = record
    case Integer of
      0: (button: Integer);
      1: (axis: SDL_GamepadBindingAxis);
      2: (hat: SDL_GamepadBindingHat);
  end;

  SDL_GamepadBindingOutputAxis = record
    axis: SDL_GamepadAxis;
    axis_min: Integer;
    axis_max: Integer;
  end;

  SDL_GamepadBindingOutput = record
    case Integer of
      0: (button: SDL_GamepadButton);
      1: (axis: SDL_GamepadBindingOutputAxis);
  end;

  PSDL_GamepadBinding = ^SDL_GamepadBinding;
  PPSDL_GamepadBinding = ^PSDL_GamepadBinding;
  SDL_GamepadBinding = record
    input_type: SDL_GamepadBindingType;
    input: SDL_GamepadBindingInput;
    output_type: SDL_GamepadBindingType;
    output: SDL_GamepadBindingOutput;
  end;

const
  SDL_PROP_GAMEPAD_CAP_MONO_LED_BOOLEAN = SDL_PROP_JOYSTICK_CAP_MONO_LED_BOOLEAN;
  SDL_PROP_GAMEPAD_CAP_RGB_LED_BOOLEAN = SDL_PROP_JOYSTICK_CAP_RGB_LED_BOOLEAN;
  SDL_PROP_GAMEPAD_CAP_PLAYER_LED_BOOLEAN = SDL_PROP_JOYSTICK_CAP_PLAYER_LED_BOOLEAN;
  SDL_PROP_GAMEPAD_CAP_RUMBLE_BOOLEAN = SDL_PROP_JOYSTICK_CAP_RUMBLE_BOOLEAN;
  SDL_PROP_GAMEPAD_CAP_TRIGGER_RUMBLE_BOOLEAN = SDL_PROP_JOYSTICK_CAP_TRIGGER_RUMBLE_BOOLEAN;

function SDL_AddGamepadMapping(mapping: PUTF8Char): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_AddGamepadMappingsFromIO(src: PSDL_IOStream; closeio: Boolean): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_AddGamepadMappingsFromFile(file_: PUTF8Char): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_ReloadGamepadMappings: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadMappings(count: PInteger): PPUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadMappingForGUID(guid: SDL_GUID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadMapping(gamepad: PSDL_Gamepad): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_SetGamepadMapping(instance_id: SDL_JoystickID; mapping: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasGamepad: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepads(count: PInteger): PSDL_JoystickID; cdecl;
  external SDL_LIB_NAME;
function SDL_IsGamepad(instance_id: SDL_JoystickID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadNameForID(instance_id: SDL_JoystickID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadPathForID(instance_id: SDL_JoystickID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadPlayerIndexForID(instance_id: SDL_JoystickID): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadGUIDForID(instance_id: SDL_JoystickID): SDL_GUID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadVendorForID(instance_id: SDL_JoystickID): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadProductForID(instance_id: SDL_JoystickID): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadProductVersionForID(instance_id: SDL_JoystickID): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadTypeForID(instance_id: SDL_JoystickID): SDL_GamepadType; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRealGamepadTypeForID(instance_id: SDL_JoystickID): SDL_GamepadType; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadMappingForID(instance_id: SDL_JoystickID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_OpenGamepad(instance_id: SDL_JoystickID): PSDL_Gamepad; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadFromID(instance_id: SDL_JoystickID): PSDL_Gamepad; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadFromPlayerIndex(player_index: Integer): PSDL_Gamepad; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadProperties(gamepad: PSDL_Gamepad): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadID(gamepad: PSDL_Gamepad): SDL_JoystickID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadName(gamepad: PSDL_Gamepad): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadPath(gamepad: PSDL_Gamepad): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadType(gamepad: PSDL_Gamepad): SDL_GamepadType; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRealGamepadType(gamepad: PSDL_Gamepad): SDL_GamepadType; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadPlayerIndex(gamepad: PSDL_Gamepad): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_SetGamepadPlayerIndex(gamepad: PSDL_Gamepad; player_index: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadVendor(gamepad: PSDL_Gamepad): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadProduct(gamepad: PSDL_Gamepad): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadProductVersion(gamepad: PSDL_Gamepad): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadFirmwareVersion(gamepad: PSDL_Gamepad): Uint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadSerial(gamepad: PSDL_Gamepad): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadSteamHandle(gamepad: PSDL_Gamepad): Uint64; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadConnectionState(gamepad: PSDL_Gamepad): SDL_JoystickConnectionState; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadPowerInfo(gamepad: PSDL_Gamepad; percent: PInteger): SDL_PowerState; cdecl;
  external SDL_LIB_NAME;
function SDL_GamepadConnected(gamepad: PSDL_Gamepad): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadJoystick(gamepad: PSDL_Gamepad): PSDL_Joystick; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetGamepadEventsEnabled(enabled: Boolean); cdecl;
  external SDL_LIB_NAME;
function SDL_GamepadEventsEnabled: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadBindings(gamepad: PSDL_Gamepad; count: PInteger): PPSDL_GamepadBinding; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UpdateGamepads; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadTypeFromString(str: PUTF8Char): SDL_GamepadType; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadStringForType(type_: SDL_GamepadType): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadAxisFromString(str: PUTF8Char): SDL_GamepadAxis; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadStringForAxis(axis: SDL_GamepadAxis): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GamepadHasAxis(gamepad: PSDL_Gamepad; axis: SDL_GamepadAxis): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadAxis(gamepad: PSDL_Gamepad; axis: SDL_GamepadAxis): Sint16; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadButtonFromString(str: PUTF8Char): SDL_GamepadButton; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadStringForButton(button: SDL_GamepadButton): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GamepadHasButton(gamepad: PSDL_Gamepad; button: SDL_GamepadButton): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadButton(gamepad: PSDL_Gamepad; button: SDL_GamepadButton): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadButtonLabelForType(type_: SDL_GamepadType; button: SDL_GamepadButton): SDL_GamepadButtonLabel; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadButtonLabel(gamepad: PSDL_Gamepad; button: SDL_GamepadButton): SDL_GamepadButtonLabel; cdecl;
  external SDL_LIB_NAME;
function SDL_GetNumGamepadTouchpads(gamepad: PSDL_Gamepad): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetNumGamepadTouchpadFingers(gamepad: PSDL_Gamepad; touchpad: Integer): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadTouchpadFinger(gamepad: PSDL_Gamepad; touchpad, finger: Integer;
  down: PBoolean; x, y, pressure: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GamepadHasSensor(gamepad: PSDL_Gamepad; type_: SDL_SensorType): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetGamepadSensorEnabled(gamepad: PSDL_Gamepad; type_: SDL_SensorType; enabled: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GamepadSensorEnabled(gamepad: PSDL_Gamepad; type_: SDL_SensorType): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadSensorDataRate(gamepad: PSDL_Gamepad; type_: SDL_SensorType): Single; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadSensorData(gamepad: PSDL_Gamepad; type_: SDL_SensorType; data: PSingle; num_values: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GamepadHasCapSense(gamepad: PSDL_Gamepad; type_: SDL_GamepadCapSenseType): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadCapSense(gamepad: PSDL_Gamepad; type_: SDL_GamepadCapSenseType): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RumbleGamepad(gamepad: PSDL_Gamepad; low_frequency_rumble, high_frequency_rumble: Uint16;
  duration_ms: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RumbleGamepadTriggers(gamepad: PSDL_Gamepad; left_rumble, right_rumble: Uint16;
  duration_ms: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetGamepadLED(gamepad: PSDL_Gamepad; red, green, blue: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SendGamepadEffect(gamepad: PSDL_Gamepad; const data: Pointer; size: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_CloseGamepad(gamepad: PSDL_Gamepad); cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadAppleSFSymbolsNameForButton(gamepad: PSDL_Gamepad; button: SDL_GamepadButton): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGamepadAppleSFSymbolsNameForAxis(gamepad: PSDL_Gamepad; axis: SDL_GamepadAxis): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
