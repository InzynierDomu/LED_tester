/**
 * @file main.cpp
 * @brief Test device for LED one color and WS2812
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 01-2022
 */

#include "Color_tester/Color_tester_controller.h"
#include "Color_tester/Color_tester_model.h"
#include "Color_tester/Color_tester_view.h"
#include "Hal.h"
#include "IController.h"
#include "PWM/PWM_controller.h"
#include "PWM/PWM_model.h"
#include "PWM/PWM_view.h"
#include "PWM_chart/PWM_chart_controller.h"
#include "PWM_chart/PWM_chart_model.h"
#include "PWM_chart/PWM_chart_view.h"

#include <Arduino.h>
#include <memory>

Hal m_hal; ///< hardware layer
Color_tester::Color_tester_model m_color_tester_model; ///< data for color tester/picker mode
PWM::PWM_model m_PWM_model; ///< data for pwm manual control mode
PWM_chart::PWM_chart_model m_PWM_chart_model; ///< data for Change of PWM in time characteristics mode
IController* m_controller; ///< dynamically changing controller to opararting on hal, model and connect with view

Mode m_mode = Mode::ws_color_tester; ///< mode which device current running

/**
 * @brief according to new mode change view and controller
 * @param mode: mode to set active
 */
void change_mode(Mode const mode)
{
  if (m_controller != nullptr)
  {
    delete m_controller;
  }

  switch (mode)
  {
    case Mode::ws_color_tester:
    {
      std::unique_ptr<Color_tester::Color_tester_view> color_tester_view(new Color_tester::Color_tester_view(m_hal, m_color_tester_model));
      m_controller = new Color_tester::Color_tester_controller(m_hal, m_color_tester_model, std::move(color_tester_view));
      break;
    }
    case Mode::pwm_generator:
    {
      std::unique_ptr<PWM::PWM_view> pwm_view(new PWM::PWM_view(m_hal, m_PWM_model));
      m_controller = new PWM::PWM_controller(m_hal, m_PWM_model, std::move(pwm_view));
      break;
    }
    case Mode::characteristic_tester:
    {
      std::unique_ptr<PWM_chart::PWM_chart_view> pwm_chart_view(new PWM_chart::PWM_chart_view(m_hal, m_PWM_chart_model));
      m_controller = new PWM_chart::PWM_chart_controller(m_hal, m_PWM_chart_model, std::move(pwm_chart_view));
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