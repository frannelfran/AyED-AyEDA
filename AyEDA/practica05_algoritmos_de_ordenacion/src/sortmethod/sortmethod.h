#pragma once
#include "../sequence/sequence.h"

using namespace std;

template<class Key>
class SortMethod {
 public:
  // Constructores
  SortMethod() {}
  SortMethod(Sequence<Key>* sequence, bool show) : sequence_(sequence), show_(show) {}

  // Métodos
  virtual void Sort() const = 0;

 protected:
  Sequence<Key>* sequence_;
  bool show_;
};

// Ordenación por selección

template<class Key>
class SelectionSort : public SortMethod<Key> {
 public:
  // Constructores
  SelectionSort() {}
  SelectionSort(Sequence<Key>* sequence, bool show) : SortMethod<Key>(sequence, show) {}

  // Métodos
  void Sort() const override;
};

// QuickSort

template<class Key>
class QuickSort : public SortMethod<Key> {
 public:
  // Constructores
  QuickSort() {}
  QuickSort(Sequence<Key>* sequence, bool show) : SortMethod<Key>(sequence, show) {}

  // Métodos
  void Sort() const override;
  void QSort(Sequence<Key>*, int, int) const;
};

// HeapSort

template<class Key>
class HeapSort : public SortMethod<Key> {
 public:
  // Constructores
  HeapSort() {}
  HeapSort(Sequence<Key>* sequence, bool show) : SortMethod<Key>(sequence, show) {}

  // Métodos
  void Sort() const override;
  void Baja(int, Sequence<Key>*, int) const;
};

// ShellSort

template<class Key>
class ShellSort : public SortMethod<Key> {
 public:
  // Constructores
  ShellSort() {}
  ShellSort(Sequence<Key>* sequence, bool show) : SortMethod<Key>(sequence, show) {}

  // Métodos
  void Sort() const override;
  void DeltaSort(int, Sequence<Key>*, int) const;
};

// RadixSort

template<class Key>
class RadixSort : public SortMethod<Key> {
 public:
  // Constructores
  RadixSort() {}
  RadixSort(Sequence<Key>* sequence, bool show) : SortMethod<Key>(sequence, show) {}

  // Métodos
  void Sort() const override;
  void CountSort(Sequence<Key>*, int) const;
  int GetMax(Sequence<Key>*) const;
};

/**
 * @brief Método de ordenación por selección
*/

template<class Key> void SelectionSort<Key>::Sort() const {
  int n = this->sequence_->GetSize();
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (this->sequence_->operator[](Position(j)) < this->sequence_->operator[](Position(min))) {
        min = j;
      }
    }
    this->sequence_->Swap(Position(i), Position(min));
    if (this->show_) this->sequence_->Print(cout);
  }
}

/**
 * @brief Método de ordenación QuickSort
*/

template<class Key> void QuickSort<Key>::Sort() const {
  QSort(this->sequence_, 0, this->sequence_->GetSize() - 1);
}

/**
 * @brief Función Qsort de QuickSort
 * @param secuencia Secuencia de claves
 * @param izq Límite izquierdo
 * @param der Límite derecho
*/

template<class Key> void QuickSort<Key>::QSort(Sequence<Key>* secuencia, int ini, int fin) const {
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
      if (this->show_) secuencia->Print(cout);
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

template<class Key> void HeapSort<Key>::Baja(int i, Sequence<Key>* secuencia, int n) const {
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
      if (this->show_) secuencia->Print(cout);
      i = h;
    }
  }
}

/**
 * @brief Método de ordenación HeapSort
*/

template<class Key> void HeapSort<Key>::Sort() const {
  int n = this->sequence_->GetSize();
  for (int i = n / 2 - 1; i >= 0; i--) {
    Baja(i, this->sequence_, n);
  }
  for (int i = n - 1; i > 0; i--) {
    this->sequence_->Swap(Position(0), Position(i));
    if (this->show_) this->sequence_->Print(cout);
    Baja(0, this->sequence_, i);
  }
}

/**
 * @brief Método de ordenación ShellSort
*/

template<class Key> void ShellSort<Key>::Sort() const {
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

template<class Key> void ShellSort<Key>::DeltaSort(int delta, Sequence<Key>* secuencia, int n) const {
  for (int i = delta; i < n; i++) {
    Key x = secuencia->operator[](Position(i));
    int j = i;
    while ((j >= delta) && (x < secuencia->operator[](Position(j - delta)))) {
      secuencia->Swap(Position(j), Position(j - delta));
      if (this->show_) secuencia->Print(cout);
      j = j - delta;
    }
  }
}

/**
 * @brief Método de ordenación RadixSort
*/

template <class Key> void RadixSort<Key>::Sort() const {
  Key max = this->sequence_->operator[](Position(0));
  for (int i = 0; i < this->sequence_->GetSize(); i++) {
    if (this->sequence_->operator[](Position(i)) > max) {
      max = this->sequence_->operator[](Position(i));
    }
  }
  for (int exp = 1; max.GetKey() / exp > 0; exp *= 10) {
    CountSort(this->sequence_, exp);
  }
}

/**
 * @brief Método de ordenación CountSort
 * @param secuencia Secuencia de claves
 * @param exp Exponente
*/

template<class Key> void RadixSort<Key>::CountSort(Sequence<Key>* secuencia, int exp) const {
  int size = secuencia->GetSize();
  vector<Key> output(size);
  int count[10] = {0};
  for (int i = 0; i < size; i++) {
    count[(secuencia->operator[](Position(i)).GetKey() / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[(secuencia->operator[](Position(i)).GetKey() / exp) % 10] - 1] = secuencia->operator[](Position(i));
    count[(secuencia->operator[](Position(i)).GetKey() / exp) % 10]--;
  }

  for (int i = 0; i < size; i++) {
    secuencia->operator[](Position(i)) = output[i];
  }

  if (this->show_) secuencia->Print(cout);
}