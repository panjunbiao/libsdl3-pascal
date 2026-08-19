procedure SDL_INIT_INTERFACE(iface: PSDL_StorageInterface);
begin
  FillChar(iface^, SizeOf(iface^), 0);
  iface^.version := SizeOf(SDL_StorageInterface);
end;
