#include "../test/native/PWM_Controller_test.h"

namespace PWM
{

PWM_Controller_test::PWM_Controller_test()
: hal_mock{}
, view_mock{}
, uut(hal_mock, model, &view_mock)
{}

TEST_F(PWM_Controller_test, active)
{
  EXPECT_CALL(view_mock, print_screen());
  EXPECT_CALL(hal_mock, set_keyboard_callback(_, _));
  uut.active();
}

TEST_F(PWM_Controller_test, set_pwm_up)
{
  EXPECT_CALL(hal_mock, set_PWM_output(1));
  EXPECT_CALL(view_mock, update_duty());
  uut.keyboar_reaction(Cursor_move::up);
}

TEST_F(PWM_Controller_test, set_pwm_down)
{
  EXPECT_CALL(view_mock, update_duty());
  EXPECT_CALL(hal_mock, set_PWM_output(0));
  uut.keyboar_reaction(Cursor_move::down);
}

} // namespace PWM