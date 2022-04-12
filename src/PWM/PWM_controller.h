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
  IHal& m_hal;
  PWM_model& m_model;
  IPWM_view* m_view;
};

} // namespace PWM