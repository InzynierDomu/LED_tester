#pragma once

#include "../test/native/mocks/Hal_mock.h"
#include "../test/native/mocks/Color_view_mock.h"
#include "Color_tester/Color_tester_controller.cpp"
#include "Color_tester/Color_tester_model.h"

#include "gtest/gtest.h"

namespace Color_tester
{

using namespace ::testing;

struct Color_Controller_test : public ::testing::Test
{
  Color_Controller_test();

  protected:
  Hal_mock hal_mock;
  Color_tester_model model;
  Color_view_mock view_mock;
  Color_tester_controller uut;
};

} // namespace Color_tester
