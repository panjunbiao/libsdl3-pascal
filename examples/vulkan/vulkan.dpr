program vulkan;

{ Load the Vulkan loader and print the instance extensions SDL needs. }

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  Window: PSDL_Window;
  Count: Uint32;
  Names, Item: PPUTF8Char;
  I: Integer;
begin
  SDL_SetMainReady;
  SDL_SetAppMetadata('libsdl3-pascal vulkan', '0.1.0', 'com.libsdl3pascal.vulkan');

  if not SDL_Init(SDL_INIT_VIDEO) then
  begin
    WriteLn('SDL_Init failed: ', SDL_GetError);
    Halt(1);
  end;

  Window := SDL_CreateWindow('libsdl3-pascal vulkan', 640, 480, SDL_WINDOW_VULKAN);
  if Window = nil then
  begin
    WriteLn('SDL_CreateWindow failed: ', SDL_GetError);
    SDL_Quit;
    Halt(1);
  end;

  if not SDL_Vulkan_LoadLibrary(nil) then
  begin
    WriteLn('SDL_Vulkan_LoadLibrary failed: ', SDL_GetError);
    WriteLn('A Vulkan loader (vulkan-1.dll) has to be installed.');
    SDL_DestroyWindow(Window);
    SDL_Quit;
    Halt(1);
  end;

  Count := 0;
  Names := SDL_Vulkan_GetInstanceExtensions(@Count);
  if Names = nil then
  begin
    WriteLn('SDL_Vulkan_GetInstanceExtensions failed: ', SDL_GetError);
    SDL_Vulkan_UnloadLibrary;
    SDL_DestroyWindow(Window);
    SDL_Quit;
    Halt(1);
  end;

  WriteLn('instance extensions: ', Count);
  Item := Names;
  for I := 0 to Integer(Count) - 1 do
  begin
    WriteLn('  ', Item^);
    Inc(Item);
  end;

  SDL_Vulkan_UnloadLibrary;
  SDL_DestroyWindow(Window);
  SDL_Quit;
end.
