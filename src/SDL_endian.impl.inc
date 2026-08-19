function SDL_Swap16(x: Uint16): Uint16;
begin
  Result := Uint16((x shl 8) or (x shr 8));
end;

function SDL_Swap32(x: Uint32): Uint32;
begin
  Result := (x shl 24) or ((x shl 8) and $00FF0000) or
    ((x shr 8) and $0000FF00) or (x shr 24);
end;

function SDL_Swap64(x: Uint64): Uint64;
begin
  Result := (Uint64(SDL_Swap32(Uint32(x and $FFFFFFFF))) shl 32) or
    Uint64(SDL_Swap32(Uint32(x shr 32)));
end;

function SDL_SwapFloat(x: Single): Single;
var
  u: Uint32;
begin
  Move(x, u, SizeOf(u));
  u := SDL_Swap32(u);
  Move(u, Result, SizeOf(Result));
end;

function SDL_Swap16LE(x: Uint16): Uint16;
begin
  Result := x;
end;

function SDL_Swap32LE(x: Uint32): Uint32;
begin
  Result := x;
end;

function SDL_Swap64LE(x: Uint64): Uint64;
begin
  Result := x;
end;

function SDL_SwapFloatLE(x: Single): Single;
begin
  Result := x;
end;

function SDL_Swap16BE(x: Uint16): Uint16;
begin
  Result := SDL_Swap16(x);
end;

function SDL_Swap32BE(x: Uint32): Uint32;
begin
  Result := SDL_Swap32(x);
end;

function SDL_Swap64BE(x: Uint64): Uint64;
begin
  Result := SDL_Swap64(x);
end;

function SDL_SwapFloatBE(x: Single): Single;
begin
  Result := SDL_SwapFloat(x);
end;
