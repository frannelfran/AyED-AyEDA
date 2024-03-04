#include "cellace110.h"

/**
 * @brief Calcular el nuevo estado de la célula
 * @return Nuevo estado de la célula
*/

int CellAce110::Rule(const State& celula_l, const State& celula_r) {
  int l = celula_l.GetData(), c = estado_.GetData(), r = celula_r.GetData();
  return (c + r + c * r + l * c * r) % 2;
}