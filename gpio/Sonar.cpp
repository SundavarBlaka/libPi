#include "Sonar.h"

namespace gpio
{

Sonar::Sonar(const OutputPin &trigger, const InputPin &echo, const unsigned int timeout)
    : _trigger{trigger}, _echo{echo}, _timeout{timeout}
{
}

Sonar::Sonar(const OutputPin &trigger, const InputPin &echo, const unsigned int maxDist)
    : _trigger{trigger}, _echo{echo}
{
    _timeout = ((2 * maxDist) / 343.8F) * 100000;
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

const unsigned int Sonar::getTimeout() const
{
    return _timeout;
}
} // namespace gpio