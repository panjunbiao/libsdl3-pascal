function SDL_TTF_VERSION_ATLEAST(X, Y, Z: Integer): Boolean;
begin
  Result := (SDL_TTF_MAJOR_VERSION >= X) and
    ((SDL_TTF_MAJOR_VERSION > X) or (SDL_TTF_MINOR_VERSION >= Y)) and
    ((SDL_TTF_MAJOR_VERSION > X) or (SDL_TTF_MINOR_VERSION > Y) or (SDL_TTF_MICRO_VERSION >= Z));
end;
