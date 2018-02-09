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

const float Sonar::getDistance() const
{
    //TODO spostare la procedura in un thread separato

    //aspetta 10ms per essere sicuro di non accavallarsi alle onde riflesse
    delay(10);

    //invia un impulso di 10 us
    getTriggerPin().write(true);
    delayMicroseconds(10);
    getTriggerPin().write(false);

    //salva l'istante in cui inizia la ricerca
    unsigned int now = micros();

    //aspetta fino a che le condizioni necessarie per la rilevazione non si verificano
    while (getEchoPin().read() == false && micros() - now < _timeout)
    {
    }

    //tempi in us
    unsigned int startTime, endTime, travelTime;

    recordPulse(startTime, endTime);

    travelTime = endTime - startTime;

    //ritorna il calcolo della distanza
    return ((travelTime / 1000000.0F) * 340.29F) / 2;
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