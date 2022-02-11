#pragma once

#include <stdint.h>

namespace Color_tester
{

///< color name for cursor positions
enum Cursor_position_name
{
  r = 0,
  g,
  b
};

struct Color
{
  uint8_t color_saturation[3]{255, 255, 255}; ///< rgb saturation color values
  uint16_t color_short;
  uint32_t color_long;
};

struct Color_tester_model
{
  Color_tester_model();
  ~Color_tester_model();
  Color color;
  Cursor_position_name position; ///< current color to posible change saturation value
};

} // namespace Color_tester