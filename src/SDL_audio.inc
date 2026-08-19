{ SDL_audio.inc -- 1-to-1 from SDL_audio.h }

type
  SDL_AudioFormat = type Uint32;
  PSDL_AudioFormat = ^SDL_AudioFormat;
  SDL_AudioDeviceID = Uint32;
  PSDL_AudioDeviceID = ^SDL_AudioDeviceID;

const
  SDL_AUDIO_MASK_BITSIZE = $00FF;
  SDL_AUDIO_MASK_FLOAT = $0100;
  SDL_AUDIO_MASK_BIG_ENDIAN = $1000;
  SDL_AUDIO_MASK_SIGNED = $8000;

  SDL_AUDIO_UNKNOWN = SDL_AudioFormat($0000);
  SDL_AUDIO_U8 = SDL_AudioFormat($0008);
  SDL_AUDIO_S8 = SDL_AudioFormat($8008);
  SDL_AUDIO_S16LE = SDL_AudioFormat($8010);
  SDL_AUDIO_S16BE = SDL_AudioFormat($9010);
  SDL_AUDIO_S32LE = SDL_AudioFormat($8020);
  SDL_AUDIO_S32BE = SDL_AudioFormat($9020);
  SDL_AUDIO_F32LE = SDL_AudioFormat($8120);
  SDL_AUDIO_F32BE = SDL_AudioFormat($9120);
{$IFDEF FPC}
  {$IFDEF ENDIAN_BIG}
  SDL_AUDIO_S16 = SDL_AUDIO_S16BE;
  SDL_AUDIO_S32 = SDL_AUDIO_S32BE;
  SDL_AUDIO_F32 = SDL_AUDIO_F32BE;
  {$ELSE}
  SDL_AUDIO_S16 = SDL_AUDIO_S16LE;
  SDL_AUDIO_S32 = SDL_AUDIO_S32LE;
  SDL_AUDIO_F32 = SDL_AUDIO_F32LE;
  {$ENDIF}
{$ELSE}
  SDL_AUDIO_S16 = SDL_AUDIO_S16LE;
  SDL_AUDIO_S32 = SDL_AUDIO_S32LE;
  SDL_AUDIO_F32 = SDL_AUDIO_F32LE;
{$ENDIF}

  SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK = SDL_AudioDeviceID($FFFFFFFF);
  SDL_AUDIO_DEVICE_DEFAULT_RECORDING = SDL_AudioDeviceID($FFFFFFFE);
  SDL_PROP_AUDIOSTREAM_AUTO_CLEANUP_BOOLEAN = 'SDL.audiostream.auto_cleanup';

type
  PSDL_AudioSpec = ^SDL_AudioSpec;
  SDL_AudioSpec = record
    format: SDL_AudioFormat;
    channels: Integer;
    freq: Integer;
  end;

  SDL_AudioStream = record
  end;
  PSDL_AudioStream = ^SDL_AudioStream;
  PPSDL_AudioStream = ^PSDL_AudioStream;

  SDL_AudioStreamDataCompleteCallback = procedure(userdata: Pointer; const buf: Pointer; buflen: Integer); cdecl;
  SDL_AudioStreamCallback = procedure(userdata: Pointer; stream: PSDL_AudioStream; additional_amount, total_amount: Integer); cdecl;
  SDL_AudioPostmixCallback = procedure(userdata: Pointer; const spec: PSDL_AudioSpec; buffer: PSingle; buflen: Integer); cdecl;

function SDL_AUDIO_BITSIZE(x: SDL_AudioFormat): Uint32;
function SDL_AUDIO_BYTESIZE(x: SDL_AudioFormat): Uint32;
function SDL_AUDIO_ISFLOAT(x: SDL_AudioFormat): Boolean;
function SDL_AUDIO_ISBIGENDIAN(x: SDL_AudioFormat): Boolean;
function SDL_AUDIO_ISLITTLEENDIAN(x: SDL_AudioFormat): Boolean;
function SDL_AUDIO_ISSIGNED(x: SDL_AudioFormat): Boolean;
function SDL_AUDIO_ISINT(x: SDL_AudioFormat): Boolean;
function SDL_AUDIO_ISUNSIGNED(x: SDL_AudioFormat): Boolean;
function SDL_AUDIO_FRAMESIZE(const x: SDL_AudioSpec): Integer;
function SDL_DEFINE_AUDIO_FORMAT(signed_, bigendian, flt, size: Uint32): SDL_AudioFormat;

