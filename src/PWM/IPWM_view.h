#pragma once

namespace PWM
{

class IPWM_view
{
  public:
  virtual ~IPWM_view() {};
  virtual void print_screen() = 0;
  virtual void update_duty() = 0;
};

} // namespace PWM