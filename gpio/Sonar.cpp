//
// Created by federico on 05/02/18.
//

#include "Sonar.h"

namespace gpio
{

Sonar::Sonar(const OutputPin &trigger, const InputPin &echo, const unsigned int timeout)
    : _trigger{trigger}, _echo{echo}, _timeout{timeout}
{
    _trigger.write(false);
    delay(500);
}

float Sonar::getDistance(bool &error) const
{
    //TODO spostare la procedura in un thread separato

    float res = 0;

    //assicurati che trigger sia false
    _trigger.write(false);
    delay(50);

    // invia un impulso
    _trigger.write(true);
    delayMicroseconds(10);
    _trigger.write(false);

    //salva il momento in cui inizia la ricerca
    unsigned long now = micros();

    while (_echo.read() == false && (micros() - now) <= _timeout)
    {
    }

    // Controlla il timeout
    if (micros() - now > _timeout)
    {
        std::cerr << "Fuori dal raggio d'azione" << std::endl;
        error = true;
    }
    else
    {
        unsigned long ping, pong;
        ping = micros();

        // Aspetta una risposta
        while (_echo.read() == true && (micros() - ping) <= _timeout)
        {
        }

        // Controlla il timeout
        if ((micros() - ping) > _timeout)
        {
            std::cerr << "Fuori dal raggio d'azione" << std::endl;
            error = true;
        }
        else
        {
            pong = micros();

            // Calcola la distanza
            res = (pong - ping) * 0.017150F;
            error = false;
        }
    }

    return res;
}

void Sonar::recordPulse(unsigned int &startTime, unsigned int &endTime) const
{
    startTime = micros();

    while (getEchoPin().read() == true)
    {
    }

    endTime = micros();
}

const OutputPin &Sonar::getTriggerPin() const
{
    return _trigger;
}

const InputPin &Sonar::getEchoPin() const
{
    return _echo;
}

const unsigned int Sonar::getTimeout() const
{
    return _timeout;
}
}