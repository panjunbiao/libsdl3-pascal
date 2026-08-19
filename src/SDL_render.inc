{ SDL_render.inc -- 1-to-1 from SDL_render.h. GPU renderer APIs skipped. }

const
  SDL_SOFTWARE_RENDERER = 'software';
  SDL_GPU_RENDERER = 'gpu';
  SDL_RENDERER_VSYNC_DISABLED = 0;
  SDL_RENDERER_VSYNC_ADAPTIVE = -1;
  SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE = 8;

type
  PSDL_Vertex = ^SDL_Vertex;
  SDL_Vertex = record
    position: SDL_FPoint;
    color: SDL_FColor;
    tex_coord: SDL_FPoint;
  end;

  SDL_TextureAccess = (
    SDL_TEXTUREACCESS_STATIC,
    SDL_TEXTUREACCESS_STREAMING,
    SDL_TEXTUREACCESS_TARGET
  );

  SDL_TextureAddressMode = (
    SDL_TEXTURE_ADDRESS_INVALID = -1,
    SDL_TEXTURE_ADDRESS_AUTO,
    SDL_TEXTURE_ADDRESS_CLAMP,
    SDL_TEXTURE_ADDRESS_WRAP
  );
  PSDL_TextureAddressMode = ^SDL_TextureAddressMode;

  SDL_RendererLogicalPresentation = (
    SDL_LOGICAL_PRESENTATION_DISABLED,
    SDL_LOGICAL_PRESENTATION_STRETCH,
    SDL_LOGICAL_PRESENTATION_LETTERBOX,
    SDL_LOGICAL_PRESENTATION_OVERSCAN,
    SDL_LOGICAL_PRESENTATION_INTEGER_SCALE
  );
  PSDL_RendererLogicalPresentation = ^SDL_RendererLogicalPresentation;

  SDL_Renderer = record
  end;
  PSDL_Renderer = ^SDL_Renderer;
  PPSDL_Renderer = ^PSDL_Renderer;

  PSDL_Texture = ^SDL_Texture;
  PPSDL_Texture = ^PSDL_Texture;
  SDL_Texture = record
    format: SDL_PixelFormat;
    w: Integer;
    h: Integer;
    refcount: Integer;
  end;

