#pragma once

#include "Adafruit_NeoPixel.h"
#include "TFT_eSPI.h"

///< possible joystick cursor moves
enum class Cursor_move
{
  up,
  down,
  left,
  right
};

class Controller;

using callback_cursor_move = void (Controller::*)(Cursor_move);

class IHal
{
  public:
  virtual ~IHal() {}
  virtual void init() = 0;
  virtual TFT_eSPI& get_screen() = 0;
  virtual void set_color_rgb(uint32_t color) = 0;
  virtual void check_button() = 0;
  virtual void set_keyboard_callback(callback_cursor_move callback, Controller* controller) = 0;
};
