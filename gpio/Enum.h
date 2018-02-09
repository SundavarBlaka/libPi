//
// Created by federico on 03/02/18.
//

#ifndef LIBPI_ENUM_H
#define LIBPI_ENUM_H

#include <stdexcept>
#include <string>

namespace lib
{

class Enum
{
private:
  /*
   * Nome della costante
   */
  std::string _enumName;

  int _val;

protected:
  /** 
   * @brief Costruttore 
   * 
   * @param nome Nome della costante: 
   */
  explicit Enum(const std::string &nome, const int &val);

public:
  /** 
   * @brief  Conversione della costante in stringa
   *    
   * @retval Conversione della costante in stringa
   */
  virtual std::string toString() const;

  bool operator==(const Enum &that) const;

  bool operator!=(const Enum &that) const;

  /** 
   * @brief  Conversione implicita in intero
   * @note   Da usare solo negli switch
   */
  operator int() const;

  /** 
   * @brief  Conversione esplicita in intero
   * @note   Da usare solo negli switch
   * @retval Valore convertito in intero
   */
  const int toInt() const;

  virtual ~Enum();
};
}
#endif //LIBPI_ENUM_H
