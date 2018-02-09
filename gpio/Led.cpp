//
// Created by federico on 04/02/18.
//

#include "Led.h"

namespace gpio
{

Led::Led(const gpio::OutputPin &pin) : _pin{pin} {}

const gpio::OutputPin &Led::getPin() const
{
    return _pin;
}

void Led::turnOn() const
{
    getPin().write(true);
}

void Led::turnOff() const
{
    getPin().write(false);
}

void Led::blink(const float freq, const unsigned short sec) const
{
    float time = sec / freq;

    for (int i = 0; i + 1 < sec * freq; ++i)
    {
        //accende il led
        turnOn();
        //aspetta x millisecondi
        delay(time * 1000);
        //spegni
        turnOff();
        //aspetta
        delay(time * 1000);
    }
}
}