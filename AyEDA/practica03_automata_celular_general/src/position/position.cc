#include "position.h"

Position::Position(initializer_list<int> coordenadas) {
  assert (coordenadas.size() == 1 || coordenadas.size() == 2); // Verificamos que el tamaño sea 1 o 2
  for (auto it = coordenadas.begin(); it != coordenadas.end(); it++) {
    position_[0] = *it;
  }
}