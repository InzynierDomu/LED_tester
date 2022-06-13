/**
 * @file Color_tester_controller.h
 * @brief Controller for color picker mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

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

  void active() override;
  void keyboar_reaction(Cursor_move move) override;

  private:
  Color_tester_controller(const Color_tester_controller&);
  uint16_t color16(uint8_t* colors_saturation);
  uint32_t color32(uint8_t* colors_saturation);
  void change_color(Cursor_move move);
  void move_cursor(Cursor_move move);
  uint8_t map(const uint8_t x, const uint8_t in_min, const uint8_t in_max, const uint8_t out_min, const uint8_t out_max);

  IHal& m_hal; ///< hardware layer
  Color_tester_model& m_model; ///< data model
  IColor_tester_view* m_view; ///< view
};

} // namespace Color_tester