function SDL_GetNumAudioDrivers: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioDriver(index: Integer): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetCurrentAudioDriver: PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioPlaybackDevices(count: PInteger): PSDL_AudioDeviceID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioRecordingDevices(count: PInteger): PSDL_AudioDeviceID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioDeviceName(devid: SDL_AudioDeviceID): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioDeviceFormat(devid: SDL_AudioDeviceID; spec: PSDL_AudioSpec; sample_frames: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioDeviceChannelMap(devid: SDL_AudioDeviceID; count: PInteger): PInteger; cdecl;
  external SDL_LIB_NAME;
function SDL_OpenAudioDevice(devid: SDL_AudioDeviceID; const spec: PSDL_AudioSpec): SDL_AudioDeviceID; cdecl;
  external SDL_LIB_NAME;
function SDL_IsAudioDevicePhysical(devid: SDL_AudioDeviceID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_IsAudioDevicePlayback(devid: SDL_AudioDeviceID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_PauseAudioDevice(devid: SDL_AudioDeviceID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ResumeAudioDevice(devid: SDL_AudioDeviceID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_AudioDevicePaused(devid: SDL_AudioDeviceID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioDeviceGain(devid: SDL_AudioDeviceID): Single; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAudioDeviceGain(devid: SDL_AudioDeviceID; gain: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_CloseAudioDevice(devid: SDL_AudioDeviceID); cdecl;
  external SDL_LIB_NAME;
function SDL_BindAudioStreams(devid: SDL_AudioDeviceID; streams: PPSDL_AudioStream; num_streams: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_BindAudioStream(devid: SDL_AudioDeviceID; stream: PSDL_AudioStream): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnbindAudioStreams(streams: PPSDL_AudioStream; num_streams: Integer); cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnbindAudioStream(stream: PSDL_AudioStream); cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamDevice(stream: PSDL_AudioStream): SDL_AudioDeviceID; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateAudioStream(const src_spec, dst_spec: PSDL_AudioSpec): PSDL_AudioStream; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamProperties(stream: PSDL_AudioStream): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamFormat(stream: PSDL_AudioStream; src_spec, dst_spec: PSDL_AudioSpec): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAudioStreamFormat(stream: PSDL_AudioStream; const src_spec, dst_spec: PSDL_AudioSpec): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamFrequencyRatio(stream: PSDL_AudioStream): Single; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAudioStreamFrequencyRatio(stream: PSDL_AudioStream; ratio: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamGain(stream: PSDL_AudioStream): Single; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAudioStreamGain(stream: PSDL_AudioStream; gain: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamInputChannelMap(stream: PSDL_AudioStream; count: PInteger): PInteger; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamOutputChannelMap(stream: PSDL_AudioStream; count: PInteger): PInteger; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAudioStreamInputChannelMap(stream: PSDL_AudioStream; chmap: PInteger; count: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAudioStreamOutputChannelMap(stream: PSDL_AudioStream; chmap: PInteger; count: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_PutAudioStreamData(stream: PSDL_AudioStream; const buf: Pointer; len: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_PutAudioStreamDataNoCopy(stream: PSDL_AudioStream; const buf: Pointer; len: Integer;
  callback: SDL_AudioStreamDataCompleteCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_PutAudioStreamPlanarData(stream: PSDL_AudioStream; channel_buffers: PPointer; num_channels, num_samples: Integer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamData(stream: PSDL_AudioStream; buf: Pointer; len: Integer): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamAvailable(stream: PSDL_AudioStream): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioStreamQueued(stream: PSDL_AudioStream): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_FlushAudioStream(stream: PSDL_AudioStream): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ClearAudioStream(stream: PSDL_AudioStream): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_PauseAudioStreamDevice(stream: PSDL_AudioStream): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ResumeAudioStreamDevice(stream: PSDL_AudioStream): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_AudioStreamDevicePaused(stream: PSDL_AudioStream): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_LockAudioStream(stream: PSDL_AudioStream): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_UnlockAudioStream(stream: PSDL_AudioStream): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAudioStreamGetCallback(stream: PSDL_AudioStream; callback: SDL_AudioStreamCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAudioStreamPutCallback(stream: PSDL_AudioStream; callback: SDL_AudioStreamCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyAudioStream(stream: PSDL_AudioStream); cdecl;
  external SDL_LIB_NAME;
function SDL_OpenAudioDeviceStream(devid: SDL_AudioDeviceID; const spec: PSDL_AudioSpec;
  callback: SDL_AudioStreamCallback; userdata: Pointer): PSDL_AudioStream; cdecl;
  external SDL_LIB_NAME;
function SDL_SetAudioPostmixCallback(devid: SDL_AudioDeviceID; callback: SDL_AudioPostmixCallback; userdata: Pointer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadWAV_IO(src: PSDL_IOStream; closeio: Boolean; spec: PSDL_AudioSpec; audio_buf: PPUint8; audio_len: PUint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_LoadWAV(path: PUTF8Char; spec: PSDL_AudioSpec; audio_buf: PPUint8; audio_len: PUint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_MixAudio(dst, src: PUint8; format: SDL_AudioFormat; len: Uint32; volume: Single): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ConvertAudioSamples(const src_spec: PSDL_AudioSpec; src_data: PUint8; src_len: Integer;
  const dst_spec: PSDL_AudioSpec; dst_data: PPUint8; dst_len: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetAudioFormatName(format: SDL_AudioFormat): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetSilenceValueForFormat(format: SDL_AudioFormat): Integer; cdecl;
  external SDL_LIB_NAME;
