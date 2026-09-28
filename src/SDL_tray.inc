{ SDL_tray.inc -- 1-to-1 from SDL_tray.h (SDL 3.4.16) }

type
  SDL_Tray = record
  end;
  PSDL_Tray = ^SDL_Tray;
  PPSDL_Tray = ^PSDL_Tray;
  SDL_TrayMenu = record
  end;
  PSDL_TrayMenu = ^SDL_TrayMenu;
  PPSDL_TrayMenu = ^PSDL_TrayMenu;
  SDL_TrayEntry = record
  end;
  PSDL_TrayEntry = ^SDL_TrayEntry;
  PPSDL_TrayEntry = ^PSDL_TrayEntry;
  SDL_TrayEntryFlags = Uint32;
  PSDL_TrayEntryFlags = ^SDL_TrayEntryFlags;
  PPSDL_TrayEntryFlags = ^PSDL_TrayEntryFlags;
  SDL_TrayCallback = procedure(userdata: Pointer; entry: PSDL_TrayEntry); cdecl;
  PSDL_TrayCallback = ^SDL_TrayCallback;
  PPSDL_TrayCallback = ^PSDL_TrayCallback;

const
  SDL_TRAYENTRY_BUTTON = $00000001;
  SDL_TRAYENTRY_CHECKBOX = $00000002;
  SDL_TRAYENTRY_SUBMENU = $00000004;
  SDL_TRAYENTRY_DISABLED = Uint32($80000000);
  SDL_TRAYENTRY_CHECKED = $40000000;

function SDL_CreateTray(icon: PSDL_Surface; tooltip: PUTF8Char): PSDL_Tray; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetTrayIcon(tray: PSDL_Tray; icon: PSDL_Surface); cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetTrayTooltip(tray: PSDL_Tray; tooltip: PUTF8Char); cdecl;
  external SDL_LIB_NAME;
function SDL_CreateTrayMenu(tray: PSDL_Tray): PSDL_TrayMenu; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateTraySubmenu(entry: PSDL_TrayEntry): PSDL_TrayMenu; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTrayMenu(tray: PSDL_Tray): PSDL_TrayMenu; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTraySubmenu(entry: PSDL_TrayEntry): PSDL_TrayMenu; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTrayEntries(menu: PSDL_TrayMenu; count: PInteger): PPSDL_TrayEntry; cdecl;
  external SDL_LIB_NAME;
procedure SDL_RemoveTrayEntry(entry: PSDL_TrayEntry); cdecl;
  external SDL_LIB_NAME;
function SDL_InsertTrayEntryAt(menu: PSDL_TrayMenu; pos: Integer; label_: PUTF8Char; flags: SDL_TrayEntryFlags): PSDL_TrayEntry; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetTrayEntryLabel(entry: PSDL_TrayEntry; label_: PUTF8Char); cdecl;
  external SDL_LIB_NAME;
function SDL_GetTrayEntryLabel(entry: PSDL_TrayEntry): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetTrayEntryChecked(entry: PSDL_TrayEntry; checked: Boolean); cdecl;
  external SDL_LIB_NAME;
function SDL_GetTrayEntryChecked(entry: PSDL_TrayEntry): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetTrayEntryEnabled(entry: PSDL_TrayEntry; enabled: Boolean); cdecl;
  external SDL_LIB_NAME;
function SDL_GetTrayEntryEnabled(entry: PSDL_TrayEntry): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetTrayEntryCallback(entry: PSDL_TrayEntry; callback: SDL_TrayCallback; userdata: Pointer); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ClickTrayEntry(entry: PSDL_TrayEntry); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyTray(tray: PSDL_Tray); cdecl;
  external SDL_LIB_NAME;
function SDL_GetTrayEntryParent(entry: PSDL_TrayEntry): PSDL_TrayMenu; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTrayMenuParentEntry(menu: PSDL_TrayMenu): PSDL_TrayEntry; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTrayMenuParentTray(menu: PSDL_TrayMenu): PSDL_Tray; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UpdateTrays; cdecl;
  external SDL_LIB_NAME;
