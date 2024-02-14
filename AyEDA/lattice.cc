#include "lattice.h"

/**
 * @brief Constructor de la clase Lattice
 * @param celula Objeto de la clase Cell
 * @return Objeto Lattice
*/

Lattice::Lattice(const Cell& celula) {
  this->lattice_.push_back(celula);
}

/**
 * @brief Obtener la célula según su posición
 * @param posicion Posición de la célula a buscar
 * @return Objeto Cell
*/

const Cell& Lattice::GetCell(const Position& posicion) const {
  return lattice_.at(posicion.GetData());
}