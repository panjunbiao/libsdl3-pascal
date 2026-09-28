program gpu;

{ Clear a window through SDL_GPU. No shaders: the render pass only clears. }

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  Window: PSDL_Window;
  Device: PSDL_GPUDevice;
  Event: SDL_Event;
  Running: Boolean;
  Cmd: PSDL_GPUCommandBuffer;
  Swap: PSDL_GPUTexture;
  Info: SDL_GPUColorTargetInfo;
  Pass: PSDL_GPURenderPass;
  T: Double;

function GpuFormats: SDL_GPUShaderFormat;
begin
  Result := SDL_GPUShaderFormat(
    SDL_GPU_SHADERFORMAT_SPIRV or
    SDL_GPU_SHADERFORMAT_DXBC or
    SDL_GPU_SHADERFORMAT_DXIL or
    SDL_GPU_SHADERFORMAT_METALLIB);
end;

procedure Fail(const Step: string);
begin
  WriteLn(Step, ' failed: ', SDL_GetError);
  if Device <> nil then
  begin
    if Window <> nil then
      SDL_ReleaseWindowFromGPUDevice(Device, Window);
    SDL_DestroyGPUDevice(Device);
  end;
  if Window <> nil then
    SDL_DestroyWindow(Window);
  SDL_Quit;
  Halt(1);
end;

begin
  Window := nil;
  Device := nil;
  SDL_SetMainReady;
  SDL_SetAppMetadata('libsdl3-pascal gpu', '0.1.0', 'com.libsdl3pascal.gpu');

  if not SDL_Init(SDL_INIT_VIDEO) then
    Fail('SDL_Init');

  Window := SDL_CreateWindow('libsdl3-pascal gpu', 640, 480, 0);
  if Window = nil then
    Fail('SDL_CreateWindow');

  Device := SDL_CreateGPUDevice(GpuFormats, False, nil);
  if Device = nil then
    Fail('SDL_CreateGPUDevice');
  WriteLn('GPU driver: ', SDL_GetGPUDeviceDriver(Device));

  if not SDL_ClaimWindowForGPUDevice(Device, Window) then
    Fail('SDL_ClaimWindowForGPUDevice');

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

    if Running then
    begin
      Cmd := SDL_AcquireGPUCommandBuffer(Device);
      if Cmd = nil then
        Fail('SDL_AcquireGPUCommandBuffer');
      if not SDL_WaitAndAcquireGPUSwapchainTexture(Cmd, Window, @Swap, nil, nil) then
        Fail('SDL_WaitAndAcquireGPUSwapchainTexture');
      if Swap = nil then
        SDL_CancelGPUCommandBuffer(Cmd)
      else
      begin
        T := SDL_GetPerformanceCounter / SDL_GetPerformanceFrequency;
        FillChar(Info, SizeOf(Info), 0);
        Info.texture := Swap;
        Info.clear_color.r := 0.5 + 0.5 * SDL_sin(T);
        Info.clear_color.g := 0.5 + 0.5 * SDL_sin(T + SDL_PI_D * 2 / 3);
        Info.clear_color.b := 0.5 + 0.5 * SDL_sin(T + SDL_PI_D * 4 / 3);
        Info.clear_color.a := 1;
        Info.load_op := SDL_GPU_LOADOP_CLEAR;
        Info.store_op := SDL_GPU_STOREOP_STORE;
        Pass := SDL_BeginGPURenderPass(Cmd, @Info, 1, nil);
        if Pass <> nil then
          SDL_EndGPURenderPass(Pass);
        if not SDL_SubmitGPUCommandBuffer(Cmd) then
          Fail('SDL_SubmitGPUCommandBuffer');
      end;
    end;
  end;

  SDL_ReleaseWindowFromGPUDevice(Device, Window);
  SDL_DestroyGPUDevice(Device);
  SDL_DestroyWindow(Window);
  SDL_Quit;
end.
