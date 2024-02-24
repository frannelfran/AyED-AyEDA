#include "cell.h"
#include "state.h"
#include "position.h"

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
 * @brief Calcular el siguiente estado de cada célula del retículo
 * @param lattice Retículo sonde se encuentran las células
 * @return Nuevo estado
*/

int Cell::NextState(const Lattice& lattice) {
  return 0;
}

/**
 * @overload Sobrecarga del operador <<
*/

ostream& operator<<(ostream& os, const Cell& cell) {
  string estado = (cell.estado_.GetData() == 1) ? "x" : " ";
  os << estado;
  return os;
}