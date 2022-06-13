/**
 * @file PWM_view.cpp
 * @brief UI view for pwm control mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#include "PWM_view.h"

#include <string>

namespace PWM
{

/**
 * @brief constructor
 * @param hal: hardware layer
 * @param model: data related to manual pwm control mode
 */
PWM_view::PWM_view(IHal& hal, PWM_model& model)
: m_hal(hal)
, m_model(model)
{}

/**
 * @brief print all for this mode after changing mode
 */
void PWM_view::print_screen()
{
  m_hal.clear_screen();

  m_hal.print_text("PWM duty", 30, 70);
  print_pwm_duty();
  m_hal.draw_gradient_circle(240, 120, 40, m_model.duty);
}

/**
 * @brief clear and print new duty value, change gradient color on screen
 */
void PWM_view::update_duty()
{
  m_hal.clear_part_screen(50, 120, 50, 20);
  print_pwm_duty();
  m_hal.draw_gradient_circle(240, 120, 40, m_model.duty);
}

void PWM_view::print_pwm_duty()
{
  std::string duty_val = std::to_string(m_model.duty);
  m_hal.print_text(duty_val, 50, 120);
}

} // namespace PWM