#include "PWM_chart_view.h"

namespace PWM_chart
{

PWM_chart_view::PWM_chart_view(IHal& hal, PWM_chart_model& model)
: m_hal(hal)
, m_model(model)
{}

void PWM_chart_view::print_screen()
{
  m_hal.clear_screen();

  m_hal.draw_cursor(18, ((m_model.position + 1) * 25) - 2);

  print_math_fun_names();
  print_chart();
  print_math_fun();
  update_pwm_cursor();
}

void PWM_chart_view::update_cursor()
{
  m_hal.draw_cursor(18, ((m_model.position + 1) * 25) - 2);
  m_hal.clear_part_screen(101, 20, 200, 200);
  print_math_fun();
}

void PWM_chart_view::clear_cursor()
{
  m_hal.clear_cursor(18, ((m_model.position + 1) * 25) - 2);
}

void PWM_chart_view::clear_pwm_cursor()
{
  m_hal.clear_chart_cursor(m_model.pwm_cursor_position + 101, 20, 199);
  uint8_t y = m_model.math_functions[m_model.position].fun(m_model.pwm_cursor_position, 199);
  m_hal.draw_point(m_model.pwm_cursor_position + 101, 219 - y);
}

void PWM_chart_view::update_pwm_cursor()
{
  m_hal.draw_chart_cursor(m_model.pwm_cursor_position + 101, 20, 199);
}

void PWM_chart_view::print_chart()
{
  m_hal.draw_chart_axes(100, 17, 203, "T", "D");
}

void PWM_chart_view::print_math_fun()
{
  for (uint8_t i = 0; i < 199; i++)
  {
    uint8_t y = m_model.math_functions[m_model.position].fun(i, 199);
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

} // namespace PWM_chart