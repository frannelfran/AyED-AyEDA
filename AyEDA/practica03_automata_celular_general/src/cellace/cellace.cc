#include "cellace.h"

int CellAce::NextState(const Lattice& lattice) {
  State l = lattice.GetCell(Position({posicion_.GetX() - 1})).GetState();
  State r = lattice.GetCell(Position({posicion_.GetX() + 1})).GetState();
  return Rule(l, r);
}

ostream& CellAce::Display(ostream& os) const {
  string estado = (estado_.GetData() == 1) ? "x" : " ";
  os << estado;
  os << posicion_.GetX();
  return os;
}