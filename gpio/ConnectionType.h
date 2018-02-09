//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_CONNECTION_H
#define LIBPI_CONNECTION_H

#include <string>

namespace gpio
{
enum class ConnectionType : unsigned short
{
  Input,
  Output,
  PwmOutput,
  GpioClock
};
}

#endif //LIBPI_CONNECTION_H
