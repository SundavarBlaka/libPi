//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_ENUM_H
#define LIBPI_ENUM_H

#include <stdexcept>
#include <string>

namespace lib
{

    class Enum
    {
    private:
        std::string _enumName;

    protected:
        /**
         * Costruttore
         * @param nome Nome della costante
         */
        explicit Enum(const std::string &nome);

    public:
        virtual std::string toString() const;

        bool operator==(const Enum &rhs) const;

        bool operator!=(const Enum &rhs) const;

        virtual ~Enum()
        {};
    };
}
#endif //LIBPI_ENUM_H
