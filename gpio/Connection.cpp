//
// Created by federico on 03/02/18.
//

#include "Connection.h"

namespace gpio
{
    const Connection Connection::Input = Connection("Input");
    const Connection Connection::Output = Connection("Output");
    const Connection Connection::PwmOutput = Connection("PwmOutput");
    const Connection Connection::GpioClock = Connection("GpioClock");
}