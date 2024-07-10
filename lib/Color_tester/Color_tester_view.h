/**
 * @file Color_tester_view.h
 * @brief UI view for color picker mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

#include "Color_tester_model.h"
#include "IColor_tester_view.h"
#include "IHal.h "

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
  void clear_cursor() override;

  private:
  Color_tester_view(const Color_tester_view&);
  void update_color();
  void print_color(uint8_t position);

  IHal& m_hal; ///< hardware layer
  Color_tester_model& m_model; ///< data model
  const uint16_t m_cursor_position_x[3]; ///< cursor position for colors
  const uint16_t m_shift_from_cursor; ///< difference for position cursor and saturation color value
};

} // namespace Color_tester