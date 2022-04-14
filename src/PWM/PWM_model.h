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

  uint16_t duty;
};

} // namespace PWM