//
// Created by federico on 04/02/18.
//

#include "InputPin.h"

namespace gpio
{
    Connection InputPin::getConnectionType() const
    {
        return Connection::Input;
    }

    gpio::Logic InputPin::read() const
    {
        int val = digitalRead(getPinNumber());

        return (val == 0) ? Logic::Low : Logic::High;
    }
}