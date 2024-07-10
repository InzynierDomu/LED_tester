/**
 * @file PWM_view.h
 * @brief UI view for pwm control mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

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
  PWM_view(const PWM_view&);
  void print_pwm_duty();

  IHal& m_hal; ///< hardware layer
  PWM_model& m_model; ///< data model
};

} // namespace PWM
