#include "../test/native/PWM_chart_controller_test.h"

namespace PWM_chart
{

PWM_chart_controller_test::PWM_chart_controller_test()
: hal_mock{}
, view_mock{}
, uut(hal_mock, model, &view_mock)
{}

} // namespace PWM_chart