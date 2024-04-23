#pragma once
#include "../key/key.h"
#include "../nodoB/nodoB.h"
#include <queue>

using namespace std;

// Clase abstracta para representar un árbol binario

template <class Key>
class Ab {
 public:
  // Constructores
  Ab() : raiz_(NULL) {}

  // Métodos
  virtual bool Insertar(const Key& k) = 0;
  virtual NodoB<Key>* Buscar(const Key& k) const = 0;
  virtual void Inorder() const = 0;

  // Sobrecarga de operadores
  template<class T> friend ostream& operator<<(ostream& os, const Ab<T>& ab);

 protected:
  NodoB<Key>* raiz_;
};

// Clase ABB<Key> para representar un árbol binario de búsqueda

template <class Key>
class Abb : public Ab<Key> {
 public:
  // Constructor
  Abb() : Ab<Key>() {}

  // Métodos
  bool Insertar(const Key& k) override;
  NodoB<Key>* Buscar(const Key& k) const override { return NULL; }
  void Inorder() const override {}


  // Métodos de lapropia clase
  bool InsertarRama(NodoB<Key>*& nodo, const Key& k);
};

/**
 * @brief Inserta un nodo en el árbol
 * @param k Clave del nodo a insertar
*/

template <class Key> bool Abb<Key>::Insertar(const Key& k) {
  return InsertarRama(this->raiz_, k);
}

/**
 * @brief Inserta un nodo en una rama del árbol
 * @param nodo Nodo raíz de la rama
 * @param k Clave del nodo a insertar
*/

template <class Key> bool Abb<Key>::InsertarRama(NodoB<Key>*& nodo, const Key& k) {
  if (nodo == nullptr) {
    nodo = new NodoB<Key>(k);
    return true;
  } else if (k < nodo->GetDato()) {
    return InsertarRama(nodo->GetIzdo(), k);
  } else if (k > nodo->GetDato()) {
    return InsertarRama(nodo->GetDcho(), k);
  }
  return false; // La clave ya existe en el árbol
}

/**
 * @overload Sobrecarga del operador <<
*/

template<class Key> ostream& operator<<(ostream& os, const Ab<Key>& ab) {
  queue<NodoB<Key>*> cola;
  NodoB<Key>* nodo = ab.raiz_;
  cola.push(nodo);
  int nivel = 0;
  while (!cola.empty()) {
    int nivel_actual = cola.size();
    os << "Nivel " << nivel << ": ";
    for (int i = 0; i < nivel_actual; i++) {
      nodo =  cola.front();
      cola.pop();
      if (nodo != NULL) {
        os << "[" << nodo->GetDato() << "]";
        cola.push(nodo->GetIzdo());
        cola.push(nodo->GetDcho());
      } else {
        os << "[.]";
      }
    }
    os << endl;
    nivel++;
  }
  return os;
}

