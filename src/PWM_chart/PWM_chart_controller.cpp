#include "PWM_chart_controller.h"

namespace PWM_chart
{
PWM_chart_controller::PWM_chart_controller(IHal& hal, PWM_chart_model& model, IPWM_chart_view* view)
: m_hal(hal)
, m_model(model)
, m_view(view)
{}

PWM_chart_controller::~PWM_chart_controller()
{
  delete m_view;
}

void PWM_chart_controller::active()
{
  m_hal.set_keyboard_callback(&IController::keyboar_reaction, this);
  m_view->print_screen();
}

void PWM_chart_controller::keyboar_reaction(Cursor_move move)
{
  if (move == Cursor_move::up)
  {}
  else if (move == Cursor_move::down)
  {}
}

} // namespace PWM_chart