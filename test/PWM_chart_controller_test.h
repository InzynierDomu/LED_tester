#pragma once

#include "../test/mocks/Hal_mock.h"
#include "../test/mocks/PWM_chart_view_mock.h"
#include "PWM_chart_controller.h"
#include "PWM_chart_model.h"

#include "gtest/gtest.h"

namespace PWM_chart
{

using namespace ::testing;

struct PWM_chart_controller_test : public ::testing::Test
{
  protected:
  PWM_chart_controller_test();

  Hal_mock hal_mock;
  PWM_chart_model model;
  std::shared_ptr<PWM_chart_view_mock> view_mock;
  PWM_chart_controller uut;
};

} // namespace PWM_chart