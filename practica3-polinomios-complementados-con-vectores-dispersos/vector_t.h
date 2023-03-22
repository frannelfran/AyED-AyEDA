// AUTOR: Javier Gonzalez Brito 
// FECHA: 10/03/2023 
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 3.1
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> class Vector_t {
 public:
  // constructores
  Vector_t(const int = 0);
  Vector_t(const Vector_t&); // constructor de copia

  // operador de asignación
  Vector_t<T>& operator=(const Vector_t<T>&);

  // destructor
  ~Vector_t();
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  // Redimensionado
  void resize(const int);
  
  // E/S
  void read(std::istream& = std::cin);
  void write(std::ostream& = std::cout) const;

 private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};


template<class T> Vector_t<T>::Vector_t(const int n) : v_(NULL), sz_(n) {
  build();
}

// constructor de copia
template<class T> Vector_t<T>::Vector_t(const Vector_t<T>& w)
    : v_(NULL), sz_(0) {
  *this = w; // se invoca directamente al operator=
}

// operador de asignación
template<class T> Vector_t<T>& Vector_t<T>::operator=(const Vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);
  
  return *this;
}

template<class T> Vector_t<T>::~Vector_t() {
  destroy();
}

template<class T> void Vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template<class T> void Vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template<class T> void Vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

template<class T> inline T Vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template<class T> inline int Vector_t<T>::get_size() const {
  return sz_;
}

template<class T> void Vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

template<class T> T& Vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template<class T> T& Vector_t<T>::operator[](const int i) {
  return at(i);
}

template<class T> const T& Vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template<class T> const T& Vector_t<T>::operator[](const int i) const {
  return at(i);
}

template<class T> void Vector_t<T>::read(std::istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> at(i);
}

template<class T> void Vector_t<T>::write(std::ostream& os) const {
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

template<class T> std::istream& operator>>(std::istream& is, Vector_t<T>& v) {
  v.read(is);
  return is;
}

template<class T> std::ostream& operator<<(std::ostream& os, const Vector_t<T>& v) {
  v.write(os);
  return os;
}

#endif  // VECTORT_H_
