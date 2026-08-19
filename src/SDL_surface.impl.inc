function SDL_MUSTLOCK(const S: PSDL_Surface): Boolean;
begin
  Result := (S <> nil) and ((S^.flags and SDL_SURFACE_LOCK_NEEDED) = SDL_SURFACE_LOCK_NEEDED);
end;
