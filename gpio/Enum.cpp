//
// Created by federico on 03/02/18.
//

#include "Enum.h"

namespace lib
{
    Enum::Enum(const std::string &nome)
    {
        if (nome.empty())
        {
            throw std::invalid_argument("Nome non valido");
        }
    }

    std::string Enum::toString() const
    {
        return _enumName;
    }

    bool Enum::operator==(const Enum &rhs) const
    {
        return _enumName == rhs._enumName;
    }

    bool Enum::operator!=(const Enum &rhs) const
    {
        return !(rhs == *this);
    }
}