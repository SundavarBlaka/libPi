#include "Led.h"

namespace gpio
{

Led::Led(const gpio::OutputPin &pin) : _pin{pin}, _status{false}
{
    //se il pin è acceso
    if (_pin.getStatus())
    {
        _pin.write(false);
    }
}

void Led::turnOn() const
{
    //se il pin è spento accendilo
    if (!_status)
    {
        _pin.write(true);
    }
}

void Led::turnOff() const
{
    //se il pin è acceso spegnilo
    if (_status)
    {
        _pin.write(false);
    }
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

Led::~Led()
{
}
} //namespace gpio