//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_LOGIC_H
#define LIBPI_LOGIC_H

#include "Enum.h"

namespace gpio
{
    class Logic : public lib::Enum
    {
    private:
        bool _val;
    protected:
        /**
         * Costruttore
         * @param nome Nome della costante
         */
        Logic(const std::string &nome, const bool val) : lib::Enum{nome}, _val{val}
        {};

    public:
        /**
         * Costanti della enumerazione
         */
        static const Logic High;
        static const Logic Low;

        /**
         * Converte il valore in logica binaria
         * @return Valore corrispondente in logica binaria
         */
        bool toBoolean() const;

        virtual ~Logic()
        {}
    };
}


#endif //LIBPI_LOGIC_H
