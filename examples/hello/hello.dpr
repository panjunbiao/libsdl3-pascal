program hello;

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  Window: PSDL_Window;
  Event: SDL_Event;
  Running: Boolean;
begin
  SDL_SetMainReady;
  SDL_SetAppMetadata('libsdl3-pascal hello', '0.1.0', 'com.libsdl3pascal.hello');

  if not SDL_Init(SDL_INIT_VIDEO) then
  begin
    WriteLn('SDL_Init failed: ', SDL_GetError);
    Halt(1);
  end;

  WriteLn('SDL_GetVersion = ', SDL_GetVersion, ' (headers ', SDL_VERSION, ')');

  Window := SDL_CreateWindow('libsdl3-pascal', 640, 480, 0);
  if Window = nil then
  begin
    WriteLn('SDL_CreateWindow failed: ', SDL_GetError);
    SDL_Quit;
    Halt(1);
  end;

  Running := True;
  while Running do
  begin
    while SDL_PollEvent(@Event) do
    begin
      if (Event.type_ = Uint32(SDL_EVENT_QUIT)) or
         (Event.type_ = Uint32(SDL_EVENT_WINDOW_CLOSE_REQUESTED)) then
        Running := False;
    end;
    SDL_Delay(16);
  end;

  SDL_DestroyWindow(Window);
  SDL_Quit;
end.
