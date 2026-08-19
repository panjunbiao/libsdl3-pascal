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
  WriteLn('All required ABI checks passed.');
end.
