#include "Controller.h"

Controller::Controller(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    static unsigned int count = 0;
    switch (lightState)
    {
    case LIGHT_OFF:
        if (strBtn == "powerButton") {
            lightState = LIGHT_ON;
            view->updateState("StateOn");
        }
        break;
    
    case LIGHT_ON:
        if (strBtn == "powerButton") {
            count++;
            if(count >= 5){
                lightState = LIGHT_OFF;
                view->updateState("StateOff");
                count = 0;
            }
            else{
                view->updateState("Next");
            }
        }
        break;
    }
}