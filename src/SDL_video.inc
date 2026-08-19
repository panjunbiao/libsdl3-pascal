{ SDL_video.inc -- 1-to-1 from SDL_video.h }

type
  SDL_DisplayID = Uint32;
  PSDL_DisplayID = ^SDL_DisplayID;
  SDL_WindowID = Uint32;

  SDL_SystemTheme = (
    SDL_SYSTEM_THEME_UNKNOWN,
    SDL_SYSTEM_THEME_LIGHT,
    SDL_SYSTEM_THEME_DARK
  );

  SDL_DisplayModeData = record
  end;
  PSDL_DisplayModeData = ^SDL_DisplayModeData;

  PSDL_DisplayMode = ^SDL_DisplayMode;
  PPSDL_DisplayMode = ^PSDL_DisplayMode;
  SDL_DisplayMode = record
    displayID: SDL_DisplayID;
    format: SDL_PixelFormat;
    w: Integer;
    h: Integer;
    pixel_density: Single;
    refresh_rate: Single;
    refresh_rate_numerator: Integer;
    refresh_rate_denominator: Integer;
    internal: PSDL_DisplayModeData;
  end;

  SDL_DisplayOrientation = (
    SDL_ORIENTATION_UNKNOWN,
    SDL_ORIENTATION_LANDSCAPE,
    SDL_ORIENTATION_LANDSCAPE_FLIPPED,
    SDL_ORIENTATION_PORTRAIT,
    SDL_ORIENTATION_PORTRAIT_FLIPPED
  );

  SDL_Window = record
  end;
  PSDL_Window = ^SDL_Window;
  PPSDL_Window = ^PSDL_Window;

  SDL_WindowFlags = Uint64;

  SDL_FlashOperation = (
    SDL_FLASH_CANCEL,
    SDL_FLASH_BRIEFLY,
    SDL_FLASH_UNTIL_FOCUSED
  );

  SDL_ProgressState = (
    SDL_PROGRESS_STATE_INVALID = -1,
    SDL_PROGRESS_STATE_NONE,
    SDL_PROGRESS_STATE_INDETERMINATE,
    SDL_PROGRESS_STATE_NORMAL,
    SDL_PROGRESS_STATE_PAUSED,
    SDL_PROGRESS_STATE_ERROR
  );

  SDL_GLContextState = record
  end;
  SDL_GLContext = ^SDL_GLContextState;

  SDL_EGLDisplay = Pointer;
  SDL_EGLConfig = Pointer;
  SDL_EGLSurface = Pointer;
  SDL_EGLAttrib = NativeInt;
  PSDL_EGLAttrib = ^SDL_EGLAttrib;
  SDL_EGLint = Integer;
  PSDL_EGLint = ^SDL_EGLint;

  SDL_EGLAttribArrayCallback = function(userdata: Pointer): PSDL_EGLAttrib; cdecl;
  SDL_EGLIntArrayCallback = function(userdata: Pointer; display: SDL_EGLDisplay; config: SDL_EGLConfig): PSDL_EGLint; cdecl;

  SDL_GLAttr = (
    SDL_GL_RED_SIZE,
    SDL_GL_GREEN_SIZE,
    SDL_GL_BLUE_SIZE,
    SDL_GL_ALPHA_SIZE,
    SDL_GL_BUFFER_SIZE,
    SDL_GL_DOUBLEBUFFER,
    SDL_GL_DEPTH_SIZE,
    SDL_GL_STENCIL_SIZE,
    SDL_GL_ACCUM_RED_SIZE,
    SDL_GL_ACCUM_GREEN_SIZE,
    SDL_GL_ACCUM_BLUE_SIZE,
    SDL_GL_ACCUM_ALPHA_SIZE,
    SDL_GL_STEREO,
    SDL_GL_MULTISAMPLEBUFFERS,
    SDL_GL_MULTISAMPLESAMPLES,
    SDL_GL_ACCELERATED_VISUAL,
    SDL_GL_RETAINED_BACKING,
    SDL_GL_CONTEXT_MAJOR_VERSION,
    SDL_GL_CONTEXT_MINOR_VERSION,
    SDL_GL_CONTEXT_FLAGS,
    SDL_GL_CONTEXT_PROFILE_MASK,
    SDL_GL_SHARE_WITH_CURRENT_CONTEXT,
    SDL_GL_FRAMEBUFFER_SRGB_CAPABLE,
    SDL_GL_CONTEXT_RELEASE_BEHAVIOR,
    SDL_GL_CONTEXT_RESET_NOTIFICATION,
    SDL_GL_CONTEXT_NO_ERROR,
    SDL_GL_FLOATBUFFERS,
    SDL_GL_EGL_PLATFORM
  );

  SDL_GLProfile = Uint32;
  SDL_GLContextFlag = Uint32;
  SDL_GLContextReleaseFlag = Uint32;
  SDL_GLContextResetNotification = Uint32;

  SDL_HitTestResult = (
    SDL_HITTEST_NORMAL,
    SDL_HITTEST_DRAGGABLE,
    SDL_HITTEST_RESIZE_TOPLEFT,
    SDL_HITTEST_RESIZE_TOP,
    SDL_HITTEST_RESIZE_TOPRIGHT,
    SDL_HITTEST_RESIZE_RIGHT,
    SDL_HITTEST_RESIZE_BOTTOMRIGHT,
    SDL_HITTEST_RESIZE_BOTTOM,
    SDL_HITTEST_RESIZE_BOTTOMLEFT,
    SDL_HITTEST_RESIZE_LEFT
  );

  SDL_HitTest = function(win: PSDL_Window; const area: PSDL_Point; data: Pointer): SDL_HitTestResult; cdecl;

