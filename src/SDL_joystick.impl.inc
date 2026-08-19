procedure SDL_INIT_INTERFACE(desc: PSDL_VirtualJoystickDesc);
begin
  FillChar(desc^, SizeOf(desc^), 0);
  desc^.version := SizeOf(SDL_VirtualJoystickDesc);
end;
