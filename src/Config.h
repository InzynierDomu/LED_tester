/**
 * @file Config.h
 * @brief Configuration file
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

namespace Config
{
const uint8_t led_ws_pin = 0; ///< pin for WS2812 LED - BCM27
const uint8_t led_ws_count = 1; ///< WS2812 LED count
const uint8_t led_pin = 2; ///< pin for LED - BCM23
const uint16_t PWM_max = 255; ///< max PWM from resolution
} // namespace Config