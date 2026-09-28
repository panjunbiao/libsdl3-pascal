{ SDL_vulkan.inc -- 1-to-1 from SDL_vulkan.h (SDL 3.4.14) }
{ Vk* handles are pointer-sized on Win64. VkAllocationCallbacks stays opaque. }

type
  VkInstance = Pointer;
  PVkInstance = ^VkInstance;
  VkPhysicalDevice = Pointer;
  PVkPhysicalDevice = ^VkPhysicalDevice;
  VkSurfaceKHR = Pointer;
  PVkSurfaceKHR = ^VkSurfaceKHR;
  PVkAllocationCallbacks = Pointer;

function SDL_Vulkan_LoadLibrary(path: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_Vulkan_GetVkGetInstanceProcAddr: SDL_FunctionPointer; cdecl;
  external SDL_LIB_NAME;
procedure SDL_Vulkan_UnloadLibrary; cdecl;
  external SDL_LIB_NAME;
function SDL_Vulkan_GetInstanceExtensions(count: PUint32): PPUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_Vulkan_CreateSurface(window: PSDL_Window; instance: VkInstance; allocator: PVkAllocationCallbacks; surface: PVkSurfaceKHR): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_Vulkan_DestroySurface(instance: VkInstance; surface: VkSurfaceKHR; allocator: PVkAllocationCallbacks); cdecl;
  external SDL_LIB_NAME;
function SDL_Vulkan_GetPresentationSupport(instance: VkInstance; physicalDevice: VkPhysicalDevice; queueFamilyIndex: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
