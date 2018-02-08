//
// Created by federico on 08/02/18.
//

#ifndef LIBPI_SERIALCONNECTION_H
#define LIBPI_SERIALCONNECTION_H


#include <stdexcept>
#include "SerialException.h"

extern "C"
{
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
         * Costruttore
         * @param device Nome del dispositivo
         * @param baud Velocità della connsessione
         */
        SerialConnection(const std::string &device, const unsigned int &baud);

        /**
         * Ottiene la velocità della connessione
         * @return velocità della connessione
         */
        unsigned int getBaud() const;

        /**
         * Ottiene il nome del dispositivo
         * @return Nome del dispositivo
         */
        std::string getDeviceName() const;

        /**
         * Apre la connessione
         */
        void open();

        /**
         * Chiude la connessione
         */
        void close();

        /**
         * Scrive un carattere
         * @param c Carattere da scrivere
         */
        void write(const unsigned char &c) const;

        /**
         * Scrive una stringa
         * @param s Stringa da scrivere
         */
        void write(const std::string &s) const;

        /**
         * Ritorna il numero di caratteri rimanenti nel buffer
         * @return Numero di caratteri rimanenti
         */
        unsigned int getCharaters() const;

        /**
         * Legge un carattere dal buffer
         * @return Carattere letto
         */
        unsigned char read() const;

        /**
         * Distruttore
         */
        ~SerialConnection();
    };
}

#endif //LIBPI_SERIALCONNECTION_H
