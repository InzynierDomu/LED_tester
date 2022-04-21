#include "../test/native/PWM_chart_view_test.h"

namespace PWM_chart
{

PWM_chart_view_test::PWM_chart_view_test()
: hal_mock{}
, uut(hal_mock, model)
{}

TEST_F(PWM_chart_view_test, print_fun_menu)
{
  EXPECT_CALL(hal_mock, clear_screen());
  EXPECT_CALL(hal_mock, draw_cursor(_, _));
  EXPECT_CALL(hal_mock, draw_line_horizontal(_, _, _));
  EXPECT_CALL(hal_mock, draw_line_vertical(_, _, _));
  EXPECT_CALL(hal_mock, draw_point(_, _)).Times(199);
  EXPECT_CALL(hal_mock, print_text("x", _, _));
  EXPECT_CALL(hal_mock, print_text("sin", _, _));
  uut.print_screen();
}

} // namespace PWM_chart