#include "lattice.h"

Lattice::Lattice() {}

/**
 * @brief Constructor de la clase Lattice
 * @param vector_celulas Vector que contiene las células
 * @return Objeto Lattice
*/

Lattice::Lattice(const vector<Cell>& vector_celulas) {
  this->lattice_ = vector_celulas;
}

/**
 * @brief Obtener la célula según su posición
 * @param posicion Posición de la célula a buscar
 * @return Objeto Cell
*/

const Cell& Lattice::GetCell(const Position& posicion) const {
  return lattice_.at(posicion.GetData());
}

/**
 * @overload Sobrecarga del operador <<
*/

ostream& operator<<(ostream& os, const Lattice& latt) {
  for (auto it = latt.lattice_.begin(); it != latt.lattice_.end(); it++) {
    os << *it;
  }
  cout << endl;
  return os;
}