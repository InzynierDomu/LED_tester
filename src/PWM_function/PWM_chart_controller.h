#pragma once

#include "PWM_chart_model.h"
#include "PWM_chart_view.h"
#include "Controller.h"
#include "Hal.h"

namespace PWM_chart
{

class PWM_chart_controller : public Controller
{
    public:
    PWM_chart_controller(Hal& hal, PWM_chart_model& model, PWM_chart_view& view);
    
    void active();
    void keyboard_reaction(Cursor_move move);

    private:    
    Hal& m_hal;
    PWM_chart_model& m_model;
    PWM_chart_view& m_veiw;
};

}