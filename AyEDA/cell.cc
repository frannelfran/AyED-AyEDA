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
 * @brief Función que devuelve el estado de la célula
 * @return Estado de la célula
*/

State Cell::GetState() const {
  return this->estado_;
}

/**
 * @brief Devolver la posición de la célula
 * @return Posición de la célula
*/

Position Cell::GetPosition() const {
  return this->posicion_;
}

/**
 * @brief Establecer la posición de la célula
 * @param posicion Posición a establecer en la célula
*/

void Cell::SetPosicion(Position posicion) {
  posicion_.SetData(posicion.GetData());
}

/**
 * @brief Función para establecer un estado
 * @param estado Estado a establecer
*/

void Cell::SetState(State estado) {
  estado_.SetData(estado.GetData());
}

/**
 * @overload Sobrecarga del operador <<
*/

ostream& operator<<(ostream& os, const Cell& cell) {
  State est = cell.estado_;
  if (est.GetData() == 1) {
    os << "x";
  }
  else {
    os << " ";
  }
  cout << cell.posicion_.GetData();
  return os;
}