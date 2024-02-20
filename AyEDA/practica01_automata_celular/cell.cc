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
 * @brief Aplicar la formula para calcular el siguiente estado
 * @param state_l Estado de la célula de la izquierda
 * @param state_r Estado de la célula de la derecha
 * @return Nuevo estado
*/

int Cell::CalcularEstado(const State& state_l, const State& state_r) {
  int l = state_l.GetData(), c = estado_.GetData(), r = state_r.GetData(); // Obtener los estados de cada célula
  return (c + r + c * r + l * c * r) % 2; // Calcular el nuevo estado
}

/**
 * @brief Calcular el siguiente estado de cada célula del retículo
 * @param lattice Retículo sonde se encuentran las células
 * @return Nuevo estado
*/

int Cell::NextState(const Lattice& lattice) {
  Position posicion_left, posicion_right;
  Cell celula_l, celula_r;
  
  // Comprobar que la frontera es abierta
  if (lattice.GetFrontera() == "open") {
    // Obtengo la posición de la célula de la izquierda
    posicion_left.SetData(posicion_.GetData() - 1);
    // Obtengo la posición de la célula de la derecha
    posicion_right.SetData(posicion_.GetData() + 1);
  }
  else if (lattice.GetFrontera() == "periodic") { // Sino es periódica
    // Mirar cuando se encuentra en la primera posición
    if (posicion_.GetData() == 0) {
      posicion_left.SetData(lattice.GetSize() - 1);
      posicion_right.SetData(1);
    }
    // Mirar cuando se encuentra en la última posición
    else if (posicion_.GetData() == lattice.GetSize() - 1) {
      posicion_right.SetData(0);
      posicion_left.SetData(posicion_.GetData() - 1);
    }
    // Sino aplicar el recorrido predeterminado
    else {
      posicion_left.SetData(posicion_.GetData() - 1);
      posicion_right.SetData(posicion_.GetData() + 1);
    }
  }
  
  celula_l = lattice.GetCell(posicion_left);
  celula_r = lattice.GetCell(posicion_right);
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