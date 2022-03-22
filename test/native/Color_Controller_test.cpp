#include "../test/native/Color_Controller_test.h"

namespace Color_tester
{

Color_Controller_test::Color_Controller_test()
: hal_mock{}
, view_mock{}
, uut(hal_mock, model, &view_mock)
{}

TEST_F(Color_Controller_test, dummy)
{
  // uut.active();
  ASSERT_EQ(0, 0);
}

} // namespace Color_tester