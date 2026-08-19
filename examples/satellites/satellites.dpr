program satellites;

{$APPTYPE CONSOLE}

uses
  SDL3,
  SDL3_image,
  SDL3_ttf,
  SDL3_mixer;

function Asset(const Rel: UTF8String): UTF8String;
var
  Base: PUTF8Char;
begin
  Base := SDL_GetBasePath;
  if Base <> nil then
    Result := UTF8String(Base) + Rel
  else
    Result := Rel;
end;

procedure Die(const Msg: PUTF8Char);
begin
  WriteLn(Msg, ': ', SDL_GetError);
  Halt(1);
end;

procedure Fit(Texture: PSDL_Texture; BoxX, BoxY, BoxW, BoxH: Single; var Dst: SDL_FRect);
var
  Tw, Th, Scale: Single;
begin
  SDL_GetTextureSize(Texture, @Tw, @Th);
  Scale := BoxW / Tw;
  if Th * Scale > BoxH then
    Scale := BoxH / Th;
  Dst.w := Tw * Scale;
  Dst.h := Th * Scale;
  Dst.x := BoxX + (BoxW - Dst.w) / 2;
  Dst.y := BoxY + (BoxH - Dst.h) / 2;
end;

const
  { 你好，世界 as UTF-8 code units. Use AnsiChar bytes; a UnicodeString of
    #$E4#$BD#$A0 is U+00E4 U+00BD U+00A0, and UTF8String() would encode it again. }
  ChineseUtf8: packed array[0..15] of AnsiChar = (
    AnsiChar($E4), AnsiChar($BD), AnsiChar($A0),
    AnsiChar($E5), AnsiChar($A5), AnsiChar($BD),
    AnsiChar($EF), AnsiChar($BC), AnsiChar($8C),
    AnsiChar($E4), AnsiChar($B8), AnsiChar($96),
    AnsiChar($E7), AnsiChar($95), AnsiChar($8C),
    AnsiChar(0)
  );

var
  Window: PSDL_Window;
  Renderer: PSDL_Renderer;
  Event: SDL_Event;
  Running: Boolean;
  Roses, Classroom: PSDL_Texture;
  RosesDst, ClassDst: SDL_FRect;
  FontLatin, FontSC: PTTF_Font;
  Engine: PTTF_TextEngine;
  TextLatin, TextChinese: PTTF_Text;
  Mixer: PMIX_Mixer;
  Music: PMIX_Audio;
  Track: PMIX_Track;
  Linked, ImgVer, TtfVer, MixVer: Integer;
  Latin: UTF8String;
begin
  SDL_SetMainReady;
  SDL_SetAppMetadata('libsdl3-pascal satellites', '1.1.0', 'com.libsdl3pascal.satellites');
  SDL_SetHint(SDL_HINT_RENDER_VSYNC, '1');

  Linked := SDL_GetVersion;
  if SDL_VERSIONNUM_MAJOR(Linked) <> SDL_MAJOR_VERSION then
  begin
    WriteLn('SDL3.dll major version does not match this binding.');
    Halt(1);
  end;
  if Linked < SDL_VERSION then
  begin
    WriteLn('SDL3.dll is older than the SDL 3.4.14 pin.');
    Halt(1);
  end;

  if not SDL_Init(SDL_INIT_VIDEO or SDL_INIT_AUDIO) then
    Die('SDL_Init');

  ImgVer := IMG_Version;
  TtfVer := TTF_Version;
  MixVer := MIX_Version;
  if SDL_VERSIONNUM_MAJOR(ImgVer) <> SDL_IMAGE_MAJOR_VERSION then
    Die('SDL3_image.dll major mismatch');
  if ImgVer < SDL_IMAGE_VERSION then
    Die('SDL3_image.dll is older than the 3.4.4 pin');
  if SDL_VERSIONNUM_MAJOR(TtfVer) <> SDL_TTF_MAJOR_VERSION then
    Die('SDL3_ttf.dll major mismatch');
  if TtfVer < SDL_TTF_VERSION then
    Die('SDL3_ttf.dll is older than the 3.2.2 pin');
  if SDL_VERSIONNUM_MAJOR(MixVer) <> SDL_MIXER_MAJOR_VERSION then
    Die('SDL3_mixer.dll major mismatch');
  if MixVer < SDL_MIXER_VERSION then
    Die('SDL3_mixer.dll is older than the 3.2.4 pin');

  if not TTF_Init then
    Die('TTF_Init');
  if not MIX_Init then
    Die('MIX_Init');

  if not SDL_CreateWindowAndRenderer('libsdl3-pascal satellites', 1100, 620, 0, @Window, @Renderer) then
    Die('SDL_CreateWindowAndRenderer');

  Roses := IMG_LoadTexture(Renderer, PUTF8Char(Asset('assets/images/roses_1991.67.1.jpg')));
  if Roses = nil then
    Die('IMG_LoadTexture JPEG');
  Classroom := IMG_LoadTexture(Renderer, PUTF8Char(Asset('assets/images/majabel-class-845194.png')));
  if Classroom = nil then
    Die('IMG_LoadTexture PNG');
  Fit(Roses, 20, 20, 520, 420, RosesDst);
  Fit(Classroom, 560, 20, 520, 420, ClassDst);

  FontLatin := TTF_OpenFont(PUTF8Char(Asset('assets/fonts/NotoSans-Regular.ttf')), 28);
  if FontLatin = nil then
    Die('TTF_OpenFont Noto Sans');
  FontSC := TTF_OpenFont(PUTF8Char(Asset('assets/fonts/NotoSansSC-Regular.ttf')), 28);
  if FontSC = nil then
    Die('TTF_OpenFont Noto Sans SC');

  Engine := TTF_CreateRendererTextEngine(Renderer);
  if Engine = nil then
    Die('TTF_CreateRendererTextEngine');

  Latin := 'SDL_image + SDL_ttf + SDL_mixer';
  TextLatin := TTF_CreateText(Engine, FontLatin, PUTF8Char(Latin), Length(Latin));
  if TextLatin = nil then
    Die('TTF_CreateText Latin');
  TextChinese := TTF_CreateText(Engine, FontSC, @ChineseUtf8[0], 15);
  if TextChinese = nil then
    Die('TTF_CreateText Chinese');
  TTF_SetTextColor(TextLatin, 240, 240, 245, SDL_ALPHA_OPAQUE);
  TTF_SetTextColor(TextChinese, 240, 220, 160, SDL_ALPHA_OPAQUE);

  Mixer := MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nil);
  if Mixer = nil then
    Die('MIX_CreateMixerDevice');
  Music := MIX_LoadAudio(Mixer, PUTF8Char(Asset('assets/audio/kamhunt-acoustic-guitar-loop-f-91bpm-132687.mp3')), True);
  if Music = nil then
    Die('MIX_LoadAudio MP3');
  Track := MIX_CreateTrack(Mixer);
  if Track = nil then
    Die('MIX_CreateTrack');
  if not MIX_SetTrackAudio(Track, Music) then
    Die('MIX_SetTrackAudio');
  MIX_SetTrackLoops(Track, -1);
  if not MIX_PlayTrack(Track, 0) then
    Die('MIX_PlayTrack');

  WriteLn('SDL_GetVersion = ', Linked, ' image=', ImgVer, ' ttf=', TtfVer, ' mixer=', MixVer);
  WriteLn('Hint SDL_HINT_RENDER_VSYNC = ', SDL_GetHint(SDL_HINT_RENDER_VSYNC));

  Running := True;
  while Running do
  begin
    while SDL_PollEvent(@Event) do
    begin
      if (Event.type_ = Uint32(SDL_EVENT_QUIT)) or
         (Event.type_ = Uint32(SDL_EVENT_WINDOW_CLOSE_REQUESTED)) then
        Running := False;
      if (Event.type_ = Uint32(SDL_EVENT_KEY_DOWN)) and
         (Event.key.scancode = SDL_SCANCODE_ESCAPE) then
        Running := False;
    end;

    SDL_SetRenderDrawColor(Renderer, 18, 18, 28, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(Renderer);
    SDL_RenderTexture(Renderer, Roses, nil, @RosesDst);
    SDL_RenderTexture(Renderer, Classroom, nil, @ClassDst);
    TTF_DrawRendererText(TextLatin, 24, 460);
    TTF_DrawRendererText(TextChinese, 24, 510);
    SDL_RenderPresent(Renderer);
  end;

  MIX_DestroyTrack(Track);
  MIX_DestroyAudio(Music);
  MIX_DestroyMixer(Mixer);
  TTF_DestroyText(TextLatin);
  TTF_DestroyText(TextChinese);
  TTF_DestroyRendererTextEngine(Engine);
  TTF_CloseFont(FontLatin);
  TTF_CloseFont(FontSC);
  SDL_DestroyTexture(Roses);
  SDL_DestroyTexture(Classroom);
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  MIX_Quit;
  TTF_Quit;
  SDL_Quit;
end.
