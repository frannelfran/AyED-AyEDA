// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      
      std::cout << " (es un dígito) " << std::endl
		  << "   Lo metemos en la pila..." << std::endl;
      stack_.push(i);
    } 
    else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  // poner código
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/');
  int resultado;
  int operando1 = stack_.top();
  std::cout << "   Sacamos de la pila un operando: " << operando1 << std::endl;
  stack_.pop();
  int operando2 = stack_.top();
  std::cout << "   Sacamos de la pila otro operando: " << operando2 << std::endl;
  stack_.pop();
  
  switch (c) {
    case '+':
      resultado = operando1 + operando2;
      break;
    case '-':
      resultado = operando2 - operando1;
      break;
    case '*':
      resultado = operando1 * operando2;
      break;
    case '/':
      resultado = operando2 / operando1;
      break;
    // Fin de los casos
  }

  stack_.push(resultado);
  std::cout << "   Metemos en la pila el resultado: " << resultado << std::endl;
}

 
#endif  // RPNT_H_
