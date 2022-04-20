#pragma once

#include "IController.h"
#include "IHal.h"
#include "IPWM_chart_view.h"
#include "PWM_chart_model.h"

namespace PWM_chart
{

class PWM_chart_controller : public IController
{
  public:
  PWM_chart_controller(IHal& hal, PWM_chart_model& model, IPWM_chart_view* view);
  ~PWM_chart_controller();

  void active() override;
  void keyboar_reaction(Cursor_move move) override;

  private:
  IHal& m_hal;
  PWM_chart_model& m_model;
  IPWM_chart_view* m_view;
};

} // namespace PWM_chart