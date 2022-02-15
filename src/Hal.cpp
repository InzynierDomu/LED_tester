#include "Hal.h"

#include "Free_Fonts.h"

Hal::Hal()
: m_ws_leds{m_led_ws_count, m_led_ws_pin, NEO_GRB + NEO_KHZ800}
{}

Hal::~Hal() {}

void Hal::init()
{
  pinMode(WIO_5S_UP, INPUT);
  pinMode(WIO_5S_DOWN, INPUT);
  pinMode(WIO_5S_LEFT, INPUT);
  pinMode(WIO_5S_RIGHT, INPUT);

  m_screen.begin();
  m_screen.setRotation(3);

  m_screen.setFreeFont(&FreeSansBold12pt7b);
  m_screen.setTextColor(TFT_BLACK);
  m_ws_leds.begin();
}

TFT_eSPI& Hal::get_screen()
{
  return m_screen;
}

void Hal::set_color_rgb(uint32_t color)
{
  m_ws_leds.setPixelColor(0, color);
  m_ws_leds.show();
}

void Hal::check_button()
{
  if (digitalRead(WIO_5S_DOWN) == LOW)
  {
    (m_controller->*m_callback)(Cursor_move::down);
    delay(200);
  }
  if (digitalRead(WIO_5S_UP) == LOW)
  {
    (m_controller->*m_callback)(Cursor_move::up);
    delay(200);
  }
  if (digitalRead(WIO_5S_RIGHT) == LOW)
  {
    (m_controller->*m_callback)(Cursor_move::right);
    delay(100);
  }
  if (digitalRead(WIO_5S_LEFT) == LOW)
  {
    (m_controller->*m_callback)(Cursor_move::left);
    delay(100);
  }
}

void Hal::set_keyboard_callback(/*void (Controller::*callback)(Cursor_move)*/callback_cursor_move callback, Controller* controller)
{
  m_callback = callback;
  m_controller = controller;
}