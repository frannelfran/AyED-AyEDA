#include "cellLife23_3.h"

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