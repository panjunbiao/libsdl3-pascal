function SDL_AUDIO_BITSIZE(x: SDL_AudioFormat): Uint32;
begin
  Result := Uint32(x) and SDL_AUDIO_MASK_BITSIZE;
end;

function SDL_AUDIO_BYTESIZE(x: SDL_AudioFormat): Uint32;
begin
  Result := SDL_AUDIO_BITSIZE(x) div 8;
end;

function SDL_AUDIO_ISFLOAT(x: SDL_AudioFormat): Boolean;
begin
  Result := (Uint32(x) and SDL_AUDIO_MASK_FLOAT) <> 0;
end;

function SDL_AUDIO_ISBIGENDIAN(x: SDL_AudioFormat): Boolean;
begin
  Result := (Uint32(x) and SDL_AUDIO_MASK_BIG_ENDIAN) <> 0;
end;

function SDL_AUDIO_ISLITTLEENDIAN(x: SDL_AudioFormat): Boolean;
begin
  Result := not SDL_AUDIO_ISBIGENDIAN(x);
end;

function SDL_AUDIO_ISSIGNED(x: SDL_AudioFormat): Boolean;
begin
  Result := (Uint32(x) and SDL_AUDIO_MASK_SIGNED) <> 0;
end;

function SDL_AUDIO_ISINT(x: SDL_AudioFormat): Boolean;
begin
  Result := not SDL_AUDIO_ISFLOAT(x);
end;

function SDL_AUDIO_ISUNSIGNED(x: SDL_AudioFormat): Boolean;
begin
  Result := not SDL_AUDIO_ISSIGNED(x);
end;

function SDL_AUDIO_FRAMESIZE(const x: SDL_AudioSpec): Integer;
begin
  Result := Integer(SDL_AUDIO_BYTESIZE(x.format)) * x.channels;
end;

function SDL_DEFINE_AUDIO_FORMAT(signed_, bigendian, flt, size: Uint32): SDL_AudioFormat;
begin
  Result := SDL_AudioFormat((signed_ shl 15) or (bigendian shl 12) or (flt shl 8) or
    (size and SDL_AUDIO_MASK_BITSIZE));
end;
