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
  Color color;
  Cursor_position_name position; ///< current color to posible change saturation value
};

} // namespace Color_tester