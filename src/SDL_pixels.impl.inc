function SDL_PIXELFLAG(format: SDL_PixelFormat): Uint32;
begin
  Result := (Uint32(format) shr 28) and $0F;
end;

function SDL_PIXELORDER(format: SDL_PixelFormat): Uint32;
begin
  Result := (Uint32(format) shr 20) and $0F;
end;

function SDL_PIXELLAYOUT(format: SDL_PixelFormat): Uint32;
begin
  Result := (Uint32(format) shr 16) and $0F;
end;

function SDL_ISPIXELFORMAT_FOURCC(format: SDL_PixelFormat): Boolean;
begin
  Result := (Uint32(format) <> 0) and (SDL_PIXELFLAG(format) <> 1);
end;

function SDL_BITSPERPIXEL(format: SDL_PixelFormat): Uint32;
begin
  if SDL_ISPIXELFORMAT_FOURCC(format) then
    Result := 0
  else
    Result := (Uint32(format) shr 8) and $FF;
end;

function SDL_BYTESPERPIXEL(format: SDL_PixelFormat): Uint32;
begin
  if SDL_ISPIXELFORMAT_FOURCC(format) then
  begin
    if (format = SDL_PIXELFORMAT_YUY2) or (format = SDL_PIXELFORMAT_UYVY) or
       (format = SDL_PIXELFORMAT_YVYU) or (format = SDL_PIXELFORMAT_P010) then
      Result := 2
    else
      Result := 1;
  end
  else
    Result := Uint32(format) and $FF;
end;

function SDL_ISPIXELFORMAT_INDEXED(format: SDL_PixelFormat): Boolean;
begin
  Result := (not SDL_ISPIXELFORMAT_FOURCC(format)) and
    (((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_INDEX1)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_INDEX2)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_INDEX4)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_INDEX8)));
end;

function SDL_ISPIXELFORMAT_PACKED(format: SDL_PixelFormat): Boolean;
begin
  Result := (not SDL_ISPIXELFORMAT_FOURCC(format)) and
    (((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_PACKED8)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_PACKED16)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_PACKED32)));
end;

function SDL_ISPIXELFORMAT_ARRAY(format: SDL_PixelFormat): Boolean;
begin
  Result := (not SDL_ISPIXELFORMAT_FOURCC(format)) and
    (((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_ARRAYU8)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_ARRAYU16)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_ARRAYU32)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_ARRAYF16)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_ARRAYF32)));
end;

function SDL_ISPIXELFORMAT_10BIT(format: SDL_PixelFormat): Boolean;
begin
  Result := (not SDL_ISPIXELFORMAT_FOURCC(format)) and
    ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_PACKED32)) and
    (SDL_PIXELLAYOUT(format) = Uint32(SDL_PACKEDLAYOUT_2101010));
end;

function SDL_ISPIXELFORMAT_FLOAT(format: SDL_PixelFormat): Boolean;
begin
  Result := (not SDL_ISPIXELFORMAT_FOURCC(format)) and
    (((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_ARRAYF16)) or
     ((Uint32(format) shr 24) and $0F = Uint32(SDL_PIXELTYPE_ARRAYF32)));
end;

function SDL_ISPIXELFORMAT_ALPHA(format: SDL_PixelFormat): Boolean;
begin
  Result :=
    (SDL_ISPIXELFORMAT_PACKED(format) and
     ((SDL_PIXELORDER(format) = Uint32(SDL_PACKEDORDER_ARGB)) or
      (SDL_PIXELORDER(format) = Uint32(SDL_PACKEDORDER_RGBA)) or
      (SDL_PIXELORDER(format) = Uint32(SDL_PACKEDORDER_ABGR)) or
      (SDL_PIXELORDER(format) = Uint32(SDL_PACKEDORDER_BGRA)))) or
    (SDL_ISPIXELFORMAT_ARRAY(format) and
     ((SDL_PIXELORDER(format) = Uint32(SDL_ARRAYORDER_ARGB)) or
      (SDL_PIXELORDER(format) = Uint32(SDL_ARRAYORDER_RGBA)) or
      (SDL_PIXELORDER(format) = Uint32(SDL_ARRAYORDER_ABGR)) or
      (SDL_PIXELORDER(format) = Uint32(SDL_ARRAYORDER_BGRA))));
