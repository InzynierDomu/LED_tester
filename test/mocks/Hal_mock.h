#pragma once

#include "IHal.h"

#include "gmock/gmock.h"

class Hal_mock : public IHal
{
  public:
  MOCK_METHOD0(init, void());
  MOCK_METHOD0(get_screen, TFT_eSPI&());
  MOCK_METHOD1(set_color_rgb, void(uint32_t color));
  MOCK_METHOD0(check_button, void());
  MOCK_METHOD2(set_keyboard_callback, void(callback_cursor_move callback, Controller* controller));
};