procedure SDL_INIT_INTERFACE(engine: PTTF_TextEngine);
begin
  FillChar(engine^, SizeOf(engine^), 0);
  engine^.version := SizeOf(TTF_TextEngine);
end;
