#include "SerialConnection.h"

namespace serial
{
SerialConnection::SerialConnection(const std::string &device, const unsigned int &baud)
    : _device{device}, _baud{baud}, _isOpened{false}
{
    //TODO: controllare che il nome del dispositivo sia effettivante presente
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
    if (!_isOpened)
    {
        int res = serialOpen(_device.c_str(), _baud);

        if (res == -1)
        {
            throw SerialException{"Impossibile aprire la connessione"};
        }

        _fd = res;
        _isOpened = true;
    }
}

void SerialConnection::close()
{
    if (_isOpened)
    {
        serialClose(_fd);
        _isOpened = false;
    }
}

void SerialConnection::write(const unsigned char &c) const
{
    if (_isOpened)
    {
        serialPutchar(_fd, c);
    }
    else
    {
        throw SerialException{"Connection is closed, unable to write"};
    }
}

void SerialConnection::write(const std::string &s) const
{
    if (_isOpened)
    {
        serialPuts(_fd, s.c_str());
    }
    else
    {
        throw SerialException{"Connection is closed, unable to write"};
    }
}

unsigned int SerialConnection::getCharaters() const
{
    unsigned int res;

    if (_isOpened)
    {
        res = serialDataAvail(_fd);
    }
    else
    {
        std::cerr << "The connection is closed. Returning 0" << std::endl;
        res = 0;
    }

    return res;
}

unsigned char SerialConnection::read() const
{
    int res = '\0';

    if (_isOpened && getCharaters() > 0)
    {
        res = serialGetchar(_fd);
    }
    else
    {
        throw SerialException{"Unable to read"};
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
} // namespace serial