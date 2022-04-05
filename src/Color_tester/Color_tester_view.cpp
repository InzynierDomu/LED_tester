#include "Color_tester_view.h"

#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>

namespace Color_tester
{

Color_tester_view::Color_tester_view(IHal& hal, Color_tester_model& model)
: m_hal(hal)
, m_model(model)
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
  std::string color_val = "0x";
  std::stringstream stream;
  stream << std::setfill('0') << std::setw(6) << std::uppercase << std::hex << m_model.color.color_long;
  color_val += stream.str();
  m_hal.print_text(color_val, 179, 170);
}

void Color_tester_view::update_cursor()
{
  m_hal.clear_part_screen(30, 70, 13, 240);
  m_hal.draw_cursor(36, m_cursor_position_x[static_cast<Cursor_position_name>(m_model.position)]);
}

void Color_tester_view::print_color(uint8_t position)
{
  std::string color_val = std::to_string(m_model.color.color_saturation[position]);
  m_hal.print_text(color_val, 90, m_cursor_position_x[position] - m_shift_from_cursor);
}

} // namespace Color_tester