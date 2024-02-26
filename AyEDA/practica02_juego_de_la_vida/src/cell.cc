#include "../include/cell.h"
#include "../include/state.h"
#include "../include/position.h"

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
 * @brief Calcular el siguiente estado de cada célula del retículo
 * @param lattice Retículo sonde se encuentran las células
 * @return Nuevo estado
*/

int Cell::NextState(const Lattice& lattice) {
  int celulas_vivas = 0; // Número de células vivas alrededor de la célula a actualizar su estado
  // Calcular las células vecinas teniendo en cuenta la vecindad de Moore
  for (int i = posicion_.GetDataM() - 1; i <= posicion_.GetDataM() + 1; i++) {
    for (int j = posicion_.GetDataN() - 1; j <= posicion_.GetDataN() + 1; j++) {
      // No contar esta céula misma como vecino
      if (!(i == posicion_.GetDataM() && j == posicion_.GetDataN())) {
        const Cell& vecina = lattice.GetCell(Position(i, j));
        if (vecina.GetState().GetData() == 1) {
          celulas_vivas++;
        }
      }
    }
  }
  // Aplicar las reglas de Moore si la célula está viva
  return Moore(celulas_vivas);
}

/**
 * @brief Función que aplica la regla de Moore para saber el nuevo estado de la célula
 * @param vivas Número de células vivas alrededor de la célula a examinar sus vecinas
 * @return Nuevo estado de la célula
*/

int Cell::Moore(int vivas) {
  if (estado_.GetData()) {
    if (!(vivas < 2 || vivas > 3)) {
      return 1;
    }
  }
  else { // Sino la célula está muerta
    if (vivas == 3) {
      return 1;
    }
  }
  return 0;
}

/**
 * @overload Sobrecarga del operador <<
*/

ostream& operator<<(ostream& os, const Cell& cell) {
  string estado = (cell.estado_.GetData() == 1) ? "x" : " ";
  os << estado;
  return os;
}