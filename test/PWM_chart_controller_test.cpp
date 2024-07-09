#include "../test/PWM_chart_controller_test.h"

namespace PWM_chart
{

PWM_chart_controller_test::PWM_chart_controller_test()
: view_mock(new PWM_chart_view_mock())
, uut(hal_mock, model, view_mock)
{}

TEST_F(PWM_chart_controller_test, active)
{
  EXPECT_CALL(*view_mock, print_screen());
  EXPECT_CALL(hal_mock, set_keyboard_callback(_, _));
  EXPECT_CALL(hal_mock, set_PWM_output(0));
  uut.active();
}

TEST_F(PWM_chart_controller_test, next_math_fun)
{
  EXPECT_CALL(*view_mock, clear_cursor());
  EXPECT_CALL(*view_mock, update_cursor());
  uut.keyboar_reaction(Cursor_move::down);
  ASSERT_EQ(model.position, 1);
}

TEST_F(PWM_chart_controller_test, move_pwm_cursor)
{
  EXPECT_CALL(*view_mock, clear_pwm_cursor()).Times(2);
  EXPECT_CALL(*view_mock, update_pwm_cursor()).Times(2);
  EXPECT_CALL(hal_mock, set_PWM_output(_)).Times(2);
  uut.keyboar_reaction(Cursor_move::right);
  ASSERT_EQ(model.pwm_cursor_position, 1);
  ASSERT_EQ(model.duty, 1);
  uut.keyboar_reaction(Cursor_move::right);
  ASSERT_EQ(model.pwm_cursor_position, 2);
  ASSERT_EQ(model.duty, 2);
}

} // namespace PWM_chart