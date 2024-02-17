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
 * @brief Aplicar la formula para calcular el siguiente estado
 * @param state_l Estado de la célula de la izquierda
 * @param state_r Estado de la célula de la derecha
 * @return Nuevo estado
*/

int Cell::CalcularEstado(const State& state_l, const State& state_r) {
  int l = state_l.GetData(), c = estado_.GetData(), r = state_r.GetData();
  return (c + r + c * r + l * c *r) % 2;
}

/**
 * @brief Calcular el siguiente estado de cada célula del retículo
 * @param lattice Retículo sonde se encuentran las células
 * @return Nuevo estado
*/

int Cell::NextState(const Lattice& lattice) {
  Position posicion_left, posicion_right;
  int posicion_l = posicion_.GetData() - 1;
  posicion_left.SetData(posicion_.GetData() - 1);
  Cell celula_l = lattice.GetCell(posicion_l); // Obtengo la célula de la izquierda
  int posicion_r = posicion_.GetData() + 1;
  posicion_right.SetData(posicion_r);
  Cell celula_r = lattice.GetCell(posicion_right); // Obtengo la célula de la derecha
  return CalcularEstado(celula_l.GetState(), celula_r.GetState()); // Calculo el siguiente estado
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
  return os;
}