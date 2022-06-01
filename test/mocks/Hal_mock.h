#pragma once

#include "IHal.h"

#include "gmock/gmock.h"

class Hal_mock : public IHal
{
  public:
  MOCK_METHOD0(init, void());
  MOCK_METHOD0(clear_screen, void());
  MOCK_METHOD4(clear_part_screen, void(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height));
  MOCK_METHOD2(clear_cursor, void(const uint16_t position_x, const uint16_t position_y));
  MOCK_METHOD3(clear_chart_cursor, void(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght));
  MOCK_METHOD3(print_text, void(const std::string& text, const uint16_t position_x, const uint16_t position_y));
  MOCK_METHOD2(draw_cursor, void(const uint16_t position_x, const uint16_t position_y));
  MOCK_METHOD3(draw_chart_cursor, void(const uint16_t position_x, const uint16_t position_y, const uint16_t lenght));
  MOCK_METHOD4(draw_frame, void(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height));
  MOCK_METHOD5(draw_rect, void(const uint16_t position_x, const uint16_t position_y, const uint16_t width, const uint16_t height,
                               const uint16_t color));
  MOCK_METHOD4(draw_gradient_circle,
               void(const uint16_t position_x, const uint16_t position_y, const uint16_t radius, const uint16_t value));
  MOCK_METHOD5(draw_chart_axes, void(const uint16_t position_x, const uint16_t position_y, const uint16_t size,
                                     const std::string& x_axis_name, const std::string& y_axis_name));
  MOCK_METHOD2(draw_point, void(const uint16_t position_x, const uint16_t position_y));
  MOCK_METHOD1(set_color_rgb, void(const uint32_t color));
  MOCK_METHOD1(set_PWM_output, void(const uint16_t duty));
  MOCK_METHOD0(check_button, void());
  MOCK_METHOD1(check_button_mode, bool(Mode& mode));
  MOCK_METHOD2(set_keyboard_callback, void(callback_cursor_move callback, IController* controller));
  MOCK_METHOD0(wait, void());
};