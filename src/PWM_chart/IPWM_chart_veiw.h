#pragma once

namespace PWM_chart
{

class IPWM_chart_view
{
  public:
  virtual ~IPWM_chart_view() {}
  virtual void print_screen() = 0;
};

} // namespace PWM_chart