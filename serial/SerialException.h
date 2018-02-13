#ifndef LIBPI_SERIALEXCEPTION_H
#define LIBPI_SERIALEXCEPTION_H

#include <stdexcept>
#include <string>

namespace serial
{
/**
 * @brief Represents a generic runtime error connected to serial communication
 * 
 */
class SerialException : public std::runtime_error
{
  public:
    /**
     * @brief Constructor
     * 
     * @param msg Error message
     */
    SerialException(const std::string &msg);

    virtual ~SerialException();
};
} // namespace serial

#endif //LIBPI_SERIALEXCEPTION_H
