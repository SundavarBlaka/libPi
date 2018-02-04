//
// Created by federico on 04/02/18.
//

#include "Led.h"

namespace gpio
{
    const gpio::OutputPin *const Led::getPin() const
    {
        return &_pin;
    }

    void Led::turnOn() const
    {
        getPin()->write(Logic::High);
    }

    void Led::turnOff() const
    {
        getPin()->write(Logic::Low);
    }

    void Led::blink(const unsigned float freq, const unsigned short sec) const
    {
        float time = sec / freq;

        std::chrono::duration<int, std::milli> timespan(time * 1000);

        for (int i = 0; i + 1 < sec * freq; ++i)
        {
            //accende il led
            turnOn();
            //aspetta x millisecondi
            std::this_thread::sleep_for(timespan);
            //spegni
            turnOff();
            //aspetta
            std::this_thread::sleep_for(timespan);
        }

    }
}