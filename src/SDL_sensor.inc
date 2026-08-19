{ SDL_sensor.inc -- 1-to-1 from SDL_sensor.h (needed by virtual joystick / gamepad). }

type
  SDL_Sensor = record
  end;
  PSDL_Sensor = ^SDL_Sensor;

  SDL_SensorID = Uint32;
  PSDL_SensorID = ^SDL_SensorID;

  SDL_SensorType = (
    SDL_SENSOR_INVALID = -1,
    SDL_SENSOR_UNKNOWN,
    SDL_SENSOR_ACCEL,
    SDL_SENSOR_GYRO,
    SDL_SENSOR_ACCEL_L,
    SDL_SENSOR_GYRO_L,
    SDL_SENSOR_ACCEL_R,
    SDL_SENSOR_GYRO_R,
    SDL_SENSOR_COUNT
  );

const
  SDL_STANDARD_GRAVITY = 9.80665;

function SDL_GetSensors(count: PInteger): PSDL_SensorID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorNameForID(instance_id: SDL_SensorID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorTypeForID(instance_id: SDL_SensorID): SDL_SensorType; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorNonPortableTypeForID(instance_id: SDL_SensorID): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_OpenSensor(instance_id: SDL_SensorID): PSDL_Sensor; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorFromID(instance_id: SDL_SensorID): PSDL_Sensor; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorProperties(sensor: PSDL_Sensor): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorName(sensor: PSDL_Sensor): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorType(sensor: PSDL_Sensor): SDL_SensorType; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorNonPortableType(sensor: PSDL_Sensor): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorID(sensor: PSDL_Sensor): SDL_SensorID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSensorData(sensor: PSDL_Sensor; data: PSingle; num_values: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_CloseSensor(sensor: PSDL_Sensor); cdecl;
  external SDL_LIB_NAME;
procedure SDL_UpdateSensors; cdecl;
  external SDL_LIB_NAME;
