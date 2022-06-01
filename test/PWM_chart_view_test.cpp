#include "../test/PWM_chart_view_test.h"

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
  EXPECT_CALL(hal_mock, draw_chart_axes(_, _, _, _, _));
  EXPECT_CALL(hal_mock, draw_chart_cursor(_, _, _));
  EXPECT_CALL(hal_mock, draw_point(_, _)).Times(199);
  EXPECT_CALL(hal_mock, print_text("Lin", _, _));
  EXPECT_CALL(hal_mock, print_text("Sin", _, _));
  EXPECT_CALL(hal_mock, print_text("Pow", _, _));
  uut.print_screen();
}

} // namespace PWM_chart