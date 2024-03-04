#include "cellace.h"

ostream& CellAce::Display(ostream& os) const {
  string estado = (estado_.GetData() == 1) ? "x" : " ";
  os << estado;
  os << posicion_.GetX();
  return os;
}

/**
 * @brief Calcular el nuevo estado de la célula
 * @param ret Referencia al retículo
 * @return Nuevo estado de la célula
*/

int CellAce::NextState(const Lattice& ret) {
  State l = ret.GetCell(Position({posicion_.GetX() - 1})).GetState();
  State r = ret.GetCell(Position({posicion_.GetX() + 1})).GetState();
  return Rule(l, r);
}