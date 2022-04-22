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
  uint8_t map(uint8_t x, uint8_t in_min, uint8_t in_max, uint8_t out_min, uint8_t out_max);

  IHal& m_hal;
  PWM_chart_model& m_model;
  const uint8_t m_chart_size;
};

} // namespace PWM_chart