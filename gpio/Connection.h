//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_CONNECTION_H
#define LIBPI_CONNECTION_H

#include <string>
#include "Enum.h"

namespace gpio
{
    class Connection : public lib::Enum
    {
    protected:
        /**
         * Costruttore
         * @param nome Nome della costante
         */
        explicit Connection(const std::string &nome) : Enum{nome}
        {};

    public:
        /**
         * Costanti della enumerazione
         */
        static const Connection Input;
        static const Connection Output;
        static const Connection PwmOutput;
        static const Connection GpioClock;

        virtual ~Connection()
        {};
    };
}

#endif //LIBPI_CONNECTION_H
