#pragma once

#include <stdint.h>

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
  virtual void clear_screen();
  virtual void clear_part_screen(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height) = 0;
  virtual void print_text(const char* text, const uint16_t position_x, const uint16_t position_y) = 0;
  virtual void draw_cursor(const uint16_t position_x, const uint16_t position_y) = 0;
  virtual void draw_frame(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height) = 0;
  virtual void draw_rect(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height,
                         const uint16_t color) = 0;
  virtual void set_color_rgb(const uint32_t color) = 0;
  virtual void check_button() = 0;
  virtual void set_keyboard_callback(callback_cursor_move callback, Controller* controller) = 0;
};
