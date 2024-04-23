#pragma once
#include "../key/key.h"

using namespace std;

// Clase para representar los nodos de un árbol binario

template <class Key>
class NodoB {
 public:
  NodoB(const Key& dato, NodoB<Key>* izdo, NodoB<Key>* dcho) : dato_(dato), izdo_(izdo), dcho_(dcho) {}
  NodoB(const Key& dato) : dato_(dato), izdo_(nullptr), dcho_(nullptr) {}

  // Getters
  inline NodoB<Key>*& GetIzdo() { return izdo_; }
  inline NodoB<Key>*& GetDcho() { return dcho_; }
  inline Key GetDato() const { return dato_; }  

  // Setters
  inline void SetIzdo(NodoB<Key>* izdo) { izdo_ = izdo; }
  inline void SetDcho(NodoB<Key>* dcho) { dcho_ = dcho; }

 protected:
  Key dato_;
  NodoB<Key>* izdo_;
  NodoB<Key>* dcho_;
};