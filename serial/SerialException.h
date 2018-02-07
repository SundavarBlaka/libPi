//
// Created by federico on 06/02/18.
//

#ifndef LIBPI_SERIALEXCEPTION_H
#define LIBPI_SERIALEXCEPTION_H

#include <exception>
#include <string>

namespace serial
{
    class SerialException : public std::exception
    {
    private:
        std::string msg;
    public:

        SerialException(const std::string &msg) : exception()
        {}

        const char* what() const override;

        virtual ~SerialException()
        {};
    };
}

#endif //LIBPI_SERIALEXCEPTION_H
