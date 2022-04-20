#include "Hal.h"

#include "Free_Fonts.h"

Hal::Hal()
: m_ws_leds{Config::led_ws_count, Config::led_ws_pin, NEO_GRB + NEO_KHZ800}
, m_controller(nullptr)
, m_callback(nullptr)
, m_keyboard_blocking_time_ms(100)
{}

void Hal::init()
{
  pinMode(WIO_5S_UP, INPUT);
  pinMode(WIO_5S_DOWN, INPUT);
  pinMode(WIO_5S_LEFT, INPUT);
  pinMode(WIO_5S_RIGHT, INPUT);
  pinMode(WIO_KEY_A, INPUT);
  pinMode(WIO_KEY_B, INPUT);
  pinMode(WIO_KEY_C, INPUT);

  m_screen.begin();
  m_screen.setRotation(3);

  m_screen.setFreeFont(&FreeSansBold12pt7b);
  m_screen.setTextColor(TFT_BLACK);
  m_ws_leds.begin();
}

void Hal::clear_screen()
{
  m_screen.fillScreen(TFT_WHITE);
}
void Hal::clear_part_screen(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height)
{
  m_screen.fillRect(position_x, position_y, width, height, TFT_WHITE);
}
void Hal::print_text(const std::string& text, const uint16_t position_x, const uint16_t position_y)
{
  m_screen.drawString(text.c_str(), position_x, position_y);
}
void Hal::draw_cursor(const uint16_t position_x, const uint16_t position_y)
{
  m_screen.fillCircle(position_x, position_y, 6, TFT_RED);
}
void Hal::draw_frame(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height)
{
  m_screen.drawRect(position_x, position_y, width, height, TFT_BLACK);
}
void Hal::draw_rect(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height, const uint16_t color)
{
  m_screen.fillRect(position_x, position_y, width, height, color);
}

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

void Hal::draw_line_vertical(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght) 
{
  m_screen.drawFastVLine(position_x, position_y, lenght, TFT_BLACK);
  //todo: draw arrow
}

void Hal::draw_line_horizontal(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght) 
{
  m_screen.drawFastHLine(position_x, position_y, lenght, TFT_BLACK);
  //todo: draw arrow
}

void Hal::draw_point(const uint16_t position_x, const uint16_t position_y)
{
  m_screen.drawPixel(position_x, position_y, TFT_BLACK);
}

void Hal::set_color_rgb(const uint32_t color)
{
  m_ws_leds.setPixelColor(0, color);
  m_ws_leds.show();
}

void Hal::set_PWM_output(const uint16_t duty)
{
  analogWrite(Config::led_pin, duty);
}

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
    }
  }
}

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

void Hal::set_keyboard_callback(callback_cursor_move callback, IController* controller)
{
  m_callback = callback;
  m_controller = controller;
}