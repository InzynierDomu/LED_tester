/**
 * @file PWM_chart_view.h
 * @brief UI view for pwm characteristics mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

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
  uint8_t map(const uint16_t x, const uint16_t in_min, const uint16_t in_max, const uint16_t out_min, const uint16_t out_max);

  IHal& m_hal; ///< hardware layer
  PWM_chart_model& m_model; ///< data model
  const uint8_t m_chart_size; ///< size chart axes
};

} // namespace PWM_chart