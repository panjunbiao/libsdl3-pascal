function SDL_WINDOWPOS_UNDEFINED_DISPLAY(X: Integer): Integer;
begin
  Result := SDL_WINDOWPOS_UNDEFINED_MASK or X;
end;

function SDL_WINDOWPOS_CENTERED_DISPLAY(X: Integer): Integer;
begin
  Result := SDL_WINDOWPOS_CENTERED_MASK or X;
end;

function SDL_WINDOWPOS_ISUNDEFINED(X: Integer): Boolean;
begin
  Result := (X and $FFFF0000) = SDL_WINDOWPOS_UNDEFINED_MASK;
end;

function SDL_WINDOWPOS_ISCENTERED(X: Integer): Boolean;
begin
  Result := (X and $FFFF0000) = SDL_WINDOWPOS_CENTERED_MASK;
end;
