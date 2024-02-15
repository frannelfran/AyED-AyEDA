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
 * @brief Asignar el retículo
 * @param vector_celulas Vector que contiene las células
*/

void Lattice::SetLattice(const vector<Cell>& vector_celulas) {
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
 * @brief Hacer la configuración inicial del retículo
 * @param size Número de células del retículo
*/

void Lattice::Initial(int size) {
  int posicion = 0, posicion_par = size / 2;
  for (int it = 0; it < size; it++) {
    bool estado = false;
    if (it == posicion_par) {
      estado = true;
    }
    Position pos(posicion);
    State sta(estado);
    Cell cell(pos, sta);
    lattice_.push_back(cell);
  }
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