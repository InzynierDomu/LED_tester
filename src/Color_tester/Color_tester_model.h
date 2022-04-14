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
  uint16_t color_short;
  uint32_t color_long;
};

struct Color_tester_model
{
  Color_tester_model()
  : position(Cursor_position_name::r)
  , color{}
  {}
  ~Color_tester_model() {}
  Cursor_position_name position; ///< current color to posible change saturation value
  Color color;
};

} // namespace Color_tester