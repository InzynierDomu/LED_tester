#pragma once
#include <math.h>
#include <stdint.h>
#include <string>

namespace PWM_chart
{

using math_fun = uint16_t (*)(uint16_t, u_int16_t);

struct Math_function
{
  Math_function(std::string _name, math_fun _fun)
  : name(_name)
  , fun(_fun)
  {}

  std::string name;
  math_fun fun;
};

namespace Math_functions
{

static uint16_t linear(uint16_t x, u_int16_t)
{
  return x;
}

static uint16_t sin(uint16_t x, uint16_t max)
{
  return std::sin(x);
}

} // namespace Math_functions

struct PWM_chart_model
{
  PWM_chart_model()
  : math_functions{{"x", Math_functions::linear}, {"sin", Math_functions::sin}}
  , position(0)
  {}

  Math_function math_functions[2];
  uint8_t position;
};

} // namespace PWM_chart