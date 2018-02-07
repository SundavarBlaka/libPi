//
// Created by federico on 04/02/18.
//

#ifndef LIBPI_LED_H
#define LIBPI_LED_H

#include <chrono>
#include <thread>
#include "Device.h"
#include "Logic.h"
#include "OutputPin.h"

namespace gpio
{
    class Led : public gpio::Device
    {
    private:
        gpio::OutputPin _pin;


        const gpio::OutputPin *const getPin() const;

    public:
        Led(const gpio::OutputPin &pin, const std::string &name) : _pin{pin}, Device(name)
        {}

        /**
         * accende il led
         */
        virtual void turnOn() const;

        /**
         * spegne il led
         */
        virtual void turnOff() const;

        /**
         * fa lampeggiare il led con una certa frequenza
         * @param freq Frequenza del lampeggiante
         */
        virtual void blink(const unsigned float freq, const unsigned short sec) const;
    };
}
#endif //LIBPI_LED_H
