#include "../test/Color_tester_controller_test.h"

namespace Color_tester
{

Color_tester_controller_test::Color_tester_controller_test()
: hal_mock{}
{
  view_mock = std::make_unique<Color_tester_view_mock>();
  uut(hal_mock, model, std::move(view_mock));
}

TEST_F(Color_tester_controller_test, active)
{
  EXPECT_CALL(view_mock, print_screen());
  EXPECT_CALL(hal_mock, set_keyboard_callback(_, _));
  uut.active();
}

TEST_F(Color_tester_controller_test, move_up_from_start)
{
  EXPECT_CALL(view_mock, clear_cursor());
  EXPECT_CALL(view_mock, update_cursor());  
  uut.keyboar_reaction(Cursor_move::up);
  ASSERT_EQ(model.position, 2);
}

TEST_F(Color_tester_controller_test, move_dow_3times_from_start)
{
  EXPECT_CALL(view_mock, clear_cursor()).Times(3);
  EXPECT_CALL(view_mock, update_cursor()).Times(3);
  uut.keyboar_reaction(Cursor_move::down);
  ASSERT_EQ(model.position, 1);
  uut.keyboar_reaction(Cursor_move::down);
  ASSERT_EQ(model.position, 2);
  uut.keyboar_reaction(Cursor_move::down);
  ASSERT_EQ(model.position, 0);
}

TEST_F(Color_tester_controller_test, try_change_color_below_0)
{
  EXPECT_CALL(view_mock, update_color_saturation());
  EXPECT_CALL(hal_mock, set_color_rgb(0));
  uut.keyboar_reaction(Cursor_move::left);
}

} // namespace Color_tester