program process;

{ Run a child process, then print its stdout with SDL_ReadProcess. }

{$APPTYPE CONSOLE}

uses
  SDL3;

var
  Exe, Flag, Script: UTF8String;
  Args: array[0..3] of PUTF8Char;
  Child: PSDL_Process;
  Output: PUTF8Char;
  Bytes: NativeUInt;
  ExitCode: Integer;
begin
  SDL_SetMainReady;
  if not SDL_Init(0) then
  begin
    WriteLn('SDL_Init failed: ', SDL_GetError);
    Halt(1);
  end;

  Exe := 'C:\Windows\System32\cmd.exe';
  Flag := '/c';
  Script := 'echo hello from SDL_CreateProcess';
  Args[0] := PUTF8Char(Exe);
  Args[1] := PUTF8Char(Flag);
  Args[2] := PUTF8Char(Script);
  Args[3] := nil;

  Child := SDL_CreateProcess(@Args[0], True);
  if Child = nil then
  begin
    WriteLn('SDL_CreateProcess failed: ', SDL_GetError);
    SDL_Quit;
    Halt(1);
  end;

  Bytes := 0;
  ExitCode := -1;
  Output := PUTF8Char(SDL_ReadProcess(Child, @Bytes, @ExitCode));
  if Output = nil then
  begin
    WriteLn('SDL_ReadProcess failed: ', SDL_GetError);
    SDL_DestroyProcess(Child);
    SDL_Quit;
    Halt(1);
  end;

  WriteLn(Output);
  WriteLn('bytes=', Bytes, ' exit=', ExitCode, ' strlen=', SDL_strlen(Output));
  SDL_free(Output);
  SDL_DestroyProcess(Child);
  SDL_Quit;
end.
