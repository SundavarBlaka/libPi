#include "SerialException.h"

namespace serial
{
SerialException::SerialException(const std::string &msg) : std::runtime_error(msg)
{
}

SerialException::~SerialException()
{
    std::runtime_error::~runtime_error();
}
} // namespace serial