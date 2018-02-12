#ifndef LIBPI_CONNECTION_H
#define LIBPI_CONNECTION_H

#include <string>

namespace gpio
{
/**
 * @brief Describes all possible connection's types
 * 
 */
enum class ConnectionType : unsigned short
{
  Input,
  Output,
  PwmOutput,
  GpioClock
};
} // namespace gpio

#endif //LIBPI_CONNECTION_H
