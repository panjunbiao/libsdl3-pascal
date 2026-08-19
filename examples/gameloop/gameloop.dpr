program gameloop;

{$APPTYPE CONSOLE}

{ Binding showcase: fixed-timestep loop, keyboard/mouse, optional gamepad,
  renderer, and a generated texture. Not a game engine. }

uses
  SDL3;

const
  WinW = 960;
  WinH = 540;
  PlayerW = 48;
  PlayerH = 48;
  Speed = 240.0;
  Deadzone = 8000;
  TexSize = 64;

var
  Window: PSDL_Window;
  Renderer: PSDL_Renderer;
  Texture: PSDL_Texture;
  Gamepad: PSDL_Gamepad;
  Event: SDL_Event;
  Running: Boolean;
  PlayerX, PlayerY: Single;
  Keys: PBoolean;
  PrevNs, NowNs, AccNs, StepNs: Uint64;
  FpsClock: Uint64;
  Frames, Fps: Integer;
  MouseX, MouseY: Single;
  Line: array[0..95] of AnsiChar;

function KeyHeld(Code: SDL_Scancode): Boolean;
begin
  Result := PByte(Keys)[Ord(Code)] <> 0;
end;

procedure Die(Msg: PUTF8Char);
begin
  WriteLn(Msg, ': ', SDL_GetError);
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, 'libsdl3-pascal gameloop', Msg, Window);
  if Renderer <> nil then
    SDL_DestroyRenderer(Renderer);
  if Window <> nil then
    SDL_DestroyWindow(Window);
  SDL_Quit;
  Halt(1);
end;

procedure OpenFirstGamepad;
var
  Count: Integer;
  Ids: PSDL_JoystickID;
begin
  if Gamepad <> nil then
    Exit;
  Ids := SDL_GetGamepads(@Count);
  if (Ids <> nil) and (Count > 0) then
    Gamepad := SDL_OpenGamepad(Ids^);
  if Ids <> nil then
    SDL_free(Ids);
end;

procedure HandleGamepadRemoved(Id: SDL_JoystickID);
begin
  if (Gamepad <> nil) and (SDL_GetGamepadID(Gamepad) = Id) then
  begin
    SDL_CloseGamepad(Gamepad);
    Gamepad := nil;
  end;
end;

function AxisToUnit(Value: Sint16): Single;
begin
  if Abs(Value) < Deadzone then
    Exit(0);
  Result := Value / 32767.0;
end;

function MakeCheckerTexture: PSDL_Texture;
var
  Pixels: array[0..TexSize * TexSize - 1] of Uint32;
  X, Y: Integer;
  Dark: Boolean;
begin
  { SDL_PIXELFORMAT_RGBA32 on Win64 is byte order R,G,B,A in memory. }
  for Y := 0 to TexSize - 1 do
    for X := 0 to TexSize - 1 do
    begin
      Dark := ((X shr 3) xor (Y shr 3)) and 1 = 0;
      if Dark then
        Pixels[Y * TexSize + X] := $FF50503A
      else
        Pixels[Y * TexSize + X] := $FF38382A;
    end;
  Result := SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_RGBA32,
    SDL_TEXTUREACCESS_STATIC, TexSize, TexSize);
  if Result = nil then
    Exit;
  if not SDL_UpdateTexture(Result, nil, @Pixels[0], TexSize * SizeOf(Uint32)) then
  begin
    SDL_DestroyTexture(Result);
    Result := nil;
  end;
end;

procedure WriteInt(var Dst: array of AnsiChar; var Pos: Integer; Value: Integer);
var
  Tmp: array[0..9] of AnsiChar;
  N, I: Integer;
begin
  if Value < 0 then
    Value := 0;
  N := 0;
  repeat
    Tmp[N] := AnsiChar(Ord('0') + (Value mod 10));
    Value := Value div 10;
    Inc(N);
  until Value = 0;
  for I := N - 1 downto 0 do
  begin
    if Pos > High(Dst) - 1 then
      Break;
    Dst[Pos] := Tmp[I];
    Inc(Pos);
  end;
end;

procedure WriteLit(var Dst: array of AnsiChar; var Pos: Integer; const S: AnsiString);
var
  I: Integer;
begin
  for I := 1 to Length(S) do
  begin
    if Pos > High(Dst) - 1 then
      Break;
    Dst[Pos] := S[I];
    Inc(Pos);
  end;
end;

procedure BuildStatusLine;
var
  Pos: Integer;
  MX, MY: Integer;
begin
  Pos := 0;
  WriteLit(Line, Pos, 'fps=');
  WriteInt(Line, Pos, Fps);
  WriteLit(Line, Pos, '  mouse=');
  MX := Trunc(MouseX);
  MY := Trunc(MouseY);
  WriteInt(Line, Pos, MX);
  WriteLit(Line, Pos, ',');
  WriteInt(Line, Pos, MY);
  if Gamepad <> nil then
    WriteLit(Line, Pos, '  gamepad')
  else
    WriteLit(Line, Pos, '  keys/mouse');
  Line[Pos] := #0;
end;

procedure StepPlayer(Dt: Single);
var
  Vx, Vy, Mag: Single;
  Ax, Ay: Single;
