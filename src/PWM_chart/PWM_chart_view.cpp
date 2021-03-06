/**
 * @file PWM_chart_view.cpp
 * @brief UI view for pwm characteristics mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#include "PWM_chart_view.h"

#include "Config.h"

namespace PWM_chart
{

/**
 * @brief constructor
 * @param hal: hardware layer
 * @param model: data related to PWM characteristics mode
 */
PWM_chart_view::PWM_chart_view(IHal& hal, PWM_chart_model& model)
: m_hal(hal)
, m_model(model)
, m_chart_size(199)
{}

/**
 * @brief print all for this mode after changing mode
 */
void PWM_chart_view::print_screen()
{
  m_hal.clear_screen();

  m_hal.draw_cursor(18, ((m_model.position + 1) * 25) - 2);

  print_math_fun_names();
  print_chart();
  print_math_fun();
  update_pwm_cursor();
}

/**
 * @brief draw rectangle cursor on current math function nad print it on chart
 */
void PWM_chart_view::update_cursor()
{
  m_hal.draw_cursor(18, ((m_model.position + 1) * 25) - 2);
  print_math_fun();
}

/**
 * @brief clear cursor on math function and chart
 */
void PWM_chart_view::clear_cursor()
{
  m_hal.clear_cursor(18, ((m_model.position + 1) * 25) - 2);
  m_hal.clear_part_screen(101, 20, 200, 200);
}

/**
 * @brief clear cursor on chart
 */
void PWM_chart_view::clear_pwm_cursor()
{
  auto cursor_position = map(m_model.pwm_cursor_position, 0, Config::PWM_max, 0, m_chart_size);
  m_hal.clear_chart_cursor(cursor_position + 101, 20, m_chart_size);
  uint8_t y = m_model.math_functions[m_model.position].fun(cursor_position, m_chart_size);
  m_hal.draw_point(cursor_position + 101, 219 - y);
}

/**
 * @brief draw cursor on current position
 */
void PWM_chart_view::update_pwm_cursor()
{
  auto cursor_position = map(m_model.pwm_cursor_position, 0, Config::PWM_max, 0, m_chart_size);
  m_hal.draw_chart_cursor(cursor_position + 101, 20, m_chart_size);
}

void PWM_chart_view::print_chart()
{
  m_hal.draw_chart_axes(100, 17, 203, "T", "D");
}

void PWM_chart_view::print_math_fun()
{
  for (uint8_t i = 0; i < m_chart_size; i++)
  {
    uint8_t y = m_model.math_functions[m_model.position].fun(i, m_chart_size);
    m_hal.draw_point(101 + i, 219 - y);
  }
}

void PWM_chart_view::print_math_fun_names()
{
  for (uint8_t i = 1; i < m_model.math_fun_count + 1; i++)
  {
    m_hal.print_text(m_model.math_functions[i - 1].name, 20, i * 25);
  }
}

uint8_t PWM_chart_view::map(const uint16_t x, const uint16_t in_min, const uint16_t in_max, const uint16_t out_min, const uint16_t out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

} // namespace PWM_chart