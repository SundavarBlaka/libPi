//
// Created by federico on 04/02/18.
//

#ifndef LIBPI_OUTPUTPIN_H
#define LIBPI_OUTPUTPIN_H

#include "Pin.h"
#include "Logic.h"

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
        OutputPin(const unsigned short pin, const std::string tag) : Pin(pin, Connection::Output, tag)
        {}

        /**
         * Ritorna il tipo della connessione
         * @return Tipo della connessione
         */
        virtual Connection getConnectionType() const override;

        void write(Logic val) const;

        virtual ~OutputPin()
        {}
    };
}

#endif //LIBPI_OUTPUTPIN_H
