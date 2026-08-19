procedure SDL_RectToFRect(const rect: PSDL_Rect; frect: PSDL_FRect);
begin
  frect^.x := rect^.x;
  frect^.y := rect^.y;
  frect^.w := rect^.w;
  frect^.h := rect^.h;
end;

function SDL_PointInRect(const p: PSDL_Point; const r: PSDL_Rect): Boolean;
begin
  Result := (p <> nil) and (r <> nil) and
    (p^.x >= r^.x) and (p^.x < (r^.x + r^.w)) and
    (p^.y >= r^.y) and (p^.y < (r^.y + r^.h));
end;

function SDL_RectEmpty(const r: PSDL_Rect): Boolean;
begin
  Result := (r = nil) or (r^.w <= 0) or (r^.h <= 0);
end;

function SDL_RectsEqual(const a, b: PSDL_Rect): Boolean;
begin
  Result := (a <> nil) and (b <> nil) and
    (a^.x = b^.x) and (a^.y = b^.y) and
    (a^.w = b^.w) and (a^.h = b^.h);
end;

function SDL_PointInRectFloat(const p: PSDL_FPoint; const r: PSDL_FRect): Boolean;
begin
  Result := (p <> nil) and (r <> nil) and
    (p^.x >= r^.x) and (p^.x <= (r^.x + r^.w)) and
    (p^.y >= r^.y) and (p^.y <= (r^.y + r^.h));
end;

function SDL_RectEmptyFloat(const r: PSDL_FRect): Boolean;
begin
  Result := (r = nil) or (r^.w < 0.0) or (r^.h < 0.0);
end;
