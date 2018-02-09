//
// Created by federico on 03/02/18.
//

#include "Enum.h"

namespace lib
{
Enum::Enum(const std::string &nome, const int &val)
    : _enumName{nome}, _val{val}
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

bool Enum::operator==(const Enum &that) const
{
    return _enumName == that._enumName;
}

bool Enum::operator!=(const Enum &that) const
{
    return !(that == *this);
}

Enum::operator int() const
{
    return _val;
}

const int Enum::toInt() const
{
    return _val;
}

Enum::~Enum(){};
}