{ SDL_pixels.inc -- Phase 1: SDL_PixelFormat as Uint32. Full enum in Phase 2. }

type
  SDL_PixelFormat = type Uint32;

const
  SDL_PIXELFORMAT_UNKNOWN = SDL_PixelFormat(0);
