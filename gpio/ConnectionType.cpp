//
// Created by federico on 03/02/18.
//

#include "ConnectionType.h"

namespace gpio
{
    const ConnectionType ConnectionType::Input = ConnectionType("Input");
    const ConnectionType ConnectionType::Output = ConnectionType("Output");
    const ConnectionType ConnectionType::PwmOutput = ConnectionType("PwmOutput");
    const ConnectionType ConnectionType::GpioClock = ConnectionType("GpioClock");
}