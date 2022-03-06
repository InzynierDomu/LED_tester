#pragma once

#ifndef UNIT_TEST
#include "Hal.h"
#endif
#include "Color_tester_model.h"

#include <stdint.h>

namespace Color_tester
{

class Color_tester_view
{
  public:
  Color_tester_view(IHal& hal, Color_tester_model& model);

  void print_screen();
  void update_color_saturation();
  void update_cursor();

  private:
  void update_color();
  void print_color(uint8_t position);

  IHal& m_hal;
  Color_tester_model& m_model;
  const uint16_t m_cursor_position_x[3]; ///< cursor position for colors
  const uint16_t m_shift_from_cursor; ///< difference for position cursor and saturation color value
};

} // namespace Color_tester