const
  SDL_PROP_RENDERER_CREATE_NAME_STRING = 'SDL.renderer.create.name';
  SDL_PROP_RENDERER_CREATE_WINDOW_POINTER = 'SDL.renderer.create.window';
  SDL_PROP_RENDERER_CREATE_SURFACE_POINTER = 'SDL.renderer.create.surface';
  SDL_PROP_RENDERER_CREATE_OUTPUT_COLORSPACE_NUMBER = 'SDL.renderer.create.output_colorspace';
  SDL_PROP_RENDERER_CREATE_PRESENT_VSYNC_NUMBER = 'SDL.renderer.create.present_vsync';
  SDL_PROP_RENDERER_CREATE_GPU_DEVICE_POINTER = 'SDL.renderer.create.gpu.device';
  SDL_PROP_RENDERER_CREATE_GPU_SHADERS_SPIRV_BOOLEAN = 'SDL.renderer.create.gpu.shaders_spirv';
  SDL_PROP_RENDERER_CREATE_GPU_SHADERS_DXIL_BOOLEAN = 'SDL.renderer.create.gpu.shaders_dxil';
  SDL_PROP_RENDERER_CREATE_GPU_SHADERS_MSL_BOOLEAN = 'SDL.renderer.create.gpu.shaders_msl';
  SDL_PROP_RENDERER_CREATE_VULKAN_INSTANCE_POINTER = 'SDL.renderer.create.vulkan.instance';
  SDL_PROP_RENDERER_CREATE_VULKAN_SURFACE_NUMBER = 'SDL.renderer.create.vulkan.surface';
  SDL_PROP_RENDERER_CREATE_VULKAN_PHYSICAL_DEVICE_POINTER = 'SDL.renderer.create.vulkan.physical_device';
  SDL_PROP_RENDERER_CREATE_VULKAN_DEVICE_POINTER = 'SDL.renderer.create.vulkan.device';
  SDL_PROP_RENDERER_CREATE_VULKAN_GRAPHICS_QUEUE_FAMILY_INDEX_NUMBER = 'SDL.renderer.create.vulkan.graphics_queue_family_index';
  SDL_PROP_RENDERER_CREATE_VULKAN_PRESENT_QUEUE_FAMILY_INDEX_NUMBER = 'SDL.renderer.create.vulkan.present_queue_family_index';
  SDL_PROP_RENDERER_NAME_STRING = 'SDL.renderer.name';
  SDL_PROP_RENDERER_WINDOW_POINTER = 'SDL.renderer.window';
  SDL_PROP_RENDERER_SURFACE_POINTER = 'SDL.renderer.surface';
  SDL_PROP_RENDERER_VSYNC_NUMBER = 'SDL.renderer.vsync';
  SDL_PROP_RENDERER_MAX_TEXTURE_SIZE_NUMBER = 'SDL.renderer.max_texture_size';
  SDL_PROP_RENDERER_TEXTURE_FORMATS_POINTER = 'SDL.renderer.texture_formats';
  SDL_PROP_RENDERER_TEXTURE_WRAPPING_BOOLEAN = 'SDL.renderer.texture_wrapping';
  SDL_PROP_RENDERER_OUTPUT_COLORSPACE_NUMBER = 'SDL.renderer.output_colorspace';
  SDL_PROP_RENDERER_HDR_ENABLED_BOOLEAN = 'SDL.renderer.HDR_enabled';
  SDL_PROP_RENDERER_SDR_WHITE_POINT_FLOAT = 'SDL.renderer.SDR_white_point';
  SDL_PROP_RENDERER_HDR_HEADROOM_FLOAT = 'SDL.renderer.HDR_headroom';
  SDL_PROP_RENDERER_D3D9_DEVICE_POINTER = 'SDL.renderer.d3d9.device';
  SDL_PROP_RENDERER_D3D11_DEVICE_POINTER = 'SDL.renderer.d3d11.device';
  SDL_PROP_RENDERER_D3D11_SWAPCHAIN_POINTER = 'SDL.renderer.d3d11.swap_chain';
  SDL_PROP_RENDERER_D3D12_DEVICE_POINTER = 'SDL.renderer.d3d12.device';
  SDL_PROP_RENDERER_D3D12_SWAPCHAIN_POINTER = 'SDL.renderer.d3d12.swap_chain';
  SDL_PROP_RENDERER_D3D12_COMMAND_QUEUE_POINTER = 'SDL.renderer.d3d12.command_queue';
  SDL_PROP_RENDERER_VULKAN_INSTANCE_POINTER = 'SDL.renderer.vulkan.instance';
  SDL_PROP_RENDERER_VULKAN_SURFACE_NUMBER = 'SDL.renderer.vulkan.surface';
  SDL_PROP_RENDERER_VULKAN_PHYSICAL_DEVICE_POINTER = 'SDL.renderer.vulkan.physical_device';
  SDL_PROP_RENDERER_VULKAN_DEVICE_POINTER = 'SDL.renderer.vulkan.device';
  SDL_PROP_RENDERER_VULKAN_GRAPHICS_QUEUE_FAMILY_INDEX_NUMBER = 'SDL.renderer.vulkan.graphics_queue_family_index';
  SDL_PROP_RENDERER_VULKAN_PRESENT_QUEUE_FAMILY_INDEX_NUMBER = 'SDL.renderer.vulkan.present_queue_family_index';
  SDL_PROP_RENDERER_VULKAN_SWAPCHAIN_IMAGE_COUNT_NUMBER = 'SDL.renderer.vulkan.swapchain_image_count';
  SDL_PROP_RENDERER_GPU_DEVICE_POINTER = 'SDL.renderer.gpu.device';
  SDL_PROP_TEXTURE_CREATE_COLORSPACE_NUMBER = 'SDL.texture.create.colorspace';
  SDL_PROP_TEXTURE_CREATE_FORMAT_NUMBER = 'SDL.texture.create.format';
  SDL_PROP_TEXTURE_CREATE_ACCESS_NUMBER = 'SDL.texture.create.access';
  SDL_PROP_TEXTURE_CREATE_WIDTH_NUMBER = 'SDL.texture.create.width';
  SDL_PROP_TEXTURE_CREATE_HEIGHT_NUMBER = 'SDL.texture.create.height';
  SDL_PROP_TEXTURE_CREATE_PALETTE_POINTER = 'SDL.texture.create.palette';
  SDL_PROP_TEXTURE_CREATE_SDR_WHITE_POINT_FLOAT = 'SDL.texture.create.SDR_white_point';
  SDL_PROP_TEXTURE_CREATE_HDR_HEADROOM_FLOAT = 'SDL.texture.create.HDR_headroom';
  SDL_PROP_TEXTURE_CREATE_D3D11_TEXTURE_POINTER = 'SDL.texture.create.d3d11.texture';
  SDL_PROP_TEXTURE_CREATE_D3D11_TEXTURE_U_POINTER = 'SDL.texture.create.d3d11.texture_u';
  SDL_PROP_TEXTURE_CREATE_D3D11_TEXTURE_V_POINTER = 'SDL.texture.create.d3d11.texture_v';
  SDL_PROP_TEXTURE_CREATE_D3D12_TEXTURE_POINTER = 'SDL.texture.create.d3d12.texture';
  SDL_PROP_TEXTURE_CREATE_D3D12_TEXTURE_U_POINTER = 'SDL.texture.create.d3d12.texture_u';
  SDL_PROP_TEXTURE_CREATE_D3D12_TEXTURE_V_POINTER = 'SDL.texture.create.d3d12.texture_v';
  SDL_PROP_TEXTURE_CREATE_METAL_PIXELBUFFER_POINTER = 'SDL.texture.create.metal.pixelbuffer';
  SDL_PROP_TEXTURE_CREATE_METAL_TEXTURE_POINTER = 'SDL.texture.create.metal.texture';
  SDL_PROP_TEXTURE_CREATE_METAL_TEXTURE_UV_POINTER = 'SDL.texture.create.metal.texture_uv';
  SDL_PROP_TEXTURE_CREATE_METAL_TEXTURE_U_POINTER = 'SDL.texture.create.metal.texture_u';
  SDL_PROP_TEXTURE_CREATE_METAL_TEXTURE_V_POINTER = 'SDL.texture.create.metal.texture_v';
  SDL_PROP_TEXTURE_CREATE_METAL_TEXTURE_USAGE_NUMBER = 'SDL.texture.create.metal.texture_usage';
  SDL_PROP_TEXTURE_CREATE_OPENGL_TEXTURE_NUMBER = 'SDL.texture.create.opengl.texture';
  SDL_PROP_TEXTURE_CREATE_OPENGL_TEXTURE_UV_NUMBER = 'SDL.texture.create.opengl.texture_uv';
  SDL_PROP_TEXTURE_CREATE_OPENGL_TEXTURE_U_NUMBER = 'SDL.texture.create.opengl.texture_u';
  SDL_PROP_TEXTURE_CREATE_OPENGL_TEXTURE_V_NUMBER = 'SDL.texture.create.opengl.texture_v';
  SDL_PROP_TEXTURE_CREATE_OPENGLES2_TEXTURE_NUMBER = 'SDL.texture.create.opengles2.texture';
  SDL_PROP_TEXTURE_CREATE_OPENGLES2_TEXTURE_UV_NUMBER = 'SDL.texture.create.opengles2.texture_uv';
  SDL_PROP_TEXTURE_CREATE_OPENGLES2_TEXTURE_U_NUMBER = 'SDL.texture.create.opengles2.texture_u';
  SDL_PROP_TEXTURE_CREATE_OPENGLES2_TEXTURE_V_NUMBER = 'SDL.texture.create.opengles2.texture_v';
  SDL_PROP_TEXTURE_CREATE_VULKAN_TEXTURE_NUMBER = 'SDL.texture.create.vulkan.texture';
  SDL_PROP_TEXTURE_CREATE_VULKAN_LAYOUT_NUMBER = 'SDL.texture.create.vulkan.layout';
  SDL_PROP_TEXTURE_CREATE_GPU_TEXTURE_POINTER = 'SDL.texture.create.gpu.texture';
  SDL_PROP_TEXTURE_CREATE_GPU_TEXTURE_UV_POINTER = 'SDL.texture.create.gpu.texture_uv';
  SDL_PROP_TEXTURE_CREATE_GPU_TEXTURE_U_POINTER = 'SDL.texture.create.gpu.texture_u';
  SDL_PROP_TEXTURE_CREATE_GPU_TEXTURE_V_POINTER = 'SDL.texture.create.gpu.texture_v';
  SDL_PROP_TEXTURE_COLORSPACE_NUMBER = 'SDL.texture.colorspace';
  SDL_PROP_TEXTURE_FORMAT_NUMBER = 'SDL.texture.format';
  SDL_PROP_TEXTURE_ACCESS_NUMBER = 'SDL.texture.access';
  SDL_PROP_TEXTURE_WIDTH_NUMBER = 'SDL.texture.width';
  SDL_PROP_TEXTURE_HEIGHT_NUMBER = 'SDL.texture.height';
  SDL_PROP_TEXTURE_SDR_WHITE_POINT_FLOAT = 'SDL.texture.SDR_white_point';
  SDL_PROP_TEXTURE_HDR_HEADROOM_FLOAT = 'SDL.texture.HDR_headroom';
  SDL_PROP_TEXTURE_D3D11_TEXTURE_POINTER = 'SDL.texture.d3d11.texture';
  SDL_PROP_TEXTURE_D3D11_TEXTURE_U_POINTER = 'SDL.texture.d3d11.texture_u';
  SDL_PROP_TEXTURE_D3D11_TEXTURE_V_POINTER = 'SDL.texture.d3d11.texture_v';
  SDL_PROP_TEXTURE_D3D12_TEXTURE_POINTER = 'SDL.texture.d3d12.texture';
  SDL_PROP_TEXTURE_D3D12_TEXTURE_U_POINTER = 'SDL.texture.d3d12.texture_u';
  SDL_PROP_TEXTURE_D3D12_TEXTURE_V_POINTER = 'SDL.texture.d3d12.texture_v';
  SDL_PROP_TEXTURE_METAL_TEXTURE_POINTER = 'SDL.texture.metal.texture';
  SDL_PROP_TEXTURE_METAL_TEXTURE_UV_POINTER = 'SDL.texture.metal.texture_uv';
  SDL_PROP_TEXTURE_METAL_TEXTURE_U_POINTER = 'SDL.texture.metal.texture_u';
  SDL_PROP_TEXTURE_METAL_TEXTURE_V_POINTER = 'SDL.texture.metal.texture_v';
  SDL_PROP_TEXTURE_OPENGL_TEXTURE_NUMBER = 'SDL.texture.opengl.texture';
  SDL_PROP_TEXTURE_OPENGL_TEXTURE_UV_NUMBER = 'SDL.texture.opengl.texture_uv';
  SDL_PROP_TEXTURE_OPENGL_TEXTURE_U_NUMBER = 'SDL.texture.opengl.texture_u';
  SDL_PROP_TEXTURE_OPENGL_TEXTURE_V_NUMBER = 'SDL.texture.opengl.texture_v';
  SDL_PROP_TEXTURE_OPENGL_TEXTURE_TARGET_NUMBER = 'SDL.texture.opengl.target';
  SDL_PROP_TEXTURE_OPENGL_TEX_W_FLOAT = 'SDL.texture.opengl.tex_w';
  SDL_PROP_TEXTURE_OPENGL_TEX_H_FLOAT = 'SDL.texture.opengl.tex_h';
  SDL_PROP_TEXTURE_OPENGLES2_TEXTURE_NUMBER = 'SDL.texture.opengles2.texture';
  SDL_PROP_TEXTURE_OPENGLES2_TEXTURE_UV_NUMBER = 'SDL.texture.opengles2.texture_uv';
  SDL_PROP_TEXTURE_OPENGLES2_TEXTURE_U_NUMBER = 'SDL.texture.opengles2.texture_u';
  SDL_PROP_TEXTURE_OPENGLES2_TEXTURE_V_NUMBER = 'SDL.texture.opengles2.texture_v';
  SDL_PROP_TEXTURE_OPENGLES2_TEXTURE_TARGET_NUMBER = 'SDL.texture.opengles2.target';
  SDL_PROP_TEXTURE_VULKAN_TEXTURE_NUMBER = 'SDL.texture.vulkan.texture';
  SDL_PROP_TEXTURE_GPU_TEXTURE_POINTER = 'SDL.texture.gpu.texture';
  SDL_PROP_TEXTURE_GPU_TEXTURE_UV_POINTER = 'SDL.texture.gpu.texture_uv';
  SDL_PROP_TEXTURE_GPU_TEXTURE_U_POINTER = 'SDL.texture.gpu.texture_u';
  SDL_PROP_TEXTURE_GPU_TEXTURE_V_POINTER = 'SDL.texture.gpu.texture_v';

