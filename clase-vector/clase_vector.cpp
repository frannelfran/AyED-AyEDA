#include "clase_vector.hpp"

VectorT::VectorT() { // Constructor por defecto
  int n_ = 0;
  double base_ = 0;
}

VectorT::VectorT(int n) { // Constructor con parámetros 
  int n_ = n;
  base = new double [n_];
}

VectorT::VectorT(const VectorT &v) { // Cosntructor copia
  int n_ = v.n;
  base = new double [v.n];
  for(int i = 0; i < n; i++) {
    base[i] = v.base[i];
  }
}

VectorT::~VectorT() { // Destructor
  delete [] base;
}