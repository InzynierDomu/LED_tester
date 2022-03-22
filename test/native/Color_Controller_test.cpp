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
  EXPECT_CALL(view_mock, print_screen());
  EXPECT_CALL(hal_mock, set_keyboard_callback(_,_));
  uut.active();
  ASSERT_EQ(0, 0);
}

} // namespace Color_tester