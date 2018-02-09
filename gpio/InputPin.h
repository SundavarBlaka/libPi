//
// Created by federico on 04/02/18.
//

#ifndef LIBPI_INPUTPIN_H
#define LIBPI_INPUTPIN_H

#include "Pin.h"

namespace gpio
{
class InputPin : public Pin
{
public:
  /**
   * Costruttore
   * @param pin Pin a cui collegarsi
   * @param tag Tag relativo alla connessione
   */
  InputPin(const unsigned short &pin);

  /**
   * Costruttore
   * @param pin Pin a cui collegarsi
   * @param pud Tipologia di resistenza
   * @param tag Tag relativo alla connessione
   */
  InputPin(const unsigned short &pin, const gpio::Pud &pud);

  /**
   * Ritorna il tipo della connessione
   * @return Tipo della connessione
   */
  virtual ConnectionType getConnectionType() const override;

  /**
   * Legge un dato dal pin
   * @return Dato letto
   */
  bool read() const;

  virtual ~InputPin();
};
}

#endif // LIBPI_INPUTPIN_H
