{ SDL_metal.inc -- 1-to-1 from SDL_metal.h (SDL 3.4.16) }

type
  SDL_MetalView = Pointer;
  PSDL_MetalView = ^SDL_MetalView;
  PPSDL_MetalView = ^PSDL_MetalView;

function SDL_Metal_CreateView(window: PSDL_Window): SDL_MetalView; cdecl;
  external SDL_LIB_NAME;
procedure SDL_Metal_DestroyView(view: SDL_MetalView); cdecl;
  external SDL_LIB_NAME;
function SDL_Metal_GetLayer(view: SDL_MetalView): Pointer; cdecl;
  external SDL_LIB_NAME;
