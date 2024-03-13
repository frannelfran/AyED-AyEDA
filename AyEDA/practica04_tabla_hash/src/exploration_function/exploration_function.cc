#include "exploration_function.h"

/**
 * @brief Función de exploración lineal
 * @param key Clave a buscar
 * @return Posición de la tabla
*/

unsigned LinearExploration::operator()(const Key& key, unsigned i) const {
  return i;
}

/**
 * @brief Función de exploración cuadrática
 * @param key Clave a buscar
 * @return Posición de la tabla
*/

unsigned QuadraticExploration::operator()(const Key& key, unsigned i) const {
  return i * i;
}

/**
 * @brief Función de exploración por doble dispersión
 * @param key Clave a buscar
 * @return Posición de la tabla
*/

unsigned DoubleDispersionExploration::operator()(const Key& key, unsigned i) const {
  return dispersion_function_->operator()(key) * i;
}

/**
 * @brief Función de exploración por re-dispersión
 * @param key Clave a buscar
 * @return Posición de la tabla
*/

unsigned ReDispersionExploration::operator()(const Key& key, unsigned i) const {
  srand(key.GetKey());
  for (int j = 0; j < i; j++) {
    rand();
  }
  return rand();
}