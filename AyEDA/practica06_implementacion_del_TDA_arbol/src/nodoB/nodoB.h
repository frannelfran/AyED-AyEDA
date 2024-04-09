#pragma once
#include "../key/key.h"

using namespace std;

// Clase para representar los nodos de un árbol binario

template <class Key>
class NodoB {

 protected:
  Key dato_;
  NodoB* izdo_;
  NodoB* dcho_;
};