function SDL_GetNumRenderDrivers(): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderDriver(index: Integer): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateWindowAndRenderer(title: PUTF8Char; width: Integer; height: Integer; window_flags: SDL_WindowFlags; window: PPSDL_Window; renderer: PPSDL_Renderer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateRenderer(window: PSDL_Window; name: PUTF8Char): PSDL_Renderer; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateRendererWithProperties(props: SDL_PropertiesID): PSDL_Renderer; cdecl;
  external SDL_LIB_NAME;
{ skipped SDL_CreateGPURenderer -- GPU types not in 2D core }
{ skipped SDL_GetGPURendererDevice -- GPU types not in 2D core }
function SDL_CreateSoftwareRenderer(surface: PSDL_Surface): PSDL_Renderer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderer(window: PSDL_Window): PSDL_Renderer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderWindow(renderer: PSDL_Renderer): PSDL_Window; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRendererName(renderer: PSDL_Renderer): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRendererProperties(renderer: PSDL_Renderer): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderOutputSize(renderer: PSDL_Renderer; w: PInteger; h: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCurrentRenderOutputSize(renderer: PSDL_Renderer; w: PInteger; h: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateTexture(renderer: PSDL_Renderer; format: SDL_PixelFormat; access: SDL_TextureAccess; w: Integer; h: Integer): PSDL_Texture; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateTextureFromSurface(renderer: PSDL_Renderer; surface: PSDL_Surface): PSDL_Texture; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateTextureWithProperties(renderer: PSDL_Renderer; props: SDL_PropertiesID): PSDL_Texture; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTextureProperties(texture: PSDL_Texture): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRendererFromTexture(texture: PSDL_Texture): PSDL_Renderer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTextureSize(texture: PSDL_Texture; w: PSingle; h: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetTexturePalette(texture: PSDL_Texture; palette: PSDL_Palette): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTexturePalette(texture: PSDL_Texture): PSDL_Palette; cdecl;
  external SDL_LIB_NAME;
function SDL_SetTextureColorMod(texture: PSDL_Texture; r: Uint8; g: Uint8; b: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetTextureColorModFloat(texture: PSDL_Texture; r: Single; g: Single; b: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTextureColorMod(texture: PSDL_Texture; r: PUint8; g: PUint8; b: PUint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTextureColorModFloat(texture: PSDL_Texture; r: PSingle; g: PSingle; b: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetTextureAlphaMod(texture: PSDL_Texture; alpha: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetTextureAlphaModFloat(texture: PSDL_Texture; alpha: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTextureAlphaMod(texture: PSDL_Texture; alpha: PUint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTextureAlphaModFloat(texture: PSDL_Texture; alpha: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetTextureBlendMode(texture: PSDL_Texture; blendMode: SDL_BlendMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTextureBlendMode(texture: PSDL_Texture; blendMode: PSDL_BlendMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetTextureScaleMode(texture: PSDL_Texture; scaleMode: SDL_ScaleMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetTextureScaleMode(texture: PSDL_Texture; scaleMode: PSDL_ScaleMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_UpdateTexture(texture: PSDL_Texture; rect: PSDL_Rect; pixels: Pointer; pitch: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_UpdateYUVTexture(texture: PSDL_Texture; rect: PSDL_Rect; Yplane: PUint8; Ypitch: Integer; Uplane: PUint8; Upitch: Integer; Vplane: PUint8; Vpitch: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_UpdateNVTexture(texture: PSDL_Texture; rect: PSDL_Rect; Yplane: PUint8; Ypitch: Integer; UVplane: PUint8; UVpitch: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_LockTexture(texture: PSDL_Texture; rect: PSDL_Rect; pixels: PPointer; pitch: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_LockTextureToSurface(texture: PSDL_Texture; rect: PSDL_Rect; surface: PPSDL_Surface): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnlockTexture(texture: PSDL_Texture); cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderTarget(renderer: PSDL_Renderer; texture: PSDL_Texture): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderTarget(renderer: PSDL_Renderer): PSDL_Texture; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderLogicalPresentation(renderer: PSDL_Renderer; w: Integer; h: Integer; mode: SDL_RendererLogicalPresentation): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderLogicalPresentation(renderer: PSDL_Renderer; w: PInteger; h: PInteger; mode: PSDL_RendererLogicalPresentation): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderLogicalPresentationRect(renderer: PSDL_Renderer; rect: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderCoordinatesFromWindow(renderer: PSDL_Renderer; window_x: Single; window_y: Single; x: PSingle; y: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderCoordinatesToWindow(renderer: PSDL_Renderer; x: Single; y: Single; window_x: PSingle; window_y: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ConvertEventToRenderCoordinates(renderer: PSDL_Renderer; event: PSDL_Event): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderViewport(renderer: PSDL_Renderer; rect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderViewport(renderer: PSDL_Renderer; rect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderViewportSet(renderer: PSDL_Renderer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderSafeArea(renderer: PSDL_Renderer; rect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderClipRect(renderer: PSDL_Renderer; rect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderClipRect(renderer: PSDL_Renderer; rect: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderClipEnabled(renderer: PSDL_Renderer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderScale(renderer: PSDL_Renderer; scaleX: Single; scaleY: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderScale(renderer: PSDL_Renderer; scaleX: PSingle; scaleY: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderDrawColor(renderer: PSDL_Renderer; r: Uint8; g: Uint8; b: Uint8; a: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderDrawColorFloat(renderer: PSDL_Renderer; r: Single; g: Single; b: Single; a: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderDrawColor(renderer: PSDL_Renderer; r: PUint8; g: PUint8; b: PUint8; a: PUint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderDrawColorFloat(renderer: PSDL_Renderer; r: PSingle; g: PSingle; b: PSingle; a: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderColorScale(renderer: PSDL_Renderer; scale: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderColorScale(renderer: PSDL_Renderer; scale: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderDrawBlendMode(renderer: PSDL_Renderer; blendMode: SDL_BlendMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderDrawBlendMode(renderer: PSDL_Renderer; blendMode: PSDL_BlendMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderClear(renderer: PSDL_Renderer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderPoint(renderer: PSDL_Renderer; x: Single; y: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderPoints(renderer: PSDL_Renderer; points: PSDL_FPoint; count: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderLine(renderer: PSDL_Renderer; x1: Single; y1: Single; x2: Single; y2: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderLines(renderer: PSDL_Renderer; points: PSDL_FPoint; count: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderRect(renderer: PSDL_Renderer; rect: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderRects(renderer: PSDL_Renderer; rects: PSDL_FRect; count: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderFillRect(renderer: PSDL_Renderer; rect: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderFillRects(renderer: PSDL_Renderer; rects: PSDL_FRect; count: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderTexture(renderer: PSDL_Renderer; texture: PSDL_Texture; srcrect: PSDL_FRect; dstrect: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderTextureRotated(renderer: PSDL_Renderer; texture: PSDL_Texture; srcrect: PSDL_FRect; dstrect: PSDL_FRect; angle: double; center: PSDL_FPoint; flip: SDL_FlipMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderTextureAffine(renderer: PSDL_Renderer; texture: PSDL_Texture; srcrect: PSDL_FRect; origin: PSDL_FPoint; right: PSDL_FPoint; down: PSDL_FPoint): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderTextureTiled(renderer: PSDL_Renderer; texture: PSDL_Texture; srcrect: PSDL_FRect; scale: Single; dstrect: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderTexture9Grid(renderer: PSDL_Renderer; texture: PSDL_Texture; srcrect: PSDL_FRect; left_width: Single; right_width: Single; top_height: Single; bottom_height: Single; scale: Single; dstrect: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderTexture9GridTiled(renderer: PSDL_Renderer; texture: PSDL_Texture; srcrect: PSDL_FRect; left_width: Single; right_width: Single; top_height: Single; bottom_height: Single; scale: Single; dstrect: PSDL_FRect; tileScale: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderGeometry(renderer: PSDL_Renderer; texture: PSDL_Texture; vertices: PSDL_Vertex; num_vertices: Integer; indices: PInteger; num_indices: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderGeometryRaw(renderer: PSDL_Renderer; texture: PSDL_Texture; xy: PSingle; xy_stride: Integer; color: PSDL_FColor; color_stride: Integer; uv: PSingle; uv_stride: Integer; num_vertices: Integer; indices: Pointer; num_indices: Integer; size_indices: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderTextureAddressMode(renderer: PSDL_Renderer; u_mode: SDL_TextureAddressMode; v_mode: SDL_TextureAddressMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderTextureAddressMode(renderer: PSDL_Renderer; u_mode: PSDL_TextureAddressMode; v_mode: PSDL_TextureAddressMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderReadPixels(renderer: PSDL_Renderer; rect: PSDL_Rect): PSDL_Surface; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderPresent(renderer: PSDL_Renderer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyTexture(texture: PSDL_Texture); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyRenderer(renderer: PSDL_Renderer); cdecl;
  external SDL_LIB_NAME;
function SDL_FlushRenderer(renderer: PSDL_Renderer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderMetalLayer(renderer: PSDL_Renderer): Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderMetalCommandEncoder(renderer: PSDL_Renderer): Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_AddVulkanRenderSemaphores(renderer: PSDL_Renderer; wait_stage_mask: Uint32; wait_semaphore: Sint64; signal_semaphore: Sint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetRenderVSync(renderer: PSDL_Renderer; vsync: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRenderVSync(renderer: PSDL_Renderer; vsync: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderDebugText(renderer: PSDL_Renderer; x: Single; y: Single; str: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_RenderDebugTextFormat(renderer: PSDL_Renderer; x, y: Single; fmt: PUTF8Char): Boolean; cdecl varargs;
  external SDL_LIB_NAME;
function SDL_SetDefaultTextureScaleMode(renderer: PSDL_Renderer; scale_mode: SDL_ScaleMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetDefaultTextureScaleMode(renderer: PSDL_Renderer; scale_mode: PSDL_ScaleMode): Boolean; cdecl;
  external SDL_LIB_NAME;
{ skipped SDL_CreateGPURenderState -- GPU types not in 2D core }
{ skipped SDL_SetGPURenderStateFragmentUniforms -- GPU types not in 2D core }
{ skipped SDL_SetGPURenderState -- GPU types not in 2D core }
{ skipped SDL_DestroyGPURenderState -- GPU types not in 2D core }
