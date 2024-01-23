#include <iostream>

class VectorT {
  public: // Características de la clase 
  VectorT();
  VectorT(int n);
  VectorT(const VectorT &v);
  ~VectorT();
  private: // Atributos
  double *base;
  int n;
};