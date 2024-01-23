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

#include "vector_t.hpp"

using namespace std;

template<class T>
class MatrixT {
public: // Características de la clase 
  MatrixT(const int = 0, const int = 0);
  ~MatrixT(); 
  
  void resize(const int, const int);
  
  // getters
  int get_columnas(void) const;
  int get_filas(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const MatrixT<T>&, const MatrixT<T>&);
  void write(ostream& = cout) const;
  void read(istream& = cin);

private: // Atributos de la clase matriz 
  int filas_, columnas_; // filas_ filas y columnas_ columnas
  VectorT<T> v_; // Vector de la clase VectorT
  
  int pos(const int, const int) const;
};

template<class T>
MatrixT<T>::MatrixT(const int filas, const int columnas) { 
  filas_ = filas;
  columnas_ = columnas;
  v_.resize(filas_ * columnas_);
}

template<class T>
MatrixT<T>::~MatrixT() // Destructor 
{}

template<class T>
void MatrixT<T>::resize(const int filas, const int columnas) { // Reaze una matriz 
  assert(filas > 0 && columnas > 0);
  filas_ = filas;
  columnas_ = columnas;
  v_.resize(filas_ * columnas_);
}

template<class T>
inline int MatrixT<T>::get_columnas() const { // Retorna las filas de la matrix
  return filas_;
}

template<class T>
inline int MatrixT<T>::get_filas() const { // Retorna las columnas de la matrix 
  return columnas_;
}

template<class T>
T& MatrixT<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_columnas()); // El porgrama para si las columnas son menores que 0
  assert(j > 0 && j <= get_filas()); // El programa para si las filas son menores que 0
  return v_[pos(i, j)]; // Retorna el vector asociado a la matriz 
}

template<class T>
T& MatrixT<T>::operator()(const int i, const int j) {
  return at(i, j);
}

template<class T>
const T& MatrixT<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_columnas());
  assert(j > 0 && j <= get_filas());
  return v_[pos(i, j)];
}

template<class T>  
const T& MatrixT<T>::operator()(const int i, const int j) const {
  return at(i, j);
}

template<class T>
void MatrixT<T>::write(ostream& os) const { // Procedimiento que escribe las filas y columnas de una matriz
  os << get_columnas() << "x" << get_filas() << endl;
  for (int i = 1; i <= get_columnas(); ++i) {
    for (int j = 1; j <= get_filas(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}

template<class T>
void MatrixT<T>::read(istream& is) { // Procedimiento que se le pasa por consola las filas y columnas de la matriz 
  is >> filas_ >> columnas_;
  resize(filas_, columnas_);
  for (int i = 1; i <= get_columnas(); ++i)
    for (int j = 1; j <= get_filas(); ++j)
      is >> at(i, j);
}

template<class T>
inline int MatrixT<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_columnas());
  assert(j > 0 && j <= get_filas());
  return (i - 1) * get_filas() + (j - 1); // Devuelve la posición original de filas y columnas de la matriz
}

// FASE III: producto matricial
template<class T>
void MatrixT<T>::multiply(const MatrixT<T>& A, const MatrixT<T>& B) {
  assert(A.get_filas() == B.get_columnas()); // Para que se multipliquen las filas y columnas tienen que coincidir
  resize(A.get_columnas(), B.get_filas()); // Matriz resultante 
  for(int i = 1; i <= A.get_columnas(); i++) {
    for(int j = 1; j <= B.get_filas(); j++) {
      for (int k = 1; k <= A.get_filas(); k++) {
        at(i,j) = at(i,j) + (A.at(i,k) * B.at(k,j)); // Producto matricial 
      }
    }
  }
}