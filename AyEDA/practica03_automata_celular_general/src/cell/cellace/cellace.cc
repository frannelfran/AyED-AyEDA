#include "cellace.h"

/**
 * @brief Mostrar la célula por pantalla
 * @param os Stream de salida
*/

ostream& CellAce::Display(ostream& os) const {
  string estado = (estado_.GetData() == 1) ? "x" : " ";
  os << estado;
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

/**
 * @brief Calcular el nuevo estado de la célula
 * @return Nuevo estado de la célula
*/

int CellAce30::Rule(const State& celula_l, const State& celula_r) {
  int l = celula_l.GetData(), c = estado_.GetData(), r = celula_r.GetData();
  return (l + c + r + c * r) % 2;
}

/**
 * @brief Calcular el nuevo estado de la célula
 * @return Nuevo estado de la célula
*/

int CellAce110::Rule(const State& celula_l, const State& celula_r) {
  int l = celula_l.GetData(), c = estado_.GetData(), r = celula_r.GetData();
  return (c + r + c * r + l * c * r) % 2;
}