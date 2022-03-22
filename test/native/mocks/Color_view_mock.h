#pragma once

#include "Color_tester/IColor_tester_view.h"

#include "gmock/gmock.h"

class Color_view_mock : public IColor_tester_view
{
  public:
  MOCK_METHOD0(print_screen, void());
  MOCK_METHOD0(update_color_saturation, void());
  MOCK_METHOD0(update_cursor, void());
};