#ifndef __LED_H__
#define __LED_H__

class Led
{
private:
    const bool ON = 1;
    const bool OFF = 0;
    int pinNumber1;
    int pinNumber2;
    int pinNumber3;
    int pinNumber4;
    int pinNumber5;
    bool ledState;

    void writePin(int pin, bool pinState);

public:
    Led(int pin1, int pin2, int pin3, int pin4, int pin5);
    virtual ~Led();
    void On(int pinNumber);
    void Off();
    void Toggle();
};

#endif /* __LED_H__ */