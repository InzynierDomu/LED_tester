#pragma onece

#ifndef UNIT_TEST
#include "Hal.h"
#endif
#include "PWM_model.h"

namespace PWM
{

class PWM_view
{
  public:
  PWM_view(IHal& hal, PWM_model& model);

  private:
  IHal& m_hal;
  PWM_model& m_model;
};

} // namespace PWM
