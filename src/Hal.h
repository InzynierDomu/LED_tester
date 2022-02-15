#pragma once

#include "IHal.h"

class Hal : public IHal
{
  public:
  Hal();
  ~Hal();

  void init() override;
  TFT_eSPI& get_screen() override;
  void set_color_rgb(uint32_t color) override;
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