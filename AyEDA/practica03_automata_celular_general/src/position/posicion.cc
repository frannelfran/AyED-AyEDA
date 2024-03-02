#include "position.h"

Position::Position(initializer_list<int> coordenadas) {
  assert (coordenadas.size() == 1 || coordenadas.size() == 2); // Verificamos que el tamaño sea 1 o 2
  int i = 0;
  for (auto& it : coordenadas) {
    if (i < 2) {
      this->position_[i] = it;
      i++;
    }
  }
}