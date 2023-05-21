// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T&);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;
  void change();
  void mirror(stack_l_t<T>);
  void delete_odd(stack_l_t<T>);

  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

private:
  dll_t<T> l_;
};


// operaciones
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
}

template<class T> const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

template<class T> bool stack_l_t<T>::empty(void) const {
  return l_.empty();
}

// E/S
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}

template <class T> void stack_l_t<T>::change() {
  dll_node_t<T>* aux = l_.get_head();
  dll_node_t<T>* siguiente = aux -> get_next();
  
  char primero = aux -> get_data();
  char segundo = siguiente -> get_data();
  aux -> set_data(segundo);
  siguiente -> set_data(primero);
}

template <class T> void stack_l_t<T>::mirror(stack_l_t<T> pila_normal) {
  dll_node_t<T>* aux = pila_normal.l_.get_head();
  while(aux != NULL) {
    char letra = aux -> get_data();
    aux = aux -> get_next();
    pila_normal.pop();
    pila_normal.write();
    push(letra);
  }
}

template <class T> void stack_l_t<T>::delete_odd(stack_l_t<T> pila_original) {
  dll_node_t<T>* aux = pila_original.l_.get_head();
  dll_node_t<T>* aux2;
  stack_l_t<T> pila_par;
  int k = 2;
  unsigned i = 0;
  assert(!pila_original.empty());
  while(aux != NULL) {
    if(i % k != 0) {
      char letra_impar = aux -> get_data();
      push(letra_impar);
    }
    else {
      char letra_par = aux -> get_data();
      pila_par.push(letra_par);
      pila_par.write();
    }
    aux = aux -> get_next();
    i++;
  }
}

#endif  // STACKL_H_
