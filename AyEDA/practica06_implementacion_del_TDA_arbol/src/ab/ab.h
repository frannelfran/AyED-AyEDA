#pragma once
#include "../key/key.h"
#include "../nodoB/nodoB.h"

using namespace std;

// Clase abstracta para representar un árbol binario

template <class Key>
class Ab {
 public:
  // Métodos
  virtual bool Insertar(const Key& k) = 0;
  virtual NodoB<Key>* Buscar(const Key& k) const = 0;
  virtual void Inorder() const = 0;

  // Sobrecarga de operadores
  template<class T> friend ostream& operator<<(ostream& os, const Ab<T> ab);

 protected:
  NodoB<Key>* raiz_;
};

// Clase ABE<Key> para representar un árbol binario equilibrado

template <class Key>
class Abe : public Ab<Key> {
 public:
  // Métodos 
  bool Insertar(const Key& k) override;
  NodoB<Key>* Buscar(const Key& k) const override;
  void Inorder() const override;

  // Funciones de la propia clase
  NodoB<Key>* BuscarRama(NodoB<Key>* nodo, const Key& k);
};

// Clase ABB<Key> para representar un árbol binario de búsqueda
/*
template <class Key>
class Abb : public Ab<Key> {
 public:
  // Métodos
  bool Insertar(const Key& k) override;
  bool Buscar(const Key& k) const override;
  void Inorder() const override;
};
*/

/**
 * @brief Buscar una clave en el árbol
 * @param k Clave a buscar
 * @return Puntero al nodo que contiene la clave
*/

template<class Key> NodoB<Key>* Abe<Key>::Buscar(const Key& k) const {
  return BuscarRama(this->raiz_, k);
}

/**
 * @brief Buscar una clave en una rama del árbol
 * @param nodo Nodo raíz de la rama
 * @param k Clave a buscar
 * @return Puntero al nodo que contiene la clave
*/

template<class Key> NodoB<Key>* Abe<Key>::BuscarRama(NodoB<Key>* nodo, const Key& k) {
  if (nodo == NULL) {
    return NULL;
  }
  if (k == nodo->dato_) {
    return nodo;
  }
  if (k < nodo->dato_) {
    return BuscarRama(nodo->izdo_, k);
  }
  return BuscarRama(nodo->dcho_, k);
}