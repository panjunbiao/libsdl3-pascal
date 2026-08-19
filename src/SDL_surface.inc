{ SDL_surface.inc -- 1-to-1 from SDL_surface.h }

type
  SDL_SurfaceFlags = Uint32;

const
  SDL_SURFACE_PREALLOCATED = $00000001;
  SDL_SURFACE_LOCK_NEEDED = $00000002;
  SDL_SURFACE_LOCKED = $00000004;
  SDL_SURFACE_SIMD_ALIGNED = $00000008;

  SDL_PROP_SURFACE_SDR_WHITE_POINT_FLOAT = 'SDL.surface.SDR_white_point';
  SDL_PROP_SURFACE_HDR_HEADROOM_FLOAT = 'SDL.surface.HDR_headroom';
  SDL_PROP_SURFACE_TONEMAP_OPERATOR_STRING = 'SDL.surface.tonemap';
  SDL_PROP_SURFACE_HOTSPOT_X_NUMBER = 'SDL.surface.hotspot.x';
  SDL_PROP_SURFACE_HOTSPOT_Y_NUMBER = 'SDL.surface.hotspot.y';
  SDL_PROP_SURFACE_ROTATION_FLOAT = 'SDL.surface.rotation';

type
  SDL_ScaleMode = (
    SDL_SCALEMODE_INVALID = -1,
    SDL_SCALEMODE_NEAREST,
    SDL_SCALEMODE_LINEAR,
    SDL_SCALEMODE_PIXELART
  );
  PSDL_ScaleMode = ^SDL_ScaleMode;

  SDL_FlipMode = (
    SDL_FLIP_NONE,
    SDL_FLIP_HORIZONTAL,
    SDL_FLIP_VERTICAL,
    SDL_FLIP_HORIZONTAL_AND_VERTICAL = 3
  );

  PSDL_Surface = ^SDL_Surface;
  PPSDL_Surface = ^PSDL_Surface;
  SDL_Surface = record
    flags: SDL_SurfaceFlags;
    format: SDL_PixelFormat;
    w: Integer;
    h: Integer;
    pitch: Integer;
    pixels: Pointer;
    refcount: Integer;
    reserved: Pointer;
  end;

function SDL_MUSTLOCK(const S: PSDL_Surface): Boolean;

function SDL_CreateSurface(width, height: Integer; format: SDL_PixelFormat): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateSurfaceFrom(width, height: Integer; format: SDL_PixelFormat; pixels: Pointer; pitch: Integer): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroySurface(surface: PSDL_Surface); cdecl;
  external SDL_LIB_NAME;
function SDL_GetSurfaceProperties(surface: PSDL_Surface): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_SetSurfaceColorspace(surface: PSDL_Surface; colorspace: SDL_Colorspace): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSurfaceColorspace(surface: PSDL_Surface): SDL_Colorspace; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateSurfacePalette(surface: PSDL_Surface): PSDL_Palette; cdecl;
  external SDL_LIB_NAME;
function SDL_SetSurfacePalette(surface: PSDL_Surface; palette: PSDL_Palette): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSurfacePalette(surface: PSDL_Surface): PSDL_Palette; cdecl;
  external SDL_LIB_NAME;
function SDL_AddSurfaceAlternateImage(surface, image: PSDL_Surface): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SurfaceHasAlternateImages(surface: PSDL_Surface): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSurfaceImages(surface: PSDL_Surface; count: PInteger): PPSDL_Surface; cdecl;
  external SDL_LIB_NAME;
procedure SDL_RemoveSurfaceAlternateImages(surface: PSDL_Surface); cdecl;
  external SDL_LIB_NAME;
function SDL_LockSurface(surface: PSDL_Surface): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnlockSurface(surface: PSDL_Surface); cdecl;
  external SDL_LIB_NAME;
