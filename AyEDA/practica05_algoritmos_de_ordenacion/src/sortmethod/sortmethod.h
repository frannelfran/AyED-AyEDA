#pragma once
#include "sequence/sequence.h"

using namespace std;

class SortMethod {
  public:
    // Constructores
    SortMethod() {}
    SortMethod(Sequence* sequence) : sequence_(sequence) {}

    // Métodos
    virtual void Sort() const = 0;

  protected:
    Sequence* sequence_;
};

// Ordenación por selección

class SelectionSort : public SortMethod {
  public:
    // Constructores
    SelectionSort() {}
    SelectionSort(Sequence* sequence) : SortMethod(sequence) {}

    // Métodos
    void Sort() const override;
};

// QuickSort

class QuickSort : public SortMethod {
  public:
    // Constructores
    QuickSort() {}
    QuickSort(Sequence* sequence) : SortMethod(sequence) {}

    // Métodos
    void Sort() const override;
};

// HeapSort

class HeapSort : public SortMethod {
  public:
    // Constructores
    HeapSort() {}
    HeapSort(Sequence* sequence) : SortMethod(sequence) {}

    // Métodos
    void Sort() const override;
};

// ShellSort

class ShellSort : public SortMethod {
  public:
    // Constructores
    ShellSort() {}
    ShellSort(Sequence* sequence) : SortMethod(sequence) {}

    // Métodos
    void Sort() const override;
};

// RadixSort

class RadixSort : public SortMethod {
  public:
    // Constructores
    RadixSort() {}
    RadixSort(Sequence* sequence) : SortMethod(sequence) {}

    // Métodos
    void Sort() const override;
};