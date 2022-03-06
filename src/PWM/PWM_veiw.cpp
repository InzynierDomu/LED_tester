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

  m_hal.print_text("PWM", 50, 70);
}

} // namespace PWM