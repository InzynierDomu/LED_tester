#pragma once

#include "Color_tester_model.h"
#include "Color_tester_view.h"
#include "IController.h"

#include <stdint.h>

namespace Color_tester
{

class Color_tester_controller : public IController
{
  public:
  Color_tester_controller(IHal& hal, Color_tester_model& model, Color_tester_view* view);
  ~Color_tester_controller();

  void active() override;
  void keyboar_reaction(Cursor_move move) override;

  private:
  uint16_t color16(uint8_t* colors_saturation);
  uint32_t color32(uint8_t* colors_saturation);
  void change_color(Cursor_move move);
  void move_cursor(Cursor_move move);

  IHal& m_hal;
  Color_tester_model& m_model;
  Color_tester_view* m_view;
};

} // namespace Color_tester