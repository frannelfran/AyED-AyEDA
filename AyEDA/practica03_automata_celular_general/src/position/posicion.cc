#include "position.h"

Position::Position(initializer_list<int> coordenadas) {
  int i = 0;
  for (auto& it : coordenadas) {
    if (i < 2) {
      this->position_[i] = it;
      i++;
    }
  }
}