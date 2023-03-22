// AUTOR: Javier Gonzalez Brito
// FECHA: 10/03/2023 
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class Pair_t {
 public:
  // constructores
  Pair_t(void); 
  Pair_t(T, int);

  // destructor
  ~Pair_t(void);

  // getters & setters
  T get_val(void) const;
  int get_inx(void) const;
  void set(T, int);

  // E/S
  std::istream& read(std::istream& is = std::cin);
  std::ostream& write(std::ostream& os = std::cout) const;

 private:
  T val_;
  int inx_;
};


template<class T> Pair_t<T>::Pair_t() : val_(), inx_(-1) {}

template<class T> Pair_t<T>::Pair_t(T val, int inx) : val_(val), inx_(inx) {}

template<class T> Pair_t<T>::~Pair_t() {}

template<class T> void Pair_t<T>::set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

template<class T> int Pair_t<T>::get_inx() const {
  return inx_;
}

template<class T> T Pair_t<T>::get_val() const {
  return val_;
}

template<class T> std::istream& Pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}

template<class T> std::ostream& Pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}

template<class T> std::ostream& operator<<(std::ostream& os, const Pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
