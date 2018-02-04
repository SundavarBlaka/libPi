//
// Created by federico on 03/02/18.
//

#include "Pud.h"

namespace gpio
{
    const Pud Pud::PullUpResistor = Pud{"PullUpResistor"};
    const Pud Pud::PullDownResistor = Pud{"PullDownResistor"};
    const Pud Pud::NoPull = Pud{"NoPull"};
}