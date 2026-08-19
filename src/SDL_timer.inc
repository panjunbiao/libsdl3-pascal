{ SDL_timer.inc -- Phase 1 exposes SDL_Delay for examples. Remaining timer APIs in Phase 3. }

procedure SDL_Delay(ms: Uint32); cdecl; external SDL_LIB_NAME;
