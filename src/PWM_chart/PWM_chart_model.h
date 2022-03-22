#pragma once
// #include "math.h"
#include "string"


namespace PWM_chart
{

class Math_function
{
  std::string name;
  uint16_t (*fun)(uint16_t);
};

namespace Math_functions
{

static uint16_t linear(uint16_t x)
{
  return x;
}

} // namespace Math_functions

struct PWM_chart_model
{
  PWM_chart_model() {}

  // Math_function math_functions[2];
};

} // namespace PWM_chart