end;

function SDL_DEFINE_PIXELFORMAT(type_, order, layout, bits, bytes: Uint32): SDL_PixelFormat;
begin
  Result := SDL_PixelFormat((1 shl 28) or (type_ shl 24) or (order shl 20) or
    (layout shl 16) or (bits shl 8) or bytes);
end;

function SDL_DEFINE_PIXELFOURCC(A, B, C, D: Uint8): SDL_PixelFormat;
begin
  Result := SDL_PixelFormat(SDL_FOURCC(A, B, C, D));
end;

function SDL_DEFINE_COLORSPACE(type_, range, primaries, transfer, matrix, chroma: Uint32): SDL_Colorspace;
begin
  Result := SDL_Colorspace((type_ shl 28) or (range shl 24) or (chroma shl 20) or
    (primaries shl 10) or (transfer shl 5) or matrix);
end;

function SDL_COLORSPACETYPE(cspace: SDL_Colorspace): SDL_ColorType;
begin
  Result := SDL_ColorType((Uint32(cspace) shr 28) and $0F);
end;

function SDL_COLORSPACERANGE(cspace: SDL_Colorspace): SDL_ColorRange;
begin
  Result := SDL_ColorRange((Uint32(cspace) shr 24) and $0F);
end;

function SDL_COLORSPACECHROMA(cspace: SDL_Colorspace): SDL_ChromaLocation;
begin
  Result := SDL_ChromaLocation((Uint32(cspace) shr 20) and $0F);
end;

function SDL_COLORSPACEPRIMARIES(cspace: SDL_Colorspace): SDL_ColorPrimaries;
begin
  Result := SDL_ColorPrimaries((Uint32(cspace) shr 10) and $1F);
end;

function SDL_COLORSPACETRANSFER(cspace: SDL_Colorspace): SDL_TransferCharacteristics;
begin
  Result := SDL_TransferCharacteristics((Uint32(cspace) shr 5) and $1F);
end;

function SDL_COLORSPACEMATRIX(cspace: SDL_Colorspace): SDL_MatrixCoefficients;
begin
  Result := SDL_MatrixCoefficients(Uint32(cspace) and $1F);
end;

function SDL_ISCOLORSPACE_MATRIX_BT601(cspace: SDL_Colorspace): Boolean;
begin
  Result := (SDL_COLORSPACEMATRIX(cspace) = SDL_MATRIX_COEFFICIENTS_BT601) or
    (SDL_COLORSPACEMATRIX(cspace) = SDL_MATRIX_COEFFICIENTS_BT470BG);
end;

function SDL_ISCOLORSPACE_MATRIX_BT709(cspace: SDL_Colorspace): Boolean;
begin
  Result := SDL_COLORSPACEMATRIX(cspace) = SDL_MATRIX_COEFFICIENTS_BT709;
end;

function SDL_ISCOLORSPACE_MATRIX_BT2020_NCL(cspace: SDL_Colorspace): Boolean;
begin
  Result := SDL_COLORSPACEMATRIX(cspace) = SDL_MATRIX_COEFFICIENTS_BT2020_NCL;
end;

function SDL_ISCOLORSPACE_LIMITED_RANGE(cspace: SDL_Colorspace): Boolean;
begin
  Result := SDL_COLORSPACERANGE(cspace) <> SDL_COLOR_RANGE_FULL;
end;

function SDL_ISCOLORSPACE_FULL_RANGE(cspace: SDL_Colorspace): Boolean;
begin
  Result := SDL_COLORSPACERANGE(cspace) = SDL_COLOR_RANGE_FULL;
end;
