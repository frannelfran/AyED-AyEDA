// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLLT_H_
#define SLLT_H_

#include <iostream>
#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T> class sll_t {
 public:
  // constructor
  sll_t(void) : head_(NULL) {}

  // destructor
  ~sll_t(void);

  // getters
  sll_node_t<T>* get_head(void) const { return head_; };
  
  bool empty(void) const;

  // operaciones
  void push_front(sll_node_t<T>*);
  sll_node_t<T>* pop_front(void);

  void insert_after(sll_node_t<T>*, sll_node_t<T>*);
  sll_node_t<T>* erase_after(sll_node_t<T>*);
  sll_node_t<T>* erase_last();
  void change_elto();
  void delete_odd(sll_t<T>);

  sll_node_t<T>* search(const T&) const;

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  sll_node_t<T>* head_;
};


// destructor
template <class T> sll_t<T>::~sll_t(void) {
  while (!empty()) {
    sll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

// Comprobar si lista vacía
template <class T> bool sll_t<T>::empty(void) const {
  return head_ == NULL;
}

// operaciones
template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n->set_next(head_);
  head_ = n;
}

template <class T> sll_node_t<T>* sll_t<T>::pop_front(void) { 
  assert(!empty());
  sll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev,
					       sll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) { 
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T>* aux = prev->get_next();
  
  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const {
  sll_node_t<T>* aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();
    
  return aux;
}

// E/S
template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

template <class T> sll_node_t<T>* sll_t<T>::erase_last() {
  sll_node_t<char>* aux = get_head();
  sll_node_t<char>* aux2 = aux -> get_next();
  assert(!empty());
  while(aux2 -> get_next() != NULL) {
    aux = aux -> get_next();
    aux2 = aux2 -> get_next();
  }
  char element = aux2 -> get_data();
  std::cout << "Se ha extraído la letra " << "'" << element << "'" << std::endl;
  return aux;
}

template <class T> void sll_t<T>::change_elto() {
  assert(!empty());
  sll_node_t<char>* aux = get_head();
  sll_node_t<char>* aux2 = aux -> get_next();
  char primero = aux2 -> get_data();
  erase_after(aux);
  push_front(new sll_node_t<T>(primero));
}

template <class T> void sll_t<T>::delete_odd(sll_t<T> lista) {
  sll_node_t<char>* aux1 = lista.get_head();
  sll_node_t<char>* aux2;
  sll_node_t<char>* aux3;
  unsigned i = 0;
  while(aux1 -> get_next() != NULL) {
    if(i % 2 == 0) {
      char letra_par = aux1 -> get_data();
      aux3 = lista.search(letra_par);
      aux3 = lista.erase_after(aux3);
      aux2 = aux3;
      char letra_impar = aux2 -> get_data();
      push_front(new sll_node_t<char>(letra_impar));
    }
    aux1 = aux1 -> get_next();
    i += 2;
  }
  std::cout << "\nLista con los elementos impares quitados\n" << std::endl;
  lista.write();
}

#endif  // SLLT_H_
