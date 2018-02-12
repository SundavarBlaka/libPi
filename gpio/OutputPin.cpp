#include "OutputPin.h"

namespace gpio
{

OutputPin::OutputPin(const unsigned short &pin)
    : Pin(pin, ConnectionType::Output)
{
}

gpio::ConnectionType OutputPin::getConnectionType() const
{
    return ConnectionType::Output;
}

void OutputPin::write(bool val) const
{
    int d = (val) ? 1 : 0;

    digitalWrite(getPinNumber(), d);
}
} // namespace gpio