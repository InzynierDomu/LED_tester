#pragma once

#include "Controller.h"
#include "Color_tester_model.h"
#include "Color_tester_view.h"

#include <stdint.h>

namespace Color_tester
{

class Color_tester_controller : public Controller
{
  public:
  Color_tester_controller(Hal& hal, Color_tester_model& model, Color_tester_view& view);
  ~Color_tester_controller();

  void active();
  uint16_t color16(uint8_t* colors_saturation); // todo: move to color struct
  uint32_t color32(uint8_t* colors_saturation); // todo: move to color struct
  void keyboar_reaction(Cursor_move move); // todo: callback do hal

  private:
  void change_color(Cursor_move move);
  void move_cursor(Cursor_move move);

  Hal& m_hal;
  Color_tester_model& m_model;
  Color_tester_view& m_view;
};

} // namespace Color_tester