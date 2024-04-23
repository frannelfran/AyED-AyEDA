#pragma once
#include "../key/key.h"
#include "../nodoB/nodoB.h"

using namespace std;

// Clase abstracta para representar un árbol binario

template <class Key>
class Ab {
 public:
  // Constructores
  Ab() : raiz_(NULL) {}

  // Métodos
  virtual void Insertar(const Key& k) = 0;
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
  Abb() : Ab<Key>(NULL) {}

  // Métodos
  void Insertar(const Key& k) override;
  NodoB<Key>* Buscar(const Key& k) const override { return NULL; }
  void Inorder() const override {}


  // Métodos de lapropia clase
  void InsertarRama(NodoB<Key>*& nodo, const Key& k);
};

/**
 * @brief Inserta un nodo en el árbol
 * @param k Clave del nodo a insertar
*/

template <class Key> void Abb<Key>::Insertar(const Key& k) {
  InsertarRama(this->raiz_, k);
}

/**
 * @brief Inserta un nodo en una rama del árbol
 * @param nodo Nodo raíz de la rama
 * @param k Clave del nodo a insertar
*/

template <class Key> void Abb<Key>::InsertarRama(NodoB<Key>*& nodo, const Key& k) {
  if (nodo == NULL) {
    nodo = new NodoB<Key>(k);
  } else if (k < nodo->GetDato()) {
    InsertarRama(nodo->GetIzdo(), k);
  } else if (k > nodo->GetDato()) {
    InsertarRama(nodo->GetDcho(), k);
  }
}

