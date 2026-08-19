function SDL_MostSignificantBitIndex32(x: Uint32): Integer;
const
  B: array[0..4] of Uint32 = ($2, $C, $F0, $FF00, $FFFF0000);
  S: array[0..4] of Integer = (1, 2, 4, 8, 16);
var
  msbIndex, i: Integer;
begin
  if x = 0 then
    Exit(-1);
  msbIndex := 0;
  for i := 4 downto 0 do
    if (x and B[i]) <> 0 then
    begin
      x := x shr S[i];
      msbIndex := msbIndex or S[i];
    end;
  Result := msbIndex;
end;

function SDL_HasExactlyOneBitSet32(x: Uint32): Boolean;
begin
  Result := (x <> 0) and ((x and (x - 1)) = 0);
end;
