#ifndef LISTENER_H
#define LISTENER_H

#include "Button.h"
#include "Led.h"

#pragma once

class Listener
{
private:
    Button *powerButton;
    Led *light;
public:
    Listener(Button *button, Led *led);
    ~Listener();
    void checkEvent();
};

#endif