begin
  Vx := 0;
  Vy := 0;
  if KeyHeld(SDL_SCANCODE_A) or KeyHeld(SDL_SCANCODE_LEFT) then
    Vx := Vx - 1;
  if KeyHeld(SDL_SCANCODE_D) or KeyHeld(SDL_SCANCODE_RIGHT) then
    Vx := Vx + 1;
  if KeyHeld(SDL_SCANCODE_W) or KeyHeld(SDL_SCANCODE_UP) then
    Vy := Vy - 1;
  if KeyHeld(SDL_SCANCODE_S) or KeyHeld(SDL_SCANCODE_DOWN) then
    Vy := Vy + 1;

  if Gamepad <> nil then
  begin
    Ax := AxisToUnit(SDL_GetGamepadAxis(Gamepad, SDL_GAMEPAD_AXIS_LEFTX));
    Ay := AxisToUnit(SDL_GetGamepadAxis(Gamepad, SDL_GAMEPAD_AXIS_LEFTY));
    if Abs(Ax) > Abs(Vx) then
      Vx := Ax;
    if Abs(Ay) > Abs(Vy) then
      Vy := Ay;
  end;

  Mag := Sqrt(Vx * Vx + Vy * Vy);
  if Mag > 1 then
  begin
    Vx := Vx / Mag;
    Vy := Vy / Mag;
  end;

  PlayerX := PlayerX + Vx * Speed * Dt;
  PlayerY := PlayerY + Vy * Speed * Dt;
  if PlayerX < 0 then
    PlayerX := 0;
  if PlayerY < 0 then
    PlayerY := 0;
  if PlayerX > WinW - PlayerW then
    PlayerX := WinW - PlayerW;
  if PlayerY > WinH - PlayerH then
    PlayerY := WinH - PlayerH;
end;

procedure DrawFrame;
var
  Dest, Player: SDL_FRect;
begin
  SDL_SetRenderDrawColor(Renderer, 18, 18, 28, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(Renderer);

  Dest.x := 0;
  Dest.y := 0;
  Dest.w := WinW;
  Dest.h := WinH;
  SDL_RenderTextureTiled(Renderer, Texture, nil, 1.0, @Dest);

  Player.x := PlayerX;
  Player.y := PlayerY;
  Player.w := PlayerW;
  Player.h := PlayerH;
  SDL_SetRenderDrawColor(Renderer, 230, 80, 60, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(Renderer, @Player);

  BuildStatusLine;
  SDL_SetRenderDrawColor(Renderer, 220, 220, 230, SDL_ALPHA_OPAQUE);
  SDL_RenderDebugText(Renderer, 8, 8, @Line[0]);
  SDL_RenderDebugText(Renderer, 8, 24,
    'WASD/arrows or left stick to move. Esc or close to quit.');
  SDL_RenderPresent(Renderer);
end;

begin
  Window := nil;
  Renderer := nil;
  Texture := nil;
  Gamepad := nil;

  SDL_SetMainReady;
  SDL_SetAppMetadata('libsdl3-pascal gameloop', '0.1.0', 'com.libsdl3pascal.gameloop');

  if not SDL_Init(SDL_INIT_VIDEO or SDL_INIT_GAMEPAD) then
    Die('SDL_Init failed');

  if not SDL_CreateWindowAndRenderer('libsdl3-pascal gameloop', WinW, WinH, 0,
    @Window, @Renderer) then
    Die('SDL_CreateWindowAndRenderer failed');

  SDL_SetRenderVSync(Renderer, 1);
  Texture := MakeCheckerTexture;
  if Texture = nil then
    Die('SDL_CreateTexture failed');

  OpenFirstGamepad;
  Keys := SDL_GetKeyboardState(nil);
  PlayerX := (WinW - PlayerW) / 2;
  PlayerY := (WinH - PlayerH) / 2;
  StepNs := SDL_NS_PER_SECOND div 60;
  PrevNs := SDL_GetTicksNS;
  FpsClock := PrevNs;
  AccNs := 0;
  Frames := 0;
  Fps := 0;
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
      if Event.type_ = Uint32(SDL_EVENT_GAMEPAD_ADDED) then
        OpenFirstGamepad;
      if Event.type_ = Uint32(SDL_EVENT_GAMEPAD_REMOVED) then
        HandleGamepadRemoved(Event.gdevice.which);
    end;

    NowNs := SDL_GetTicksNS;
    AccNs := AccNs + (NowNs - PrevNs);
    PrevNs := NowNs;
    while AccNs >= StepNs do
    begin
      StepPlayer(1.0 / 60.0);
      AccNs := AccNs - StepNs;
    end;

    SDL_GetMouseState(@MouseX, @MouseY);
    Inc(Frames);
    if NowNs - FpsClock >= SDL_NS_PER_SECOND then
    begin
      Fps := Frames;
      Frames := 0;
      FpsClock := NowNs;
    end;

    DrawFrame;
  end;

  if Gamepad <> nil then
    SDL_CloseGamepad(Gamepad);
  SDL_DestroyTexture(Texture);
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  SDL_Quit;
end.
