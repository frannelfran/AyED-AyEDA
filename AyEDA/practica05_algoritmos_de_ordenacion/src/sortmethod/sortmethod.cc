#include "sortmethod.h"

/**
 * @brief Método de ordenación por selección
*/

void SelectionSort::Sort() const {
  int n = sequence_->GetSize();
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (sequence_->operator[](Position(j)) < sequence_->operator[](Position(min))) {
        min = j;
      }
    }
    sequence_->Swap(Position(i), Position(min));
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
  int i = ini, f = fin;
  Key p = secuencia->operator[](Position((i + f) / 2));
  while (i <= f) {
    while (secuencia->operator[](Position(i)) < p) {
      i++;
    }
    while (secuencia->operator[](Position(f)) > p) {
      f--;
    }
    if (i <= f) {
      secuencia->Swap(Position(i), Position(f));
      i++;
      f--;
    }
  }
  if (ini < f) {
    QSort(secuencia, ini, f);
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
  int h, h1, h2;
  while (2 * i + 1 < n) {
    h1 = 2 * i + 1;
    h2 = 2 * i + 2;
    if (h2 == n || secuencia->operator[](Position(h1)) > secuencia->operator[](Position(h2))) {
      h = h1;
    }
    else {
      h = h2;
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
  for (int i = n / 2 - 1; i >= 0; i--) {
    Baja(i, sequence_, n);
  }
  for (int i = n - 1; i > 0; i--) {
    sequence_->Swap(Position(0), Position(i));
    Baja(0, sequence_, i);
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

/**
 * @brief Método de ordenación RadixSort
*/

void RadixSort::Sort() const {
  int n = sequence_->GetSize();
  int m = sequence_->operator[](Position(0)).GetKey();
  for (int i = 1; i < n; i++) {
    if (sequence_->operator[](Position(i)).GetKey() > m) {
      m = sequence_->operator[](Position(i)).GetKey();
    }
  }
  for (int exp = 1; m / exp > 0; exp *= 10) {
    CountSort(sequence_, n, exp);
  }
}

/**
 * @brief Método de ordenación CountSort
 * @param secuencia Secuencia de claves
 * @param n Tamaño de la secuencia
 * @param exp Exponente
*/

void RadixSort::CountSort(Sequence* secuencia, int n, int exp) const {
  Sequence* output = new StaticSequence(secuencia->GetSize(), false);
  int count[10] = {0};
  for (int i = 0; i < n; i++) {
    count[(secuencia->operator[](Position(i)).GetKey() / exp) % 10]++;
  }
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    output->operator[](Position(count[(secuencia->operator[](Position(i)).GetKey() / exp) % 10] - 1)) = secuencia->operator[](Position(i));
    count[(secuencia->operator[](Position(i)).GetKey() / exp) % 10]--;
  }
  for (int i = 0; i < n; i++) {
    secuencia->operator[](Position(i)) = output->operator[](Position(i));
  }
  delete output;
}