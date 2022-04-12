#pragma once

#include "Color_tester_model.h"
#include "IColor_tester_view.h"
#include "IHal.h"

#include <stdint.h>

namespace Color_tester
{

class Color_tester_view : public IColor_tester_view
{
  public:
  Color_tester_view(IHal& hal, Color_tester_model& model);

  void print_screen() override;
  void update_color_saturation() override;
  void update_cursor() override;

  private:
  void update_color();
  void print_color(uint8_t position);

  IHal& m_hal;
  Color_tester_model& m_model;
  const uint16_t m_cursor_position_x[3]; ///< cursor position for colors
  const uint16_t m_shift_from_cursor; ///< difference for position cursor and saturation color value
};

} // namespace Color_tester