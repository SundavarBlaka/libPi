//
// Created by federico on 03/02/18.
//

#include "Logic.h"

namespace gpio
{
    const Logic Logic::High = Logic("High", true);
    const Logic Logic::Low = Logic("Low", false);

    bool Logic::toBoolean() const
    {
        return _val;
    }

    bool Logic::operator==(const Logic &that) const
    {
        return toBoolean() == that.toBoolean();
    }

    bool Logic::operator!=(const Logic &that) const
    {
        return !(rhs == *this);
    }
}