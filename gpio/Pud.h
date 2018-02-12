#ifndef LIBPI_PUD_H
#define LIBPI_PUD_H

namespace gpio
{
/**
 * @brief Describes the type of resistor applied to the pin
 * 
 */
enum class Pud : unsigned short
{
  NoPull,
  PullUpResistor,
  PullDownResistor
};
} // namespace gpio

#endif //LIBPI_PUD_H
