#ifndef LIBPI_LED_H
#define LIBPI_LED_H

#include "OutputPin.h"

namespace gpio
{
/**
 * @brief Represents a generic led
 * 
 */
class Led
{
private:
  gpio::OutputPin _pin;
  bool _status;

public:
  /**
   * @brief Constructor
   * 
   * @param pin OutputPin connectoed to the led
   */
  Led(const gpio::OutputPin &pin);

  /**
   * @brief Turns on the led
   * 
   */
  virtual void turnOn() const;

  /**
   * @brief Turns off the led
   * 
   */
  virtual void turnOff() const;

  /**
   * @brief Makes the led blink with the specified frequncy for the given time
   * 
   * @param freq Frequency
   * @param sec Duration
   */
  virtual void blink(const float freq, const unsigned short sec) const;

  /**
   * @brief Destructor
   * 
   */
  virtual ~Led();
};
} //namespace gpio

#endif //LIBPI_LED_H
