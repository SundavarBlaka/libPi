//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_PUD_H
#define LIBPI_PUD_H

#include "Enum.h"

namespace gpio
{
    class Pud : public lib::Enum
    {
    protected:
        /**
         * Costruttore
         * @param nome Nome della costante
         */
        explicit Pud(const std::string &nome) : Enum{nome}
        {};

    public :
        /**
         * Costanti della enumerazione
         */
        static const Pud PullUpResistor;
        static const Pud PullDownResistor;
        static const Pud NoPull;

        virtual ~Pud()
        {};
    };
}

#endif //LIBPI_PUD_H
