function SDL_SECONDS_TO_NS(S: Uint64): Uint64;
begin
  Result := S * SDL_NS_PER_SECOND;
end;

function SDL_NS_TO_SECONDS(NS: Uint64): Uint64;
begin
  Result := NS div SDL_NS_PER_SECOND;
end;

function SDL_MS_TO_NS(MS: Uint64): Uint64;
begin
  Result := MS * SDL_NS_PER_MS;
end;

function SDL_NS_TO_MS(NS: Uint64): Uint64;
begin
  Result := NS div SDL_NS_PER_MS;
end;

function SDL_US_TO_NS(US: Uint64): Uint64;
begin
  Result := US * SDL_NS_PER_US;
end;

function SDL_NS_TO_US(NS: Uint64): Uint64;
begin
  Result := NS div SDL_NS_PER_US;
end;
