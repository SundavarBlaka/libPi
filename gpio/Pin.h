//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_PIN_H
#define LIBPI_PIN_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "ConnectionType.h"
#include "Pud.h"

extern "C" {
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
  gpio::Pud _pud;
  static unsigned short _maxPinNumber; // massimo numero che i pin possono assumere

  /**
   * Controlla i parametri passati al costruttore
   * @param pinNumber numero del pin da controllare
   */
  void checkCtor(const unsigned short &pinNumber) const;

  /**
   * Effettua il setup reale del pin
   * @param pinNumber Numero del pin
   * @param type Tipo della connessione
   * @param pud Resistenza pullUp/Down
   */
  void setupPin(const unsigned short &pinNumber, const gpio::ConnectionType &type, const gpio::Pud &pud);

  /**
   * Ritorna il numero massimo che può essere associato ad un pin
   * @return Numero massimo valido
   */
  unsigned short getMaxPinNumber() const;

  /**
   * Imposta il numero massimo che i pin possono assumere
   */
  static void setMaxPinNumber(const unsigned short &max);

public:
  /**
   * Costruttore. Non è previsto nessun resistore PUD
   * @param pinNumber Numero del pin secondo la numerazione BroadCom
   * @param type Tipo della connessione
   */
  Pin(const unsigned short &pinNumber, const gpio::ConnectionType &type);

  /**
   * Costruttore. Non è previsto nessun resistore PUD
   * @param pinNumber Numero del pin secondo la numerazione BroadCom
   * @param pud Resistenza pullUp/Down
   */
  Pin(const unsigned short &pinNumber, const gpio::Pud &pud);

  /**
   * Distruttore
   */
  virtual ~Pin() {}

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
} // namespace gpio

#endif // LIBPI_PIN_H
