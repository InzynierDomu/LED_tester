/**
 * @file PWM_chart_controller.h
 * @brief controller for change of PWM in time characteristics mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

#include "../IController.h"
#include "IHal.h"
#include "IPWM_chart_view.h"
#include "PWM_chart_model.h"

#include <memory>

namespace PWM_chart
{

class PWM_chart_controller : public IController
{
  public:
  PWM_chart_controller(IHal& hal, PWM_chart_model& model, std::shared_ptr<IPWM_chart_view> view);
  ~PWM_chart_controller();

  void active() override;
  void keyboar_reaction(Cursor_move move) override;

  private:
  void move_cursor(Cursor_move move);
  void move_pwm_cursor(Cursor_move move);
  void run_pwm_fun();

  IHal& m_hal; ///< hardware layer
  PWM_chart_model& m_model; ///< data model
  std::shared_ptr<IPWM_chart_view> m_view; ///< view
};

} // namespace PWM_chart