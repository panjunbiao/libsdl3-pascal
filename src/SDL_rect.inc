{ SDL_rect.inc -- types and exported functions from SDL_rect.h }

type
  PSDL_Point = ^SDL_Point;
  SDL_Point = record
    x: Integer;
    y: Integer;
  end;

  PSDL_FPoint = ^SDL_FPoint;
  SDL_FPoint = record
    x: Single;
    y: Single;
  end;

  PSDL_Rect = ^SDL_Rect;
  SDL_Rect = record
    x, y: Integer;
    w, h: Integer;
  end;

  PSDL_FRect = ^SDL_FRect;
  SDL_FRect = record
    x: Single;
    y: Single;
    w: Single;
    h: Single;
  end;

procedure SDL_RectToFRect(const rect: PSDL_Rect; frect: PSDL_FRect);
function SDL_PointInRect(const p: PSDL_Point; const r: PSDL_Rect): Boolean;
function SDL_RectEmpty(const r: PSDL_Rect): Boolean;
function SDL_RectsEqual(const a, b: PSDL_Rect): Boolean;
function SDL_PointInRectFloat(const p: PSDL_FPoint; const r: PSDL_FRect): Boolean;
function SDL_RectEmptyFloat(const r: PSDL_FRect): Boolean;

function SDL_HasRectIntersection(const A, B: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRectIntersection(const A, B: PSDL_Rect; result_: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRectUnion(const A, B: PSDL_Rect; result_: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRectEnclosingPoints(const points: PSDL_Point; count: Integer; const clip: PSDL_Rect; result_: PSDL_Rect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRectAndLineIntersection(const rect: PSDL_Rect; X1, Y1, X2, Y2: PInteger): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_HasRectIntersectionFloat(const A, B: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRectIntersectionFloat(const A, B: PSDL_FRect; result_: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRectUnionFloat(const A, B: PSDL_FRect; result_: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRectEnclosingPointsFloat(const points: PSDL_FPoint; count: Integer; const clip: PSDL_FRect; result_: PSDL_FRect): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetRectAndLineIntersectionFloat(const rect: PSDL_FRect; X1, Y1, X2, Y2: PSingle): Boolean; cdecl;
  external SDL_LIB_NAME;
