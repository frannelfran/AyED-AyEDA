#include "dispersion_fuction.h"

/**
 * @brief Sobeecarga del operador de módulo
 * @param nif Nif a dispersar
 * @return Número dispersado
*/

unsigned DispersionFuctionMod::operator() (const Nif& nif) const {
  return nif.GetNumber() % size_;
}

/**
 * @brief Sobrecarga del operador de suma
 * @param nif Nif a dispersar
 * @return Número dispersado
*/

unsigned DispersionFuctionSum::operator() (const Nif& nif) const {
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

unsigned DispersionFuctionRandom::operator() (const Nif& nif) const {
  srand(nif.GetNumber());
  return rand() % size_;
}