#include "sortmethod.h"

/**
 * @brief Método de ordenación por selección
*/

void SelectionSort::Sort() const {
  int i, j, min;
  for (i = 0; i < sequence_->GetSize() - 1; i++) {
    min = i;
    for (j = i + 1; j < sequence_->GetSize(); j++) {
      if (sequence_->operator[](Position(j)) < sequence_->operator[](Position(min))) {
        min = j;
      }
    }
    if (min != i) {
      sequence_->Swap(Position(i), Position(min));
    }
  }
}