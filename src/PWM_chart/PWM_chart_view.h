#pragma once

#include "IHal.h"
#include "IPWM_chart_view.h"
#include "PWM_chart_model.h"

namespace PWM_chart
{

class PWM_chart_view : public IPWM_chart_view
{
  public:
  PWM_chart_view(IHal& hal, PWM_chart_model& model);
  void print_screen() override;
  void update_cursor() override;
  void clear_cursor() override;
  void clear_pwm_cursor() override;
  void update_pwm_cursor() override;

  private:
  PWM_chart_view(const PWM_chart_view&);
  void print_chart();
  void print_math_fun();
  void print_math_fun_names();

  IHal& m_hal;
  PWM_chart_model& m_model;
};

} // namespace PWM_chart