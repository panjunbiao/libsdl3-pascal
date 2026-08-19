program draw;

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  Window: PSDL_Window;
  Renderer: PSDL_Renderer;
  Event: SDL_Event;
  Running: Boolean;
  Rect: SDL_FRect;
begin
  SDL_SetMainReady;
  SDL_SetAppMetadata('libsdl3-pascal draw', '0.1.0', 'com.libsdl3pascal.draw');

  if not SDL_Init(SDL_INIT_VIDEO) then
  begin
    WriteLn('SDL_Init failed: ', SDL_GetError);
    Halt(1);
  end;

  if not SDL_CreateWindowAndRenderer('libsdl3-pascal draw', 640, 480, 0, @Window, @Renderer) then
  begin
    WriteLn('SDL_CreateWindowAndRenderer failed: ', SDL_GetError);
    SDL_Quit;
    Halt(1);
  end;

  Rect.x := 220;
  Rect.y := 140;
  Rect.w := 200;
  Rect.h := 200;

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

    SDL_SetRenderDrawColor(Renderer, 18, 18, 28, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(Renderer);
    SDL_SetRenderDrawColor(Renderer, 230, 80, 60, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(Renderer, @Rect);
    SDL_RenderPresent(Renderer);
    SDL_Delay(16);
  end;

  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  SDL_Quit;
end.
