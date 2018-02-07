//
// Created by federico on 03/02/18.
//

#include "Pin.h"

namespace gpio
{
    unsigned short Pin::getPinNumber() const
    {
        return _num;
    }

    std::string Pin::getTag() const
    {
        return _tag;
    }

    Pud Pin::getPud() const
    {
        return _pud;
    }

    unsigned short Pin::getMaxPinNumber() const
    {
        return _maxPinNumber;
    }

    void Pin::checkCtor(const unsigned short pinNumber) const
    {
        if (pinNumber <= 0 || pinNumber > getMaxPinNumber())
        {
            throw std::invalid_argument("Pin number must be between 1 and" + getMaxPinNumber());
        }
    }

    void Pin::setupPin(const unsigned short pinNumber, const gpio::ConnectionType &type, const gpio::Pud &pud)
    {
        //procedi normalmente
        int mode, pullMode;

        switch (type)
        {
            case ConnectionType::Input:
            {
                mode = INPUT;
                break;
            }
            case ConnectionType::Output:
            {
                mode = OUTPUT;
                break;
            }
            case ConnectionType::PwmOutput:
            {
                mode = PWM_OUTPUT;
                break;
            }
            case ConnectionType::GpioClock:
            {
                mode = GPIO_CLOCK;
                break;
            }
        }

        switch (pud)
        {
            case Pud::NoPull:
            {
                pullMode = PUD_OFF;
                break;
            }
            case Pud::PullUpResistor:
            {
                pullMode = PUD_UP;
                break;
            }
            case Pud::PullDownResistor:
            {
                pullMode = PUD_DOWN;
                break;
            }
        }

        //sets up the pin for I/O
        pinMode(pinNumber, mode);

        //sets up the pull up/down resistor
        //if is enabled pull up or pull down pin must be set as ConnectionType::Input
        //this check is performed by constructor signature
        pullUpDnControl(pinNumber, pullMode);
    }

    static void Pin::setMaxPinNumber(const unsigned short max)
    {
        _maxPinNumber = max;
    }

    static void Pin::setup()
    {
        wiringPiSetupGpio();

        //TODO implementare la routine per la rilevazione del massimo numero di pin dispoibile
        setMaxPinNumber(26);
    }


    bool Pin::operator==(const Pin &that) const
    {
        return _num == that.getPinNumber() &&
               _type == that.getConnectionType();
    }

    bool Pin::operator!=(const Pin &that) const
    {
        return !(that == *this);
    }
}