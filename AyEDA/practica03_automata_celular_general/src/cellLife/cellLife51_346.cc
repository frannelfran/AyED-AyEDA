#include "cellLife51_346.h"

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