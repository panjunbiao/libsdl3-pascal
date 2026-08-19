{ SDL_keyboard.inc -- 1-to-1 from SDL_keyboard.h }

type
  SDL_KeyboardID = Uint32;
  PSDL_KeyboardID = ^SDL_KeyboardID;

  SDL_TextInputType = (
    SDL_TEXTINPUT_TYPE_TEXT,
    SDL_TEXTINPUT_TYPE_TEXT_NAME,
    SDL_TEXTINPUT_TYPE_TEXT_EMAIL,
    SDL_TEXTINPUT_TYPE_TEXT_USERNAME,
    SDL_TEXTINPUT_TYPE_TEXT_PASSWORD_HIDDEN,
    SDL_TEXTINPUT_TYPE_TEXT_PASSWORD_VISIBLE,
    SDL_TEXTINPUT_TYPE_NUMBER,
    SDL_TEXTINPUT_TYPE_NUMBER_PASSWORD_HIDDEN,
    SDL_TEXTINPUT_TYPE_NUMBER_PASSWORD_VISIBLE
  );

  SDL_Capitalization = (
    SDL_CAPITALIZE_NONE,
    SDL_CAPITALIZE_SENTENCES,
    SDL_CAPITALIZE_WORDS,
    SDL_CAPITALIZE_LETTERS
  );

const
  SDL_PROP_TEXTINPUT_TYPE_NUMBER = 'SDL.textinput.type';
  SDL_PROP_TEXTINPUT_CAPITALIZATION_NUMBER = 'SDL.textinput.capitalization';
  SDL_PROP_TEXTINPUT_AUTOCORRECT_BOOLEAN = 'SDL.textinput.autocorrect';
  SDL_PROP_TEXTINPUT_MULTILINE_BOOLEAN = 'SDL.textinput.multiline';
  SDL_PROP_TEXTINPUT_ANDROID_INPUTTYPE_NUMBER = 'SDL.textinput.android.inputtype';

function SDL_HasKeyboard: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetKeyboards(count: PInteger): PSDL_KeyboardID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetKeyboardNameForID(instance_id: SDL_KeyboardID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetKeyboardFocus: PSDL_Window; cdecl;
  external SDL_LIB_NAME;
function SDL_GetKeyboardState(numkeys: PInteger): PBoolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_ResetKeyboard; cdecl;
  external SDL_LIB_NAME;
function SDL_GetModState: SDL_Keymod; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetModState(modstate: SDL_Keymod); cdecl;
  external SDL_LIB_NAME;
function SDL_GetKeyFromScancode(scancode: SDL_Scancode; modstate: SDL_Keymod; key_event: Boolean): SDL_Keycode; cdecl;
  external SDL_LIB_NAME;
function SDL_GetScancodeFromKey(key: SDL_Keycode; modstate: PSDL_Keymod): SDL_Scancode; cdecl;
  external SDL_LIB_NAME;
function SDL_SetScancodeName(scancode: SDL_Scancode; name: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetScancodeName(scancode: SDL_Scancode): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetScancodeFromName(name: PUTF8Char): SDL_Scancode; cdecl;
  external SDL_LIB_NAME;
function SDL_GetKeyName(key: SDL_Keycode): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetKeyFromName(name: PUTF8Char): SDL_Keycode; cdecl;
  external SDL_LIB_NAME;
function SDL_StartTextInput(window: PSDL_Window): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_StartTextInputWithProperties(window: PSDL_Window; props: SDL_PropertiesID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_TextInputActive(window: PSDL_Window): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_StopTextInput(window: PSDL_Window): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ClearComposition(window: PSDL_Window): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetTextInputArea(window: PSDL_Window; const rect: PSDL_Rect; cursor: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTextInputArea(window: PSDL_Window; rect: PSDL_Rect; cursor: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasScreenKeyboardSupport: Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ScreenKeyboardShown(window: PSDL_Window): Boolean; cdecl;
  external SDL_LIB_NAME;
