{ SDL_touch.inc -- 1-to-1 from SDL_touch.h }

type
  SDL_TouchID = Uint64;
  PSDL_TouchID = ^SDL_TouchID;
  SDL_FingerID = Uint64;

  SDL_TouchDeviceType = (
    SDL_TOUCH_DEVICE_INVALID = -1,
    SDL_TOUCH_DEVICE_DIRECT,
    SDL_TOUCH_DEVICE_INDIRECT_ABSOLUTE,
    SDL_TOUCH_DEVICE_INDIRECT_RELATIVE
  );

  PSDL_Finger = ^SDL_Finger;
  PPSDL_Finger = ^PSDL_Finger;
  SDL_Finger = record
    id: SDL_FingerID;
    x: Single;
    y: Single;
    pressure: Single;
  end;

const
  SDL_TOUCH_MOUSEID = SDL_MouseID($FFFFFFFF);
  SDL_MOUSE_TOUCHID = SDL_TouchID($FFFFFFFFFFFFFFFF);

function SDL_GetTouchDevices(count: PInteger): PSDL_TouchID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTouchDeviceName(touchID: SDL_TouchID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTouchDeviceType(touchID: SDL_TouchID): SDL_TouchDeviceType; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTouchFingers(touchID: SDL_TouchID; count: PInteger): PPSDL_Finger; cdecl;
  external SDL_LIB_NAME;
