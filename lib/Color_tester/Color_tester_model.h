/**
 * @file Color_tester_model.h
 * @brief Model with structures for WS2812 color control mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

#include <stdint.h>

namespace Color_tester
{

enum Cursor_position_name ///< color name for cursor positions
{
  r = 0,
  g,
  b
};

struct Color
{
  Color()
  : color_saturation{0, 0, 0}
  , color_short(0)
  , color_long(0)
  {}
  uint8_t color_saturation[3]; ///< rgb saturation color values
  uint16_t color_short; ///< rgb in 16bit 5-r, 6-g, 5-b
  uint32_t color_long; ///< rgb in 32bit 8-r, 8-g, 8-b
};

struct Color_tester_model
{
  Color_tester_model()
  : position(Cursor_position_name::r)
  , color{}
  {}
  ~Color_tester_model() {}
  Cursor_position_name position; ///< current color to posible change saturation value
  Color color; ///< color saturations, 16bit and 32bit format
};

} // namespace Color_tester