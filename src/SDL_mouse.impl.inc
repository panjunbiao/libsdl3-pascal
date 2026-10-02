function SDL_BUTTON_MASK(X: Integer): SDL_MouseButtonFlags;
begin
  Result := SDL_MouseButtonFlags(1) shl (X - 1);
end;
