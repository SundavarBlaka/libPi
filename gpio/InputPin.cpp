#include "InputPin.h"

namespace gpio
{
InputPin::InputPin(const unsigned short &pin)
    : Pin{pin, ConnectionType::Input}
{
}

InputPin::InputPin(const unsigned short &pin, const gpio::Pud &pud)
    : Pin{pin, pud} {}

ConnectionType InputPin::getConnectionType() const
{
    return ConnectionType::Input;
}

bool InputPin::read() const
{
    int val = digitalRead(getPinNumber());

    return (val == 0) ? false : true;
}

InputPin::~InputPin()
{
}
} // namespace gpio