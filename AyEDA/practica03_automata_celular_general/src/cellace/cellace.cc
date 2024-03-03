#include "cellace.h"

ostream& CellAce::Display(ostream& os) const {
  string estado = (estado_.GetData() == 1) ? "x" : "0";
  os << estado;
  os << posicion_.GetX();
  return os;
}

