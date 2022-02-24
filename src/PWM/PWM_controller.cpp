#include "PWM_controller.h"

namespace PWM
{
PWM_controller::PWM_controller(IHal& hal, PWM_model& model, PWM_view& view)
: m_hal(hal)
, m_model(model)
, m_view(view)
{}

void PWM_controller::active()
{
  m_hal.set_keyboard_callback(&Controller::keyboar_reaction, this);
}
// void PWM_controllerkeyboard_reaction(Cursor_move move) {}

} // namespace PWM