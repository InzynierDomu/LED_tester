/**
 * @file IController.h
 * @brief controller base interface
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 03-2022
 */

#pragma once

#include "IHal.h"

class IController
{
  public:
  virtual ~IController() {}
  virtual void active() = 0;
  virtual void keyboar_reaction(Cursor_move move) = 0;
};