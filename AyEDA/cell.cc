#include "cell.h"

Cell::Cell() {}

/**
 * @brief Constructor de la clase Cell
 * @param posicion Posición de la célula
 * @param estado Estado actual de la célula
 * @return Objeto célula
*/

Cell::Cell(const Position& posicion, const State& estado) {
  this->posicion_ = posicion;
  this->estado_ = estado;
}

/**
 * @brief Función que devuelve el estado de la célula
 * @return Estado de la célula
*/

State Cell::GetState() const {
  return this->estado_;
}