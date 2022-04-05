#pragma once

#include "../test/native/mocks/Hal_mock.h"
#include "Color_tester/Color_tester_model.h"
#include "Color_tester/Color_tester_view.cpp"

#include "gtest/gtest.h"

namespace Color_tester
{

using namespace ::testing;

struct Color_tester_view_test : public ::testing::Test
{
  Color_tester_view_test();

  protected:
  Hal_mock hal_mock;
  Color_tester_model model;
  Color_tester_view uut;
};

} // namespace Color_tester