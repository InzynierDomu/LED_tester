/**
 * @file PWM_chart_controller.cpp
 * @brief controller for change of PWM in time characteristics mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#include "PWM_chart_controller.h"

#include "Config.h"

namespace PWM_chart
{

/**
 * @brief constructor
 * @param hal: hardware layer
 * @param model: data related to PWM characteristics mode
 * @param view: UI part to PWM characteristics mode
 */
PWM_chart_controller::PWM_chart_controller(IHal& hal, PWM_chart_model& model, IPWM_chart_view* view)
: m_hal(hal)
, m_model(model)
, m_view(view)
{}

/**
 * @brief destructor
 */
PWM_chart_controller::~PWM_chart_controller()
{
  delete m_view;
}

void PWM_chart_controller::active()
{
  m_view->print_screen();
  m_hal.set_keyboard_callback(&IController::keyboar_reaction, this);
  m_hal.set_PWM_output(m_model.duty);
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
    if (m_model.pwm_cursor_position < Config::PWM_max)
    {
      m_model.pwm_cursor_position++;
    }
  }

  m_model.duty = m_model.math_functions[m_model.position].fun(m_model.pwm_cursor_position, Config::PWM_max);
  m_hal.set_PWM_output(m_model.duty);
  m_view->update_pwm_cursor();
}

void PWM_chart_controller::run_pwm_fun()
{
  for (int i = 0; i < Config::PWM_max; i++)
  {
    m_view->clear_pwm_cursor();
    m_model.duty = m_model.math_functions[m_model.position].fun(i, Config::PWM_max);
    m_hal.set_PWM_output(m_model.duty);
    m_model.pwm_cursor_position = i;
    m_view->update_pwm_cursor();
    m_hal.wait();
  }
}

} // namespace PWM_chart