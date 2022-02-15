#include "PWM_chart_controller.h"

namespace PWM_chart
{
PWM_chart_controller::PWM_chart_controller(Hal& hal, PWM_chart_model& model, PWM_chart_view& view)
: m_hal(hal)
, m_model(model)
, m_veiw(view)
{}

void PWM_chart_controller::active() {}
void PWM_chart_controller::keyboard_reaction(Cursor_move move) {}
} // namespace PWM_chart