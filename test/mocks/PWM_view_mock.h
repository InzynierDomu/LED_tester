#pragma once

#include "PWM/IPWM_view.h"

#include "gmock/gmock.h"

namespace PWM
{

class PWM_view_mock : public IPWM_view
{
  public:
  MOCK_METHOD0(print_screen, void());
  MOCK_METHOD0(update_duty, void());
};

} // namespace PWM