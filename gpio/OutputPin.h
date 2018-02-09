//
// Created by federico on 04/02/18.
//

#ifndef LIBPI_OUTPUTPIN_H
#define LIBPI_OUTPUTPIN_H

#include "Pin.h"

namespace gpio
{
class OutputPin : public Pin
{
  public:
    /**
         * Costruttore
         * @param pin Pin a cui collegarsi
         * @param tag Tag relativo al collegamento
         */
    OutputPin(const unsigned short &pin);

    /**
         * Ritorna il tipo della connessione
         * @return Tipo della connessione
         */
    virtual ConnectionType getConnectionType() const override;

    void write(bool val) const;

    virtual ~OutputPin()
    {
    }
};
}

#endif //LIBPI_OUTPUTPIN_H
