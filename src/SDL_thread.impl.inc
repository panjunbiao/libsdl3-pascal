function SDL_CreateThread(fn: SDL_ThreadFunction; name: PUTF8Char; data: Pointer): PSDL_Thread;
begin
  { Delphi RTL is not the MSVC CRT; pass nil so SDL uses CreateThread. }
  Result := SDL_CreateThreadRuntime(fn, name, data, nil, nil);
end;

function SDL_CreateThreadWithProperties(props: SDL_PropertiesID): PSDL_Thread;
begin
  Result := SDL_CreateThreadWithPropertiesRuntime(props, nil, nil);
end;
