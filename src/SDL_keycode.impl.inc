function SDL_SCANCODE_TO_KEYCODE(X: SDL_Scancode): SDL_Keycode;
begin
  Result := SDL_Keycode(Uint32(X) or SDLK_SCANCODE_MASK);
end;
