{ SDL_dialog.inc -- 1-to-1 from SDL_dialog.h }

type
  PSDL_DialogFileFilter = ^SDL_DialogFileFilter;
  SDL_DialogFileFilter = record
    name: PUTF8Char;
    pattern: PUTF8Char;
  end;

  SDL_DialogFileCallback = procedure(userdata: Pointer; filelist: PPUTF8Char; filter: Integer); cdecl;

  SDL_FileDialogType = (
    SDL_FILEDIALOG_OPENFILE,
    SDL_FILEDIALOG_SAVEFILE,
    SDL_FILEDIALOG_OPENFOLDER
  );

const
  SDL_PROP_FILE_DIALOG_FILTERS_POINTER = 'SDL.filedialog.filters';
  SDL_PROP_FILE_DIALOG_NFILTERS_NUMBER = 'SDL.filedialog.nfilters';
  SDL_PROP_FILE_DIALOG_WINDOW_POINTER = 'SDL.filedialog.window';
  SDL_PROP_FILE_DIALOG_LOCATION_STRING = 'SDL.filedialog.location';
  SDL_PROP_FILE_DIALOG_MANY_BOOLEAN = 'SDL.filedialog.many';
  SDL_PROP_FILE_DIALOG_TITLE_STRING = 'SDL.filedialog.title';
  SDL_PROP_FILE_DIALOG_ACCEPT_STRING = 'SDL.filedialog.accept';
  SDL_PROP_FILE_DIALOG_CANCEL_STRING = 'SDL.filedialog.cancel';

procedure SDL_ShowOpenFileDialog(callback: SDL_DialogFileCallback; userdata: Pointer; window: PSDL_Window; const filters: PSDL_DialogFileFilter; nfilters: Integer; default_location: PUTF8Char; allow_many: Boolean); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ShowSaveFileDialog(callback: SDL_DialogFileCallback; userdata: Pointer; window: PSDL_Window; const filters: PSDL_DialogFileFilter; nfilters: Integer; default_location: PUTF8Char); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ShowOpenFolderDialog(callback: SDL_DialogFileCallback; userdata: Pointer; window: PSDL_Window; default_location: PUTF8Char; allow_many: Boolean); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ShowFileDialogWithProperties(type_: SDL_FileDialogType; callback: SDL_DialogFileCallback; userdata: Pointer; props: SDL_PropertiesID); cdecl;
  external SDL_LIB_NAME;
