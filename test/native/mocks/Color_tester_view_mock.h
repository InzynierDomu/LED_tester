#pragma once

#include "Color_tester/IColor_tester_view.h"

#include "gmock/gmock.h"

namespace Color_tester
{

class Color_tester_view_mock : public IColor_tester_view
{
  public:
  MOCK_METHOD0(print_screen, void());
  MOCK_METHOD0(update_color_saturation, void());
  MOCK_METHOD0(update_cursor, void());
};

} // namespace Color_tester