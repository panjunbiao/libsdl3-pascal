{ SDL_time.inc -- 1-to-1 from SDL_time.h }

type
  PSDL_DateTime = ^SDL_DateTime;
  SDL_DateTime = record
    year: Integer;
    month: Integer;
    day: Integer;
    hour: Integer;
    minute: Integer;
    second: Integer;
    nanosecond: Integer;
    day_of_week: Integer;
    utc_offset: Integer;
  end;

  PSDL_DateFormat = ^SDL_DateFormat;
  SDL_DateFormat = (
    SDL_DATE_FORMAT_YYYYMMDD = 0,
    SDL_DATE_FORMAT_DDMMYYYY = 1,
    SDL_DATE_FORMAT_MMDDYYYY = 2
  );

  PSDL_TimeFormat = ^SDL_TimeFormat;
  SDL_TimeFormat = (
    SDL_TIME_FORMAT_24HR = 0,
    SDL_TIME_FORMAT_12HR = 1
  );

  PSDL_Time = ^SDL_Time;

function SDL_GetDateTimeLocalePreferences(dateFormat: PSDL_DateFormat; timeFormat: PSDL_TimeFormat): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCurrentTime(ticks: PSDL_Time): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_TimeToDateTime(ticks: SDL_Time; dt: PSDL_DateTime; localTime: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_DateTimeToTime(const dt: PSDL_DateTime; ticks: PSDL_Time): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_TimeToWindows(ticks: SDL_Time; dwLowDateTime, dwHighDateTime: PUint32); cdecl;
  external SDL_LIB_NAME;
function SDL_TimeFromWindows(dwLowDateTime, dwHighDateTime: Uint32): SDL_Time; cdecl;
  external SDL_LIB_NAME;
function SDL_GetDaysInMonth(year, month: Integer): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetDayOfYear(year, month, day: Integer): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetDayOfWeek(year, month, day: Integer): Integer; cdecl;
  external SDL_LIB_NAME;
