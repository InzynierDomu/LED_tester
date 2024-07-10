#pragma once

#include "../test/mocks/Hal_mock.h"
#include "PWM_chart_model.h"
#include "PWM_chart_view.h"

#include "gtest/gtest.h"

namespace PWM_chart
{

using namespace ::testing;

struct PWM_chart_view_test : public ::testing::Test
{
  protected:
  PWM_chart_view_test();

  Hal_mock hal_mock;
  PWM_chart_model model;
  PWM_chart_view uut;
};

} // namespace PWM_chart