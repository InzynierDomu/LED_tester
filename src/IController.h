#pragma once

#include "IHal.h"

class IController
{
  public:
  virtual ~IController() {}
  virtual void active() = 0;
  virtual void keyboar_reaction(Cursor_move move) = 0;
};