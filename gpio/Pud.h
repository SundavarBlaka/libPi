//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_PUD_H
#define LIBPI_PUD_H

namespace gpio
{
/**
 * @brief Descrive una resistenza pullUp o pullDown integrata nel circuito
 * 
 */
enum class Pud : unsigned short
{
  NoPull,
  PullUpResistor,
  PullDownResistor
};
}

#endif //LIBPI_PUD_H
