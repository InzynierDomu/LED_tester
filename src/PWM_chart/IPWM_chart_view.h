#pragma once

namespace PWM_chart
{

class IPWM_chart_view
{
  public:
  virtual ~IPWM_chart_view() {}
  virtual void print_screen() = 0;
  virtual void update_cursor() = 0;
  virtual void clear_cursor() = 0;
  virtual void clear_pwm_cursor() = 0;
  virtual void update_pwm_cursor() = 0;
};

} // namespace PWM_chart