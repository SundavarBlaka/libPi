//
// Created by federico on 06/02/18.
//

#include <vector>
#include "Connection.h"
#include "SerialException.h"

namespace serial
{
    void Connection::send(const unsigned char c)
    {
        //apro la connessione
        _port.open();

        if (_port.isOpen())
        {
            //ottengo il FILE* in cui scrivere
            const FILE *fd = _port.getDescriptor();

            //scrivo nella porta
            serialPutchar(fd, c);
        } else
        {
            throw SerialException("Errore: la connessione non è aperta");
        }

        //chiudi la connessione
        _port.close();
    }

    void Connection::send(const std::string &s)
    {
        //apro la connessione
        _port.open();

        if (_port.isOpen())
        {
            //ottengo il FILE* in cui scrivere
            const FILE *fd = _port.getDescriptor();

            //scrivo nella porta
            serialPuts(fd, s.c_str());
        } else
        {
            throw SerialException("Errore: la connessione non è aperta");
        }

        //chiudi la connessione
        _port.close();
    }

    char Connection::receive()
    {
        char c;
        //apro la connessione
        _port.open();

        if (_port.isOpen())
        {
            //ottengo il FILE* in cui scrivere
            const FILE *fd = _port.getDescriptor();

            //leggo nella porta
            c = serialGetchar(fd);
        } else
        {
            throw SerialException("Errore: la connessione non è aperta");
        }

        //chiudi la connessione
        _port.close();

        return c;
    }

    std::string Connection::receiveAll()
    {
        //carattere letto
        char c;
        //buffer
        std::vector<char> buf;

        //apro la connessione
        _port.open();

        if (_port.isOpen())
        {
            //ottengo il FILE* in cui scrivere
            const FILE *fd = _port.getDescriptor();

            //fino a che ci sono caratteri da leggere leggi e salva nel buffer
            while(serialDataAvail(fd) > 0)
            {
                //leggo dalla porta
                c = serialGetchar(fd);

                buf.push_back(c);
            }
        } else
        {
            throw SerialException("Errore: la connessione non è aperta");
        }

        //chiudi la connessione
        _port.close();

        //costruisco la stringa dal buffer
        std::string res{buf.begin(), buf.end()};

        return res;
    }

    unsigned int Connection::getAvailable()
    {
        unsigned int res;
        //apro la connessione
        _port.open();

        if (_port.isOpen())
        {
            //ottengo il FILE* in cui scrivere
            const FILE *fd = _port.getDescriptor();

            //scrivo nella porta
            res = serialDataAvail(fd);
        } else
        {
            throw SerialException("Errore: la connessione non è aperta");
        }

        //chiudi la connessione
        _port.close();

        return res;
    }
}