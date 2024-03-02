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
 * @overload Sobrecarga del operador <<
*/

ostream& operator<<(ostream& os, const Cell& cell) {
  string estado = (cell.estado_.GetData() == 1) ? "x" : " ";
  os << estado;
  return os;
}