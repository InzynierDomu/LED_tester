/**
 * @file PWM_cahrt_model.h
 * @brief Model with structures for change of PWM in time characteristics mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

#include <math.h>
#include <stdint.h>
#include <string>

namespace PWM_chart
{

using math_fun = uint16_t (*)(uint16_t, uint16_t);

struct Math_function
{
  Math_function(std::string _name, math_fun _fun)
  : name(_name)
  , fun(_fun)
  {}

  std::string name; ///< math function short name
  math_fun fun; ///< math function calculation
};

namespace Math_functions
{

static uint16_t linear(uint16_t x, uint16_t)
{
  return x;
}

static uint16_t sin(uint16_t x, uint16_t max)
{
  return max * (std::sin(((x - max) * M_PI) / (max * 2))) + max;
}

} // namespace Math_functions

struct PWM_chart_model
{
  PWM_chart_model()
  : math_fun_count(2)
  , math_functions{{"x", Math_functions::linear}, {"sin", Math_functions::sin}}
  , position(0)
  , pwm_cursor_position(0)
  , duty(0)
  {}

  const uint8_t math_fun_count; ///< math functions count
  const Math_function math_functions[2]; ///< math funtions
  uint8_t position; ///< current math function
  uint8_t pwm_cursor_position; ///< x position in function
  uint16_t duty; ///< PWM duty
};

} // namespace PWM_chart