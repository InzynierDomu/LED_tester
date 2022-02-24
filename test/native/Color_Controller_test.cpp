#include "../test/native/Color_Controller_test.h"

namespace Color_tester
{

Color_Controller_test::Color_Controller_test()
: hal()
, view(hal, model)
, uut(hal, model, view)
{}

TEST_F(Color_Controller_test, dummy)
{
  // uut.active();
  ASSERT_EQ(0, 0);
}

} // namespace Color_tester