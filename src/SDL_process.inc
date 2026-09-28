{ SDL_process.inc -- 1-to-1 from SDL_process.h (SDL 3.4.16) }

type
  SDL_Process = record
  end;
  PSDL_Process = ^SDL_Process;
  PPSDL_Process = ^PSDL_Process;
  SDL_ProcessIO = (
    SDL_PROCESS_STDIO_INHERITED,
    SDL_PROCESS_STDIO_NULL,
    SDL_PROCESS_STDIO_APP,
    SDL_PROCESS_STDIO_REDIRECT
  );
  PSDL_ProcessIO = ^SDL_ProcessIO;
  PPSDL_ProcessIO = ^PSDL_ProcessIO;

const
  SDL_PROP_PROCESS_CREATE_ARGS_POINTER = 'SDL.process.create.args';
  SDL_PROP_PROCESS_CREATE_ENVIRONMENT_POINTER = 'SDL.process.create.environment';
  SDL_PROP_PROCESS_CREATE_WORKING_DIRECTORY_STRING = 'SDL.process.create.working_directory';
  SDL_PROP_PROCESS_CREATE_STDIN_NUMBER = 'SDL.process.create.stdin_option';
  SDL_PROP_PROCESS_CREATE_STDIN_POINTER = 'SDL.process.create.stdin_source';
  SDL_PROP_PROCESS_CREATE_STDOUT_NUMBER = 'SDL.process.create.stdout_option';
  SDL_PROP_PROCESS_CREATE_STDOUT_POINTER = 'SDL.process.create.stdout_source';
  SDL_PROP_PROCESS_CREATE_STDERR_NUMBER = 'SDL.process.create.stderr_option';
  SDL_PROP_PROCESS_CREATE_STDERR_POINTER = 'SDL.process.create.stderr_source';
  SDL_PROP_PROCESS_CREATE_STDERR_TO_STDOUT_BOOLEAN = 'SDL.process.create.stderr_to_stdout';
  SDL_PROP_PROCESS_CREATE_BACKGROUND_BOOLEAN = 'SDL.process.create.background';
  SDL_PROP_PROCESS_CREATE_CMDLINE_STRING = 'SDL.process.create.cmdline';
  SDL_PROP_PROCESS_PID_NUMBER = 'SDL.process.pid';
  SDL_PROP_PROCESS_STDIN_POINTER = 'SDL.process.stdin';
  SDL_PROP_PROCESS_STDOUT_POINTER = 'SDL.process.stdout';
  SDL_PROP_PROCESS_STDERR_POINTER = 'SDL.process.stderr';
  SDL_PROP_PROCESS_BACKGROUND_BOOLEAN = 'SDL.process.background';

function SDL_CreateProcess(args: PPUTF8Char; pipe_stdio: Boolean): PSDL_Process; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateProcessWithProperties(props: SDL_PropertiesID): PSDL_Process; cdecl;
  external SDL_LIB_NAME;
function SDL_GetProcessProperties(process: PSDL_Process): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadProcess(process: PSDL_Process; datasize: PNativeUInt; exitcode: PInteger): Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetProcessInput(process: PSDL_Process): PSDL_IOStream; cdecl;
  external SDL_LIB_NAME;
function SDL_GetProcessOutput(process: PSDL_Process): PSDL_IOStream; cdecl;
  external SDL_LIB_NAME;
function SDL_KillProcess(process: PSDL_Process; force: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WaitProcess(process: PSDL_Process; block: Boolean; exitcode: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyProcess(process: PSDL_Process); cdecl;
  external SDL_LIB_NAME;
