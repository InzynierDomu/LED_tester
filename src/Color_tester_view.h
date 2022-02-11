#pragma once

#include "Color_tester_model.h"
#include "Free_Fonts.h"
#include "Hal.h"

#include <stdint.h>

namespace Color_tester
{

class Color_tester_view
{
  public:
  Color_tester_view(Hal& hal, Color_tester_model& model);
  ~Color_tester_view();
  void print_screen();
  void update_color_saturation();
  void update_cursor();

  private:
  void update_color();
  void print_color(uint8_t position);
  const uint16_t m_cursor_position_x[3]; ///< cursor position for colors
  const uint16_t m_shift_from_cursor; ///< difference for position cursor and saturation color value

  Color_tester_model& m_model;
  Hal& m_hal;
};

} // namespace Color_tester