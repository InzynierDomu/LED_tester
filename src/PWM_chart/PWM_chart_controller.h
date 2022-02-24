#pragma once

#include "PWM_chart_model.h"
#include "PWM_chart_view.h"
#include "Controller.h"

namespace PWM_chart
{

class PWM_chart_controller : public Controller
{
    public:
    PWM_chart_controller(IHal& hal, PWM_chart_model& model, PWM_chart_view& view);
    
    void active() override;
    // void keyboard_reaction(Cursor_move move) override;

    private:    
    IHal& m_hal;
    PWM_chart_model& m_model;
    PWM_chart_view& m_veiw;
};

}