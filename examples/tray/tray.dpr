program tray;

{ A window plus a notification-area icon. Quit is on the tray menu. }

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  Paused: Boolean;

procedure OnTrayQuit(userdata: Pointer; entry: PSDL_TrayEntry); cdecl;
var
  Event: SDL_Event;
begin
  FillChar(Event, SizeOf(Event), 0);
  Event.type_ := Uint32(SDL_EVENT_QUIT);
  SDL_PushEvent(@Event);
end;

procedure OnTrayPause(userdata: Pointer; entry: PSDL_TrayEntry); cdecl;
begin
  Paused := not Paused;
  SDL_SetTrayEntryChecked(entry, Paused);
end;

var
  Window: PSDL_Window;
  Renderer: PSDL_Renderer;
  Icon: PSDL_Surface;
  TrayIcon: PSDL_Tray;
  Menu: PSDL_TrayMenu;
  PauseEntry, QuitEntry: PSDL_TrayEntry;
  Event: SDL_Event;
  Running: Boolean;
  Tip, PauseLabel, QuitLabel: UTF8String;
begin
  SDL_SetMainReady;
  SDL_SetAppMetadata('libsdl3-pascal tray', '0.1.0', 'com.libsdl3pascal.tray');

  if not SDL_Init(SDL_INIT_VIDEO) then
  begin
    WriteLn('SDL_Init failed: ', SDL_GetError);
    Halt(1);
  end;

  if not SDL_CreateWindowAndRenderer('libsdl3-pascal tray', 640, 480, 0, @Window, @Renderer) then
  begin
    WriteLn('SDL_CreateWindowAndRenderer failed: ', SDL_GetError);
    SDL_Quit;
    Halt(1);
  end;

  Icon := SDL_CreateSurface(32, 32, SDL_PIXELFORMAT_RGBA8888);
  if Icon <> nil then
    SDL_FillSurfaceRect(Icon, nil, SDL_MapSurfaceRGBA(Icon, 230, 120, 40, 255));

  Tip := 'libsdl3-pascal tray';
  TrayIcon := SDL_CreateTray(Icon, PUTF8Char(Tip));
  SDL_DestroySurface(Icon);
  if TrayIcon = nil then
  begin
    WriteLn('SDL_CreateTray failed: ', SDL_GetError);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit;
    Halt(1);
  end;

  Menu := SDL_CreateTrayMenu(TrayIcon);
  PauseLabel := 'Pause color';
  QuitLabel := 'Quit';
  PauseEntry := SDL_InsertTrayEntryAt(Menu, -1, PUTF8Char(PauseLabel), SDL_TRAYENTRY_CHECKBOX);
  QuitEntry := SDL_InsertTrayEntryAt(Menu, -1, PUTF8Char(QuitLabel), SDL_TRAYENTRY_BUTTON);
  SDL_SetTrayEntryCallback(PauseEntry, OnTrayPause, nil);
  SDL_SetTrayEntryCallback(QuitEntry, OnTrayQuit, nil);

  Running := True;
  while Running do
  begin
    while SDL_PollEvent(@Event) do
    begin
      if (Event.type_ = Uint32(SDL_EVENT_QUIT)) or
         (Event.type_ = Uint32(SDL_EVENT_WINDOW_CLOSE_REQUESTED)) then
        Running := False;
      if (Event.type_ = Uint32(SDL_EVENT_KEY_DOWN)) and
         (Event.key.scancode = SDL_SCANCODE_ESCAPE) then
        Running := False;
    end;

    SDL_UpdateTrays;
    if Paused then
      SDL_SetRenderDrawColor(Renderer, 40, 48, 64, SDL_ALPHA_OPAQUE)
    else
      SDL_SetRenderDrawColor(Renderer, 230, 120, 40, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(Renderer);
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugText(Renderer, 16, 16, 'Tray menu: Pause color, or Quit.');
    SDL_RenderPresent(Renderer);
    SDL_Delay(16);
  end;

  SDL_DestroyTray(TrayIcon);
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  SDL_Quit;
end.
