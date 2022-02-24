#include "PWM_view.h"

namespace PWM
{
PWM_view::PWM_view(IHal& hal, PWM_model& model)
: m_hal(hal)
, m_model(model)
{}
} // namespace PWM