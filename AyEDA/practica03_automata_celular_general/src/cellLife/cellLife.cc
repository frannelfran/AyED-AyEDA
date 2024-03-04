#include "cellLife.h"

ostream& CellLife::Display(ostream& os) const {
  string estado = (estado_.GetData() == 1) ? "x" : " ";
  os << estado;
  os << posicion_.GetX() << posicion_.GetY();
  return os;
}

/**
 * @brief Calcular el nuevo estado de la célula
 * @param lattice Referencia al retículo
*/

int CellLife::NextState(const Lattice& lattice) {
  int celulas_vivas = 0; // Número de células vivas alrededor de la célula a actualizar su estado
  // Calcular las células vecinas teniendo en cuenta la vecindad de Moore
  for (int i = posicion_.GetX() - 1; i <= posicion_.GetX() + 1; i++) {
    for (int j = posicion_.GetY() - 1; j <= posicion_.GetY() + 1; j++) {
      // No contar la misma célula como vecina
      if (!(i == posicion_.GetX() && j == posicion_.GetY())) {
        const Cell& vecina = lattice.GetCell(Position({i, j}));
        if (vecina.GetState().GetData() == 1) {
          celulas_vivas++;
        }
      }
    }
  }
  // Aplicar las reglas de Moore
  return Rule(celulas_vivas);
}