#include "../test/native/PWM_controller_test.h"

namespace PWM
{

PWM_controller_test::PWM_controller_test()
: hal_mock{}
, view_mock{}
, uut(hal_mock, model, &view_mock)
{}

TEST_F(PWM_controller_test, active)
{
  EXPECT_CALL(view_mock, print_screen());
  EXPECT_CALL(hal_mock, set_keyboard_callback(_, _));
  EXPECT_CALL(hal_mock, set_PWM_output(_));
  uut.active();
}

} // namespace PWM