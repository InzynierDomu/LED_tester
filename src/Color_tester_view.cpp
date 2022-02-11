#include "Color_tester_view.h"

namespace Color_tester
{

Color_tester_view::Color_tester_view(Hal& hal, Color_tester_model& model)
: m_model(model)
, m_hal(hal)
, m_cursor_position_x{76, 126, 176}
, m_shift_from_cursor(6)
{}

Color_tester_view::~Color_tester_view() {}

void Color_tester_view::print_screen()
{
  auto screen = m_hal.get_screen();

  screen.fillScreen(TFT_WHITE);

  screen.fillCircle(36, m_cursor_position_x[static_cast<Cursor_position_name>(m_model.position)], 6, TFT_RED);

  screen.drawString("R", 50, 70);
  screen.drawString("G", 50, 120);
  screen.drawString("B", 50, 170);

  screen.drawRect(199, 79, 82, 82, TFT_BLACK);

  print_color(0);
  print_color(1);
  print_color(2);

  update_color();
}

/**
 * @brief print color saturation
 */
void Color_tester_view::update_color_saturation()
{
  m_hal.get_screen().fillRect(90, m_cursor_position_x[m_model.position] - m_shift_from_cursor, 60, 20, TFT_WHITE);
  print_color(m_model.position);
  update_color();
}

/**
 * @brief print 32bits color on screen
 */
void Color_tester_view::update_color()
{
  auto screen = m_hal.get_screen();
  screen.fillRect(200, 80, 80, 80, m_model.color.color_short);
  screen.fillRect(179, 170, 130, 22, TFT_WHITE);
  String color_description = String(m_model.color.color_long, HEX);
  color_description.toUpperCase();
  screen.drawString("0x" + color_description, 179, 170);
}

void Color_tester_view::update_cursor()
{
  auto screen = m_hal.get_screen();
  screen.fillRect(30, 70, 13, 240, TFT_WHITE);
  screen.fillCircle(36, m_cursor_position_x[static_cast<Cursor_position_name>(m_model.position)], 6, TFT_RED);
}

void Color_tester_view::print_color(uint8_t position)
{
  m_hal.get_screen().drawString(
      String(m_model.color.color_saturation[position]), 90, m_cursor_position_x[position] - m_shift_from_cursor);
}

} // namespace Color_tester