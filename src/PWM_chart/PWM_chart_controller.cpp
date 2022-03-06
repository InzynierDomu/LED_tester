#include "PWM_chart_controller.h"

namespace PWM_chart
{
PWM_chart_controller::PWM_chart_controller(IHal& hal, PWM_chart_model& model, PWM_chart_view& view)
: m_hal(hal)
, m_model(model)
, m_veiw(view)
{}

void PWM_chart_controller::active()
{
  m_hal.set_keyboard_callback(&IController::keyboar_reaction, this);
}
// void PWM_chart_controller::keyboard_reaction(Cursor_move move) {}

} // namespace PWM_chart