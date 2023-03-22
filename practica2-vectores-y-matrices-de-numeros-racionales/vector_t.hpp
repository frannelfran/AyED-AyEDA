// AUTOR: Franco Alla
// FECHA: 07-03-2023
// EMAIL: alu0101571669@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>

#include <cassert>

# include "rational_t.hpp"

using namespace std;

template<class T>
class VectorT {
public: // Características de la clase vector 
  VectorT(const int = 0);
  ~VectorT(); // Destructor 
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& posicion(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& posicion(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);
  void circular();
  
private: // Atributos de la clase 
  T *vector_;
  int size_;
  
  void build(void);
  void destroy(void);
};

template<class T>
VectorT<T>::VectorT(const int size) { 
  size_ = size;
  build();
}

template<class T>
VectorT<T>::~VectorT() { // Destructor 
  destroy();
}

template<class T>
void VectorT<T>::build() { // Cosntructor 
  vector_ = NULL;
  if (size_ != 0) {
    vector_ = new T[size_];
    assert(vector_ != NULL);
  }
}

template<class T>
void VectorT<T>::destroy() { // Destructor 
  if (vector_ != NULL) {
    delete[] vector_;
    vector_ = NULL;
  }
  size_ = 0;
}

template<class T>
void VectorT<T>::resize(const int size) { // Procedimiento que rehace el tamaño del vector 
  destroy();
  size_ = size;
  build();
}

template<class T>
inline T VectorT<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return vector_[i]; // Devuelve la posiciçon de i en el vector
}

template<class T>
inline int VectorT<T>::get_size() const { // Devuelve el tamaño del vector 
  return size_;
}

template<class T>
void VectorT<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  vector_[i] = d;
}

template<class T>
T& VectorT<T>::posicion(const int i) {
  assert(i >= 0 && i < get_size()); // El programa para de ejecutarse si la posición es menor que 0
  return vector_[i];
}

template<class T>
T& VectorT<T>::operator[](const int i) {
  return posicion(i);
}

template<class T>
const T& VectorT<T>::posicion(const int i) const { // Devuele la posición de los elementos del vector
  assert(i >= 0 && i < get_size()); // Si las filas son menores que cero el programa para 
  return vector_[i];
}

template<class T>
const T& VectorT<T>::operator[](const int i) const { // Devuelve la posición del vector 
  return posicion(i);
}

template<class T>
void VectorT<T>::write(ostream& os) const { // Escribe el vector pasado por consola 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << posicion(i) << "\t";
  os << endl;
}

template<class T>
void VectorT<T>::read(istream& is) { // Lee el vector pasado por consola 
  is >> size_;
  resize(size_);
  for (int i = 0; i < size_; ++i)
    is >> posicion(i); // 
}

// FASE II: producto escalar
template<class T>
T scal_prod(const VectorT<T>& v, const VectorT<T>& w) { // Producto escalar de dos vectores 
  double producto_escalar = 0;
  assert(v.get_size() == w.get_size()); // Comprueba si los dos vectores tienen el mismo tamaño 
  for(int i = 0; i < v.get_size(); i++) { // Recorre el vector
      producto_escalar = producto_escalar + v[i] * w[i];
    }
    return producto_escalar;
  }

double scal_prod(const VectorT<RationalT>& v, const VectorT<RationalT>& w) { // Producto escalar de la clase RationalT
  double producto_escalar = 0;
  assert(v.get_size() == w.get_size()); // El programa para si la dimensión de los vectores es distinta 
  for(int i = 0; i < v.get_size(); i++) { // Recorrer el vector 
    producto_escalar = producto_escalar + v.posicion(i).value() * w.posicion(i).value(); 
  }
  return producto_escalar;
}

// Vector circular
template<class T>
  void VectorT<T>::circular() {
  T final = posicion(0);
  for (int i =  0; i < get_size() -1; i++) {
  posicion(i) = posicion(i + 1);
  }
  posicion(get_size() - 1) = final;
}
