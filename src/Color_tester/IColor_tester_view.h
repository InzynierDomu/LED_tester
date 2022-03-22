#pragma once

class IColor_tester_view
{
  public:
  virtual ~IColor_tester_view() {}
  virtual void print_screen() = 0;
  virtual void update_color_saturation() = 0;
  virtual void update_cursor() = 0;
};