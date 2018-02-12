#ifndef LIBPI_PIN_H
#define LIBPI_PIN_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "ConnectionType.h"
#include "Pud.h"

extern "C" {
#include "wiringPi.h"
};

//TODO: impedire la creazione di un pin se non è stato eseguito il setup dei pin

namespace gpio
{
/**
 * @brief Represents a pin
 * 
 */
class Pin
{
private:
//TODO: eliminare la costante una volta implementato System
#define MAXPIN 40

  unsigned short _num;
  gpio::ConnectionType _type;
  gpio::Pud _pud;
  bool _status;

  /**
   * @brief Checks params given to the constructor
   * 
   * @param pinNumber Pin's number according to BCM numeration system
   */
  void checkCtor(const unsigned short &pinNumber) const;

  /**
   * @brief Performs the real pin setup
   * 
   * @param pinNumber Pin's number according to BCM numeration system
   * @param type Type of the connection
   * @param pud Type of the resistor
   */
  void setupPin(const unsigned short &pinNumber, const gpio::ConnectionType &type, const gpio::Pud &pud);

public:
  /**
   * @brief Constructor. No internal resistor is provided
   * 
   * @param pinNumber Pin number according to BCM numeration system
   * @param type Type of the connection
   */
  Pin(const unsigned short &pinNumber, const gpio::ConnectionType &type);

  /**
   * @brief Constructor. The connection Type is implicitly ConnectionType::Input
   * 
   * @param pinNumber Pin number according to BCM numeration system
   * @param pud Type of the resistor
   */
  Pin(const unsigned short &pinNumber, const gpio::Pud &pud);

  /**
   * @brief Destructor
   * 
   */
  virtual ~Pin();

  /**
   * @brief Returns the associated BCM pin number
   * 
   * @return BCM pin number
   */
  virtual unsigned short getPinNumber() const;

  /**
   * @brief Returns the connection type
   * 
   * @return Connection type associated to the pin
   */
  virtual gpio::ConnectionType getConnectionType() const = 0;

  /**
   * @brief Returns the type of internal resistor
   * 
   * @return Type of internal resistor
   */
  virtual gpio::Pud getPud() const;

  /**
   * @brief Returns the status
   * 
   * @return Status of the pin (on/off) 
   */
  virtual bool getStatus() const;

  /**
   * @brief Performs the initial pins setup. It must be called at the beginning of every program which uses gpio namespace
   * 
   */
  static void setup();

  /**
   * @brief Equality operator
   * 
   * @param that Pin to be compared
   * @return true If pins are equal
   * @return false If pins are different
   */
  virtual bool operator==(const Pin &that) const;

  /**
   * @brief Inequality operator
   * 
   * @param that Pin to be compared
   * @return true If pins are different
   * @return false If pins are equal
   */
  virtual bool operator!=(const Pin &that) const;
};
} // namespace gpio

#endif // LIBPI_PIN_H
