{ SDL_hidapi.inc -- 1-to-1 from SDL_hidapi.h (SDL 3.4.14) }

type
  SDL_hid_device = record
  end;
  PSDL_hid_device = ^SDL_hid_device;
  PPSDL_hid_device = ^PSDL_hid_device;
  SDL_hid_bus_type = (
    SDL_HID_API_BUS_UNKNOWN = $00,
    SDL_HID_API_BUS_USB = $01,
    SDL_HID_API_BUS_BLUETOOTH = $02,
    SDL_HID_API_BUS_I2C = $03,
    SDL_HID_API_BUS_SPI = $04
  );
  PSDL_hid_bus_type = ^SDL_hid_bus_type;
  PPSDL_hid_bus_type = ^PSDL_hid_bus_type;
  PSDL_hid_device_info = ^SDL_hid_device_info;
  PPSDL_hid_device_info = ^PSDL_hid_device_info;
  SDL_hid_device_info = record
    path: PUTF8Char;
    vendor_id: Uint16;
    product_id: Uint16;
    serial_number: PWideChar;
    release_number: Uint16;
    manufacturer_string: PWideChar;
    product_string: PWideChar;
    usage_page: Uint16;
    usage: Uint16;
    interface_number: Integer;
    interface_class: Integer;
    interface_subclass: Integer;
    interface_protocol: Integer;
    bus_type: SDL_hid_bus_type;
    next: PSDL_hid_device_info;
  end;

const
  SDL_PROP_HIDAPI_LIBUSB_DEVICE_HANDLE_POINTER = 'SDL.hidapi.libusb.device.handle';

function SDL_hid_init: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_exit: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_device_change_count: Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_enumerate(vendor_id: Uint16; product_id: Uint16): PSDL_hid_device_info; cdecl;
  external SDL_LIB_NAME;
procedure SDL_hid_free_enumeration(devs: PSDL_hid_device_info); cdecl;
  external SDL_LIB_NAME;
function SDL_hid_open(vendor_id: Uint16; product_id: Uint16; serial_number: PWideChar): PSDL_hid_device; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_open_path(path: PUTF8Char): PSDL_hid_device; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_get_properties(dev: PSDL_hid_device): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_write(dev: PSDL_hid_device; data: PUint8; length: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_read_timeout(dev: PSDL_hid_device; data: PUint8; length: NativeUInt; milliseconds: Integer): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_read(dev: PSDL_hid_device; data: PUint8; length: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_set_nonblocking(dev: PSDL_hid_device; nonblock: Integer): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_send_feature_report(dev: PSDL_hid_device; data: PUint8; length: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_get_feature_report(dev: PSDL_hid_device; data: PUint8; length: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_get_input_report(dev: PSDL_hid_device; data: PUint8; length: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_close(dev: PSDL_hid_device): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_get_manufacturer_string(dev: PSDL_hid_device; string_: PWideChar; maxlen: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_get_product_string(dev: PSDL_hid_device; string_: PWideChar; maxlen: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_get_serial_number_string(dev: PSDL_hid_device; string_: PWideChar; maxlen: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_get_indexed_string(dev: PSDL_hid_device; string_index: Integer; string_: PWideChar; maxlen: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_get_device_info(dev: PSDL_hid_device): PSDL_hid_device_info; cdecl;
  external SDL_LIB_NAME;
function SDL_hid_get_report_descriptor(dev: PSDL_hid_device; buf: PUint8; buf_size: NativeUInt): Integer; cdecl;
  external SDL_LIB_NAME;
procedure SDL_hid_ble_scan(active: Boolean); cdecl;
  external SDL_LIB_NAME;
