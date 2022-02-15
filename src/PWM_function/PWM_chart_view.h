#pragma once

#include "Hal.h"
#include "PWM_chart_model.h"

namespace PWM_chart
{

class PWM_chart_view
{
    public:
    PWM_chart_view(Hal& hal, PWM_chart_model& model);
    void print_screen();

    private:
    Hal& m_hal;
    PWM_chart_model& m_model;
};

}