#ifndef LIBPI_SERIALCONNECTION_H
#define LIBPI_SERIALCONNECTION_H

#include <stdexcept>
#include <iostream>
#include "SerialException.h"

extern "C" {
#include "wiringSerial.h"
};

namespace serial
{
class SerialConnection
{
  private:
    std::string _device;
    unsigned int _baud;
    int _fd;
    bool _isOpened;

  public:
    /**
     * @brief Constructor
     * 
     * @param device Device to connect to
     * @param baud Baud
     */
    SerialConnection(const std::string &device, const unsigned int &baud);

    /**
     * @brief Returns the baud
     * 
     * @return Baud 
     */
    unsigned int getBaud() const;

    /**
     * @brief Gets the device's name
     * 
     * @return Device's name 
     */
    std::string getDeviceName() const;

    /**
     * @brief Opens the connections
     * 
     * @throw SerialException
     */
    void open();
    
    /**
     * @brief Closes the connection
     * 
     */
    void close();

    /**
     * @brief Writes a character
     * 
     * @throw SerialException
     * 
     * @param c Charater to write
     */
    void write(const unsigned char &c) const;

    /**
     * @brief Writes a string
     * 
     * @throw SerialException
     * 
     * @param s String to write
     */
    void write(const std::string &s) const;

    /**
     * @brief Returns the number of remaining charaters inside the buffer
     * 
     * @throw SerialException
     * 
     * @return Number of characters
     */
    unsigned int getCharaters() const;

    /**
     * @brief Reads a character from the buffer
     * 
     * @throw SerialException
     * 
     * @return Character read
     */
    unsigned char read() const;

    /**
     * @brief Destructor
     * 
     */
    ~SerialConnection();
};
} // namespace serial

#endif //LIBPI_SERIALCONNECTION_H
