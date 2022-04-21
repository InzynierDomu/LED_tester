#include "PWM_chart_controller.h"

#include "Config.h"


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
  if (move == Cursor_move::up || move == Cursor_move::down)
  {
    move_cursor(move);
  }
  else if (move == Cursor_move::left || move == Cursor_move::right)
  {
    move_pwm_cursor(move);
  }
  else if (move == Cursor_move::center)
  {
    run_pwm_fun();
  }
}

void PWM_chart_controller::move_cursor(Cursor_move move)
{
  m_view->clear_cursor();

  if (move == Cursor_move::up)
  {
    if (m_model.position > 0)
    {
      m_model.position--;
    }
  }
  else if (move == Cursor_move::down)
  {
    if (m_model.position < (m_model.math_fun_count - 1))
    {
      m_model.position++;
    }
  }

  m_view->update_cursor();
}

void PWM_chart_controller::move_pwm_cursor(Cursor_move move)
{
  m_view->clear_pwm_cursor();

  if (move == Cursor_move::left)
  {
    if (m_model.pwm_cursor_position > 0)
    {
      m_model.pwm_cursor_position--;
    }
  }
  else if (move == Cursor_move::right)
  {
    if (m_model.pwm_cursor_position < (199)) // todo: fix magic number
    {
      m_model.pwm_cursor_position++;
    }
  }

  auto pwm_val = map(m_model.pwm_cursor_position, 0, 199, 0, Config::PWM_max); // todo: fix magic number
  m_model.duty = m_model.math_functions[m_model.position].fun(pwm_val, Config::PWM_max);
  m_hal.set_PWM_output(m_model.duty);
  m_view->update_pwm_cursor();
}

void PWM_chart_controller::run_pwm_fun()
{
  for (int i = 0; i < 199; i++) // todo: fix magic number
  {
    m_view->clear_pwm_cursor();
    auto pwm_val = map(i, 0, 199, 0, Config::PWM_max); // todo: fix magic number
    m_model.duty = m_model.math_functions[m_model.position].fun(pwm_val, Config::PWM_max);
    m_hal.set_PWM_output(m_model.duty);
    m_model.pwm_cursor_position = i;
    m_view->update_pwm_cursor();
    m_hal.wait();
  }
}

uint8_t PWM_chart_controller::map(uint8_t x, uint8_t in_min, uint8_t in_max, uint8_t out_min, uint8_t out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

} // namespace PWM_chart