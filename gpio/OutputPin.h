#ifndef LIBPI_OUTPUTPIN_H
#define LIBPI_OUTPUTPIN_H

#include "Pin.h"

namespace gpio
{
class OutputPin : public Pin
{
public:
  /**
   * @brief Constructor
   * 
   * @param pin Pin number according to BCM numeration system
   */
  OutputPin(const unsigned short &pin);

  /**
   * @brief Returns the type of connection
   * 
   * @return Type of connection
   */
  virtual gpio::ConnectionType getConnectionType() const override;

  /**
   * @brief Writes a value on this pin
   * 
   * @param val Value to be written
   */
  void write(bool val) const;

  /**
   * @brief Destructor
   * 
   */
  virtual ~OutputPin()
  {
  }
};
} // namespace gpio

#endif //LIBPI_OUTPUTPIN_H
