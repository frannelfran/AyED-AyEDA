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
  int resultado;
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
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'l' || c == 'r' || c == 'c');
  int resultado;
  int operando1;
  int operando2;
  int operando3; // Operando si encuentra un l de (log) y un r de raíz

  if(c == 'l' || c == 'r' || c == 'c') {
    operando3 = stack_.top();
    std::cout << "   Sacamos de la pila un operando: " << operando3 << std::endl;
    stack_.pop(); // Lo sacamos de la pila
  }
  else {
    operando1 = stack_.top();
    std::cout << "   Sacamos de la pila un operando: " << operando1 << std::endl;
    stack_.pop();
    operando2 = stack_.top();
    std::cout << "   Sacamos de la pila otro operando: " << operando2 << std::endl;
    stack_.pop();
  }

  switch (c) {
    case '+': // Suma los operandos
      resultado = operando1 + operando2;
      break;
    case '-': // Resta los operandos
      resultado = operando2 - operando1;
      break;
    case '*': // Múltiplica los operandos
      resultado = operando1 * operando2;
      break;
    case '/': // Divide los operandos
      resultado = operando2 / operando1;
      break;
    case 'c': // Eleva al cuadrado el operando
      resultado = pow(operando3, 2);
      break;
    case '^': // Eleva los operandos
      resultado = pow(operando1,operando2);
      break;
    case 'l': // Realiza el logaritmo en base 2 del operando
      resultado = log(operando3);
      break;
    case 'r': // Realiza la raíz cuadrada del operando
      resultado = sqrt(operando3);
      break;
    // Fin de los casos
  }

  stack_.push(resultado);
  std::cout << "   Metemos en la pila el resultado: " << resultado << std::endl;
}

#endif  // RPNT_H_