function SDL_LoadSurface_IO(src: PSDL_IOStream; closeio: Boolean): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadSurface(file_: PUTF8Char): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadBMP_IO(src: PSDL_IOStream; closeio: Boolean): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadBMP(file_: PUTF8Char): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_SaveBMP_IO(surface: PSDL_Surface; dst: PSDL_IOStream; closeio: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SaveBMP(surface: PSDL_Surface; file_: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadPNG_IO(src: PSDL_IOStream; closeio: Boolean): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadPNG(file_: PUTF8Char): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_SavePNG_IO(surface: PSDL_Surface; dst: PSDL_IOStream; closeio: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SavePNG(surface: PSDL_Surface; file_: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetSurfaceRLE(surface: PSDL_Surface; enabled: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SurfaceHasRLE(surface: PSDL_Surface): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetSurfaceColorKey(surface: PSDL_Surface; enabled: Boolean; key: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SurfaceHasColorKey(surface: PSDL_Surface): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSurfaceColorKey(surface: PSDL_Surface; key: PUint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetSurfaceColorMod(surface: PSDL_Surface; r, g, b: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSurfaceColorMod(surface: PSDL_Surface; r, g, b: PUint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetSurfaceAlphaMod(surface: PSDL_Surface; alpha: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSurfaceAlphaMod(surface: PSDL_Surface; alpha: PUint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetSurfaceBlendMode(surface: PSDL_Surface; blendMode: SDL_BlendMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSurfaceBlendMode(surface: PSDL_Surface; blendMode: PSDL_BlendMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetSurfaceClipRect(surface: PSDL_Surface; const rect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSurfaceClipRect(surface: PSDL_Surface; rect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_FlipSurface(surface: PSDL_Surface; flip: SDL_FlipMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RotateSurface(surface: PSDL_Surface; angle: Single): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_DuplicateSurface(surface: PSDL_Surface): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_ScaleSurface(surface: PSDL_Surface; width, height: Integer; scaleMode: SDL_ScaleMode): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_ConvertSurface(surface: PSDL_Surface; format: SDL_PixelFormat): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_ConvertSurfaceAndColorspace(surface: PSDL_Surface; format: SDL_PixelFormat; palette: PSDL_Palette;
  colorspace: SDL_Colorspace; props: SDL_PropertiesID): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_ConvertPixels(width, height: Integer; src_format: SDL_PixelFormat; const src: Pointer; src_pitch: Integer;
  dst_format: SDL_PixelFormat; dst: Pointer; dst_pitch: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ConvertPixelsAndColorspace(width, height: Integer; src_format: SDL_PixelFormat; src_colorspace: SDL_Colorspace;
  src_properties: SDL_PropertiesID; const src: Pointer; src_pitch: Integer; dst_format: SDL_PixelFormat;
  dst_colorspace: SDL_Colorspace; dst_properties: SDL_PropertiesID; dst: Pointer; dst_pitch: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_PremultiplyAlpha(width, height: Integer; src_format: SDL_PixelFormat; const src: Pointer; src_pitch: Integer;
  dst_format: SDL_PixelFormat; dst: Pointer; dst_pitch: Integer; linear: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_PremultiplySurfaceAlpha(surface: PSDL_Surface; linear: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ClearSurface(surface: PSDL_Surface; r, g, b, a: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_FillSurfaceRect(dst: PSDL_Surface; const rect: PSDL_Rect; color: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_FillSurfaceRects(dst: PSDL_Surface; const rects: PSDL_Rect; count: Integer; color: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_BlitSurface(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_BlitSurfaceUnchecked(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_BlitSurfaceScaled(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect;
  scaleMode: SDL_ScaleMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_BlitSurfaceUncheckedScaled(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect;
  scaleMode: SDL_ScaleMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_StretchSurface(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect;
  scaleMode: SDL_ScaleMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_BlitSurfaceTiled(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_BlitSurfaceTiledWithScale(src: PSDL_Surface; const srcrect: PSDL_Rect; scale: Single; scaleMode: SDL_ScaleMode;
  dst: PSDL_Surface; dstrect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_BlitSurface9Grid(src: PSDL_Surface; const srcrect: PSDL_Rect; left_width, right_width, top_height, bottom_height: Integer;
  scale: Single; scaleMode: SDL_ScaleMode; dst: PSDL_Surface; dstrect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_MapSurfaceRGB(surface: PSDL_Surface; r, g, b: Uint8): Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_MapSurfaceRGBA(surface: PSDL_Surface; r, g, b, a: Uint8): Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadSurfacePixel(surface: PSDL_Surface; x, y: Integer; r, g, b, a: PUint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadSurfacePixelFloat(surface: PSDL_Surface; x, y: Integer; r, g, b, a: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteSurfacePixel(surface: PSDL_Surface; x, y: Integer; r, g, b, a: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteSurfacePixelFloat(surface: PSDL_Surface; x, y: Integer; r, g, b, a: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
