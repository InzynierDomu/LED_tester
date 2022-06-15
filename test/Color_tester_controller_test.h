#pragma once

#include "../test/mocks/Color_tester_view_mock.h"
#include "../test/mocks/Hal_mock.h"
#include "Color_tester/Color_tester_controller.cpp"
#include "Color_tester/Color_tester_model.h"

#include "gtest/gtest.h"

namespace Color_tester
{

using namespace ::testing;

struct Color_tester_controller_test : public ::testing::Test
{
  protected:
  Color_tester_controller_test();

  Hal_mock hal_mock;
  Color_tester_model model;
  Color_tester_view_mock view_mock;
  Color_tester_controller uut;
};

} // namespace Color_tester
