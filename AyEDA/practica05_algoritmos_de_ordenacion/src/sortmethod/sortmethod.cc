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

/**
 * @brief Método de ordenación QuickSort
*/

void QuickSort::Sort() const {
  QSort(sequence_, 0, sequence_->GetSize() - 1);
}

/**
 * @brief Función Qsort de QuickSort
 * @param secuencia Secuencia de claves
 * @param izq Límite izquierdo
 * @param der Límite derecho
*/

void QuickSort::QSort(Sequence* secuencia, int ini, int fin) const {
  int i = ini, j = fin;
  Key p = secuencia->operator[](Position((i + j) / 2));
  while (i <= j) {
    while (secuencia->operator[](Position(i)) < p) {
      i++;
    }
    while (secuencia->operator[](Position(j)) > p) {
      j--;
    }
    if (i <= j) {
      secuencia->Swap(Position(i), Position(j));
      i++;
      j--;
    }
  }
  if (ini < j) {
    QSort(secuencia, ini, j);
  }
  if (i < fin) {
    QSort(secuencia, i, fin);
  }
}

/**
 * @brief Código de baja de HeapSort
 * @param i Posición de la clave
 * @param secuencia Secuencia de claves
 * @param n Tamaño de la secuencia
*/

void HeapSort::Baja(int i, Sequence* secuencia, int n) const {
  while (2 * i <= n) {
    Position h1(2 * i), h2(h1.GetData() + 1), h;
    if (h2.GetData() <= n && secuencia->operator[](h1) < secuencia->operator[](h2)) {
      h = h2;
    } else {
      h = h1;
    }
    if (secuencia->operator[](h) <= secuencia->operator[](Position(i))) {
      break;
    } else {
      secuencia->Swap(Position(i), h);
      i = h.GetData();
    }
  }
}

/**
 * @brief Método de ordenación HeapSort
*/

void HeapSort::Sort() const {
  int n = sequence_->GetSize();
  for (int i = n / 2; i > 0; i--) {
    Baja(i, sequence_, n);
  }

  for (int i = n; i > 1; i--) {
    sequence_->Swap(Position(1), Position(i));
    Baja(1, sequence_, i - 1);
  }
}

/**
 * @brief Método de ordenación ShellSort
*/

void ShellSort::Sort() const {
  int delta = sequence_->GetSize();
  while (delta > 1) {
    delta = delta / 2;
    DeltaSort(delta, sequence_, sequence_->GetSize());
  }
}

/**
 * @brief Método de ordenación ShellSort con un delta
 * @param delta Delta de la secuencia
 * @param secuencia Secuencia de claves
 * @param n Tamaño de la secuencia
*/

void ShellSort::DeltaSort(int delta, Sequence* secuencia, int n) const {
  for (int i = delta; i < n; i++) {
    Key x = secuencia->operator[](Position(i));
    int j = i;
    while ((j >= delta) && (x < secuencia->operator[](Position(j - delta)))) {
      secuencia->Swap(Position(j), Position(j - delta));
      j = j - delta;
    }
  }
}