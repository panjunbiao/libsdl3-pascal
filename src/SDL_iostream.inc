{ SDL_iostream.inc -- 1-to-1 from SDL_iostream.h }

type
  SDL_IOStatus = (
    SDL_IO_STATUS_READY,
    SDL_IO_STATUS_ERROR,
    SDL_IO_STATUS_EOF,
    SDL_IO_STATUS_NOT_READY,
    SDL_IO_STATUS_READONLY,
    SDL_IO_STATUS_WRITEONLY
  );
  PSDL_IOStatus = ^SDL_IOStatus;

  SDL_IOWhence = (
    SDL_IO_SEEK_SET,
    SDL_IO_SEEK_CUR,
    SDL_IO_SEEK_END
  );

  PSDL_IOStreamInterface = ^SDL_IOStreamInterface;
  SDL_IOStreamInterface = record
    version: Uint32;
    size: function(userdata: Pointer): Sint64; cdecl;
    seek: function(userdata: Pointer; offset: Sint64; whence: SDL_IOWhence): Sint64; cdecl;
    read: function(userdata: Pointer; ptr: Pointer; size: NativeUInt; status: PSDL_IOStatus): NativeUInt; cdecl;
    write: function(userdata: Pointer; const ptr: Pointer; size: NativeUInt; status: PSDL_IOStatus): NativeUInt; cdecl;
    flush: function(userdata: Pointer; status: PSDL_IOStatus): Boolean; cdecl;
    close: function(userdata: Pointer): Boolean; cdecl;
  end;

  SDL_IOStream = record
  end;
  PSDL_IOStream = ^SDL_IOStream;

const
  SDL_PROP_IOSTREAM_WINDOWS_HANDLE_POINTER = 'SDL.iostream.windows.handle';
  SDL_PROP_IOSTREAM_STDIO_FILE_POINTER = 'SDL.iostream.stdio.file';
  SDL_PROP_IOSTREAM_FILE_DESCRIPTOR_NUMBER = 'SDL.iostream.file_descriptor';
  SDL_PROP_IOSTREAM_ANDROID_AASSET_POINTER = 'SDL.iostream.android.aasset';
  SDL_PROP_IOSTREAM_MEMORY_POINTER = 'SDL.iostream.memory.base';
  SDL_PROP_IOSTREAM_MEMORY_SIZE_NUMBER = 'SDL.iostream.memory.size';
  SDL_PROP_IOSTREAM_MEMORY_FREE_FUNC_POINTER = 'SDL.iostream.memory.free';
  SDL_PROP_IOSTREAM_DYNAMIC_MEMORY_POINTER = 'SDL.iostream.dynamic.memory';
  SDL_PROP_IOSTREAM_DYNAMIC_CHUNKSIZE_NUMBER = 'SDL.iostream.dynamic.chunksize';

procedure SDL_INIT_INTERFACE(iface: PSDL_IOStreamInterface); overload;

function SDL_IOFromFile(file_, mode: PUTF8Char): PSDL_IOStream; cdecl;
  external SDL_LIB_NAME;
function SDL_IOFromMem(mem: Pointer; size: NativeUInt): PSDL_IOStream; cdecl;
  external SDL_LIB_NAME;
function SDL_IOFromConstMem(const mem: Pointer; size: NativeUInt): PSDL_IOStream; cdecl;
  external SDL_LIB_NAME;
function SDL_IOFromDynamicMem: PSDL_IOStream; cdecl;
  external SDL_LIB_NAME;
function SDL_OpenIO(const iface: PSDL_IOStreamInterface; userdata: Pointer): PSDL_IOStream; cdecl;
  external SDL_LIB_NAME;
function SDL_CloseIO(context: PSDL_IOStream): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetIOProperties(context: PSDL_IOStream): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetIOStatus(context: PSDL_IOStream): SDL_IOStatus; cdecl;
  external SDL_LIB_NAME;
function SDL_GetIOSize(context: PSDL_IOStream): Sint64; cdecl;
  external SDL_LIB_NAME;
function SDL_SeekIO(context: PSDL_IOStream; offset: Sint64; whence: SDL_IOWhence): Sint64; cdecl;
  external SDL_LIB_NAME;
function SDL_TellIO(context: PSDL_IOStream): Sint64; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadIO(context: PSDL_IOStream; ptr: Pointer; size: NativeUInt): NativeUInt; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteIO(context: PSDL_IOStream; const ptr: Pointer; size: NativeUInt): NativeUInt; cdecl;
  external SDL_LIB_NAME;
function SDL_IOprintf(context: PSDL_IOStream; fmt: PUTF8Char): NativeUInt; cdecl varargs;
  external SDL_LIB_NAME;
{ skipped SDL_IOvprintf -- va_list }
function SDL_FlushIO(context: PSDL_IOStream): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadFile_IO(src: PSDL_IOStream; datasize: PNativeUInt; closeio: Boolean): Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadFile(file_: PUTF8Char; datasize: PNativeUInt): Pointer; cdecl;
  external SDL_LIB_NAME;
function SDL_SaveFile_IO(src: PSDL_IOStream; const data: Pointer; datasize: NativeUInt; closeio: Boolean): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SaveFile(file_: PUTF8Char; const data: Pointer; datasize: NativeUInt): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadU8(src: PSDL_IOStream; value: PUint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadS8(src: PSDL_IOStream; value: PSint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadU16LE(src: PSDL_IOStream; value: PUint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadS16LE(src: PSDL_IOStream; value: PSint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadU16BE(src: PSDL_IOStream; value: PUint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadS16BE(src: PSDL_IOStream; value: PSint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadU32LE(src: PSDL_IOStream; value: PUint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadS32LE(src: PSDL_IOStream; value: PSint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadU32BE(src: PSDL_IOStream; value: PUint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadS32BE(src: PSDL_IOStream; value: PSint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadU64LE(src: PSDL_IOStream; value: PUint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadS64LE(src: PSDL_IOStream; value: PSint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadU64BE(src: PSDL_IOStream; value: PUint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ReadS64BE(src: PSDL_IOStream; value: PSint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteU8(dst: PSDL_IOStream; value: Uint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteS8(dst: PSDL_IOStream; value: Sint8): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteU16LE(dst: PSDL_IOStream; value: Uint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteS16LE(dst: PSDL_IOStream; value: Sint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteU16BE(dst: PSDL_IOStream; value: Uint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteS16BE(dst: PSDL_IOStream; value: Sint16): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteU32LE(dst: PSDL_IOStream; value: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteS32LE(dst: PSDL_IOStream; value: Sint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteU32BE(dst: PSDL_IOStream; value: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteS32BE(dst: PSDL_IOStream; value: Sint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteU64LE(dst: PSDL_IOStream; value: Uint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteS64LE(dst: PSDL_IOStream; value: Sint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteU64BE(dst: PSDL_IOStream; value: Uint64): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WriteS64BE(dst: PSDL_IOStream; value: Sint64): Boolean; cdecl;
  external SDL_LIB_NAME;
