/**
 * @file IColor_tester_view.h
 * @brief interface UI view for color picker mode
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

namespace Color_tester
{

class IColor_tester_view
{
  public:
  virtual ~IColor_tester_view() {}
  virtual void print_screen() = 0;
  virtual void update_color_saturation() = 0;
  virtual void update_cursor() = 0;
  virtual void clear_cursor() = 0;
};

} // namespace Color_tester