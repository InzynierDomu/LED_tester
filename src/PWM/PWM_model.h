/**
 * @file PWM_cahrt_model.h
 * @brief Model with structure for manual pwm control mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

#include <stdint.h>

namespace PWM
{

struct PWM_model
{
  PWM_model()
  : duty(0)
  {}
  ~PWM_model() {}

  uint16_t duty; ///< PWM duty
};

} // namespace PWM