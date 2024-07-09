#pragma once

#include "../test/mocks/Hal_mock.h"
#include "../test/mocks/PWM_view_mock.h"
#include "PWM/PWM_controller.cpp"
#include "PWM/PWM_model.h"

#include "gtest/gtest.h"

namespace PWM
{

using namespace ::testing;

struct PWM_controller_test : public ::testing::Test
{
  protected:
  PWM_controller_test();

  Hal_mock hal_mock;
  PWM_model model;
  std::shared_ptr<PWM_view_mock> view_mock;
  PWM_controller uut;
};

} // namespace PWM