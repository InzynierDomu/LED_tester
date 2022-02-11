#include "Color_tester_controller.h"

namespace Color_tester
{

Color_tester_controller::Color_tester_controller(Hal& hal, Color_tester_model& model, Color_tester_view& view)
: m_hal(hal)
, m_model(model)
, m_view(view)
{}

Color_tester_controller::~Color_tester_controller() {}

void Color_tester_controller::active()
{
  m_model.color.color_short = color16(m_model.color.color_saturation);
  m_model.color.color_long = color32(m_model.color.color_saturation);

  m_view.print_screen();
  m_hal.set_keyboard_callback(&Controller::keyboar_reaction, this);
}

/**
 * @brief convert rgb 8bits colors saturation table to 16bits
 * @return rgb color in 16bits format
 */
uint16_t Color_tester_controller::color16(uint8_t* colors_saturation)
{
  uint8_t r = map(colors_saturation[0], 0, 255, 0, 31);
  uint8_t g = map(colors_saturation[1], 0, 255, 0, 63);
  uint8_t b = map(colors_saturation[2], 0, 255, 0, 31);
  uint16_t color = b;
  color += r << 11;
  color += g << 5;
  return color;
}

uint32_t Color_tester_controller::color32(uint8_t* colors_saturation)
{
  uint32_t color = colors_saturation[2];
  color += colors_saturation[1] << 8;
  color += colors_saturation[0] << 16;
  return color;
}

void Color_tester_controller::keyboar_reaction(Cursor_move move)
{
  if (move == Cursor_move::up || move == Cursor_move::down)
  {
    move_cursor(move);
  }
  else if (move == Cursor_move::left || move == Cursor_move::right)
  {
    change_color(move);
  }
}

/**
 * @brief change color saturation
 * @param move increase or decrease value
 */
void Color_tester_controller::change_color(Cursor_move move)
{
  if (move == Cursor_move::right && m_model.color.color_saturation[m_model.position] < 255)
  {
    m_model.color.color_saturation[m_model.position]++;
  }
  else if (move == Cursor_move::left && m_model.color.color_saturation[m_model.position] > 0)
  {
    m_model.color.color_saturation[m_model.position]--;
  }
  m_model.color.color_short = color16(m_model.color.color_saturation);
  m_model.color.color_long = color32(m_model.color.color_saturation);

  m_view.update_color_saturation();
  m_hal.set_color_rgb(m_model.color.color_long);
}

/**
 * @brief moving circle cursor between colors
 * @param move up or down
 */
void Color_tester_controller::move_cursor(Cursor_move move)
{
  if (move == Cursor_move::up)
  {
    if (m_model.position == Cursor_position_name::r)
    {
      m_model.position = Cursor_position_name::b;
    }
    else
    {
      m_model.position = static_cast<Cursor_position_name>(m_model.position - 1);
    }
  }
  else if (move == Cursor_move::down)
  {
    if (m_model.position == Cursor_position_name::b)
    {
      m_model.position = Cursor_position_name::r;
    }
    else
    {
      m_model.position = static_cast<Cursor_position_name>(m_model.position + 1);
    }
  }

  m_view.update_cursor();
}

} // namespace Color_tester