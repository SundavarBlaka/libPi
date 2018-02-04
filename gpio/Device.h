//
// Created by federico on 04/02/18.
//

#ifndef LIBPI_DEVICE_H
#define LIBPI_DEVICE_H

#include <string>

namespace gpio
{
    class Device
    {
    private:
        const std::string _name;

    protected:
        Device(const std::string name) : _name{name}
        {}

    public:
        /**
         * Ritorna il nome del dispositivo
         * @return Nome del dispositivo
         */
        virtual const std::string getName() const;
    };
}
#endif //LIBPI_DEVICE_H
