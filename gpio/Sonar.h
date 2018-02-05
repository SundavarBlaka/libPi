//
// Created by federico on 05/02/18.
//

#ifndef LIBPI_SONAR_H
#define LIBPI_SONAR_H

#include "Device.h"
#include "InputPin.h"
#include "OutputPin.h"
#include "wiringPi.h"

namespace gpio
{
    class Sonar : public Device
    {
    private:
        OutputPin _trigger;
        InputPin _echo;
        unsigned int _timeout;

        /**
         * Constrolla la correttezza del costruttore
         * @param tag Nome del dispositivo
         */
        void checkCtor(const std::string &tag) const;

        void recordPulse(unsigned int &startTime, unsigned int &endTime) const;

    public:

        /**
         * Costruttore
         * @param echo Pin per la ricezione del segnale
         * @param trigger Pin per l'attivazione del sensore
         * @timeout Tempo da attendere prima di annullare l'operazione in millisecondi
         * @param tag Nome del dispositivo
         */
        Sonar(const InputPin &echo, const OutputPin &trigger, const std::string &tag, const unsigned int timeout = 150)
                : _echo{echo}, _trigger{trigger}, _timeout{timeout}, Device{tag}
        {
            checkCtor(tag);

            _trigger.write(Logic::Low);
            delay(500);
        }

        /**
         * Ottiene la distanza misurata dal sensore
         * @return Distanza misurata
         */
        const unsigned float getDistance() const;

        /**
         * Getter
         * @return
         */
        const OutputPin &getTriggerPin() const;

        const InputPin &getEchoPin() const;

        const unsigned int getTimeout() const;
    };
}

#endif //LIBPI_SONAR_H
