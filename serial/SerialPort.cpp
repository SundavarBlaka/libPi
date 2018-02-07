//
// Created by federico on 06/02/18.
//

#include "SerialPort.h"

namespace serial
{
    void SerialPort::open()
    {
        if (!_isOpen)
        {
            _fd = serialOpen(_device.c_str(), _baud);
            _isOpen = true;
        }
    }

    void SerialPort::close()
    {
        if (_isOpen)
        {
            serialClose(_fd);
            _fd = nullptr;
            _isOpen = false;
        }
    }

    const bool SerialPort::isOpen() const
    {
        return _isOpen;
    }

    const FILE *const SerialPort::getDescriptor() const
    {
        return _fd;
    }
}