#include "Pin.h"

namespace gpio
{
Pin::Pin(const unsigned short &pinNumber, const gpio::ConnectionType &type)
    : _num{pinNumber}, _type{type}, _pud{Pud::NoPull}, _status{false}
{
  checkCtor(pinNumber);
  setupPin(pinNumber, type, Pud::NoPull);
}

Pin::Pin(const unsigned short &pinNumber, const gpio::Pud &pud)
    : _num{pinNumber}, _type{ConnectionType::Input}, _pud{pud}, _status{false}
{
  checkCtor(pinNumber);
  setupPin(pinNumber, ConnectionType::Input, pud);
}

unsigned short Pin::getPinNumber() const
{
  return _num;
}

Pud Pin::getPud() const
{
  return _pud;
}

bool Pin::getStatus() const
{
  return _status;
}

void Pin::checkCtor(const unsigned short &pinNumber) const
{
  if (pinNumber <= 0 || pinNumber > MAXPIN)
  {
    throw std::invalid_argument("Pin number must be between 1 and" + MAXPIN);
  }
}

void Pin::setupPin(const unsigned short &pinNumber, const gpio::ConnectionType &type, const gpio::Pud &pud)
{
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

  // sets up the pin for I/O
  pinMode(pinNumber, mode);

  // sets up the pull up/down resistor
  // if is enabled pull up or pull down pin must be set as ConnectionType::Input
  // this check is performed by constructor signature
  pullUpDnControl(pinNumber, pullMode);
};

void Pin::setup()
{
  //TODO: controllare che il setup non ritorni -1
  wiringPiSetupGpio();

  // TODO: implementare la routine per la rilevazione del massimo numero di pin
  // disponibile
}

bool Pin::operator==(const Pin &that) const
{
  return _num == that._num && _type == that._type && _pud == that._pud;
}

bool Pin::operator!=(const Pin &that) const
{
  return !(that == *this);
}

Pin::~Pin()
{
}
} // namespace gpio