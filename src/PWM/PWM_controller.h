/**
 * @file PWM_controller.h
 * @brief Controller for manual pwm control mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

#include "IController.h"
#include "IPWM_view.h"
#include "PWM_model.h"

namespace PWM
{

class PWM_controller : public IController
{
  public:
  PWM_controller(IHal& hal, PWM_model& model, IPWM_view* view);
  ~PWM_controller();

  void active() override;
  void keyboar_reaction(Cursor_move move) override;

  private:
  PWM_controller(const PWM_controller&);

  IHal& m_hal; ///< hardware layer
  PWM_model& m_model; ///< data model
  IPWM_view* m_view; ///< view
};

} // namespace PWM