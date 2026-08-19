procedure SDL_INIT_INTERFACE(iface: PSDL_IOStreamInterface);
begin
  FillChar(iface^, SizeOf(iface^), 0);
  iface^.version := SizeOf(SDL_IOStreamInterface);
end;
