program hello;

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  Window: PSDL_Window;
  Event: SDL_Event;
  Running: Boolean;
  Linked: Integer;
begin
  SDL_SetMainReady;
  SDL_SetAppMetadata('libsdl3-pascal hello', '0.1.0', 'com.libsdl3pascal.hello');

  Linked := SDL_GetVersion;
  if SDL_VERSIONNUM_MAJOR(Linked) <> SDL_MAJOR_VERSION then
  begin
    WriteLn('SDL3.dll major version does not match this binding.');
    Halt(1);
  end;
  if Linked < SDL_VERSION then
  begin
    WriteLn('SDL3.dll is older than the SDL 3.4.14 pin.');
    Halt(1);
  end;

  if not SDL_Init(SDL_INIT_VIDEO) then
  begin
    WriteLn('SDL_Init failed: ', SDL_GetError);
    Halt(1);
  end;

  WriteLn('SDL_GetVersion = ', Linked, ' (headers ', SDL_VERSION, ')');

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
