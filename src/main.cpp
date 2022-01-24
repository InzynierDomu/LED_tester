#include "Adafruit_NeoPixel.h"
#include "Free_Fonts.h"
#include "Seeed_FS.h"
#include "TFT_eSPI.h"

#include <Arduino.h>

const uint8_t m_led_ws = BCM27;
const uint8_t m_led_ws_count = 1;

TFT_eSPI m_screen;
Adafruit_NeoPixel m_ws_leds(m_led_ws_count, m_led_ws, NEO_GRB + NEO_KHZ800);

enum class Mode
{
  ws_color_tester,
  pwm_generator,
  characteristic_tester
};

enum Cursor_move
{
  up,
  down,
  left,
  right
};

enum Cursor_position_name
{
  r = 0,
  g,
  b
};

Mode m_mode = Mode::ws_color_tester;

const int m_shift_from_cursor = 6;

const int m_cursor_position_x[3]{76, 126, 176};
int m_color_saturation[3]{255, 255, 255};

Cursor_position_name m_position = Cursor_position_name::r;

uint16_t color16()
{
  uint8_t r = map(m_color_saturation[0], 0, 255, 0, 31);
  uint8_t g = map(m_color_saturation[1], 0, 255, 0, 63);
  uint8_t b = map(m_color_saturation[2], 0, 255, 0, 31);
  uint16_t color = b;
  color += r << 11;
  color += g << 5;
  return color;
}

void update_color()
{
  uint32_t color = Adafruit_NeoPixel::Color(m_color_saturation[0], m_color_saturation[1], m_color_saturation[2]);

  m_screen.fillRect(200, 80, 80, 80, color16());
  m_screen.fillRect(179, 170, 130, 22, TFT_WHITE);
  String color_description = String(color, HEX);
  color_description.toUpperCase();
  m_screen.drawString("0x" + color_description, 179, 170);
  m_ws_leds.setPixelColor(0, color);
  m_ws_leds.show();
}

void print_color_saturation(Cursor_position_name position)
{
  m_screen.fillRect(90, m_cursor_position_x[position] - m_shift_from_cursor, 60, 20, TFT_WHITE);
  m_screen.drawString(String(m_color_saturation[position]), 90, m_cursor_position_x[position] - m_shift_from_cursor);
}

void change_color(Cursor_move move)
{
  if (move == Cursor_move::right && m_color_saturation[m_position] < 255)
  {
    m_color_saturation[m_position]++;
  }
  else if (move == Cursor_move::left && m_color_saturation[m_position] > 0)
  {
    m_color_saturation[m_position]--;
  }

  print_color_saturation(m_position);
  update_color();
}

void move_cursor(Cursor_move move)
{
  m_screen.fillRect(30, 70, 13, 240, TFT_WHITE);
  if (move == Cursor_move::up)
  {
    if (m_position == Cursor_position_name::r)
    {
      m_position = Cursor_position_name::b;
    }
    else
    {
      m_position = static_cast<Cursor_position_name>(m_position - 1);
    }
  }
  else if (move == Cursor_move::down)
  {
    if (m_position == Cursor_position_name::b)
    {
      m_position = Cursor_position_name::r;
    }
    else
    {
      m_position = static_cast<Cursor_position_name>(m_position + 1);
    }
  }

  m_screen.fillCircle(36, m_cursor_position_x[static_cast<Cursor_position_name>(m_position)], 6, TFT_RED);
}

void ws_color_tester_screen()
{
  m_screen.fillRect(0, 0, 320, 240, TFT_WHITE);

  m_screen.fillCircle(36, m_cursor_position_x[static_cast<Cursor_position_name>(m_position)], 6, TFT_RED);

  m_screen.drawString("R", 50, 70);
  m_screen.drawString("G", 50, 120);
  m_screen.drawString("B", 50, 170);

  m_screen.drawRect(199, 79, 82, 82, TFT_BLACK);

  print_color_saturation(Cursor_position_name::r);
  print_color_saturation(Cursor_position_name::g);
  print_color_saturation(Cursor_position_name::b);

  update_color();
}

void ws_color_tester_keyboard()
{
  if (digitalRead(WIO_5S_DOWN) == LOW)
  {
    move_cursor(Cursor_move::down);
    delay(200);
  }
  if (digitalRead(WIO_5S_UP) == LOW)
  {
    move_cursor(Cursor_move::up);
    delay(200);
  }
  if (digitalRead(WIO_5S_RIGHT) == LOW)
  {
    change_color(Cursor_move::right);
    delay(100);
  }
  if (digitalRead(WIO_5S_LEFT) == LOW)
  {
    change_color(Cursor_move::left);
    delay(100);
  }
}

void setup()
{

  pinMode(WIO_5S_UP, INPUT);
  pinMode(WIO_5S_DOWN, INPUT);
  pinMode(WIO_5S_LEFT, INPUT);
  pinMode(WIO_5S_RIGHT, INPUT);

  m_screen.begin();
  m_screen.setRotation(3);
  m_screen.fillScreen(TFT_WHITE);

  m_screen.setFreeFont(&FreeSansBold12pt7b);
  m_screen.setTextColor(TFT_BLACK);

  ws_color_tester_screen();

  m_ws_leds.begin();
}

void loop()
{
  switch (m_mode)
  {
    case Mode::ws_color_tester:
      ws_color_tester_keyboard();
      break;

    default:
      break;
  }
}