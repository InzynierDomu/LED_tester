#pragma once

#include "IController.h"
#include "PWM_model.h"
#include "PWM_view.h"

namespace PWM
{

class PWM_controller : public IController
{
  public:
  PWM_controller(IHal& hal, PWM_model& model, PWM_view* view);
  ~PWM_controller();

  void active() override;
  void keyboar_reaction(Cursor_move move) override;

  private:
  IHal& m_hal;
  PWM_model& m_model;
  PWM_view* m_view;
};

} // namespace PWM