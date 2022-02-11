#pragma once

#include "Adafruit_NeoPixel.h"
#include "TFT_eSPI.h"
// #include "Color_tester_controller.h"

///< possible joystick cursor moves
enum class Cursor_move
{
  up,
  down,
  left,
  right
};

// namespace Color_tester
// {

// class Color_tester_controller;
// }

class Controller;

class Hal
{
  public:
  Hal();
  ~Hal();

  void init();
  TFT_eSPI& get_screen();
  void set_color_rgb(uint32_t color);
  void check_button(); // todo
  void set_keyboard_callback(void (Controller::*callback)(Cursor_move), Controller* controller);
  // todo: add set claback up/down, left/right, center, reset

  private:
  const uint8_t m_led_ws_pin = BCM27; ///< pin for WS2812 LED
  const uint8_t m_led_ws_count = 1; ///< WS2812 LED count
  void (Controller::*m_callback)(Cursor_move);
  Controller* m_controller;

  TFT_eSPI m_screen; ///< TFT screen 320x240
  Adafruit_NeoPixel m_ws_leds; ///< WS2812 LED
};