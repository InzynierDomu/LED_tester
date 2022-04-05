#include "../test/native/Color_tester_view_test.h"

namespace Color_tester
{

Color_tester_view_test::Color_tester_view_test()
: hal_mock{}
, uut(hal_mock, model)
{}

TEST_F(Color_tester_view_test, print_start_color_saturation)
{
  EXPECT_CALL(hal_mock, clear_part_screen(_, _, _, _)).Times(2);
  EXPECT_CALL(hal_mock, print_text("0", _, _));
  EXPECT_CALL(hal_mock, draw_rect(_, _, _, _, 0));
  EXPECT_CALL(hal_mock, print_text("0x000000", _, _));
  uut.update_color_saturation();
}

TEST_F(Color_tester_view_test, print_white_color_saturation)
{
  model.color.color_saturation[0] = 255;
  model.color.color_long = 16777215;
  EXPECT_CALL(hal_mock, clear_part_screen(_, _, _, _)).Times(2);
  EXPECT_CALL(hal_mock, print_text("255", _, _));
  EXPECT_CALL(hal_mock, draw_rect(_, _, _, _, 0));
  EXPECT_CALL(hal_mock, print_text("0xFFFFFF", _, _));
  uut.update_color_saturation();
}

} // namespace Color_tester