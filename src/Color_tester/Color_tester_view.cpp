#include "Color_tester_view.h"

namespace Color_tester
{

Color_tester_view::Color_tester_view(Hal& hal, Color_tester_model& model)
: m_model(model)
, m_hal(hal)
, m_cursor_position_x{76, 126, 176}
, m_shift_from_cursor(6)
{}

void Color_tester_view::print_screen()
{
  m_hal.clear_screen();

  m_hal.draw_cursor(36, m_cursor_position_x[static_cast<Cursor_position_name>(m_model.position)]);

  m_hal.print_text("R", 50, 70);
  m_hal.print_text("G", 50, 120);
  m_hal.print_text("B", 50, 170);

  m_hal.draw_frame(199, 79, 82, 82);

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
  m_hal.clear_part_screen(90, m_cursor_position_x[m_model.position] - m_shift_from_cursor, 60, 20);
  print_color(m_model.position);
  update_color();
}

/**
 * @brief print 32bits color on screen
 */
void Color_tester_view::update_color()
{
  m_hal.draw_rect(200, 80, 80, 80, m_model.color.color_short);
  m_hal.clear_part_screen(179, 170, 130, 22);
  String color_description = String(m_model.color.color_long, HEX);
  color_description.toUpperCase();
  m_hal.print_text("0x" + color_description, 179, 170);
}

void Color_tester_view::update_cursor()
{
  m_hal.clear_part_screen(30, 70, 13, 240);
  m_hal.draw_cursor(36, m_cursor_position_x[static_cast<Cursor_position_name>(m_model.position)]);
}

void Color_tester_view::print_color(uint8_t position)
{
  m_hal.print_text(String(m_model.color.color_saturation[position]), 90, m_cursor_position_x[position] - m_shift_from_cursor);
}

} // namespace Color_tester