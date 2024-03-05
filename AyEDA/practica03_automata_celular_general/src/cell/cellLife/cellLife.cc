#include "cellLife.h"

/**
 * @brief Mostrar la célula por pantalla
 * @param os Stream de salida
*/

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

/**
 * @brief Calcular el nuevo estado de la célula
 * @param vivas Número de células vivas alrededor de la célula a actualizar su estado
 * @return Nuevo estado de la célula
*/

int CellLife23_3::Rule(int vivas) {
  if (estado_.GetData() == 1) { // Si la célula está viva
    if (!(vivas < 2 || vivas > 3)) {
      return 1;
    }
  }
  else if (estado_.GetData() == 0){ // Sino la célula está muerta
    if (vivas == 3) {
      return 1;
    }
  }
  return 0;
}

/**
 * @brief Calcular el nuevo estado de la célula
 * @param vivas Número de células vivas alrededor de la célula a actualizar su estado
 * @return Nuevo estado de la célula
*/

int CellLife51_346::Rule(int vivas) {
  if (estado_.GetData() == 1) { // Si la célula está viva
    if (vivas == 3 || vivas == 4 || vivas == 6) {
      return 1;
    }
  }
  else if (estado_.GetData() == 0){ // Sino la célula está muerta
    if (vivas == 5 || vivas == 1) {
      return 1;
    }
  }
  return 0;
}