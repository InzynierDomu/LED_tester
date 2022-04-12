#pragma once

#include "IHal.h"
#include "IPWM_view.h"
#include "PWM_model.h"

namespace PWM
{

class PWM_view : public IPWM_view
{
  public:
  PWM_view(IHal& hal, PWM_model& model);

  void print_screen() override;
  void update_duty() override;

  private:
  void print_pwm_duty();

  IHal& m_hal;
  PWM_model& m_model;
};

} // namespace PWM
