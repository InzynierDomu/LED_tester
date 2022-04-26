/**
 * @file IPWM_chart_view.h
 * @brief interface UI view for pwm characteristics mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

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