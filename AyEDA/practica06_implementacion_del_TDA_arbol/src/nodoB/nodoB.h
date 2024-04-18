#pragma once
#include "../key/key.h"

using namespace std;

// Clase para representar los nodos de un árbol binario

template <class Key>
class NodoB {
 public:
  NodoB(const Key& dato, NodoB* izdo, NodoB* dcho) : dato_(dato), izdo_(izdo), dcho_(dcho) {}

  // Getters
  inline NodoB* GetIzdo() const { return izdo_; }
  inline NodoB* GetDcho() const { return dcho_; }
  inline Key GetDato() const { return dato_; }  

  // Setters
  inline void SetDato(const Key& dato) { dato_ = dato; }
  inline void SetIzdo(NodoB* izdo) { izdo_ = izdo; }
  inline void SetDcho(NodoB* dcho) { dcho_ = dcho; }

  // Sobrecarga de operadores
  template<class T> friend ostream& operator<<(ostream& os, const NodoB<T>& nodo);

 protected:
  Key dato_;
  NodoB* izdo_;
  NodoB* dcho_;
};

/**
 * @brief Sobrecarga del operador de inserción
 * @param os Flujo de salida
 * @param nodo Nodo a imprimir
 * @return Referencia al flujo de salida
*/

template<class Key> ostream& operator<<(ostream& os, const NodoB<Key>& nodo) {
  if (nodo.dato_ == NULL) {
    os << "[.]";
  }
  else {
    os << "[" << nodo.dato_ << "]";
  }
  return os;
}