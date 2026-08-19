{ SDL_ttf.inc -- 1-to-1 from SDL_ttf.h (SDL_ttf 3.2.2) }
{ Skipped GPU text-engine APIs (need SDL_GPUDevice). }

const
  SDL_TTF_MAJOR_VERSION = 3;
  SDL_TTF_MINOR_VERSION = 2;
  SDL_TTF_MICRO_VERSION = 2;
  SDL_TTF_VERSION = SDL_TTF_MAJOR_VERSION * 1000000 + SDL_TTF_MINOR_VERSION * 1000 + SDL_TTF_MICRO_VERSION;

  TTF_PROP_FONT_CREATE_FILENAME_STRING = 'SDL_ttf.font.create.filename';
  TTF_PROP_FONT_CREATE_IOSTREAM_POINTER = 'SDL_ttf.font.create.iostream';
  TTF_PROP_FONT_CREATE_IOSTREAM_OFFSET_NUMBER = 'SDL_ttf.font.create.iostream.offset';
  TTF_PROP_FONT_CREATE_IOSTREAM_AUTOCLOSE_BOOLEAN = 'SDL_ttf.font.create.iostream.autoclose';
  TTF_PROP_FONT_CREATE_SIZE_FLOAT = 'SDL_ttf.font.create.size';
  TTF_PROP_FONT_CREATE_FACE_NUMBER = 'SDL_ttf.font.create.face';
  TTF_PROP_FONT_CREATE_HORIZONTAL_DPI_NUMBER = 'SDL_ttf.font.create.hdpi';
  TTF_PROP_FONT_CREATE_VERTICAL_DPI_NUMBER = 'SDL_ttf.font.create.vdpi';
  TTF_PROP_FONT_CREATE_EXISTING_FONT = 'SDL_ttf.font.create.existing_font';
  TTF_PROP_FONT_OUTLINE_LINE_CAP_NUMBER = 'SDL_ttf.font.outline.line_cap';
  TTF_PROP_FONT_OUTLINE_LINE_JOIN_NUMBER = 'SDL_ttf.font.outline.line_join';
  TTF_PROP_FONT_OUTLINE_MITER_LIMIT_NUMBER = 'SDL_ttf.font.outline.miter_limit';
  TTF_PROP_RENDERER_TEXT_ENGINE_RENDERER = 'SDL_ttf.renderer_text_engine.create.renderer';
  TTF_PROP_RENDERER_TEXT_ENGINE_ATLAS_TEXTURE_SIZE = 'SDL_ttf.renderer_text_engine.create.atlas_texture_size';

  TTF_STYLE_NORMAL = $00;
  TTF_STYLE_BOLD = $01;
  TTF_STYLE_ITALIC = $02;
  TTF_STYLE_UNDERLINE = $04;
  TTF_STYLE_STRIKETHROUGH = $08;
  TTF_FONT_WEIGHT_THIN = 100;
  TTF_FONT_WEIGHT_EXTRA_LIGHT = 200;
  TTF_FONT_WEIGHT_LIGHT = 300;
  TTF_FONT_WEIGHT_NORMAL = 400;
  TTF_FONT_WEIGHT_MEDIUM = 500;
  TTF_FONT_WEIGHT_SEMI_BOLD = 600;
  TTF_FONT_WEIGHT_BOLD = 700;
  TTF_FONT_WEIGHT_EXTRA_BOLD = 800;
  TTF_FONT_WEIGHT_BLACK = 900;
  TTF_FONT_WEIGHT_EXTRA_BLACK = 950;
  TTF_SUBSTRING_DIRECTION_MASK = $000000FF;
  TTF_SUBSTRING_TEXT_START = $00000100;
  TTF_SUBSTRING_LINE_START = $00000200;
  TTF_SUBSTRING_LINE_END = $00000400;
  TTF_SUBSTRING_TEXT_END = $00000800;

