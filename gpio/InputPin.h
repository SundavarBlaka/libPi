#ifndef LIBPI_INPUTPIN_H
#define LIBPI_INPUTPIN_H

#include "Pin.h"

namespace gpio
{
/**
 * @brief Describes an input pin 
 * 
 */
class InputPin : public Pin
{
public:
  /**
   * @brief Constructor
   * 
   * @param pin Pin number according to BCM numeration system
   */
  InputPin(const unsigned short &pin);

  /**
   * @brief Constructor
   * 
   * @param pin Pin number according to BCM numeration system
   * @param pud Internal resistor
   */
  InputPin(const unsigned short &pin, const gpio::Pud &pud);

  /**
   * @brief Returns the type of connection
   * 
   * @return Type of connection
   */
  virtual gpio::ConnectionType getConnectionType() const override;

  /**
   * @brief Reads from the pin
   * 
   * @return Pin status
   */
  bool read() const;

  /**
   * @brief Destructor
   * 
   */
  virtual ~InputPin();
};
} // namespace gpio

#endif // LIBPI_INPUTPIN_H
