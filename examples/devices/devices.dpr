program devices;

{ List camera drivers, haptic devices, and HID devices. Rumble the first haptic. }

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  I, Count: Integer;
  Name: PUTF8Char;
  Haptics: PSDL_HapticID;
  Haptic: PSDL_Haptic;
  Hid: PSDL_hid_device_info;
  Info: PSDL_hid_device_info;
begin
  SDL_SetMainReady;
  if not SDL_Init(SDL_INIT_CAMERA or SDL_INIT_HAPTIC) then
  begin
    WriteLn('SDL_Init failed: ', SDL_GetError);
    Halt(1);
  end;

  Count := SDL_GetNumCameraDrivers;
  WriteLn('camera drivers: ', Count);
  for I := 0 to Count - 1 do
  begin
    Name := SDL_GetCameraDriver(I);
    if Name <> nil then
      WriteLn('  ', Name);
  end;

  Count := 0;
  Haptics := SDL_GetHaptics(@Count);
  WriteLn('haptics: ', Count);
  if SDL_IsMouseHaptic then
    WriteLn('  mouse reports haptic support');
  if (Haptics <> nil) and (Count > 0) then
  begin
    Name := SDL_GetHapticNameForID(Haptics^);
    if Name <> nil then
      WriteLn('  rumbling ', Name);
    Haptic := SDL_OpenHaptic(Haptics^);
    if Haptic = nil then
      WriteLn('  SDL_OpenHaptic failed: ', SDL_GetError)
    else
    begin
      if SDL_InitHapticRumble(Haptic) and SDL_PlayHapticRumble(Haptic, 0.5, 400) then
        SDL_Delay(500)
      else
        WriteLn('  rumble failed: ', SDL_GetError);
      SDL_CloseHaptic(Haptic);
    end;
  end;
  SDL_free(Haptics);

  if SDL_hid_init <> 0 then
    WriteLn('SDL_hid_init failed: ', SDL_GetError)
  else
  begin
    Hid := SDL_hid_enumerate(0, 0);
    Info := Hid;
    WriteLn('HID devices:');
    if Info = nil then
      WriteLn('  (none)');
    while Info <> nil do
    begin
      Write('  ', Info.vendor_id, ':', Info.product_id);
      if Info.product_string <> nil then
        Write('  ', string(Info.product_string));
      WriteLn;
      Info := Info.next;
    end;
    SDL_hid_free_enumeration(Hid);
    SDL_hid_exit;
  end;

  SDL_Quit;
end.
