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
  virtual bool Buscar(const Key& k) const = 0;
  virtual void Inorder() const = 0;

  // Sobrecarga de operadores
  friend ostream& operator<<(ostream& os, const Ab<Key>& ab);

 protected:
  NodoB<Key>* raiz_;
};

// Clase ABE<Key> para representar un árbol binario equilibrado

template <class Key>
class Abe : public Ab<Key> {
 public:
  // Métodos
  bool Insertar(const Key& k) override;
  bool Buscar(const Key& k) const override;
  void Inorder() const override;
};

// Clase ABB<Key> para representar un árbol binario de búsqueda

template <class Key>
class Abb : public Ab<Key> {
 public:
  // Métodos
  bool Insertar(const Key& k) override;
  bool Buscar(const Key& k) const override;
  void Inorder() const override;
};

