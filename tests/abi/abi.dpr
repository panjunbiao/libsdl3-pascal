program abi;

{$APPTYPE CONSOLE}

uses
  SDL3;

procedure Check(const Name: string; Actual, Expected: Integer);
begin
  if Actual <> Expected then
  begin
    WriteLn('FAIL ', Name, ' SizeOf=', Actual, ' expected=', Expected);
    Halt(1);
  end;
  WriteLn('OK   ', Name, ' SizeOf=', Actual);
end;

begin
  Check('Sint8', SizeOf(Sint8), 1);
  Check('Uint8', SizeOf(Uint8), 1);
  Check('Sint16', SizeOf(Sint16), 2);
  Check('Uint16', SizeOf(Uint16), 2);
  Check('Sint32', SizeOf(Sint32), 4);
  Check('Uint32', SizeOf(Uint32), 4);
  Check('Sint64', SizeOf(Sint64), 8);
  Check('Uint64', SizeOf(Uint64), 8);
  Check('Boolean', SizeOf(Boolean), 1);
  Check('SDL_Point', SizeOf(SDL_Point), 8);
  Check('SDL_FPoint', SizeOf(SDL_FPoint), 8);
  Check('SDL_Rect', SizeOf(SDL_Rect), 16);
  Check('SDL_FRect', SizeOf(SDL_FRect), 16);
  Check('SDL_CommonEvent', SizeOf(SDL_CommonEvent), 16);
  Check('SDL_Event', SizeOf(SDL_Event), 128);
  Check('SDL_DisplayEvent', SizeOf(SDL_DisplayEvent), 32);
  Check('SDL_WindowEvent', SizeOf(SDL_WindowEvent), 32);
  Check('SDL_QuitEvent', SizeOf(SDL_QuitEvent), 16);
  Check('SDL_UserEvent', SizeOf(SDL_UserEvent), 40);
  Check('SDL_DisplayMode', SizeOf(SDL_DisplayMode), 40);
  Check('SDL_Color', SizeOf(SDL_Color), 4);
  Check('SDL_FColor', SizeOf(SDL_FColor), 16);
  Check('SDL_Palette', SizeOf(SDL_Palette), 24);
  Check('SDL_PixelFormatDetails', SizeOf(SDL_PixelFormatDetails), 32);
  Check('SDL_Surface', SizeOf(SDL_Surface), 48);
  Check('SDL_Vertex', SizeOf(SDL_Vertex), 32);
  Check('SDL_Texture', SizeOf(SDL_Texture), 16);
  Check('SDL_CursorFrameInfo', SizeOf(SDL_CursorFrameInfo), 16);
  Check('SDL_KeyboardDeviceEvent', SizeOf(SDL_KeyboardDeviceEvent), 24);
  Check('SDL_KeyboardEvent', SizeOf(SDL_KeyboardEvent), 40);
  Check('SDL_TextEditingEvent', SizeOf(SDL_TextEditingEvent), 40);
  Check('SDL_TextEditingCandidatesEvent', SizeOf(SDL_TextEditingCandidatesEvent), 48);
  Check('SDL_TextInputEvent', SizeOf(SDL_TextInputEvent), 32);
  Check('SDL_MouseDeviceEvent', SizeOf(SDL_MouseDeviceEvent), 24);
  Check('SDL_MouseMotionEvent', SizeOf(SDL_MouseMotionEvent), 48);
  Check('SDL_MouseButtonEvent', SizeOf(SDL_MouseButtonEvent), 40);
  Check('SDL_MouseWheelEvent', SizeOf(SDL_MouseWheelEvent), 56);
  Check('SDL_GUID', SizeOf(SDL_GUID), 16);
  Check('SDL_PathInfo', SizeOf(SDL_PathInfo), 40);
  Check('SDL_Finger', SizeOf(SDL_Finger), 24);
  Check('SDL_AudioSpec', SizeOf(SDL_AudioSpec), 12);
  Check('SDL_IOStreamInterface', SizeOf(SDL_IOStreamInterface), 56);
  Check('SDL_VirtualJoystickTouchpadDesc', SizeOf(SDL_VirtualJoystickTouchpadDesc), 8);
  Check('SDL_VirtualJoystickSensorDesc', SizeOf(SDL_VirtualJoystickSensorDesc), 8);
  Check('SDL_VirtualJoystickDesc', SizeOf(SDL_VirtualJoystickDesc), 136);
  Check('SDL_GamepadBinding', SizeOf(SDL_GamepadBinding), 32);
  Check('SDL_JoyAxisEvent', SizeOf(SDL_JoyAxisEvent), 32);
  Check('SDL_JoyBallEvent', SizeOf(SDL_JoyBallEvent), 32);
  Check('SDL_JoyHatEvent', SizeOf(SDL_JoyHatEvent), 24);
  Check('SDL_JoyButtonEvent', SizeOf(SDL_JoyButtonEvent), 24);
  Check('SDL_JoyDeviceEvent', SizeOf(SDL_JoyDeviceEvent), 24);
  Check('SDL_JoyBatteryEvent', SizeOf(SDL_JoyBatteryEvent), 32);
  Check('SDL_GamepadTouchpadEvent', SizeOf(SDL_GamepadTouchpadEvent), 40);
  Check('SDL_GamepadSensorEvent', SizeOf(SDL_GamepadSensorEvent), 48);
  Check('SDL_AudioDeviceEvent', SizeOf(SDL_AudioDeviceEvent), 24);
  Check('SDL_TouchFingerEvent', SizeOf(SDL_TouchFingerEvent), 56);
  Check('SDL_PinchFingerEvent', SizeOf(SDL_PinchFingerEvent), 24);
  Check('SDL_ClipboardEvent', SizeOf(SDL_ClipboardEvent), 32);
  Check('SDL_Locale', SizeOf(SDL_Locale), 16);
  Check('SDL_DateTime', SizeOf(SDL_DateTime), 36);
  Check('SDL_AtomicInt', SizeOf(SDL_AtomicInt), 4);
  Check('SDL_AtomicU32', SizeOf(SDL_AtomicU32), 4);
  Check('SDL_InitState', SizeOf(SDL_InitState), 24);
  Check('SDL_MessageBoxButtonData', SizeOf(SDL_MessageBoxButtonData), 16);
  Check('SDL_MessageBoxColor', SizeOf(SDL_MessageBoxColor), 3);
  Check('SDL_MessageBoxColorScheme', SizeOf(SDL_MessageBoxColorScheme), 15);
  Check('SDL_MessageBoxData', SizeOf(SDL_MessageBoxData), 56);
  Check('SDL_DialogFileFilter', SizeOf(SDL_DialogFileFilter), 16);
  Check('SDL_AssertData', SizeOf(SDL_AssertData), 48);
  Check('SDL_AsyncIOOutcome', SizeOf(SDL_AsyncIOOutcome), 56);
  Check('SDL_StorageInterface', SizeOf(SDL_StorageInterface), 96);
  Check('SDL_PenProximityEvent', SizeOf(SDL_PenProximityEvent), 24);
  Check('SDL_PenMotionEvent', SizeOf(SDL_PenMotionEvent), 40);
  Check('SDL_PenTouchEvent', SizeOf(SDL_PenTouchEvent), 40);
  Check('SDL_PenButtonEvent', SizeOf(SDL_PenButtonEvent), 40);
  Check('SDL_PenAxisEvent', SizeOf(SDL_PenAxisEvent), 48);
  WriteLn('All required ABI checks passed.');
end.
