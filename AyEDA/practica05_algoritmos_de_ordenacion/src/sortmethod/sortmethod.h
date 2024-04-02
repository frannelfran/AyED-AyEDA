#pragma once
#include "sequence/sequence.h"

using namespace std;

class SortMethod {
  public:
    // Constructores
    SortMethod() {}
    SortMethod(Sequence* sequence, bool show) : sequence_(sequence), show_(show) {}

    // Métodos
    virtual void Sort() const = 0;

  protected:
    Sequence* sequence_;
    bool show_ = false;
};

// Ordenación por selección

class SelectionSort : public SortMethod {
  public:
    // Constructores
    SelectionSort() {}
    SelectionSort(Sequence* sequence, bool show) : SortMethod(sequence, show) {}

    // Métodos
    void Sort() const override;
};

// QuickSort

class QuickSort : public SortMethod {
  public:
    // Constructores
    QuickSort() {}
    QuickSort(Sequence* sequence, bool show) : SortMethod(sequence, show) {}

    // Métodos
    void Sort() const override;
    void QSort(Sequence*, int, int) const;
};

// HeapSort

class HeapSort : public SortMethod {
  public:
    // Constructores
    HeapSort() {}
    HeapSort(Sequence* sequence, bool show) : SortMethod(sequence, show) {}

    // Métodos
    void Sort() const override;
    void Baja(int, Sequence*, int) const;
};

// ShellSort

class ShellSort : public SortMethod {
  public:
    // Constructores
    ShellSort() {}
    ShellSort(Sequence* sequence, bool show) : SortMethod(sequence, show) {}

    // Métodos
    void Sort() const override;
    void DeltaSort(int, Sequence*, int) const;
};

// RadixSort

class RadixSort : public SortMethod {
  public:
    // Constructores
    RadixSort() {}
    RadixSort(Sequence* sequence, bool show) : SortMethod(sequence, show) {}

    // Métodos
    void Sort() const override {}
};