//
// Created by federico on 05/02/18.
//

#ifndef LIBPI_SONAR_H
#define LIBPI_SONAR_H

#include "InputPin.h"
#include "OutputPin.h"
#include <cmath>

extern "C" {
#include "wiringPi.h"
};
namespace gpio
{
class Sonar
{
private:
  OutputPin _trigger;
  InputPin _echo;
  unsigned int _timeout;

  /**
     * @brief Regista gli istanti iniziali e finali dell'impulso
     * @note
     * @param startTime Istante iniziale
     * @param endTime Istante finale
     */
  void recordPulse(unsigned int &startTime, unsigned int &endTime) const;

  /**
   * @brief Ritorna un alias per il pin associato al trigger
   * @note
   * @return Pin associato al trigger 
   */
  const OutputPin &getTriggerPin() const;

  /**
   * @brief Ritorna un alias per il pin associato alla ricezione
   * @note
   * @retval Pin associato alla ricezione del segnale
   */
  const InputPin &getEchoPin() const;

public:
  /**
   * @brief Costruttore
   * @note
   * @param trigger Pin associato all'azione trigger
   * @param echo Pin designato alla ricezione del segnale
   * @param tag Tag del dispositivo
   * @param timeout Tempo massimo in cui aspettare il segnale di ritorno in millisecondi
   */
  Sonar(const OutputPin &trigger, const InputPin &echo, const unsigned int timeout);

  /**
   * @brief Ottiene la distanza tra il sensore ed un oggetto
   * @note
   * @retval Distanza misurata
   */
  float getDistance(bool &error) const;

  /**
   * @brief Ritorna il tempo massimo che una misurazione può usare
   * @note
   * @retval Timeout
   */
  const unsigned int getTimeout() const;
};
}

#endif //LIBPI_SONAR_H
