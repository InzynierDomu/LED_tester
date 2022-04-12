/**
 * @file main.cpp
 * @brief Test device for LED one color, RGB and WS2812
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 01-2022
 */

#include "Color_tester/Color_tester_controller.h"
#include "Color_tester/Color_tester_view.h"
#include "Color_tester/Color_tester_model.h"
#include "Hal.h"
#include "IController.h"
#include "PWM/PWM_controller.h"
#include "PWM/PWM_view.h"
#include "PWM/PWM_model.h"

#include <Arduino.h>

Hal m_hal;
Color_tester::Color_tester_model m_color_tester_model;
PWM::PWM_model m_PWM_model;
IController* m_controller;

Mode m_mode = Mode::ws_color_tester; ///< mode which device current running

void change_mode(Mode mode)
{
  if (m_controller != nullptr)
  {
    delete m_controller;
  }

  switch (mode)
  {
    case Mode::ws_color_tester:
    {
      Color_tester::Color_tester_view* color_tester_view = new Color_tester::Color_tester_view(m_hal, m_color_tester_model);
      m_controller = new Color_tester::Color_tester_controller(m_hal, m_color_tester_model, color_tester_view);
      break;
    }
    case Mode::pwm_generator:
    {
      PWM::PWM_view* pwm_view = new PWM::PWM_view(m_hal, m_PWM_model);
      m_controller = new PWM::PWM_controller(m_hal, m_PWM_model, pwm_view);
      break;
    }
    default:
      break;
  }

  m_controller->active();
}

/**
 * @brief setup
 */
void setup()
{
  m_hal.init();
  change_mode(m_mode);
}

/**
 * @brief main loop
 */
void loop()
{
  if (m_hal.check_button_mode(m_mode))
  {
    change_mode(m_mode);
  }
  m_hal.check_button();
}