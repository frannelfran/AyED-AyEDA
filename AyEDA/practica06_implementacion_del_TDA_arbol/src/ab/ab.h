#pragma once
#include "../key/key.h"
#include "../nodoB/nodoB.h"
#include <queue>

using namespace std;

// Clase ABstracta para representar un árbol binario

template <class Key>
class AB {
 public:
  // Constructores
  AB() : raiz_(nullptr) {}

  // Destructor
  ~AB() {
    delete this->raiz_;
  }

  // Métodos
  virtual bool Insertar(const Key& k) = 0;
  virtual bool Buscar(const Key& k) const = 0;
  virtual void Inorder() const = 0;

  // Sobrecarga de operadores
  template<class T> friend ostream& operator<<(ostream& os, const AB<T>& AB);

 protected:
  NodoB<Key>* raiz_;
};

// Clase ABB<Key> para representar un árbol binario de búsqueda

template <class Key>
class ABB : public AB<Key> {
 public:
  // Constructor
  ABB() : AB<Key>() {}

  // Destructor
  ~ABB() {}

  // Métodos
  bool Insertar(const Key& k) override;
  bool Buscar(const Key& k) const override;
  void Inorder() const override;

  // Métodos de la propia clase
  bool InsertarRama(NodoB<Key>*& nodo, const Key& k);
  bool BuscarRama(NodoB<Key>* nodo, const Key& k) const;
  void InorderRama(NodoB<Key>* nodo) const;
};

template<class Key>
class ABE : public AB<Key> {
 public:
  // Constructor
  ABE() : AB<Key>() {}
  
  // Destructor
  ~ABE() {}
  
  // Métodos
  bool Insertar(const Key& k) override;
  bool Buscar(const Key& k) const override;
  void Inorder() const override;
  
  // Métodos de la propia clase
  bool InsertarEquilRama(NodoB<Key>*& nodo, const Key& k);
  bool BuscarRama(NodoB<Key>* nodo, const Key& k) const;
  void InorderRama(NodoB<Key>* nodo) const;
  const int Tam() { return TamRama(this->raiz_); }
  const int TamRama(NodoB<Key>* nodo);
};

////////////////////////////////////////////// Implementación de los métodos de la clase ABB<Key> //////////////////////////////////////////////

/**
 * @brief Inserta un nodo en el árbol
 * @param k Clave del nodo a insertar
 * @return true si se ha insertado el nodo, false en caso contrario
*/

template <class Key> bool ABB<Key>::Insertar(const Key& k) {
  return InsertarRama(this->raiz_, k);
}

/**
 * @brief Inserta un nodo en una rama del árbol
 * @param nodo Nodo raíz de la rama
 * @param k Clave del nodo a insertar
 * @return true si se ha insertado el nodo, false en caso contrario
*/

