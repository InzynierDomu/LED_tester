#pragma once

#include "../test/native/mocks/Hal_mock.h"
#include "../test/native/mocks/PWM_view_mock.h"
#include "PWM/PWM_controller.cpp"
#include "PWM/PWM_model.h"

#include "gtest/gtest.h"

namespace PWM
{

using namespace ::testing;

struct PWM_Controller_test : public ::testing::Test
{
  PWM_Controller_test();

  protected:
  Hal_mock hal_mock;
  PWM_model model;
  PWM_view_mock view_mock;
  PWM_controller uut;
};

} // namespace PWM