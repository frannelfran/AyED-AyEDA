#include "dispersion_function.h"

/**
 * @brief Sobeecarga del operador de módulo
 * @param key Key a dispersar
 * @return Número dispersado
*/

unsigned DispersionFunctionMod::operator() (const Key& key) const {
  return key.GetKey() % size_;
}

/**
 * @brief Sobrecarga del operador de suma
 * @param key Key a dispersar
 * @return Número dispersado
*/

unsigned DispersionFunctionSum::operator() (const Key& key) const {
  int number = key.GetKey(), sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum % size_;
}

/**
 * @brief Sobrecarga del operador de aleatorio
 * @param key Key a dispersar
 * @return Número dispersado
*/

unsigned DispersionFunctionRandom::operator() (const Key& key) const {
  srand(key.GetKey());
  return rand() % size_;
}