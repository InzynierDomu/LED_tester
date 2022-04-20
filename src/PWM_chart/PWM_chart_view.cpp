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

  print_math_fun_names();
  print_chart();
  print_math_fun();
}

void PWM_chart_view::print_chart()
{
  m_hal.draw_line_horizontal(70, 220, 230);
  m_hal.draw_line_vertical(70, 20, 200);
}

void PWM_chart_view::print_math_fun()
{
  for (uint8_t i = 0; i < 199; i++)
  {
    uint8_t y = m_model.math_functions[m_model.position].fun(i, 199);
    m_hal.draw_point(71 + i, 219 - y);
  }
}

void PWM_chart_view::print_math_fun_names()
{
  for (uint8_t i = 1; i < 3; i++)  //todo: value from model (size menu)
  {
    m_hal.print_text(m_model.math_functions[i-1].name, 20, i * 20);
  }
}

} // namespace PWM_chart