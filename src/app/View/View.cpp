#include "View.h"
#include <wiringPi.h>

View::View(Led *led)
{
    light = led;
    lightState = LIGHT_OFF;
}

View::~View()
{

}

void View::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "StateOn") {
                count = 0;
                lightState = LIGHT_ON;
            }
        break;

        case LIGHT_ON:
            if (strState == "StateOff") {
                lightState = LIGHT_OFF;
            }
            else if (strState == "Next") {
                count++;
            }
        break;
    }
}


void View::lightView()
{
    switch (lightState)
    {
        case LIGHT_OFF:
            lightOff();
        break;

        case LIGHT_ON:
            lightOn(25-count);
        break;
    }
}

void View::lightOn(int pin)
{
    light->On(pin);
}

void View::lightOff()
{
    light->Off();
}