#pragma once

#include "Color_tester_model.h"
#include "Color_tester_view.h"
#include "Controller.h"

#include <stdint.h>

namespace Color_tester
{

class Color_tester_controller : public Controller
{
  public:
  Color_tester_controller(Hal& hal, Color_tester_model& model, Color_tester_view& view);

  void active();
  void keyboar_reaction(Cursor_move move);

  private:
  uint16_t color16(uint8_t* colors_saturation);
  uint32_t color32(uint8_t* colors_saturation);
  void change_color(Cursor_move move);
  void move_cursor(Cursor_move move);

  Hal& m_hal;
  Color_tester_model& m_model;
  Color_tester_view& m_view;
};

} // namespace Color_tester