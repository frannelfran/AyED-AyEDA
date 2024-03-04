#include "position.h"

Position::Position(initializer_list<int> coordenadas) {
  assert (coordenadas.size() == 1 || coordenadas.size() == 2); // Verificamos que el tamaño sea 1 o 2
  auto it = coordenadas.begin();
  position_[0] = *it; // Asignamos el primer elemento independientemente del tamaño de coordenadas
  if (coordenadas.size() == 2) {
    it++;
    position_[1] = *it; // Asignamos el segundo elemento si hay dos coordenadas
  } else {
    position_[1] = 0; // Si solo hay una coordenada, el segundo valor se establece en 0
  }
}