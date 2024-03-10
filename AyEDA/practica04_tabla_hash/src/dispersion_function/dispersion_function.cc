#include "dispersion_function.h"

/**
 * @brief Sobeecarga del operador de módulo
 * @param nif Nif a dispersar
 * @return Número dispersado
*/

unsigned DispersionFunctionMod::operator() (const Nif& nif) const {
  return nif.GetNumber() % size_;
}

/**
 * @brief Sobrecarga del operador de suma
 * @param nif Nif a dispersar
 * @return Número dispersado
*/

unsigned DispersionFunctionSum::operator() (const Nif& nif) const {
  int number = nif.GetNumber(), sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum % size_;
}

/**
 * @brief Sobrecarga del operador de aleatorio
 * @param nif Nif a dispersar
 * @return Número dispersado
*/

unsigned DispersionFunctionRandom::operator() (const Nif& nif) const {
  srand(nif.GetNumber());
  return rand() % size_;
}