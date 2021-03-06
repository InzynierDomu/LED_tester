/**
 * @file IHal.h
 * @brief interface hardware control
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

#include <stdint.h>
#include <string>

///< possible joystick cursor moves
enum class Cursor_move
{
  up,
  down,
  left,
  right,
  center
};

///< modes which device possible running
enum class Mode
{
  ws_color_tester,
  pwm_generator,
  characteristic_tester
};

class IController;

using callback_cursor_move = void (IController::*)(Cursor_move);

class IHal
{
  public:
  virtual ~IHal() {}
  virtual void init() = 0;
  virtual void clear_screen() = 0;
  virtual void clear_part_screen(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height) = 0;
  virtual void clear_cursor(const uint16_t position_x, const uint16_t position_y) = 0;
  virtual void clear_chart_cursor(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght) = 0;
  virtual void print_text(const std::string& text, const uint16_t position_x, const uint16_t position_y) = 0;
  virtual void draw_cursor(const uint16_t position_x, const uint16_t position_y) = 0;
  virtual void draw_chart_cursor(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght) = 0;
  virtual void draw_frame(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height) = 0;
  virtual void draw_rect(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height,
                         const uint16_t color) = 0;
  virtual void draw_gradient_circle(const uint16_t position_x, const uint16_t position_y, const uint16_t radius, const uint16_t value) = 0;
  virtual void draw_chart_axes(const uint16_t position_x, const uint16_t position_y, const uint16_t size, const std::string& x_axis_name,
                               const std::string& y_axis_name) = 0;
  virtual void draw_point(const uint16_t position_x, const uint16_t position_y) = 0;
  virtual void set_color_rgb(const uint32_t color) = 0;
  virtual void set_PWM_output(const uint16_t duty) = 0;
  virtual void check_button() = 0;
  virtual bool check_button_mode(Mode& mode) = 0;
  virtual void set_keyboard_callback(callback_cursor_move callback, IController* controller) = 0;
  virtual void wait() = 0;
};
