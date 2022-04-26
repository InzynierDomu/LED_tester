/**
 * @file Hal.cpp
 * @brief hardware control
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#include "Hal.h"

#include "Free_Fonts.h"

/**
 * @brief constructor
 */
Hal::Hal()
: m_ws_leds{Config::led_ws_count, Config::led_ws_pin, NEO_GRB + NEO_KHZ800}
, m_controller(nullptr)
, m_callback(nullptr)
, m_keyboard_blocking_time_ms(100)
{}

/**
 * @brief hardware initialization
 */
void Hal::init()
{
  pinMode(WIO_5S_UP, INPUT);
  pinMode(WIO_5S_DOWN, INPUT);
  pinMode(WIO_5S_LEFT, INPUT);
  pinMode(WIO_5S_RIGHT, INPUT);
  pinMode(WIO_5S_PRESS, INPUT);
  pinMode(WIO_KEY_A, INPUT);
  pinMode(WIO_KEY_B, INPUT);
  pinMode(WIO_KEY_C, INPUT);

  m_screen.begin();
  m_screen.setRotation(3);

  m_screen.setTextColor(TFT_BLACK);
  m_ws_leds.begin();
}

/**
 * @brief clear screen
 */
void Hal::clear_screen()
{
  m_screen.fillScreen(TFT_WHITE);
}

/**
 * @brief clear part of screen
 * @param position_x:
 * @param position_y:
 * @param width:
 * @param height:
 */
void Hal::clear_part_screen(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height)
{
  m_screen.fillRect(position_x, position_y, width, height, TFT_WHITE);
}

/**
 * @brief clear rectangle cursor for menu
 * @param position_x:
 * @param position_y:
 */
void Hal::clear_cursor(const uint16_t position_x, const uint16_t position_y)
{
  m_screen.drawRect(position_x, position_y, 72, 22, TFT_WHITE);
}

/**
 * @brief clear vertical cursor line for chart
 * @param position_x:
 * @param position_y:
 * @param
 */
void Hal::clear_chart_cursor(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght)
{
  m_screen.drawFastVLine(position_x, position_y, lenght, TFT_WHITE);
}

/**
 * @brief print text on screen
 * @param
 * @param position_x:
 * @param position_y:
 */
void Hal::print_text(const std::string& text, const uint16_t position_x, const uint16_t position_y)
{
  m_screen.setFreeFont(&FreeSansBold12pt7b);
  m_screen.drawString(text.c_str(), position_x, position_y);
}

/**
 * @brief dtaw rectangle cursor for menu
 * @param position_x:
 * @param position_y:
 */
void Hal::draw_cursor(const uint16_t position_x, const uint16_t position_y)
{
  m_screen.drawRect(position_x, position_y, 72, 22, TFT_RED);
}

/**
 * @brief
 * @param position_x:
 * @param position_y:
 * @param
 */
void Hal::draw_chart_cursor(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght)
{
  m_screen.drawFastVLine(position_x, position_y, lenght, TFT_RED);
}

/**
 * @brief
 * @param position_x:
 * @param position_y:
 * @param
 * @param
 */
void Hal::draw_frame(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height)
{
  m_screen.drawRect(position_x, position_y, width, height, TFT_BLACK);
}

/**
 * @brief
 * @param position_x:
 * @param position_y:
 * @param
 * @param
 * @param
 */
void Hal::draw_rect(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height, const uint16_t color)
{
  m_screen.fillRect(position_x, position_y, width, height, color);
}

/**
 * @brief
 * @param position_x:
 * @param position_y:
 * @param
 * @param
 */
void Hal::draw_gradient_circle(const uint16_t position_x, const uint16_t position_y, const uint16_t radius, const uint16_t value)
{
  uint8_t max_r = map(value, 0, 255, 0, 31);
  uint8_t max_g = map(value, 0, 255, 0, 63);
  for (uint16_t i = 1; i < radius; i++)
  {
    uint8_t b_on_circle = map(i, radius, 1, 31, 0);
    uint8_t r_on_circle = map(i, radius, 1, 31, max_r);
    uint8_t g_on_circle = map(i, radius, 1, 63, max_g);
    uint16_t color = b_on_circle;
    color += r_on_circle << 11;
    color += g_on_circle << 5;
    m_screen.drawCircle(position_x, position_y, i, color);
  }
}

