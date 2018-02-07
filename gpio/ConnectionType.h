//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_CONNECTION_H
#define LIBPI_CONNECTION_H

#include <string>
#include "Enum.h"

namespace gpio
{
    class ConnectionType : public lib::Enum
    {
    protected:
        /**
         * Costruttore
         * @param nome Nome della costante
         */
        explicit ConnectionType(const std::string &nome) : Enum{nome}
        {};

    public:
        /**
         * Costanti della enumerazione
         */
        static const ConnectionType Input;
        static const ConnectionType Output;
        static const ConnectionType PwmOutput;
        static const ConnectionType GpioClock;

        virtual ~ConnectionType()
        {};
    };
}

#endif //LIBPI_CONNECTION_H