type
  TTF_Font = record
  end;
  PTTF_Font = ^TTF_Font;

  TTF_TextEngine = record
  end;
  PTTF_TextEngine = ^TTF_TextEngine;

  TTF_TextData = record
  end;
  PTTF_TextData = ^TTF_TextData;

  TTF_FontStyleFlags = Uint32;
  TTF_SubStringFlags = Uint32;

  PTTF_Text = ^TTF_Text;
  TTF_Text = record
    text: PUTF8Char;
    num_lines: Integer;
    refcount: Integer;
    internal: PTTF_TextData;
  end;

  PTTF_SubString = ^TTF_SubString;
  PPTTF_SubString = ^PTTF_SubString;
  TTF_SubString = record
    flags: TTF_SubStringFlags;
    offset: Integer;
    length: Integer;
    line_index: Integer;
    cluster_index: Integer;
    rect: SDL_Rect;
  end;

  TTF_HintingFlags = (
    TTF_HINTING_INVALID = -1,
    TTF_HINTING_NORMAL,
    TTF_HINTING_LIGHT,
    TTF_HINTING_MONO,
    TTF_HINTING_NONE,
    TTF_HINTING_LIGHT_SUBPIXEL
  );
  PTTF_HintingFlags = ^TTF_HintingFlags;

  TTF_HorizontalAlignment = (
    TTF_HORIZONTAL_ALIGN_INVALID = -1,
    TTF_HORIZONTAL_ALIGN_LEFT,
    TTF_HORIZONTAL_ALIGN_CENTER,
    TTF_HORIZONTAL_ALIGN_RIGHT
  );
  PTTF_HorizontalAlignment = ^TTF_HorizontalAlignment;

  TTF_Direction = (
    TTF_DIRECTION_INVALID = 0,
    TTF_DIRECTION_LTR = 4,
    TTF_DIRECTION_RTL,
    TTF_DIRECTION_TTB,
    TTF_DIRECTION_BTT
  );
  PTTF_Direction = ^TTF_Direction;

  TTF_ImageType = (
    TTF_IMAGE_INVALID,
    TTF_IMAGE_ALPHA,
    TTF_IMAGE_COLOR,
    TTF_IMAGE_SDF
  );
  PTTF_ImageType = ^TTF_ImageType;

