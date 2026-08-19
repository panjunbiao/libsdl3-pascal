{ SDL_locale.inc -- 1-to-1 from SDL_locale.h }

type
  PSDL_Locale = ^SDL_Locale;
  PPSDL_Locale = ^PSDL_Locale;
  SDL_Locale = record
    language: PUTF8Char;
    country: PUTF8Char;
  end;

function SDL_GetPreferredLocales(count: PInteger): PPSDL_Locale; cdecl;
  external SDL_LIB_NAME;
