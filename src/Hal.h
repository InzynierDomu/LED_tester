#pragma once

#include "Adafruit_NeoPixel.h"
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
  void print_text(const char* text, const uint16_t position_x, const uint16_t position_y) override;
  void draw_cursor(const uint16_t position_x, const uint16_t position_y) override;
  void draw_frame(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height) override;
  void draw_rect(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height,
                 const uint16_t color) override;
  void set_color_rgb(const uint32_t color) override;
  void check_button() override;
  void set_keyboard_callback(callback_cursor_move callback, Controller* controller) override;

  private:
  const uint8_t m_led_ws_pin = BCM27; ///< pin for WS2812 LED
  const uint8_t m_led_ws_count = 1; ///< WS2812 LED count
  callback_cursor_move m_callback;
  Controller* m_controller;

  TFT_eSPI m_screen; ///< TFT screen 320x240
  Adafruit_NeoPixel m_ws_leds; ///< WS2812 LED
};