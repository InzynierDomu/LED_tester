#include "PWM_chart_view.h"

namespace PWM_chart
{

PWM_chart_view::PWM_chart_view(IHal& hal, PWM_chart_model& model)
: m_hal(hal)
, m_model(model)
{}

void PWM_chart_view::print_screen() {}

} // namespace PWM_chart