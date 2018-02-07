//
// Created by federico on 06/02/18.
//

#ifndef LIBPI_CONNECTION_H
#define LIBPI_CONNECTION_H

#include "SerialPort.h"

extern "C"
{
#include <wiringSerial.h>
};

namespace serial
{
    class Connection
    {
    private:
        SerialPort _port;

    public:
        /**
         * Cosruttore
         * @param port Porta attraverso cui comunicare
         */
        Connection(const SerialPort &port) : _port{port}
        {}

        /**
         * trasferisc un singolo carattere attraverso la porta
         * @param c Carattere da trasferire
         */
        void send(const unsigned char c);

        /**
         * Trasferisce uns stringa attraverso la porta
         * @param s Stringa da trasferire
         */
        void send(const std::string &s);

        /**
         * Legge un carattere dalla porta
         * @return Carattere letto
         */
        char receive();

        /**
         * Legge tutto ciò che è presente sul buffer
         * @return Stringa letta
         */
        std::string receiveAll();

        /**
         * Ritorna il numero di caratteri ancora disponibili nel buffer da leggere
         * @return Numero di caratteri
         */
        unsigned int getAvailable();

        /**
         * Svuota il buffer
         */
        void flush();
    };
}

#endif //LIBPI_CONNECTION_H
