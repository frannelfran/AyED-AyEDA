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
    int h1 = 2 * i, h2 = h1 + 1, h;
    if (h2 <= n && secuencia->operator[](Position(h2)) > secuencia->operator[](Position(h1))) {
      h = h2;
    }
    else {
      h = h1;
    }
    if (secuencia->operator[](Position(h)) <= secuencia->operator[](Position(i))) {
      break;
    }
    else {
      secuencia->Swap(Position(i), Position(h));
      i = h;
    }
  }
}

/**
 * @brief Método de ordenación HeapSort
*/

void HeapSort::Sort() const {
  int n = sequence_->GetSize();
  // Construir el heap (reorganizar el arreglo)
  for (int i = n / 2 - 1; i >= 0; i--) {
    Baja(i, sequence_, n - 1);
  }
  // Extraer elementos del heap uno por uno
  for (int i = n - 1; i > 0; i--) {
    // Mover la raíz actual al final del arreglo
    sequence_->Swap(Position(0), Position(i));
    // Llamar a Baja en el montículo reducido
    Baja(0, sequence_, i - 1);
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