const
  SDL_WINDOW_FULLSCREEN = Uint64($0000000000000001);
  SDL_WINDOW_OPENGL = Uint64($0000000000000002);
  SDL_WINDOW_OCCLUDED = Uint64($0000000000000004);
  SDL_WINDOW_HIDDEN = Uint64($0000000000000008);
  SDL_WINDOW_BORDERLESS = Uint64($0000000000000010);
  SDL_WINDOW_RESIZABLE = Uint64($0000000000000020);
  SDL_WINDOW_MINIMIZED = Uint64($0000000000000040);
  SDL_WINDOW_MAXIMIZED = Uint64($0000000000000080);
  SDL_WINDOW_MOUSE_GRABBED = Uint64($0000000000000100);
  SDL_WINDOW_INPUT_FOCUS = Uint64($0000000000000200);
  SDL_WINDOW_MOUSE_FOCUS = Uint64($0000000000000400);
  SDL_WINDOW_EXTERNAL = Uint64($0000000000000800);
  SDL_WINDOW_MODAL = Uint64($0000000000001000);
  SDL_WINDOW_HIGH_PIXEL_DENSITY = Uint64($0000000000002000);
  SDL_WINDOW_MOUSE_CAPTURE = Uint64($0000000000004000);
  SDL_WINDOW_MOUSE_RELATIVE_MODE = Uint64($0000000000008000);
  SDL_WINDOW_ALWAYS_ON_TOP = Uint64($0000000000010000);
  SDL_WINDOW_UTILITY = Uint64($0000000000020000);
  SDL_WINDOW_TOOLTIP = Uint64($0000000000040000);
  SDL_WINDOW_POPUP_MENU = Uint64($0000000000080000);
  SDL_WINDOW_KEYBOARD_GRABBED = Uint64($0000000000100000);
  SDL_WINDOW_FILL_DOCUMENT = Uint64($0000000000200000);
  SDL_WINDOW_VULKAN = Uint64($0000000010000000);
  SDL_WINDOW_METAL = Uint64($0000000020000000);
  SDL_WINDOW_TRANSPARENT = Uint64($0000000040000000);
  SDL_WINDOW_NOT_FOCUSABLE = Uint64($0000000080000000);

  SDL_WINDOWPOS_UNDEFINED_MASK = $1FFF0000;
  SDL_WINDOWPOS_CENTERED_MASK = $2FFF0000;
  SDL_WINDOWPOS_UNDEFINED = SDL_WINDOWPOS_UNDEFINED_MASK or 0;
  SDL_WINDOWPOS_CENTERED = SDL_WINDOWPOS_CENTERED_MASK or 0;

  SDL_WINDOW_SURFACE_VSYNC_DISABLED = 0;
  SDL_WINDOW_SURFACE_VSYNC_ADAPTIVE = -1;

  SDL_GL_CONTEXT_PROFILE_CORE = $0001;
  SDL_GL_CONTEXT_PROFILE_COMPATIBILITY = $0002;
  SDL_GL_CONTEXT_PROFILE_ES = $0004;
  SDL_GL_CONTEXT_DEBUG_FLAG = $0001;
  SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG = $0002;
  SDL_GL_CONTEXT_ROBUST_ACCESS_FLAG = $0004;
  SDL_GL_CONTEXT_RESET_ISOLATION_FLAG = $0008;
  SDL_GL_CONTEXT_RELEASE_BEHAVIOR_NONE = $0000;
  SDL_GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH = $0001;
  SDL_GL_CONTEXT_RESET_NO_NOTIFICATION = $0000;
  SDL_GL_CONTEXT_RESET_LOSE_CONTEXT = $0001;

  SDL_PROP_GLOBAL_VIDEO_WAYLAND_WL_DISPLAY_POINTER = 'SDL.video.wayland.wl_display';
  SDL_PROP_DISPLAY_HDR_ENABLED_BOOLEAN = 'SDL.display.HDR_enabled';
  SDL_PROP_DISPLAY_KMSDRM_PANEL_ORIENTATION_NUMBER = 'SDL.display.KMSDRM.panel_orientation';
  SDL_PROP_DISPLAY_WAYLAND_WL_OUTPUT_POINTER = 'SDL.display.wayland.wl_output';
  SDL_PROP_DISPLAY_WINDOWS_HMONITOR_POINTER = 'SDL.display.windows.hmonitor';

  SDL_PROP_WINDOW_CREATE_ALWAYS_ON_TOP_BOOLEAN = 'SDL.window.create.always_on_top';
  SDL_PROP_WINDOW_CREATE_BORDERLESS_BOOLEAN = 'SDL.window.create.borderless';
  SDL_PROP_WINDOW_CREATE_CONSTRAIN_POPUP_BOOLEAN = 'SDL.window.create.constrain_popup';
  SDL_PROP_WINDOW_CREATE_FOCUSABLE_BOOLEAN = 'SDL.window.create.focusable';
  SDL_PROP_WINDOW_CREATE_EXTERNAL_GRAPHICS_CONTEXT_BOOLEAN = 'SDL.window.create.external_graphics_context';
  SDL_PROP_WINDOW_CREATE_FLAGS_NUMBER = 'SDL.window.create.flags';
  SDL_PROP_WINDOW_CREATE_FULLSCREEN_BOOLEAN = 'SDL.window.create.fullscreen';
  SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER = 'SDL.window.create.height';
  SDL_PROP_WINDOW_CREATE_HIDDEN_BOOLEAN = 'SDL.window.create.hidden';
  SDL_PROP_WINDOW_CREATE_HIGH_PIXEL_DENSITY_BOOLEAN = 'SDL.window.create.high_pixel_density';
  SDL_PROP_WINDOW_CREATE_MAXIMIZED_BOOLEAN = 'SDL.window.create.maximized';
  SDL_PROP_WINDOW_CREATE_MENU_BOOLEAN = 'SDL.window.create.menu';
  SDL_PROP_WINDOW_CREATE_METAL_BOOLEAN = 'SDL.window.create.metal';
  SDL_PROP_WINDOW_CREATE_MINIMIZED_BOOLEAN = 'SDL.window.create.minimized';
  SDL_PROP_WINDOW_CREATE_MODAL_BOOLEAN = 'SDL.window.create.modal';
  SDL_PROP_WINDOW_CREATE_MOUSE_GRABBED_BOOLEAN = 'SDL.window.create.mouse_grabbed';
  SDL_PROP_WINDOW_CREATE_OPENGL_BOOLEAN = 'SDL.window.create.opengl';
  SDL_PROP_WINDOW_CREATE_PARENT_POINTER = 'SDL.window.create.parent';
  SDL_PROP_WINDOW_CREATE_RESIZABLE_BOOLEAN = 'SDL.window.create.resizable';
  SDL_PROP_WINDOW_CREATE_TITLE_STRING = 'SDL.window.create.title';
  SDL_PROP_WINDOW_CREATE_TRANSPARENT_BOOLEAN = 'SDL.window.create.transparent';
  SDL_PROP_WINDOW_CREATE_TOOLTIP_BOOLEAN = 'SDL.window.create.tooltip';
  SDL_PROP_WINDOW_CREATE_UTILITY_BOOLEAN = 'SDL.window.create.utility';
  SDL_PROP_WINDOW_CREATE_VULKAN_BOOLEAN = 'SDL.window.create.vulkan';
  SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER = 'SDL.window.create.width';
  SDL_PROP_WINDOW_CREATE_X_NUMBER = 'SDL.window.create.x';
  SDL_PROP_WINDOW_CREATE_Y_NUMBER = 'SDL.window.create.y';
  SDL_PROP_WINDOW_CREATE_COCOA_WINDOW_POINTER = 'SDL.window.create.cocoa.window';
  SDL_PROP_WINDOW_CREATE_COCOA_VIEW_POINTER = 'SDL.window.create.cocoa.view';
  SDL_PROP_WINDOW_CREATE_WINDOWSCENE_POINTER = 'SDL.window.create.uikit.windowscene';
  SDL_PROP_WINDOW_CREATE_WAYLAND_SURFACE_ROLE_CUSTOM_BOOLEAN = 'SDL.window.create.wayland.surface_role_custom';
  SDL_PROP_WINDOW_CREATE_WAYLAND_CREATE_EGL_WINDOW_BOOLEAN = 'SDL.window.create.wayland.create_egl_window';
  SDL_PROP_WINDOW_CREATE_WAYLAND_WL_SURFACE_POINTER = 'SDL.window.create.wayland.wl_surface';
  SDL_PROP_WINDOW_CREATE_WIN32_HWND_POINTER = 'SDL.window.create.win32.hwnd';
  SDL_PROP_WINDOW_CREATE_WIN32_PIXEL_FORMAT_HWND_POINTER = 'SDL.window.create.win32.pixel_format_hwnd';
  SDL_PROP_WINDOW_CREATE_X11_WINDOW_NUMBER = 'SDL.window.create.x11.window';
  SDL_PROP_WINDOW_CREATE_EMSCRIPTEN_CANVAS_ID_STRING = 'SDL.window.create.emscripten.canvas_id';
  SDL_PROP_WINDOW_CREATE_EMSCRIPTEN_KEYBOARD_ELEMENT_STRING = 'SDL.window.create.emscripten.keyboard_element';

  SDL_PROP_WINDOW_SHAPE_POINTER = 'SDL.window.shape';
  SDL_PROP_WINDOW_HDR_ENABLED_BOOLEAN = 'SDL.window.HDR_enabled';
  SDL_PROP_WINDOW_SDR_WHITE_LEVEL_FLOAT = 'SDL.window.SDR_white_level';
  SDL_PROP_WINDOW_HDR_HEADROOM_FLOAT = 'SDL.window.HDR_headroom';
  SDL_PROP_WINDOW_ANDROID_WINDOW_POINTER = 'SDL.window.android.window';
  SDL_PROP_WINDOW_ANDROID_SURFACE_POINTER = 'SDL.window.android.surface';
  SDL_PROP_WINDOW_UIKIT_WINDOW_POINTER = 'SDL.window.uikit.window';
  SDL_PROP_WINDOW_UIKIT_METAL_VIEW_TAG_NUMBER = 'SDL.window.uikit.metal_view_tag';
  SDL_PROP_WINDOW_UIKIT_OPENGL_FRAMEBUFFER_NUMBER = 'SDL.window.uikit.opengl.framebuffer';
  SDL_PROP_WINDOW_UIKIT_OPENGL_RENDERBUFFER_NUMBER = 'SDL.window.uikit.opengl.renderbuffer';
  SDL_PROP_WINDOW_UIKIT_OPENGL_RESOLVE_FRAMEBUFFER_NUMBER = 'SDL.window.uikit.opengl.resolve_framebuffer';
  SDL_PROP_WINDOW_KMSDRM_DEVICE_INDEX_NUMBER = 'SDL.window.kmsdrm.dev_index';
  SDL_PROP_WINDOW_KMSDRM_DRM_FD_NUMBER = 'SDL.window.kmsdrm.drm_fd';
  SDL_PROP_WINDOW_KMSDRM_GBM_DEVICE_POINTER = 'SDL.window.kmsdrm.gbm_dev';
  SDL_PROP_WINDOW_COCOA_WINDOW_POINTER = 'SDL.window.cocoa.window';
  SDL_PROP_WINDOW_COCOA_METAL_VIEW_TAG_NUMBER = 'SDL.window.cocoa.metal_view_tag';
  SDL_PROP_WINDOW_OPENVR_OVERLAY_ID_NUMBER = 'SDL.window.openvr.overlay_id';
  SDL_PROP_WINDOW_VIVANTE_DISPLAY_POINTER = 'SDL.window.vivante.display';
  SDL_PROP_WINDOW_VIVANTE_WINDOW_POINTER = 'SDL.window.vivante.window';
  SDL_PROP_WINDOW_VIVANTE_SURFACE_POINTER = 'SDL.window.vivante.surface';
  SDL_PROP_WINDOW_WIN32_HWND_POINTER = 'SDL.window.win32.hwnd';
  SDL_PROP_WINDOW_WIN32_HDC_POINTER = 'SDL.window.win32.hdc';
  SDL_PROP_WINDOW_WIN32_INSTANCE_POINTER = 'SDL.window.win32.instance';
  SDL_PROP_WINDOW_WAYLAND_DISPLAY_POINTER = 'SDL.window.wayland.display';
  SDL_PROP_WINDOW_WAYLAND_SURFACE_POINTER = 'SDL.window.wayland.surface';
  SDL_PROP_WINDOW_WAYLAND_VIEWPORT_POINTER = 'SDL.window.wayland.viewport';
  SDL_PROP_WINDOW_WAYLAND_EGL_WINDOW_POINTER = 'SDL.window.wayland.egl_window';
  SDL_PROP_WINDOW_WAYLAND_XDG_SURFACE_POINTER = 'SDL.window.wayland.xdg_surface';
  SDL_PROP_WINDOW_WAYLAND_XDG_TOPLEVEL_POINTER = 'SDL.window.wayland.xdg_toplevel';
  SDL_PROP_WINDOW_WAYLAND_XDG_TOPLEVEL_EXPORT_HANDLE_STRING = 'SDL.window.wayland.xdg_toplevel_export_handle';
  SDL_PROP_WINDOW_WAYLAND_XDG_POPUP_POINTER = 'SDL.window.wayland.xdg_popup';
  SDL_PROP_WINDOW_WAYLAND_XDG_POSITIONER_POINTER = 'SDL.window.wayland.xdg_positioner';
  SDL_PROP_WINDOW_X11_DISPLAY_POINTER = 'SDL.window.x11.display';
  SDL_PROP_WINDOW_X11_SCREEN_NUMBER = 'SDL.window.x11.screen';
  SDL_PROP_WINDOW_X11_WINDOW_NUMBER = 'SDL.window.x11.window';
  SDL_PROP_WINDOW_EMSCRIPTEN_CANVAS_ID_STRING = 'SDL.window.emscripten.canvas_id';
  SDL_PROP_WINDOW_EMSCRIPTEN_KEYBOARD_ELEMENT_STRING = 'SDL.window.emscripten.keyboard_element';

