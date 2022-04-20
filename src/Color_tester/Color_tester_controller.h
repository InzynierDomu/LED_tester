#pragma once

#include "Color_tester_model.h"
#include "IColor_tester_view.h"
#include "IController.h"
#include "IHal.h"

#include <stdint.h>

namespace Color_tester
{

class Color_tester_controller : public IController
{
  public:
  Color_tester_controller(IHal& hal, Color_tester_model& model, IColor_tester_view* view);
  ~Color_tester_controller();
  // Color_tester_controller& operator=(const Color_tester_controller& other);

  void active() override;
  void keyboar_reaction(Cursor_move move) override;

  private:
  Color_tester_controller(const Color_tester_controller&);
  uint16_t color16(uint8_t* colors_saturation);
  uint32_t color32(uint8_t* colors_saturation);
  void change_color(Cursor_move move);
  void move_cursor(Cursor_move move);
  uint8_t map(uint8_t x, uint8_t in_min, uint8_t in_max, uint8_t out_min, uint8_t out_max);

  IHal& m_hal;
  Color_tester_model& m_model;
  IColor_tester_view* m_view;
};

} // namespace Color_tester