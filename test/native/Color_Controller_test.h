#pragma once

#include "../test/native/mocks/Hal_mock.h"
#include "Color_tester/Color_tester_controller.h"
#include "Color_tester/Color_tester_model.h"
#include "Color_tester/Color_tester_view.h"

#include "gtest/gtest.h"

namespace Color_tester
{

struct Color_Controller_test : public testing::Test
{
  Color_Controller_test();

  protected:
  Hal_mock hal;
  Color_tester_model model;
  Color_tester_view view;
  Color_tester_controller uut;
};

} // namespace Color_tester
