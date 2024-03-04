#include "cellace30.h"

/**
 * @brief Calcular el nuevo estado de la célula
 * @return Nuevo estado de la célula
*/

int CellAce30::Rule(const State& celula_l, const State& celula_r) {
  int l = celula_l.GetData(), c = estado_.GetData(), r = celula_r.GetData();
  return (l + c + r + c * r) % 2;
}