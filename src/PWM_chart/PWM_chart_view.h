#pragma once

#include "IHal.h"
#include "PWM_chart_model.h"
#include "IPWM_chart_veiw.h"

namespace PWM_chart
{

class PWM_chart_view : public IPWM_chart_view
{
    public:
    PWM_chart_view(IHal& hal, PWM_chart_model& model);
    void print_screen();

    private:
    IHal& m_hal;
    PWM_chart_model& m_model;
};

}