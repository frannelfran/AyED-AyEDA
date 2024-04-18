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
  inline NodoB* Getdcho() const { return dcho_; }

  // Setters
  inline void SetDato(const Key& dato) { dato_ = dato; }
  inline void SetIzdo(NodoB* izdo) { izdo_ = izdo; }
  inline void SetDcho(NodoB* dcho) { dcho_ = dcho; }

 protected:
  Key dato_;
  NodoB* izdo_;
  NodoB* dcho_;
};