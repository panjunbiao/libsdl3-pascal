{ SDL_clipboard.inc -- 1-to-1 from SDL_clipboard.h }

type
  SDL_ClipboardDataCallback = function(userdata: Pointer; mime_type: PUTF8Char; size: PNativeUInt): Pointer; cdecl;
  SDL_ClipboardCleanupCallback = procedure(userdata: Pointer); cdecl;

function SDL_SetClipboardText(text: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetClipboardText: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_HasClipboardText: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetPrimarySelectionText(text: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetPrimarySelectionText: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_HasPrimarySelectionText: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetClipboardData(callback: SDL_ClipboardDataCallback; cleanup: SDL_ClipboardCleanupCallback;
  userdata: Pointer; mime_types: PPUTF8Char; num_mime_types: NativeUInt): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ClearClipboardData: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetClipboardData(mime_type: PUTF8Char; size: PNativeUInt): Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_HasClipboardData(mime_type: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetClipboardMimeTypes(num_mime_types: PNativeUInt): PPUTF8Char; cdecl;
  external SDL_LIB_NAME;
