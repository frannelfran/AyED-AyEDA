#include "lattice.h"

/**
 * @brief Constructor de la clase Lattice
 * @param celula Objeto de la clase Cell
 * @return Objeto Lattice
*/

Lattice::Lattice(const Cell& celula) {
  this->lattice_.push_back(celula);
}