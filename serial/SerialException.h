//
// Created by federico on 06/02/18.
//

#ifndef LIBPI_SERIALEXCEPTION_H
#define LIBPI_SERIALEXCEPTION_H

#include <string>
#include <stdexcept>

namespace serial
{
    class SerialException : public std::runtime_error
    {
    public:

        explicit SerialException(const char* msg);
    };
}

#endif //LIBPI_SERIALEXCEPTION_H
