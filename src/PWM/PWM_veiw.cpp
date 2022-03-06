#include "PWM_view.h"

namespace PWM
{
PWM_view::PWM_view(IHal& hal, PWM_model& model)
: m_hal(hal)
, m_model(model)
{}

void PWM_view::print_screen()
{
  m_hal.clear_screen();

  m_hal.print_text("PWM duty", 30, 70);
  print_pwm_duty();
}

void PWM_view::update_duty()
{
  m_hal.clear_part_screen(50, 120, 50, 20);
  print_pwm_duty();
}

void PWM_view::print_pwm_duty()
{
  char duty_val[3];
  itoa(m_model.duty, duty_val, 10);
  m_hal.print_text(duty_val, 50, 120);
}

} // namespace PWM