template <class Key> bool ABB<Key>::InsertarRama(NodoB<Key>*& nodo, const Key& k) {
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
 * @brief Busca un nodo en el árbol
 * @param k Clave del nodo a buscar
 * @return Puntero al nodo si se ha encontrado, NULL en caso contrario
*/

template<class Key> bool ABB<Key>::Buscar(const Key& k) const {
  return BuscarRama(this->raiz_, k);
}

/**
 * @brief Busca un nodo en una rama del árbol
 * @param nodo Nodo raíz de la rama
 * @param k Clave del nodo a buscar
 * @return Puntero al nodo si se ha encontrado, NULL en caso contrario
*/

template<class Key> bool ABB<Key>::BuscarRama(NodoB<Key>* nodo, const Key& k) const {
  if (nodo == nullptr) {
    return false;
  } else if (k == nodo->GetDato()) {
    return true;
  } else if (k < nodo->GetDato()) {
    return BuscarRama(nodo->GetIzdo(), k);
  } else if (k > nodo->GetDato()) {
    return BuscarRama(nodo->GetDcho(), k);
  }
  return false;
}

/**
 * @brief Recorre el árbol en inorden
*/

template<class Key> void ABB<Key>::Inorder() const {
  InorderRama(this->raiz_);
}

/**
 * @brief Recorre una rama del árbol en inorden
 * @param nodo Nodo raíz de la rama
*/

template<class Key> void ABB<Key>::InorderRama(NodoB<Key>* nodo) const {
  if (nodo != nullptr) {
    InorderRama(nodo->GetIzdo());
    InorderRama(nodo->GetDcho());
    cout << nodo->GetDato() << " ";
  }
}

////////////////////////////////////////////// Implementación de los métodos de la clase ABE<Key> //////////////////////////////////////////////

/**
 * @brief Calcular el tamaño de la rama
 * @param nodo Nodo raíz de la rama
 * @return Tamaño de la rama
*/

template<class Key> const int ABE<Key>::TamRama(NodoB<Key>* nodo) {
  if (nodo == nullptr) {
    return 0;
  } else {
    return (1 + TamRama(nodo->GetIzdo()) + TamRama(nodo->GetDcho()));
  }
}

/**
 * @brief Inserta un nodo en el árbol
 * @param k Clave del nodo a insertarç
 * @return true si se ha insertado el nodo, false en caso contrario
*/

template<class Key> bool ABE<Key>::Insertar(const Key& k) {
  if (this->raiz_ == nullptr) {
    this->raiz_ = new NodoB<Key>(k, nullptr, nullptr);
    return true;
  } else {
    return InsertarEquilRama(this->raiz_, k);
  }
}

/**
 * @brief Inserta un nodo en una rama del árbol
 * @param nodo Nodo raíz de la rama
 * @param k Clave del nodo a insertar
 * @return true si se ha insertado el nodo, false en caso contrario
*/

template<class Key> bool ABE<Key>::InsertarEquilRama(NodoB<Key>*& nodo, const Key& k) {
  if (TamRama(nodo->GetIzdo()) <= TamRama(nodo->GetDcho())) {
    if (nodo->GetIzdo() != nullptr) {
      return InsertarEquilRama(nodo->GetIzdo(), k);
    }
    else {
      nodo->GetIzdo() = new NodoB<Key>(k, nullptr, nullptr);
      return true;
    }
  }
  else {
    if (nodo->GetDcho() != nullptr) {
      return InsertarEquilRama(nodo->GetDcho(), k);
    }
    else {
      nodo->GetDcho() = new NodoB<Key>(k, nullptr, nullptr);
      return true;
    }
  }
  return false;
}

/**
 * @brief Busca un nodo en el árbol
 * @param k Clave del nodo a buscar
 * @return true si se ha encontrado el nodo, false en caso contrario
*/

template<class Key> bool ABE<Key>::Buscar(const Key& k) const {
  return BuscarRama(this->raiz_, k);
}

/**
 * @brief Busca un nodo en una rama del árbol
 * @param nodo Nodo raíz de la rama
 * @param k Clave del nodo a buscar
 * @return true si se ha encontrado el nodo, false en caso contrario
*/

template<class Key> bool ABE<Key>::BuscarRama(NodoB<Key>* nodo, const Key& k) const {
  if (nodo == nullptr) {
    return false;
  } else if (k == nodo->GetDato()) {
    return true;
  } else if (k < nodo->GetDato()) {
    return BuscarRama(nodo->GetIzdo(), k);
  } else if (k > nodo->GetDato()) {
    return BuscarRama(nodo->GetDcho(), k);
  }
  return false;
}

/**
 * @brief Recorre el árbol en inorden
 * @param nodo Nodo raíz de la rama
*/

template<class Key> void ABE<Key>::Inorder() const {
  InorderRama(this->raiz_);
}

/**
 * @brief Recorre una rama del árbol en inorden
 * @param nodo Nodo raíz de la rama
*/

template<class Key> void ABE<Key>::InorderRama(NodoB<Key>* nodo) const {
  if (nodo != nullptr) {
    InorderRama(nodo->GetIzdo());
    cout << nodo->GetDato() << " ";
    InorderRama(nodo->GetDcho());
  }
}





/**
 * @overload Sobrecarga del operador <<
*/

template<class Key> ostream& operator<<(ostream& os, const AB<Key>& AB) {
  queue<NodoB<Key>*> cola;
  NodoB<Key>* nodo = AB.raiz_;
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

