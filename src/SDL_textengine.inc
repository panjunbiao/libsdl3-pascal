{ SDL_textengine.inc -- 1-to-1 from SDL_textengine.h (SDL_ttf 3.2.2) }
{ Included inside the type section of SDL_ttf.inc: TTF_Text and TTF_TextEngine
  refer to each other, so they must be declared in one type section. }

  TTF_DrawCommand = (
    TTF_DRAW_COMMAND_NOOP,
    TTF_DRAW_COMMAND_FILL,
    TTF_DRAW_COMMAND_COPY
  );

  TTF_FillOperation = record
    cmd: TTF_DrawCommand;
    rect: SDL_Rect;
  end;

  TTF_CopyOperation = record
    cmd: TTF_DrawCommand;
    text_offset: Integer;
    glyph_font: PTTF_Font;
    glyph_index: Uint32;
    src: SDL_Rect;
    dst: SDL_Rect;
    reserved: Pointer;
  end;

  PTTF_DrawOperation = ^TTF_DrawOperation;
  TTF_DrawOperation = record
    case Integer of
      0: (cmd: TTF_DrawCommand);
      1: (fill: TTF_FillOperation);
      2: (copy: TTF_CopyOperation);
  end;

  TTF_TextLayout = record
  end;
  PTTF_TextLayout = ^TTF_TextLayout;

  TTF_TextData = record
    font: PTTF_Font;
    color: SDL_FColor;
    needs_layout_update: Boolean;
    layout: PTTF_TextLayout;
    x: Integer;
    y: Integer;
    w: Integer;
    h: Integer;
    num_ops: Integer;
    ops: PTTF_DrawOperation;
    num_clusters: Integer;
    clusters: PTTF_SubString;
    props: SDL_PropertiesID;
    needs_engine_update: Boolean;
    engine: PTTF_TextEngine;
    engine_text: Pointer;
  end;

  TTF_TextEngine = record
    version: Uint32;
    userdata: Pointer;
    CreateText: function(userdata: Pointer; text: PTTF_Text): Boolean; cdecl;
    DestroyText: procedure(userdata: Pointer; text: PTTF_Text); cdecl;
  end;

procedure SDL_INIT_INTERFACE(engine: PTTF_TextEngine); overload;
