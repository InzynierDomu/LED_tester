#include "PWM_controller.h"

namespace PWM
{
PWM_controller::PWM_controller(IHal& hal, PWM_model& model, IPWM_view* view)
: m_hal(hal)
, m_model(model)
, m_view(view)
{}

PWM_controller::~PWM_controller()
{
  delete m_view;
}

void PWM_controller::active()
{
  m_view->print_screen();
  m_hal.set_keyboard_callback(&IController::keyboar_reaction, this);
}

void PWM_controller::keyboar_reaction(Cursor_move move)
{
  if (move == Cursor_move::up && m_model.duty < 255)
  {
    m_model.duty++;
  }
  else if (move == Cursor_move::down && m_model.duty > 0)
  {
    m_model.duty--;
  }

  m_hal.set_PWM_output(m_model.duty);
  m_view->update_duty();
}

} // namespace PWM