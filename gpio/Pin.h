//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_PIN_H
#define LIBPI_PIN_H

#include <string>
#include <stdexcept>
#include <ostream>
#include "Pud.h"
#include "ConnectionType.h"

extern "C"
{
#include "wiringPi.h"
};

namespace gpio
{
    /**
     * Rappresenta un pin di Raspberry
     */
    class Pin
    {
    private:
        unsigned short _num;
        gpio::ConnectionType _type;
        std::string _tag;
        gpio::Pud _pud;
        static unsigned short _maxPinNumber;       //massimo numero che i pin possono assumere

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
        void setupPin(const unsigned short pinNumber, const gpio::ConnectionType &type, const gpio::Pud &pud);

        /**
        * Ritorna il numero massimo che può essere associato ad un pin
        * @return Numero massimo valido
        */
        unsigned short getMaxPinNumber() const;

        /**
         * Imposta il numero massimo che i pin possono assumere
         */
        static void setMaxPinNumber(unsigned short max);

    public:

        /**
         * Costruttore. Non è previsto nessun resistore PUD
         * @param pinNumber Numero del pin secondo la numerazione BroadCom
         * @param type Tipo della connessione
         * @param tag Tag
         */
        Pin(const unsigned short pinNumber, const gpio::ConnectionType &type, const std::string &tag = "no tag")
                : _num{pinNumber}, _type{type}, _tag{tag}, _pud{Pud::NoPull}
        {
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
                : _num{pinNumber}, _type{ConnectionType::Input}, _tag{tag}, _pud{pud}
        {
            checkCtor(pinNumber);
            setupPin(pinNumber, ConnectionType::Input, pud);
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
        virtual gpio::ConnectionType getConnectionType() const = 0;

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
        * Effettua il setup preliminare dei pin.
        * Questo metodo deve essere eseguito prima di utilizzare i pin.
        */
        static void setup();

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
