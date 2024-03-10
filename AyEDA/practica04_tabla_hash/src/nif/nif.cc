#include "nif.h"

/**
 * @brief Constructor por defecto de la clase Nif
*/

Nif::Nif() {
  this->number_ = rand() % 90000000 + 10000000;
}

/**
 * @brief Constructor de la clase Nif
 * @param number Número de NiF
*/

Nif::Nif(long int number) {
  assert(number >= 10000000 && number <= 99999999);
  number_ = static_cast<int>(number);
}

/**
 * @brief Sobrecarga del operador de igualdad
 * @param nif Nif a comparar
*/

bool Nif::operator==(const Nif& nif) {
  return this->number_ == nif.number_;
}