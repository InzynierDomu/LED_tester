#pragma once

#include "IPWM_chart_view.h"

#include "gmock/gmock.h"

namespace PWM_chart
{

class PWM_chart_view_mock : public IPWM_chart_view
{
  public:
  MOCK_METHOD0(print_screen, void());
  MOCK_METHOD0(update_cursor, void());
  MOCK_METHOD0(clear_cursor, void());
  MOCK_METHOD0(clear_pwm_cursor, void());
  MOCK_METHOD0(update_pwm_cursor, void());
};

} // namespace PWM_chart