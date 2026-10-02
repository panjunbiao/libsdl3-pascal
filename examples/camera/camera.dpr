program camera;

{ Open the first camera in a video-call mode and draw each frame. The window
  stays up if none is connected. }

{$APPTYPE CONSOLE}

uses
  SDL3;

const
  MinFps = 29.5; { 29.97 counts as 30 }
  MaxArea = 1280 * 720;

var
  Window: PSDL_Window;
  Renderer: PSDL_Renderer;
  Cam: PSDL_Camera;
  Texture: PSDL_Texture;
  Event: SDL_Event;
  Running: Boolean;
  Count: Integer;
  Ids: PSDL_CameraID;
  Spec: SDL_CameraSpec;
  Frame, Newer: PSDL_Surface;
  FpsClock, NowNs: Uint64;
  Shown: Integer;
  Title: array[0..127] of AnsiChar;

procedure Note(const Text: PUTF8Char);
begin
  SDL_SetRenderDrawColor(Renderer, 24, 24, 28, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(Renderer);
  SDL_SetRenderDrawColor(Renderer, 230, 230, 230, SDL_ALPHA_OPAQUE);
  SDL_RenderDebugText(Renderer, 16, 16, Text);
  SDL_RenderPresent(Renderer);
end;

function FrameRate(const S: SDL_CameraSpec): Double;
begin
  if S.framerate_denominator = 0 then
    Result := 0
  else
    Result := S.framerate_numerator / S.framerate_denominator;
end;

procedure PrintSpec(const Prefix: string; const S: SDL_CameraSpec);
begin
  WriteLn(Prefix, S.width, 'x', S.height, ' ', SDL_GetPixelFormatName(S.format), ' ', FrameRate(S):0:2, ' fps');
end;

{ True if A suits a video call better than B: a smooth frame rate first, then
  the largest size up to MaxArea, then a format that needs no JPEG decoding,
  then the frame rate closest to 30. }
function Better(const A, B: SDL_CameraSpec): Boolean;
var
  RateA, RateB: Double;
  AreaA, AreaB: Integer;
begin
  RateA := FrameRate(A);
  RateB := FrameRate(B);
  if ((RateA < MinFps) or (RateB < MinFps)) and (RateA <> RateB) then
    Exit(RateA > RateB);
  AreaA := A.width * A.height;
  AreaB := B.width * B.height;
  if (AreaA <= MaxArea) <> (AreaB <= MaxArea) then
    Exit(AreaA <= MaxArea);
  if AreaA <> AreaB then
  begin
    if AreaA <= MaxArea then
      Exit(AreaA > AreaB);
    Exit(AreaA < AreaB);
  end;
  if (A.format = SDL_PIXELFORMAT_MJPG) <> (B.format = SDL_PIXELFORMAT_MJPG) then
    Exit(B.format = SDL_PIXELFORMAT_MJPG);
  Result := RateA < RateB;
end;

{ A nil spec gets SDL's first mode, which is the largest whatever its frame
  rate, so pick one here instead. }
function ChooseSpec(Id: SDL_CameraID; out Best: SDL_CameraSpec): Boolean;
var
  Specs, P: PPSDL_CameraSpec;
  N, I: Integer;
begin
  Result := False;
  N := 0;
  Specs := SDL_GetCameraSupportedFormats(Id, @N);
  if Specs = nil then
    Exit;
  WriteLn('modes: ', N);
  P := Specs;
  for I := 1 to N do
  begin
    if (not Result) or Better(P^^, Best) then
    begin
      Best := P^^;
      Result := True;
    end;
    Inc(P);
  end;
  if Result then
    PrintSpec('SDL''s choice: ', Specs^^);
  SDL_free(Specs);
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

  if not SDL_CreateWindowAndRenderer('libsdl3-pascal camera', 960, 540, SDL_WINDOW_RESIZABLE, @Window, @Renderer) then
  begin
    WriteLn('SDL_CreateWindowAndRenderer failed: ', SDL_GetError);
    SDL_Quit;
    Halt(1);
  end;
  SDL_SetRenderVSync(Renderer, 1);

  Count := 0;
  Ids := SDL_GetCameras(@Count);
  WriteLn('cameras: ', Count);
  if (Ids <> nil) and (Count > 0) then
  begin
    WriteLn('opening ', SDL_GetCameraName(Ids^));
    if ChooseSpec(Ids^, Spec) then
    begin
      PrintSpec('using ', Spec);
      Cam := SDL_OpenCamera(Ids^, @Spec);
    end
    else
      Cam := SDL_OpenCamera(Ids^, nil);
    if Cam = nil then
      WriteLn('SDL_OpenCamera failed: ', SDL_GetError);
  end;
  SDL_free(Ids);

  Shown := 0;
  FpsClock := SDL_GetTicksNS;
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
      { Frames queue oldest first. Skip to the newest so a slow pass never
        leaves the picture behind the camera. }
      Frame := SDL_AcquireCameraFrame(Cam, nil);
      if Frame <> nil then
      begin
        Newer := SDL_AcquireCameraFrame(Cam, nil);
        while Newer <> nil do
        begin
          SDL_ReleaseCameraFrame(Cam, Frame);
          Frame := Newer;
          Newer := SDL_AcquireCameraFrame(Cam, nil);
        end;
        if Texture = nil then
        begin
          Texture := SDL_CreateTexture(Renderer, Frame.format, SDL_TEXTUREACCESS_STREAMING, Frame.w, Frame.h);
          SDL_SetRenderLogicalPresentation(Renderer, Frame.w, Frame.h, SDL_LOGICAL_PRESENTATION_LETTERBOX);
        end;
        if Texture <> nil then
          SDL_UpdateTexture(Texture, nil, Frame.pixels, Frame.pitch);
        SDL_ReleaseCameraFrame(Cam, Frame);
        Inc(Shown);
      end;
      SDL_SetRenderDrawColor(Renderer, 16, 16, 16, SDL_ALPHA_OPAQUE);
      SDL_RenderClear(Renderer);
      if Texture <> nil then
        SDL_RenderTexture(Renderer, Texture, nil, nil);
      SDL_RenderPresent(Renderer);

      NowNs := SDL_GetTicksNS;
      if NowNs - FpsClock >= SDL_NS_PER_SECOND then
      begin
        if Texture <> nil then
        begin
          SDL_snprintf(@Title[0], SizeOf(Title), 'libsdl3-pascal camera - %dx%d %s, %d fps',
            Texture.w, Texture.h, SDL_GetPixelFormatName(Texture.format), Shown);
          SDL_SetWindowTitle(Window, @Title[0]);
        end;
        Shown := 0;
        FpsClock := NowNs;
      end;
    end;
  end;

  SDL_DestroyTexture(Texture);
  SDL_CloseCamera(Cam);
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  SDL_Quit;
end.
