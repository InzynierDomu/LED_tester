/**
 * @file main.cpp
 * @brief Test device for LED one color, RGB and WS2812
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 01-2022
 */

#include "Adafruit_NeoPixel.h"
#include "Color_tester_controller.h"
#include "Color_tester_model.h"
#include "Color_tester_view.h"
#include "Free_Fonts.h"
#include "Hal.h"
#include "TFT_eSPI.h"

#include <Arduino.h>


// const uint8_t m_led_ws_pin = BCM27; ///< pin for WS2812 LED
// const uint8_t m_led_ws_count = 1; ///< WS2812 LED count

// TFT_eSPI m_screen; ///< TFT screen 320x240
// Adafruit_NeoPixel m_ws_leds(m_led_ws_count, m_led_ws_pin, NEO_GRB + NEO_KHZ800); ///< WS2812 LED

Hal m_hal;
Color_tester::Color_tester_model m_color_tester_model;
Color_tester::Color_tester_view m_color_tester_view(m_hal, m_color_tester_model);
Color_tester::Color_tester_controller m_color_tester_controller(m_hal, m_color_tester_model, m_color_tester_view);

///< modes which device possible running
enum class Mode
{
  ws_color_tester,
  pwm_generator,
  characteristic_tester
};

///< color name for cursor positions
// enum Cursor_position_name
// {
//   r = 0,
//   g,
//   b
// };

Mode m_mode = Mode::ws_color_tester; ///< mode which device current running

// const uint16_t m_shift_from_cursor = 6; ///< difference for position cursor and saturation color value
// const uint16_t m_cursor_position_x[3]{76, 126, 176}; ///< cursor position for colors

// uint8_t m_color_saturation[3]{255, 255, 255}; ///< rgb saturation color values

// Cursor_position_name m_position = Cursor_position_name::r; ///< current color to posible change saturation value

/**
 * @brief convert rgb 8bits colors saturation table to 16bits
 * @return rgb color in 16bits format
 */
// uint16_t color16()
// {
//   uint8_t r = map(m_color_saturation[0], 0, 255, 0, 31);
//   uint8_t g = map(m_color_saturation[1], 0, 255, 0, 63);
//   uint8_t b = map(m_color_saturation[2], 0, 255, 0, 31);
//   uint16_t color = b;
//   color += r << 11;
//   color += g << 5;
//   return color;
// }

/**
 * @brief print 32bits color on screen
 */
// void update_color()
// {
//   uint32_t color = Adafruit_NeoPixel::Color(m_color_saturation[0], m_color_saturation[1], m_color_saturation[2]);

//   m_screen.fillRect(200, 80, 80, 80, color16());
//   m_screen.fillRect(179, 170, 130, 22, TFT_WHITE);
//   String color_description = String(color, HEX);
//   color_description.toUpperCase();
//   m_screen.drawString("0x" + color_description, 179, 170);
//   m_ws_leds.setPixelColor(0, color);
//   m_ws_leds.show();
// }

/**
 * @brief print color saturation
 * @param position which color will be print
 */
// void print_color_saturation(Cursor_position_name position)
// {
//   m_screen.fillRect(90, m_cursor_position_x[position] - m_shift_from_cursor, 60, 20, TFT_WHITE);
//   m_screen.drawString(String(m_color_saturation[position]), 90, m_cursor_position_x[position] - m_shift_from_cursor);
// }

/**
 * @brief change color saturation
 * @param move increase or decrease value
 */
// void change_color(Cursor_move move)
// {
//   if (move == Cursor_move::right && m_color_saturation[m_position] < 255)
//   {
//     m_color_saturation[m_position]++;
//   }
//   else if (move == Cursor_move::left && m_color_saturation[m_position] > 0)
//   {
//     m_color_saturation[m_position]--;
//   }

//   print_color_saturation(m_position);
//   update_color();
// }

/**
 * @brief moving circle cursor between colors
 * @param move up or down
 */
// void move_cursor(Cursor_move move)
// {
//   m_screen.fillRect(30, 70, 13, 240, TFT_WHITE);
//   if (move == Cursor_move::up)
//   {
//     if (m_position == Cursor_position_name::r)
//     {
//       m_position = Cursor_position_name::b;
//     }
//     else
//     {
//       m_position = static_cast<Cursor_position_name>(m_position - 1);
//     }
//   }
//   else if (move == Cursor_move::down)
//   {
//     if (m_position == Cursor_position_name::b)
//     {
//       m_position = Cursor_position_name::r;
//     }
//     else
//     {
//       m_position = static_cast<Cursor_position_name>(m_position + 1);
//     }
//   }

//   m_screen.fillCircle(36, m_cursor_position_x[static_cast<Cursor_position_name>(m_position)], 6, TFT_RED);
// }

/**
 * @brief print screen for ws color test mode
 */
// void ws_color_tester_screen()
// {
//   m_screen.fillScreen(TFT_WHITE);

//   m_screen.fillCircle(36, m_cursor_position_x[static_cast<Cursor_position_name>(m_position)], 6, TFT_RED);

//   m_screen.drawString("R", 50, 70);
//   m_screen.drawString("G", 50, 120);
//   m_screen.drawString("B", 50, 170);

//   m_screen.drawRect(199, 79, 82, 82, TFT_BLACK);

//   print_color_saturation(Cursor_position_name::r);
//   print_color_saturation(Cursor_position_name::g);
//   print_color_saturation(Cursor_position_name::b);

//   update_color();
// }

/**
 * @brief reaction for keyboard in ws color test mode
 */
// void ws_color_tester_keyboard()
// {
//   if (digitalRead(WIO_5S_DOWN) == LOW)
//   {
//     move_cursor(Cursor_move::down);
//     delay(200);
//   }
//   if (digitalRead(WIO_5S_UP) == LOW)
//   {
//     move_cursor(Cursor_move::up);
//     delay(200);
//   }
//   if (digitalRead(WIO_5S_RIGHT) == LOW)
//   {
//     change_color(Cursor_move::right);
//     delay(100);
//   }
//   if (digitalRead(WIO_5S_LEFT) == LOW)
//   {
//     change_color(Cursor_move::left);
//     delay(100);
//   }
// }

/**
 * @brief setup
 */
void setup()
{
  // pinMode(WIO_5S_UP, INPUT);
  // pinMode(WIO_5S_DOWN, INPUT);
  // pinMode(WIO_5S_LEFT, INPUT);
  // pinMode(WIO_5S_RIGHT, INPUT);

  // m_screen.begin();
  // m_screen.setRotation(3);

  // m_screen.setFreeFont(&FreeSansBold12pt7b);
  // m_screen.setTextColor(TFT_BLACK);

  // ws_color_tester_screen();

  // m_ws_leds.begin();
  // m_hal = Hal();
  m_hal.init();
  m_color_tester_controller.active();
  
}

/**
 * @brief main loop
 */
void loop()
{
  m_hal.check_button();
  switch (m_mode)
  {
    case Mode::ws_color_tester:
      // ws_color_tester_keyboard();
      break;
    // TODO: add other modes
    default:
      break;
  }
}