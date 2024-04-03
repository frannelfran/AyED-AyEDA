#pragma once
#include "../sequence/sequence.h"

using namespace std;

template<typename Key>
class SortMethod {
  public:
    // Constructores
    SortMethod() {}
    SortMethod(Sequence<Key>* sequence) : sequence_(sequence) {}

    // Métodos
    virtual void Sort() const = 0;

  protected:
    Sequence<Key>* sequence_;
    bool show_ = false;
};

// Ordenación por selección

template<typename Key>
class SelectionSort : public SortMethod<Key> {
  public:
    // Constructores
    SelectionSort() {}
    SelectionSort(Sequence<Key>* sequence) : SortMethod<Key>(sequence) {}

    // Métodos
    void Sort() const override;
};

// QuickSort

template<typename Key>
class QuickSort : public SortMethod<Key> {
  public:
    // Constructores
    QuickSort() {}
    QuickSort(Sequence<Key>* sequence) : SortMethod<Key>(sequence) {}

    // Métodos
    void Sort() const override;
    void QSort(Sequence<Key>*, int, int) const;
};

// HeapSort

template<typename Key>
class HeapSort : public SortMethod<Key> {
  public:
    // Constructores
    HeapSort() {}
    HeapSort(Sequence<Key>* sequence) : SortMethod<Key>(sequence) {}

    // Métodos
    void Sort() const override;
    void Baja(int, Sequence<Key>*, int) const;
};

// ShellSort

template<typename Key>
class ShellSort : public SortMethod<Key> {
  public:
    // Constructores
    ShellSort() {}
    ShellSort(Sequence<Key>* sequence) : SortMethod<Key>(sequence) {}

    // Métodos
    void Sort() const override;
    void DeltaSort(int, Sequence<Key>*, int) const;
};

// RadixSort

template<typename Key>
class RadixSort : public SortMethod<Key> {
  public:
    // Constructores
    RadixSort() {}
    RadixSort(Sequence<Key>* sequence) : SortMethod<Key>(sequence) {}

    // Métodos
    void Sort() const override;
    void CountSort(Sequence<Key>*, int, int) const;
};

/**
 * @brief Método de ordenación por selección
*/

template<typename Key> void SelectionSort<Key>::Sort() const {
  int n = this->sequence_->GetSize();
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (this->sequence_->operator[](Position(j)) < this->sequence_->operator[](Position(min))) {
        min = j;
      }
    }
    this->sequence_->Swap(Position(i), Position(min));
  }
}

/**
 * @brief Método de ordenación QuickSort
*/

template<typename Key> void QuickSort<Key>::Sort() const {
  QSort(this->sequence_, 0, this->sequence_->GetSize() - 1);
}

/**
 * @brief Función Qsort de QuickSort
 * @param secuencia Secuencia de claves
 * @param izq Límite izquierdo
 * @param der Límite derecho
*/

template<typename Key> void QuickSort<Key>::QSort(Sequence<Key>* secuencia, int ini, int fin) const {
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

template<typename Key> void HeapSort<Key>::Baja(int i, Sequence<Key>* secuencia, int n) const {
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

template<typename Key> void HeapSort<Key>::Sort() const {
  int n = this->sequence_->GetSize();
  for (int i = n / 2 - 1; i >= 0; i--) {
    Baja(i, this->sequence_, n);
  }
  for (int i = n - 1; i > 0; i--) {
    this->sequence_->Swap(Position(0), Position(i));
    Baja(0, this->sequence_, i);
  }
}

/**
 * @brief Método de ordenación ShellSort
*/

template<typename Key> void ShellSort<Key>::Sort() const {
  int delta = this->sequence_->GetSize();
  while (delta > 1) {
    delta = delta / 2;
    DeltaSort(delta, this->sequence_, this->sequence_->GetSize());
  }
}

/**
 * @brief Método de ordenación ShellSort con un delta
 * @param delta Delta de la secuencia
 * @param secuencia Secuencia de claves
 * @param n Tamaño de la secuencia
*/

template<typename Key> void ShellSort<Key>::DeltaSort(int delta, Sequence<Key>* secuencia, int n) const {
  for (int i = delta; i < n; i++) {
    Key x = secuencia->operator[](Position(i));
    int j = i;
    while ((j >= delta) && (x < secuencia->operator[](Position(j - delta)))) {
      secuencia->Swap(Position(j), Position(j - delta));
      j = j - delta;
    }
  }
}