#pragma once

#include "Adafruit_NeoPixel.h"
#include "Config.h"
#include "IHal.h"
#include "TFT_eSPI.h"

class Hal : public IHal
{
  public:
  Hal();
  ~Hal() = default;

  void init() override;
  void clear_screen() override;
  void clear_part_screen(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height) override;
  void clear_cursor(const uint16_t position_x, const uint16_t position_y) override;
  void clear_chart_cursor(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght) override;
  void print_text(const std::string& text, const uint16_t position_x, const uint16_t position_y) override;
  void draw_cursor(const uint16_t position_x, const uint16_t position_y) override;
  void draw_chart_cursor(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght) override;
  void draw_frame(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height) override;
  void draw_rect(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height,
                 const uint16_t color) override;
  void draw_gradient_circle(const uint16_t position_x, const uint16_t position_y, const uint16_t radius, const uint16_t value) override;
  void draw_chart_axes(const uint16_t position_x, const uint16_t position_y, const uint16_t size, const std::string& x_axis_name,
                       const std::string& y_axis_name) override;
  void draw_point(const uint16_t position_x, const uint16_t position_y) override;
  void set_color_rgb(const uint32_t color) override;
  void set_PWM_output(const uint16_t duty) override;
  void check_button() override;
  bool check_button_mode(Mode& mode) override;
  void set_keyboard_callback(callback_cursor_move callback, IController* controller) override;
  void wait() override;

  private:
  TFT_eSPI m_screen; ///< TFT screen 320x240
  Adafruit_NeoPixel m_ws_leds; ///< WS2812 LED
  callback_cursor_move m_callback;
  IController* m_controller;

  const uint32_t m_keyboard_blocking_time_ms;
};