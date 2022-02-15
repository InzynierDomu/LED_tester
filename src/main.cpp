/**
 * @file main.cpp
 * @brief Test device for LED one color, RGB and WS2812
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 01-2022
 */

#include "Adafruit_NeoPixel.h"
#include "Color_tester/Color_tester_controller.h"
#include "Color_tester/Color_tester_model.h"
#include "Color_tester/Color_tester_view.h"
#include "Free_Fonts.h"
#include "Hal.h"
#include "TFT_eSPI.h"

#include <Arduino.h>

Hal m_hal;
Color_tester::Color_tester_model m_color_tester_model;
Color_tester::Color_tester_view m_color_tester_view(m_hal, m_color_tester_model);
Color_tester::Color_tester_controller m_color_tester_controller(m_hal, m_color_tester_model, m_color_tester_view);

///< modes which device possible running
// enum class Mode
// {
//   ws_color_tester,
//   pwm_generator,
//   characteristic_tester
// };

// Mode m_mode = Mode::ws_color_tester; ///< mode which device current running

/**
 * @brief setup
 */
void setup()
{
  m_hal.init();
  m_color_tester_controller.active();
}

/**
 * @brief main loop
 */
void loop()
{
  m_hal.check_button();
}