function TTF_Version: Integer; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_GetFreeTypeVersion(major: PInteger; minor: PInteger; patch: PInteger); cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_GetHarfBuzzVersion(major: PInteger; minor: PInteger; patch: PInteger); cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_Init: Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_OpenFont(file_: PUTF8Char; ptsize: Single): PTTF_Font; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_OpenFontIO(src: PSDL_IOStream; closeio: Boolean; ptsize: Single): PTTF_Font; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_OpenFontWithProperties(props: SDL_PropertiesID): PTTF_Font; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_CopyFont(existing_font: PTTF_Font): PTTF_Font; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontProperties(font: PTTF_Font): SDL_PropertiesID; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontGeneration(font: PTTF_Font): Uint32; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_AddFallbackFont(font: PTTF_Font; fallback: PTTF_Font): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_RemoveFallbackFont(font: PTTF_Font; fallback: PTTF_Font); cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_ClearFallbackFonts(font: PTTF_Font); cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetFontSize(font: PTTF_Font; ptsize: Single): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetFontSizeDPI(font: PTTF_Font; ptsize: Single; hdpi: Integer; vdpi: Integer): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontSize(font: PTTF_Font): Single; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontDPI(font: PTTF_Font; hdpi: PInteger; vdpi: PInteger): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_SetFontStyle(font: PTTF_Font; style: TTF_FontStyleFlags); cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontStyle(font: PTTF_Font): TTF_FontStyleFlags; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetFontOutline(font: PTTF_Font; outline: Integer): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontOutline(font: PTTF_Font): Integer; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_SetFontHinting(font: PTTF_Font; hinting: TTF_HintingFlags); cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetNumFontFaces(font: PTTF_Font): Integer; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontHinting(font: PTTF_Font): TTF_HintingFlags; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetFontSDF(font: PTTF_Font; enabled: Boolean): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontSDF(font: PTTF_Font): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontWeight(font: PTTF_Font): Integer; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_SetFontWrapAlignment(font: PTTF_Font; align: TTF_HorizontalAlignment); cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontWrapAlignment(font: PTTF_Font): TTF_HorizontalAlignment; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontHeight(font: PTTF_Font): Integer; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontAscent(font: PTTF_Font): Integer; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontDescent(font: PTTF_Font): Integer; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_SetFontLineSkip(font: PTTF_Font; lineskip: Integer); cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontLineSkip(font: PTTF_Font): Integer; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_SetFontKerning(font: PTTF_Font; enabled: Boolean); cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontKerning(font: PTTF_Font): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_FontIsFixedWidth(font: PTTF_Font): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_FontIsScalable(font: PTTF_Font): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontFamilyName(font: PTTF_Font): PUTF8Char; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontStyleName(font: PTTF_Font): PUTF8Char; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetFontDirection(font: PTTF_Font; direction: TTF_Direction): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontDirection(font: PTTF_Font): TTF_Direction; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_StringToTag(string_: PUTF8Char): Uint32; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_TagToString(tag: Uint32; string_: PUTF8Char; size: NativeUInt); cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetFontScript(font: PTTF_Font; script: Uint32): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetFontScript(font: PTTF_Font): Uint32; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetGlyphScript(ch: Uint32): Uint32; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetFontLanguage(font: PTTF_Font; language_bcp47: PUTF8Char): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_FontHasGlyph(font: PTTF_Font; ch: Uint32): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetGlyphImage(font: PTTF_Font; ch: Uint32; image_type: PTTF_ImageType): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetGlyphImageForIndex(font: PTTF_Font; glyph_index: Uint32; image_type: PTTF_ImageType): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetGlyphMetrics(font: PTTF_Font; ch: Uint32; minx: PInteger; maxx: PInteger; miny: PInteger; maxy: PInteger; advance: PInteger): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetGlyphKerning(font: PTTF_Font; previous_ch: Uint32; ch: Uint32; kerning: PInteger): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetStringSize(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; w: PInteger; h: PInteger): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetStringSizeWrapped(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; wrap_width: Integer; w: PInteger; h: PInteger): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_MeasureString(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; max_width: Integer; measured_width: PInteger; measured_length: PNativeUInt): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderText_Solid(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; fg: SDL_Color): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderText_Solid_Wrapped(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; fg: SDL_Color; wrapLength: Integer): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderGlyph_Solid(font: PTTF_Font; ch: Uint32; fg: SDL_Color): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderText_Shaded(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; fg: SDL_Color; bg: SDL_Color): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderText_Shaded_Wrapped(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; fg: SDL_Color; bg: SDL_Color; wrap_width: Integer): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderGlyph_Shaded(font: PTTF_Font; ch: Uint32; fg: SDL_Color; bg: SDL_Color): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderText_Blended(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; fg: SDL_Color): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderText_Blended_Wrapped(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; fg: SDL_Color; wrap_width: Integer): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderGlyph_Blended(font: PTTF_Font; ch: Uint32; fg: SDL_Color): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderText_LCD(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; fg: SDL_Color; bg: SDL_Color): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderText_LCD_Wrapped(font: PTTF_Font; text: PUTF8Char; length: NativeUInt; fg: SDL_Color; bg: SDL_Color; wrap_width: Integer): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_RenderGlyph_LCD(font: PTTF_Font; ch: Uint32; fg: SDL_Color; bg: SDL_Color): PSDL_Surface; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_CreateSurfaceTextEngine: PTTF_TextEngine; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_DrawSurfaceText(text: PTTF_Text; x: Integer; y: Integer; surface: PSDL_Surface): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_DestroySurfaceTextEngine(engine: PTTF_TextEngine); cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_CreateRendererTextEngine(renderer: PSDL_Renderer): PTTF_TextEngine; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_CreateRendererTextEngineWithProperties(props: SDL_PropertiesID): PTTF_TextEngine; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_DrawRendererText(text: PTTF_Text; x: Single; y: Single): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_DestroyRendererTextEngine(engine: PTTF_TextEngine); cdecl;
  external SDL_TTF_LIB_NAME;
{ skipped TTF_CreateGPUTextEngine -- GPU text engine }
{ skipped TTF_CreateGPUTextEngineWithProperties -- GPU text engine }
{ skipped TTF_GetGPUTextDrawData -- GPU text engine }
{ skipped TTF_DestroyGPUTextEngine -- GPU text engine }
{ skipped TTF_SetGPUTextEngineWinding -- GPU text engine }
{ skipped TTF_GetGPUTextEngineWinding -- GPU text engine }
function TTF_CreateText(engine: PTTF_TextEngine; font: PTTF_Font; text: PUTF8Char; length: NativeUInt): PTTF_Text; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextProperties(text: PTTF_Text): SDL_PropertiesID; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextEngine(text: PTTF_Text; engine: PTTF_TextEngine): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextEngine(text: PTTF_Text): PTTF_TextEngine; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextFont(text: PTTF_Text; font: PTTF_Font): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextFont(text: PTTF_Text): PTTF_Font; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextDirection(text: PTTF_Text; direction: TTF_Direction): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextDirection(text: PTTF_Text): TTF_Direction; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextScript(text: PTTF_Text; script: Uint32): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextScript(text: PTTF_Text): Uint32; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextColor(text: PTTF_Text; r: Uint8; g: Uint8; b: Uint8; a: Uint8): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextColorFloat(text: PTTF_Text; r: Single; g: Single; b: Single; a: Single): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextColor(text: PTTF_Text; r: PUint8; g: PUint8; b: PUint8; a: PUint8): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextColorFloat(text: PTTF_Text; r: PSingle; g: PSingle; b: PSingle; a: PSingle): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextPosition(text: PTTF_Text; x: Integer; y: Integer): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextPosition(text: PTTF_Text; x: PInteger; y: PInteger): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextWrapWidth(text: PTTF_Text; wrap_width: Integer): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextWrapWidth(text: PTTF_Text; wrap_width: PInteger): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextWrapWhitespaceVisible(text: PTTF_Text; visible: Boolean): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_TextWrapWhitespaceVisible(text: PTTF_Text): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_SetTextString(text: PTTF_Text; string_: PUTF8Char; length: NativeUInt): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_InsertTextString(text: PTTF_Text; offset: Integer; string_: PUTF8Char; length: NativeUInt): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_AppendTextString(text: PTTF_Text; string_: PUTF8Char; length: NativeUInt): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_DeleteTextString(text: PTTF_Text; offset: Integer; length: Integer): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextSize(text: PTTF_Text; w: PInteger; h: PInteger): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextSubString(text: PTTF_Text; offset: Integer; substring: PTTF_SubString): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextSubStringForLine(text: PTTF_Text; line: Integer; substring: PTTF_SubString): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextSubStringsForRange(text: PTTF_Text; offset: Integer; length: Integer; count: PInteger): PPTTF_SubString; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetTextSubStringForPoint(text: PTTF_Text; x: Integer; y: Integer; substring: PTTF_SubString): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetPreviousTextSubString(text: PTTF_Text; substring: PTTF_SubString; previous: PTTF_SubString): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_GetNextTextSubString(text: PTTF_Text; substring: PTTF_SubString; next: PTTF_SubString): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_UpdateText(text: PTTF_Text): Boolean; cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_DestroyText(text: PTTF_Text); cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_CloseFont(font: PTTF_Font); cdecl;
  external SDL_TTF_LIB_NAME;
procedure TTF_Quit; cdecl;
  external SDL_TTF_LIB_NAME;
function TTF_WasInit: Integer; cdecl;
  external SDL_TTF_LIB_NAME;
