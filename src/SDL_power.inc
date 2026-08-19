{ SDL_power.inc -- 1-to-1 from SDL_power.h (needed by joystick battery events). }

type
  SDL_PowerState = (
    SDL_POWERSTATE_ERROR = -1,
    SDL_POWERSTATE_UNKNOWN,
    SDL_POWERSTATE_ON_BATTERY,
    SDL_POWERSTATE_NO_BATTERY,
    SDL_POWERSTATE_CHARGING,
    SDL_POWERSTATE_CHARGED
  );

function SDL_GetPowerInfo(seconds, percent: PInteger): SDL_PowerState; cdecl;
  external SDL_LIB_NAME;
