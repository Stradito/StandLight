#include "Led.h"
#include "wiringPi.h"

Led::Led(int pin1, int pin2, int pin3, int pin4, int pin5)
    : pinNumber1(pin1), pinNumber2(pin2), pinNumber3(pin3), pinNumber4(pin4), pinNumber5(pin5), ledState(OFF)
{
    wiringPiSetup();
    pinMode(pinNumber1, OUTPUT);
    pinMode(pinNumber2, OUTPUT);
    pinMode(pinNumber3, OUTPUT);
    pinMode(pinNumber4, OUTPUT);
    pinMode(pinNumber5, OUTPUT);
}

Led::~Led()
{
}

void Led::writePin(int pin, bool pinState)
{
    digitalWrite(pin, (int)pinState);
}

void Led::On(int pinNumber)
{
    ledState = ON;
    writePin(pinNumber, ledState);
}

void Led::Off()
{
    ledState = OFF;
    writePin(pinNumber1, ledState);
    writePin(pinNumber2, ledState);
    writePin(pinNumber3, ledState);
    writePin(pinNumber4, ledState);
    writePin(pinNumber5, ledState);
}
void Led::Toggle()
{
    ledState ^= 1;
    writePin(pinNumber1, ledState);
}
