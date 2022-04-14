#pragma once
// #include "math.h"
#include <stdint.h>
#include <string>

namespace PWM_chart
{

using math_fun = uint16_t (*)(uint16_t);

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

static uint16_t linear(uint16_t x)
{
  return x;
}

} // namespace Math_functions

struct PWM_chart_model
{
  PWM_chart_model() {}

  Math_function math_functions[1]{{"linear", Math_functions::linear}};
};

} // namespace PWM_chart