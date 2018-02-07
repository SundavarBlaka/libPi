//
// Created by federico on 06/02/18.
//

#include "SerialException.h"

namespace serial
{
    const char *SerialException::what() const
    {
        return msg.c_str();
    }
}