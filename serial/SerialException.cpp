//
// Created by federico on 06/02/18.
//

#include "SerialException.h"

namespace serial
{
    SerialException::SerialException(const char *msg) : std::runtime_error(msg)
    {

    }
}