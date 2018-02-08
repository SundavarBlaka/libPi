//
// Created by federico on 08/02/18.
//

#include "SerialConnection.h"

namespace serial
{
    SerialConnection::SerialConnection(const std::string &device, const unsigned int &baud)
            : _device{device}, _baud{baud}, _isOpened{false}
    {
        std::string in = device.substr(0, 8);

        if (in != "/dev/tty")
        {
            throw std::invalid_argument{"Il nome del file non rappresenta una porta seriale" + device};
        }
    }

    unsigned int SerialConnection::getBaud() const
    {
        return _baud;
    }

    std::string SerialConnection::getDeviceName() const
    {
        return _device;
    }

    void SerialConnection::open()
    {
        int res = serialOpen(_device.c_str(), _baud);

        if (res == -1)
        {
            throw SerialException{"Impossibile aprire la connessione"};
        }

        _fd = res;
        _isOpened = true;
    }

    void SerialConnection::close()
    {
        serialClose(_fd);
        _isOpened = false;
    }

    //TODO controllare che la connessione sia aperta durante i trasferimenti

    void SerialConnection::write(const unsigned char &c) const
    {
        serialPutchar(_fd, c);
    }

    void SerialConnection::write(const std::string &s) const
    {
        serialPuts(_fd, s.c_str());
    }

    unsigned int SerialConnection::getCharaters() const
    {
        return serialDataAvail(_fd);
    }

    unsigned char SerialConnection::read() const
    {
        int res;
        if (getCharaters() > 0)
        {
            res = serialGetchar(_fd);
        } else
        {
            res = '\0';
        }

        if (res < 0)
        {
            throw SerialException{"Qualcosa è andato storto durante la lettura di un carattere"};
        }

        return static_cast<unsigned char>(res);
    }

    SerialConnection::~SerialConnection()
    {
        if (_isOpened)
        {
            this->close();
        }
    }
}