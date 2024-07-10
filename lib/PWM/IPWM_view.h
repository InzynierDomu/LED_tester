/**
 * @file IPWM_view.h
 * @brief interface UI view for pwm control mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

namespace PWM
{

class IPWM_view
{
  public:
  virtual ~IPWM_view(){};
  virtual void print_screen() = 0;
  virtual void update_duty() = 0;
};

} // namespace PWM