/**
 * @file Color_tester_view.cpp
 * @brief UI view for color picker mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#include "Color_tester_view.h"

#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>

namespace Color_tester
{

/**
 * @brief constructor
 * @param hal: hardware layer
 * @param model: data related to PWM characteristics mode
 */
Color_tester_view::Color_tester_view(IHal& hal, Color_tester_model& model)
: m_hal(hal)
, m_model(model)
, m_cursor_position_x{70, 120, 170}
, m_shift_from_cursor(2)
{}

/**
 * @brief print all for this mode after changing mode
 */
void Color_tester_view::print_screen()
{
  m_hal.clear_screen();

  m_hal.draw_cursor(58, m_cursor_position_x[static_cast<Cursor_position_name>(m_model.position)] - m_shift_from_cursor);

  m_hal.print_text("R", 60, 70);
  m_hal.print_text("G", 60, 120);
  m_hal.print_text("B", 60, 170);

  m_hal.draw_frame(199, 79, 82, 82);

  print_color(0);
  print_color(1);
  print_color(2);

  update_color();
}

/**
 * @brief clear and print color saturation
 */
void Color_tester_view::update_color_saturation()
{
  m_hal.clear_part_screen(85, m_cursor_position_x[m_model.position], 42, 19);
  print_color(m_model.position);
  update_color();
}

/**
 * @brief draw rectangle cursor on current color
 */
void Color_tester_view::update_cursor()
{
  m_hal.draw_cursor(58, m_cursor_position_x[static_cast<Cursor_position_name>(m_model.position)] - m_shift_from_cursor);
}

/**
 * @brief clear rectangle cursor
 */
void Color_tester_view::clear_cursor()
{
  m_hal.clear_cursor(58, m_cursor_position_x[static_cast<Cursor_position_name>(m_model.position)] - m_shift_from_cursor);
}

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

void Color_tester_view::print_color(uint8_t position)
{
  std::string color_val = std::to_string(m_model.color.color_saturation[position]);
  m_hal.print_text(color_val, 85, m_cursor_position_x[position]);
}

} // namespace Color_tester