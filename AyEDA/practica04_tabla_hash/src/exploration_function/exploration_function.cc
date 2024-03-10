#include "exploration_function.h"
#include "../dispersion_function/dispersion_function.h"

/**
 * @brief Función de exploración lineal
 * @param key Nif a dispersar
 * @param i Número de intento
 * @return Número dispersado
*/

unsigned ExplorationLinear::operator() (const Nif& key, unsigned i) const {
  return i;
}

/**
 * @brief Función de exploración cuadrática
 * @param key Nif a dispersar
 * @param i Número de intento
 * @return Número dispersado
*/

unsigned ExplorationQuadratic::operator() (const Nif& key, unsigned i) const {
  assert (i > 0); // Solo para números positivos
  return i * i;
}

/**
 * @brief Función de exploración doble
 * @param key Nif a dispersar
 * @param i Número de intento
 * @return Número dispersado
*/

unsigned ExplorationDouble::operator() (const Nif& key, unsigned i) const {
  return (*dispersion_)(key) * i;
}

/**
 * @brief Función de exploración por re-dispersión
 * @param key Nif a dispersar
 * @param i Número de intento
 * @return Número dispersado
*/

unsigned ExplorationReDispersion::operator() (const Nif& key, unsigned i) const {
  srand(key.GetNumber());
  return rand();
}