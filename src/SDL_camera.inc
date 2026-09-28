{ SDL_camera.inc -- 1-to-1 from SDL_camera.h (SDL 3.4.16) }

type
  SDL_CameraID = Uint32;
  PSDL_CameraID = ^SDL_CameraID;
  PPSDL_CameraID = ^PSDL_CameraID;
  SDL_Camera = record
  end;
  PSDL_Camera = ^SDL_Camera;
  PPSDL_Camera = ^PSDL_Camera;
  PSDL_CameraSpec = ^SDL_CameraSpec;
  PPSDL_CameraSpec = ^PSDL_CameraSpec;
  SDL_CameraSpec = record
    format: SDL_PixelFormat;
    colorspace: SDL_Colorspace;
    width: Integer;
    height: Integer;
    framerate_numerator: Integer;
    framerate_denominator: Integer;
  end;
  SDL_CameraPosition = (
    SDL_CAMERA_POSITION_UNKNOWN,
    SDL_CAMERA_POSITION_FRONT_FACING,
    SDL_CAMERA_POSITION_BACK_FACING
  );
  PSDL_CameraPosition = ^SDL_CameraPosition;
  PPSDL_CameraPosition = ^PSDL_CameraPosition;
  SDL_CameraPermissionState = (
    SDL_CAMERA_PERMISSION_STATE_DENIED = -1,
    SDL_CAMERA_PERMISSION_STATE_PENDING,
    SDL_CAMERA_PERMISSION_STATE_APPROVED
  );
  PSDL_CameraPermissionState = ^SDL_CameraPermissionState;
  PPSDL_CameraPermissionState = ^PSDL_CameraPermissionState;

function SDL_GetNumCameraDrivers: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCameraDriver(index: Integer): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCurrentCameraDriver: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCameras(count: PInteger): PSDL_CameraID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCameraSupportedFormats(instance_id: SDL_CameraID; count: PInteger): PPSDL_CameraSpec; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCameraName(instance_id: SDL_CameraID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCameraPosition(instance_id: SDL_CameraID): SDL_CameraPosition; cdecl;
  external SDL_LIB_NAME;
function SDL_OpenCamera(instance_id: SDL_CameraID; spec: PSDL_CameraSpec): PSDL_Camera; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCameraPermissionState(camera: PSDL_Camera): SDL_CameraPermissionState; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCameraID(camera: PSDL_Camera): SDL_CameraID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCameraProperties(camera: PSDL_Camera): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCameraFormat(camera: PSDL_Camera; spec: PSDL_CameraSpec): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_AcquireCameraFrame(camera: PSDL_Camera; timestampNS: PUint64): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseCameraFrame(camera: PSDL_Camera; frame: PSDL_Surface); cdecl;
  external SDL_LIB_NAME;
procedure SDL_CloseCamera(camera: PSDL_Camera); cdecl;
  external SDL_LIB_NAME;