/**
 * @brief
 * @param position_x:
 * @param position_y:
 * @param
 * @param
 * @param
 */
void Hal::draw_chart_axes(const uint16_t position_x, const uint16_t position_y, const uint16_t size, const std::string& x_axis_name,
                          const std::string& y_axis_name)
{
  m_screen.drawFastVLine(position_x, position_y, size, TFT_BLACK);
  m_screen.drawFastHLine(position_x, position_y + size, size, TFT_BLACK);
  m_screen.drawLine(position_x, position_y, position_x + 3, position_y + 3, TFT_BLACK);
  m_screen.drawLine(position_x, position_y, position_x - 3, position_y + 3, TFT_BLACK);
  m_screen.drawLine(position_x + size, position_y + size, position_x + size - 3, position_y + size + 3, TFT_BLACK);
  m_screen.drawLine(position_x + size, position_y + size, position_x + size - 3, position_y + size - 3, TFT_BLACK);
  m_screen.setFreeFont(&FreeSans9pt7b);
  m_screen.drawString(x_axis_name.c_str(), position_x + size + 2, position_y + size + 3);
  m_screen.drawString(y_axis_name.c_str(), position_x - 15, position_y - 12);
}

/**
 * @brief
 * @param position_x:
 * @param position_y:
 */
void Hal::draw_point(const uint16_t position_x, const uint16_t position_y)
{
  m_screen.drawPixel(position_x, position_y, TFT_BLACK);
}

/**
 * @brief
 * @param
 */
void Hal::set_color_rgb(const uint32_t color)
{
  m_ws_leds.setPixelColor(0, color);
  m_ws_leds.show();
}

/**
 * @brief
 * @param
 */
void Hal::set_PWM_output(const uint16_t duty)
{
  analogWrite(Config::led_pin, duty);
}

/**
 * @brief
 */
void Hal::check_button()
{
  static unsigned long last_loop_time;
  unsigned long loop_time = millis();
  if (loop_time - last_loop_time > m_keyboard_blocking_time_ms)
  {
    if (m_controller != nullptr && m_callback != nullptr)
    {
      if (digitalRead(WIO_5S_DOWN) == LOW)
      {
        (m_controller->*m_callback)(Cursor_move::down);
        last_loop_time = loop_time;
      }
      else if (digitalRead(WIO_5S_UP) == LOW)
      {
        (m_controller->*m_callback)(Cursor_move::up);
        last_loop_time = loop_time;
      }
      else if (digitalRead(WIO_5S_RIGHT) == LOW)
      {
        (m_controller->*m_callback)(Cursor_move::right);
        last_loop_time = loop_time;
      }
      else if (digitalRead(WIO_5S_LEFT) == LOW)
      {
        (m_controller->*m_callback)(Cursor_move::left);
        last_loop_time = loop_time;
      }
      else if (digitalRead(WIO_5S_PRESS) == LOW)
      {
        (m_controller->*m_callback)(Cursor_move::center);
        last_loop_time = loop_time;
      }
    }
  }
}

/**
 * @brief
 * @param
 */
bool Hal::check_button_mode(Mode& mode)
{
  Mode new_mode = mode;
  if (digitalRead(WIO_KEY_A) == LOW)
  {
    new_mode = Mode::characteristic_tester;
  }
  else if (digitalRead(WIO_KEY_B) == LOW)
  {
    new_mode = Mode::pwm_generator;
  }
  else if (digitalRead(WIO_KEY_C) == LOW)
  {
    new_mode = Mode::ws_color_tester;
  }
  else
  {
    return false;
  }

  if (new_mode == mode)
  {
    return false;
  }
  mode = new_mode;
  return true;
}

/**
 * @brief
 * @param
 * @param
 */
void Hal::set_keyboard_callback(callback_cursor_move callback, IController* controller)
{
  m_callback = callback;
  m_controller = controller;
}

/**
 * @brief delay
 */
void Hal::wait()
{
  unsigned long start_time = millis();
  do
  { } while ((start_time + 100) > millis()); }