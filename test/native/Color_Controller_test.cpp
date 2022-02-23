#include "../test/native/mocks/Hal_mock.h"
#include "Color_tester/Color_tester_controller.h"
#include "Color_tester/Color_tester_model.h"
#include "Color_tester/Color_tester_view.h"

#include "gtest/gtest.h"

namespace Color_tester
{

class Color_Controller_test : public testing::Test
{
  protected:
  Color_Controller_test()
  : hal()
  , view(hal, model)
  , uut(hal, model, view)
  {}

  Hal_mock hal;
  Color_tester_model model;
  Color_tester_view view;
  Color_tester_controller uut;
};

TEST_F(Color_Controller_test, dummy)
{
  // uut.active();
  ASSERT_EQ(0, 0);
}

} // namespace Color_tester