// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>

#include "dll_node_t.h"

// Clase para almacenar una lista doblemente enlazada
template <class T> class dll_t {
 public:
  // constructor
  dll_t(void) : head_(NULL), tail_(NULL), sz_(0) {}

  // destructor
  ~dll_t(void); 

  // getters
  dll_node_t<T>* get_tail(void) const { return tail_; }
  dll_node_t<T>* get_head(void) const { return head_; }
  int get_size(void) const { return sz_; }

  bool empty(void) const;

  // operaciones
  void push_back(dll_node_t<T>*);
  void push_front(dll_node_t<T>*);

  dll_node_t<T>* pop_back(void);
  dll_node_t<T>* pop_front(void);
  void insert_nodo(char, char);
  void change_last();
  void duplicate();
  void erase_odd();
  void pair_list(dll_t<char>);
  dll_node_t<T>* erase(dll_node_t<T>*);

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  dll_node_t<T>* head_;
  dll_node_t<T>* tail_;
  int            sz_;
};


// destructor
template <class T> dll_t<T>::~dll_t(void) {
  while (head_ != NULL) {
    dll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

// Comprobar si lista vacía
template <class T> bool dll_t<T>::empty(void) const {
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } else
    return false;
}

// operaciones
template <class T> void dll_t<T>::push_front(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}

template <class T> void dll_t<T>::push_back(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_back(void) {
  assert(!empty());

  dll_node_t<T>* aux = tail_;
  tail_ = tail_->get_prev();
  if (tail_ != NULL)
    tail_->set_next(NULL);
  else
    head_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_front(void) {
  assert(!empty());

  dll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  if (head_ != NULL)
    head_->set_prev(NULL);
  else
    tail_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T> dll_node_t<T>* dll_t<T>::erase(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (nodo->get_prev() != NULL)
    nodo->get_prev()->set_next(nodo->get_next());
  else
    head_ = nodo->get_next();
  if (nodo->get_next() != NULL)
    nodo->get_next()->set_prev(nodo->get_prev());
  else
    tail_ = nodo->get_prev();
  sz_--;
  nodo->set_prev(NULL);
  nodo->set_next(NULL);
  return nodo;
}

// E/S
template <class T> std::ostream& dll_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

template <class T> void dll_t<T>::insert_nodo(char letra_a_insertar, char nodo_a_buscar) {
  dll_node_t<T>* aux = get_head();
  assert(!empty()); // Mientras no este vacía la lista

  while(aux != NULL) {
    char buscar = aux -> get_data();
    if(buscar == nodo_a_buscar) {
      aux -> set_data(letra_a_insertar);
    }
    aux = aux -> get_next();
  }
}

template <class T> void dll_t<T>::change_last() {
  dll_node_t<T>* cola = get_tail();
  dll_node_t<T>* antes_cola = cola -> get_prev();
  char aux, aux2;

  assert(!empty());
  aux = cola -> get_data();
  aux2 = antes_cola -> get_data();
  cola -> set_data(aux2);
  antes_cola -> set_data(aux);
}

template <class T> void dll_t<T>::duplicate() {
  dll_node_t<T>* aux = get_head();
  dll_node_t<T>* tail = get_tail();
  char letra, letra_cola;
  letra_cola = tail -> get_data();

  assert(!empty());
  while(letra != letra_cola) {
    letra = aux -> get_data();
    push_back(new dll_node_t<T>(letra));
    aux = aux -> get_next();
  }
}

/*template<class T> void dll_t<T>::erase_odd() { // Cambiar porque está mal
  dll_node_t<T>* aux = get_head();
  dll_node_t<T>* aux2;
  unsigned i = 0;
  assert(!empty());
  while(aux != NULL) {
    if(i % 2 != 0) {
      aux2 = aux;
      delete aux2;
    }
    aux = aux -> get_next();
    i++;
  }
}*/


template <class T> void dll_t<T>::pair_list(dll_t<char> lista) {
  dll_node_t<T>* aux = lista.get_head(); // Cola de la lista
  dll_t<char> lista_par;
  unsigned i = 0;
  char letra_par;
  assert(!lista.empty());
  // Colocar los elementos pares en otra lista
  while(aux != NULL) {
    if(i % 2 == 0) {
      letra_par = aux -> get_data();
      lista_par.push_front(new dll_node_t<T>(letra_par));
    }
    aux = aux -> get_next(); // Siguiente eleento
    i++;
  }

  // Ordenar la lista
  aux = lista_par.get_head();
  while(aux != NULL) {
    letra_par = aux -> get_data();
    push_front(new dll_node_t<T>(letra_par));
    aux = aux -> get_next();
  }
}


#endif  // DLLT_H_
