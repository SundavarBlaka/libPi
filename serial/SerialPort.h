//
// Created by federico on 06/02/18.
//

#ifndef LIBPI_SERIAL_H
#define LIBPI_SERIAL_H

#include <cstdio>
#include <cstring>
#include <memory>
#include "Connection.h"

extern "C"
{
#include <wiringSerial.h>
};

namespace serial
{
    class SerialPort
    {
        friend class Connection;

    private:
        std::string _device;
        unsigned int _baud;
        FILE *_fd;
        bool _isOpen;

        /**
        * Ottiene un FILE* per comunicare con la porta.
        * Tale metodo
        * @return
        */
        const FILE *const getDescriptor() const;

    public:
        /**
         * Costruttore
         * @param device Nome del file da aprire per la comunicazione
         * @param baud Baud rate
         */
        SerialPort(const std::string &device, const int &baud) : _device{device}, _baud{baud}, _isOpen{false}
        {}

        /**
         * Apre una connessione. La connessione va chiusa manualmente dopo essere stata aperta
         * per poter consentire al flusso di dati di essere trasferito
         */
        void open();

        /**
         * Chiude la connessione
         */
        void close();

        /**
         * Testa se la connsessione è aperta.
         * @return true se la connessione è aperta
         */
        const bool isOpen() const;
    };
}

#endif //LIBPI_SERIAL_H
