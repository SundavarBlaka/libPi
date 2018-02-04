//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_PIN_H
#define LIBPI_PIN_H

#include <string>
#include <stdexcept>
#include <ostream>
#include "wiringPi.h"
#include "Pud.h"
#include "Connection.h"

namespace gpio
{
    /**
     * Rappresenta un pin di Raspberry
     */
    class Pin
    {
    private:
        unsigned short _num;
        gpio::Connection _type;
        std::string _tag;
        gpio::Pud _pud;
        static unsigned short _maxPinNumber;       //massimo numero che i pin possono assumere
        static bool _isSystemSetUp = false;        //indica se il sistema è pronto all'uso

        /**
         * Controlla i parametri passati al costruttore
         * @param pinNumber numero del pin da controllare
         */
        void checkCtor(unsigned short pinNumber) const;

        /**
         * Effettua il setup reale del pin
         * @param pinNumber Numero del pin
         * @param type Tipo della connessione
         * @param pud Resistenza pullUp/Down
         */
        void setupPin(unsigned short pinNumber, gpio::Connection type, gpio::Pud pud);

        /**
        * Ritorna il numero massimo che può essere associato ad un pin
        * @return Numero massimo valido
        */
        unsigned short getMaxPinNumber() const;

        /**
         * Imposta il numero massimo che i pin possono assumere
         */
        void setMaxPinNumber(unsigned short max);

        /**
        * Effettua il setup preliminare dei pin.
        * Questo metodo deve essere eseguito prima di utilizzare i pin.
        */
        void setup();

        /**
        * Ritorna se è stato effettuato il setup dei pin
        * @return vero se è stato effettuato il setup dei pin, falso altrimenti
        */
        bool isSystemSetUp() const;

    public:

        /**
         * Costruttore. Non è previsto nessun resistore PUD
         * @param pinNumber Numero del pin secondo la numerazione BroadCom
         * @param type Tipo della connessione
         * @param tag Tag
         */
        Pin(const unsigned short pinNumber, const gpio::Connection type, const std::string tag = "no tag")
                : _num{pinNumber}, _type{type}, _tag{tag}, _pud{Pud::NoPull}
        {
            //Controlla che sia stato effettuato il setup
            if (!Pin::isSystemSetUp())
            {
                setup();
            }

            checkCtor(pinNumber);
            setupPin(pinNumber, type, Pud::NoPull);
        }

        /**
         * Costruttore. Non è previsto nessun resistore PUD
         * @param pinNumber Numero del pin secondo la numerazione BroadCom
         * @param pud Resistenza pullUp/Down
         * @param tag Tag
         */
        Pin(const unsigned short pinNumber, const gpio::Pud pud, const std::string tag = "no tag")
                : _num{pinNumber}, _type{Connection::Input}, _tag{tag}, _pud{pud}
        {
            //Controlla che sia stato effettuato il setup
            if (!Pin::isSystemSetUp())
            {
                setup();
            }

            checkCtor(pinNumber);
            setupPin(pinNumber, Connection::Input, pud);
        }

        /**
         * Distruttore
         */
        virtual ~Pin()
        {}

        /**
         * Ritorna il numero del pin associato
         * @return Numero del pin associato
         */
        virtual unsigned short getPinNumber() const;

        /**
         * Ritorna il tipo della connessione
         * @return Tipo della connessione
         */
        virtual gpio::Connection getConnectionType() const = 0;

        /**
         * Ritorna il tag associato al pin
         * @return Tag associato al pin
         */
        virtual std::string getTag() const;

        /**
         * Ritorna L'istanza di Pud associata
         * @return PUD
         */
        virtual Pud getPud() const;

        /**
         * Operatore di uguaglianza
         * @param that Pin da confrontare
         * @return vero se i due pin sono uguali, falso altrimenti
         */
        virtual bool operator==(const Pin &that) const;

        /**
         * Operatore di disuguaglianza
         * @param that Pin da confrontare
         * @return vero se i due pin sono diversi, falso altrimenti
         */
        virtual bool operator!=(const Pin &that) const;
    };
}

#endif //LIBPI_PIN_H
