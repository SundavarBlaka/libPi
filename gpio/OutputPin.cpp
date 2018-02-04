//
// Created by federico on 04/02/18.
//

#include "OutputPin.h"

namespace gpio
{
    Connection OutputPin::getConnectionType() const
    {
        return Connection::Output;
    }

    void OutputPin::write(Logic val) const
    {
        int d = (val.toBoolean()) ? 1 : 0;

        digitalWrite(d);
    }
}