function SDL_WINDOWPOS_UNDEFINED_DISPLAY(X: Integer): Integer;
function SDL_WINDOWPOS_CENTERED_DISPLAY(X: Integer): Integer;
function SDL_WINDOWPOS_ISUNDEFINED(X: Integer): Boolean;
function SDL_WINDOWPOS_ISCENTERED(X: Integer): Boolean;

function SDL_GetNumVideoDrivers: Integer; cdecl; external SDL_LIB_NAME;
function SDL_GetVideoDriver(index: Integer): PUTF8Char; cdecl; external SDL_LIB_NAME;
function SDL_GetCurrentVideoDriver: PUTF8Char; cdecl; external SDL_LIB_NAME;
function SDL_GetSystemTheme: SDL_SystemTheme; cdecl; external SDL_LIB_NAME;
function SDL_GetDisplays(count: PInteger): PSDL_DisplayID; cdecl; external SDL_LIB_NAME;
function SDL_GetPrimaryDisplay: SDL_DisplayID; cdecl; external SDL_LIB_NAME;
function SDL_GetDisplayProperties(displayID: SDL_DisplayID): SDL_PropertiesID; cdecl; external SDL_LIB_NAME;
function SDL_GetDisplayName(displayID: SDL_DisplayID): PUTF8Char; cdecl; external SDL_LIB_NAME;
function SDL_GetDisplayBounds(displayID: SDL_DisplayID; rect: PSDL_Rect): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetDisplayUsableBounds(displayID: SDL_DisplayID; rect: PSDL_Rect): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetNaturalDisplayOrientation(displayID: SDL_DisplayID): SDL_DisplayOrientation; cdecl; external SDL_LIB_NAME;
function SDL_GetCurrentDisplayOrientation(displayID: SDL_DisplayID): SDL_DisplayOrientation; cdecl; external SDL_LIB_NAME;
function SDL_GetDisplayContentScale(displayID: SDL_DisplayID): Single; cdecl; external SDL_LIB_NAME;
function SDL_GetFullscreenDisplayModes(displayID: SDL_DisplayID; count: PInteger): PPSDL_DisplayMode; cdecl; external SDL_LIB_NAME;
function SDL_GetClosestFullscreenDisplayMode(displayID: SDL_DisplayID; w, h: Integer; refresh_rate: Single; include_high_density_modes: Boolean; closest: PSDL_DisplayMode): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetDesktopDisplayMode(displayID: SDL_DisplayID): PSDL_DisplayMode; cdecl; external SDL_LIB_NAME;
function SDL_GetCurrentDisplayMode(displayID: SDL_DisplayID): PSDL_DisplayMode; cdecl; external SDL_LIB_NAME;
function SDL_GetDisplayForPoint(const point: PSDL_Point): SDL_DisplayID; cdecl; external SDL_LIB_NAME;
function SDL_GetDisplayForRect(const rect: PSDL_Rect): SDL_DisplayID; cdecl; external SDL_LIB_NAME;
function SDL_GetDisplayForWindow(window: PSDL_Window): SDL_DisplayID; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowPixelDensity(window: PSDL_Window): Single; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowDisplayScale(window: PSDL_Window): Single; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowFullscreenMode(window: PSDL_Window; const mode: PSDL_DisplayMode): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowFullscreenMode(window: PSDL_Window): PSDL_DisplayMode; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowICCProfile(window: PSDL_Window; size: PNativeUInt): Pointer; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowPixelFormat(window: PSDL_Window): SDL_PixelFormat; cdecl; external SDL_LIB_NAME;
function SDL_GetWindows(count: PInteger): PPSDL_Window; cdecl; external SDL_LIB_NAME;
function SDL_CreateWindow(title: PUTF8Char; w, h: Integer; flags: SDL_WindowFlags): PSDL_Window; cdecl; external SDL_LIB_NAME;
function SDL_CreatePopupWindow(parent: PSDL_Window; offset_x, offset_y, w, h: Integer; flags: SDL_WindowFlags): PSDL_Window; cdecl; external SDL_LIB_NAME;
function SDL_CreateWindowWithProperties(props: SDL_PropertiesID): PSDL_Window; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowID(window: PSDL_Window): SDL_WindowID; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowFromID(id: SDL_WindowID): PSDL_Window; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowParent(window: PSDL_Window): PSDL_Window; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowProperties(window: PSDL_Window): SDL_PropertiesID; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowFlags(window: PSDL_Window): SDL_WindowFlags; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowTitle(window: PSDL_Window; title: PUTF8Char): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowTitle(window: PSDL_Window): PUTF8Char; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowIcon(window: PSDL_Window; icon: PSDL_Surface): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowPosition(window: PSDL_Window; x, y: Integer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowPosition(window: PSDL_Window; x, y: PInteger): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowSize(window: PSDL_Window; w, h: Integer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowSize(window: PSDL_Window; w, h: PInteger): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowSafeArea(window: PSDL_Window; rect: PSDL_Rect): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowAspectRatio(window: PSDL_Window; min_aspect, max_aspect: Single): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowAspectRatio(window: PSDL_Window; min_aspect, max_aspect: PSingle): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowBordersSize(window: PSDL_Window; top, left, bottom, right: PInteger): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowSizeInPixels(window: PSDL_Window; w, h: PInteger): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowMinimumSize(window: PSDL_Window; min_w, min_h: Integer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowMinimumSize(window: PSDL_Window; w, h: PInteger): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowMaximumSize(window: PSDL_Window; max_w, max_h: Integer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowMaximumSize(window: PSDL_Window; w, h: PInteger): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowBordered(window: PSDL_Window; bordered: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowResizable(window: PSDL_Window; resizable: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowAlwaysOnTop(window: PSDL_Window; on_top: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowFillDocument(window: PSDL_Window; fill: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_ShowWindow(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_HideWindow(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_RaiseWindow(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_MaximizeWindow(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_MinimizeWindow(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_RestoreWindow(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowFullscreen(window: PSDL_Window; fullscreen: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SyncWindow(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_WindowHasSurface(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowSurface(window: PSDL_Window): PSDL_Surface; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowSurfaceVSync(window: PSDL_Window; vsync: Integer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowSurfaceVSync(window: PSDL_Window; vsync: PInteger): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_UpdateWindowSurface(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_UpdateWindowSurfaceRects(window: PSDL_Window; const rects: PSDL_Rect; numrects: Integer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_DestroyWindowSurface(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowKeyboardGrab(window: PSDL_Window; grabbed: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowMouseGrab(window: PSDL_Window; grabbed: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowKeyboardGrab(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowMouseGrab(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetGrabbedWindow: PSDL_Window; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowMouseRect(window: PSDL_Window; const rect: PSDL_Rect): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowMouseRect(window: PSDL_Window): PSDL_Rect; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowOpacity(window: PSDL_Window; opacity: Single): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowOpacity(window: PSDL_Window): Single; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowParent(window, parent: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowModal(window: PSDL_Window; modal: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowFocusable(window: PSDL_Window; focusable: Boolean): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_ShowWindowSystemMenu(window: PSDL_Window; x, y: Integer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowHitTest(window: PSDL_Window; callback: SDL_HitTest; callback_data: Pointer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowShape(window: PSDL_Window; shape: PSDL_Surface): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_FlashWindow(window: PSDL_Window; operation: SDL_FlashOperation): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowProgressState(window: PSDL_Window; state: SDL_ProgressState): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowProgressState(window: PSDL_Window): SDL_ProgressState; cdecl; external SDL_LIB_NAME;
function SDL_SetWindowProgressValue(window: PSDL_Window; value: Single): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GetWindowProgressValue(window: PSDL_Window): Single; cdecl; external SDL_LIB_NAME;
procedure SDL_DestroyWindow(window: PSDL_Window); cdecl; external SDL_LIB_NAME;
function SDL_ScreenSaverEnabled: Boolean; cdecl; external SDL_LIB_NAME;
function SDL_EnableScreenSaver: Boolean; cdecl; external SDL_LIB_NAME;
function SDL_DisableScreenSaver: Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GL_LoadLibrary(path: PUTF8Char): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GL_GetProcAddress(proc: PUTF8Char): SDL_FunctionPointer; cdecl; external SDL_LIB_NAME;
function SDL_EGL_GetProcAddress(proc: PUTF8Char): SDL_FunctionPointer; cdecl; external SDL_LIB_NAME;
procedure SDL_GL_UnloadLibrary; cdecl; external SDL_LIB_NAME;
function SDL_GL_ExtensionSupported(extension: PUTF8Char): Boolean; cdecl; external SDL_LIB_NAME;
procedure SDL_GL_ResetAttributes; cdecl; external SDL_LIB_NAME;
function SDL_GL_SetAttribute(attr: SDL_GLAttr; value: Integer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GL_GetAttribute(attr: SDL_GLAttr; value: PInteger): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GL_CreateContext(window: PSDL_Window): SDL_GLContext; cdecl; external SDL_LIB_NAME;
function SDL_GL_MakeCurrent(window: PSDL_Window; context: SDL_GLContext): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GL_GetCurrentWindow: PSDL_Window; cdecl; external SDL_LIB_NAME;
function SDL_GL_GetCurrentContext: SDL_GLContext; cdecl; external SDL_LIB_NAME;
function SDL_EGL_GetCurrentDisplay: SDL_EGLDisplay; cdecl; external SDL_LIB_NAME;
function SDL_EGL_GetCurrentConfig: SDL_EGLConfig; cdecl; external SDL_LIB_NAME;
function SDL_EGL_GetWindowSurface(window: PSDL_Window): SDL_EGLSurface; cdecl; external SDL_LIB_NAME;
procedure SDL_EGL_SetAttributeCallbacks(platformAttribCallback: SDL_EGLAttribArrayCallback; surfaceAttribCallback, contextAttribCallback: SDL_EGLIntArrayCallback; userdata: Pointer); cdecl; external SDL_LIB_NAME;
function SDL_GL_SetSwapInterval(interval: Integer): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GL_GetSwapInterval(interval: PInteger): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GL_SwapWindow(window: PSDL_Window): Boolean; cdecl; external SDL_LIB_NAME;
function SDL_GL_DestroyContext(context: SDL_GLContext): Boolean; cdecl; external SDL_LIB_NAME;
