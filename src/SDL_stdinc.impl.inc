{ SDL_stdinc.impl.inc -- Pascal bodies for C inline helpers in SDL_stdinc.h }

function SDL_FOURCC(A, B, C, D: Uint8): Uint32;
begin
  Result := Uint32(A) or (Uint32(B) shl 8) or (Uint32(C) shl 16) or (Uint32(D) shl 24);
end;

function SDL_iconv_utf8_locale(S: PUTF8Char): PUTF8Char;
begin
  Result := SDL_iconv_string('', 'UTF-8', S, SDL_strlen(S) + 1);
end;

function SDL_iconv_utf8_ucs2(S: PUTF8Char): PUint16;
begin
  Result := PUint16(SDL_iconv_string('UCS-2', 'UTF-8', S, SDL_strlen(S) + 1));
end;

function SDL_iconv_utf8_ucs4(S: PUTF8Char): PUint32;
begin
  Result := PUint32(SDL_iconv_string('UCS-4', 'UTF-8', S, SDL_strlen(S) + 1));
end;

function SDL_iconv_wchar_utf8(S: PWideChar): PUTF8Char;
begin
  Result := SDL_iconv_string('UTF-8', 'WCHAR_T', PUTF8Char(S), (SDL_wcslen(S) + 1) * SizeOf(WideChar));
end;

function SDL_size_mul_check_overflow(a, b: NativeUInt; ret: PNativeUInt): Boolean;
begin
  if (a <> 0) and (b > SDL_SIZE_MAX div a) then
    Exit(False);
  ret^ := a * b;
  Result := True;
end;

function SDL_size_add_check_overflow(a, b: NativeUInt; ret: PNativeUInt): Boolean;
begin
  if b > SDL_SIZE_MAX - a then
    Exit(False);
  ret^ := a + b;
  Result := True;
end;
