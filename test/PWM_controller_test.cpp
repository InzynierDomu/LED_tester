#include "../test/PWM_controller_test.h"

namespace PWM
{

PWM_controller_test::PWM_controller_test()
: hal_mock{}
, the_view_mock{new PWM::PWM_view_mock()}
, uut(hal_mock, model, the_view_mock)
{}

TEST_F(PWM_controller_test, active)
{
  EXPECT_CALL(*the_view_mock, print_screen());
  EXPECT_CALL(hal_mock, set_keyboard_callback(_, _));
  EXPECT_CALL(hal_mock, set_PWM_output(_));
  uut.active();
}

TEST_F(PWM_controller_test, set_pwm_up)
{
  EXPECT_CALL(hal_mock, set_PWM_output(1));
  EXPECT_CALL(*the_view_mock, update_duty());
  uut.keyboar_reaction(Cursor_move::up);
}

TEST_F(PWM_controller_test, set_pwm_down)
{
  EXPECT_CALL(hal_mock, set_PWM_output(0));
  EXPECT_CALL(*the_view_mock, update_duty());
  uut.keyboar_reaction(Cursor_move::down);
}

} // namespace PWM