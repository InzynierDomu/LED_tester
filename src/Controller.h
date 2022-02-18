#ifndef UNIT_TEST
#include "Hal.h"
#endif

class Controller
{
public:
    virtual void active() =0;
    virtual void keyboar_reaction(Cursor_move move) = 0;
};