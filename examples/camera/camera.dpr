program camera;

{ Open the first camera and draw each frame. The window stays up if none is connected. }

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  Window: PSDL_Window;
  Renderer: PSDL_Renderer;
  Cam: PSDL_Camera;
  Texture: PSDL_Texture;
  Event: SDL_Event;
  Running: Boolean;
  Count: Integer;
  Ids: PSDL_CameraID;
  Timestamp: Uint64;
  Frame: PSDL_Surface;

procedure Note(const Text: PUTF8Char);
begin
  SDL_SetRenderDrawColor(Renderer, 24, 24, 28, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(Renderer);
  SDL_SetRenderDrawColor(Renderer, 230, 230, 230, SDL_ALPHA_OPAQUE);
  SDL_RenderDebugText(Renderer, 16, 16, Text);
  SDL_RenderPresent(Renderer);
end;

begin
  Cam := nil;
  Texture := nil;
  SDL_SetMainReady;
  SDL_SetAppMetadata('libsdl3-pascal camera', '0.1.0', 'com.libsdl3pascal.camera');

  if not SDL_Init(SDL_INIT_VIDEO or SDL_INIT_CAMERA) then
  begin
    WriteLn('SDL_Init failed: ', SDL_GetError);
    Halt(1);
  end;

  if not SDL_CreateWindowAndRenderer('libsdl3-pascal camera', 640, 480, 0, @Window, @Renderer) then
  begin
    WriteLn('SDL_CreateWindowAndRenderer failed: ', SDL_GetError);
    SDL_Quit;
    Halt(1);
  end;

  Count := 0;
  Ids := SDL_GetCameras(@Count);
  WriteLn('cameras: ', Count);
  if (Ids <> nil) and (Count > 0) then
  begin
    WriteLn('opening ', SDL_GetCameraName(Ids^));
    Cam := SDL_OpenCamera(Ids^, nil);
    if Cam = nil then
      WriteLn('SDL_OpenCamera failed: ', SDL_GetError);
  end;
  SDL_free(Ids);

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

    if Cam = nil then
      Note('No camera. Close the window to quit.')
    else if SDL_GetCameraPermissionState(Cam) = SDL_CAMERA_PERMISSION_STATE_PENDING then
      Note('Waiting for camera permission.')
    else if SDL_GetCameraPermissionState(Cam) = SDL_CAMERA_PERMISSION_STATE_DENIED then
      Note('Camera permission denied.')
    else
    begin
      Timestamp := 0;
      Frame := SDL_AcquireCameraFrame(Cam, @Timestamp);
      if Frame <> nil then
      begin
        if Texture = nil then
          Texture := SDL_CreateTexture(Renderer, Frame.format, SDL_TEXTUREACCESS_STREAMING, Frame.w, Frame.h);
        if Texture <> nil then
          SDL_UpdateTexture(Texture, nil, Frame.pixels, Frame.pitch);
        SDL_ReleaseCameraFrame(Cam, Frame);
      end;
      SDL_SetRenderDrawColor(Renderer, 16, 16, 16, SDL_ALPHA_OPAQUE);
      SDL_RenderClear(Renderer);
      if Texture <> nil then
        SDL_RenderTexture(Renderer, Texture, nil, nil);
      SDL_RenderPresent(Renderer);
    end;
    SDL_Delay(16);
  end;

  SDL_DestroyTexture(Texture);
  SDL_CloseCamera(Cam);
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  SDL_Quit;
end.
