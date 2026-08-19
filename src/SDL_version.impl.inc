function SDL_VERSIONNUM(major, minor, patch: Integer): Integer;
begin
  Result := major * 1000000 + minor * 1000 + patch;
end;

function SDL_VERSIONNUM_MAJOR(version: Integer): Integer;
begin
  Result := version div 1000000;
end;

function SDL_VERSIONNUM_MINOR(version: Integer): Integer;
begin
  Result := (version div 1000) mod 1000;
end;

function SDL_VERSIONNUM_MICRO(version: Integer): Integer;
begin
  Result := version mod 1000;
end;

function SDL_VERSION_ATLEAST(X, Y, Z: Integer): Boolean;
begin
  Result := SDL_VERSION >= SDL_VERSIONNUM(X, Y, Z);
end;
