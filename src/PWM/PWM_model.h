#pragma once

namespace PWM
{
struct PWM_model
{
  PWM_model()
  : duty(0)
  {}

  uint16_t duty;
};

} // namespace PWM