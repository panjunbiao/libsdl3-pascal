procedure SDL_MemoryBarrierRelease;
begin
  SDL_MemoryBarrierReleaseFunction;
end;

procedure SDL_MemoryBarrierAcquire;
begin
  SDL_MemoryBarrierAcquireFunction;
end;

function SDL_AtomicIncRef(a: PSDL_AtomicInt): Integer;
begin
  Result := SDL_AddAtomicInt(a, 1);
end;

function SDL_AtomicDecRef(a: PSDL_AtomicInt): Boolean;
begin
  Result := SDL_AddAtomicInt(a, -1) = 1;
end;
