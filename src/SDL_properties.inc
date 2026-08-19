{ SDL_properties.inc -- 1-to-1 from SDL_properties.h }

type
  SDL_PropertiesID = Uint32;

  SDL_PropertyType = (
    SDL_PROPERTY_TYPE_INVALID,
    SDL_PROPERTY_TYPE_POINTER,
    SDL_PROPERTY_TYPE_STRING,
    SDL_PROPERTY_TYPE_NUMBER,
    SDL_PROPERTY_TYPE_FLOAT,
    SDL_PROPERTY_TYPE_BOOLEAN
  );

  SDL_CleanupPropertyCallback = procedure(userdata: Pointer; value: Pointer); cdecl;
  SDL_EnumeratePropertiesCallback = procedure(userdata: Pointer; props: SDL_PropertiesID; name: PUTF8Char); cdecl;

const
  SDL_PROP_NAME_STRING = 'SDL.name';

function SDL_GetGlobalProperties: SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateProperties: SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_CopyProperties(src, dst: SDL_PropertiesID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_LockProperties(props: SDL_PropertiesID): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnlockProperties(props: SDL_PropertiesID); cdecl;
  external SDL_LIB_NAME;
function SDL_SetPointerPropertyWithCleanup(props: SDL_PropertiesID; name: PUTF8Char; value: Pointer; cleanup: SDL_CleanupPropertyCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetPointerProperty(props: SDL_PropertiesID; name: PUTF8Char; value: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetStringProperty(props: SDL_PropertiesID; name: PUTF8Char; value: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetNumberProperty(props: SDL_PropertiesID; name: PUTF8Char; value: Sint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetFloatProperty(props: SDL_PropertiesID; name: PUTF8Char; value: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetBooleanProperty(props: SDL_PropertiesID; name: PUTF8Char; value: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasProperty(props: SDL_PropertiesID; name: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetPropertyType(props: SDL_PropertiesID; name: PUTF8Char): SDL_PropertyType; cdecl;
  external SDL_LIB_NAME;
function SDL_GetPointerProperty(props: SDL_PropertiesID; name: PUTF8Char; default_value: Pointer): Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetStringProperty(props: SDL_PropertiesID; name: PUTF8Char; default_value: PUTF8Char): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetNumberProperty(props: SDL_PropertiesID; name: PUTF8Char; default_value: Sint64): Sint64; cdecl;
  external SDL_LIB_NAME;
function SDL_GetFloatProperty(props: SDL_PropertiesID; name: PUTF8Char; default_value: Single): Single; cdecl;
  external SDL_LIB_NAME;
function SDL_GetBooleanProperty(props: SDL_PropertiesID; name: PUTF8Char; default_value: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ClearProperty(props: SDL_PropertiesID; name: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetNumProperties(props: SDL_PropertiesID): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_EnumerateProperties(props: SDL_PropertiesID; callback: SDL_EnumeratePropertiesCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyProperties(props: SDL_PropertiesID); cdecl;
  external SDL_LIB_NAME;
