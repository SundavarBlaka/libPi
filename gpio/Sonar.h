#ifndef LIBPI_SONAR_H
#define LIBPI_SONAR_H

#include "InputPin.h"
#include "OutputPin.h"
#include <iostream>

extern "C" {
#include "wiringPi.h"
};

namespace gpio
{
/**
 * @brief Represents a generic sonar with a trigger and an echo pin
 * 
 */
class Sonar
{
private:
  OutputPin _trigger;
  InputPin _echo;
  //In ms
  unsigned int _timeout;

public:
  /**
   * @brief Constructor
   * 
   * @param trigger Trigger pin
   * @param echo Echo pin
   * @param timeout Amount of time (in ms) to wait before stopping the research
   */
  Sonar(const OutputPin &trigger, const InputPin &echo, const unsigned int timeout);

  /**
   * @brief Constructor
   * 
   * @param trigger Trigger pin
   * @param echo Echo pin
   * @param maxDist Maximum distance to be measured in m
   */
  Sonar(const OutputPin &trigger, const InputPin &echo, const unsigned int maxDist);

  /**
   * @brief Returns the distance between the sensor and the object
   * 
   * @return Measured distance
   */
  float getDistance(bool &error) const;

  /**
   * @brief Returns the timeout
   * 
   * @return Timeout
   */
  const unsigned int getTimeout() const;
};
} // namespace gpio

#endif //LIBPI_SONAR_H
