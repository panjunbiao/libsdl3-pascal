{ SDL_messagebox.inc -- 1-to-1 from SDL_messagebox.h }

type
  SDL_MessageBoxFlags = Uint32;
  SDL_MessageBoxButtonFlags = Uint32;

  PSDL_MessageBoxButtonData = ^SDL_MessageBoxButtonData;
  SDL_MessageBoxButtonData = record
    flags: SDL_MessageBoxButtonFlags;
    buttonID: Integer;
    text: PUTF8Char;
  end;

  PSDL_MessageBoxColor = ^SDL_MessageBoxColor;
  SDL_MessageBoxColor = record
    r, g, b: Uint8;
  end;

  SDL_MessageBoxColorType = (
    SDL_MESSAGEBOX_COLOR_BACKGROUND,
    SDL_MESSAGEBOX_COLOR_TEXT,
    SDL_MESSAGEBOX_COLOR_BUTTON_BORDER,
    SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND,
    SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED,
    SDL_MESSAGEBOX_COLOR_COUNT
  );

  PSDL_MessageBoxColorScheme = ^SDL_MessageBoxColorScheme;
  SDL_MessageBoxColorScheme = record
    colors: array[0..4] of SDL_MessageBoxColor;
  end;

  PSDL_MessageBoxData = ^SDL_MessageBoxData;
  SDL_MessageBoxData = record
    flags: SDL_MessageBoxFlags;
    window: PSDL_Window;
    title: PUTF8Char;
    message: PUTF8Char;
    numbuttons: Integer;
    buttons: PSDL_MessageBoxButtonData;
    colorScheme: PSDL_MessageBoxColorScheme;
  end;

const
  SDL_MESSAGEBOX_ERROR = $00000010;
  SDL_MESSAGEBOX_WARNING = $00000020;
  SDL_MESSAGEBOX_INFORMATION = $00000040;
  SDL_MESSAGEBOX_BUTTONS_LEFT_TO_RIGHT = $00000080;
  SDL_MESSAGEBOX_BUTTONS_RIGHT_TO_LEFT = $00000100;
  SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT = $00000001;
  SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT = $00000002;

function SDL_ShowMessageBox(const messageboxdata: PSDL_MessageBoxData; buttonid: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ShowSimpleMessageBox(flags: SDL_MessageBoxFlags; title, message_: PUTF8Char; window: PSDL_Window): Boolean; cdecl;
  external SDL_LIB_NAME;
