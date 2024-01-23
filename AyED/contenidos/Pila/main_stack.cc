// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_stack.cc -o main_stack
// EJECUCIÓN: ./main_stack

#include <iostream>

#include "stack_v_t.h"
#include "stack_l_t.h"

using namespace std;

int main(void) {

  stack_v_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 10; i++) {
    pila_vector.push('a' + i);
    pila_vector.write();
    cout << endl;
  }
  cout << endl;

  stack_l_t<char> pila_lista;
  cout << "********** PILA LISTA **********" << endl;
  for (int i = 0; i < 10; i++) {
    pila_lista.push('a' + i);
    pila_lista.write();
    cout << endl;
  }

  // Pila con el primer y segundo elemento intercambiado
  cout << " Intercambiando primer y segundo elemento..." << endl;
  pila_lista.change();
  pila_lista.write();
  cout << endl;

  //Sacar elementos de una pila y colocarlos de manera invertida en otra
  cout << "Vaciando pila original..." << endl;
  stack_l_t<char> pila_invertida;
  pila_invertida.mirror(pila_lista);
  cout << "Invirtiendo pila..." << endl;
  pila_invertida.write();
  cout << endl;

  //Eliminar los elementos pares de una pila y colocarlos en otra
  stack_l_t<char> pila_impares;
  cout << "Gnerando pila con los elementos de las posiciones pares..." << endl;
  pila_impares.delete_odd(pila_invertida);
  cout << "Generando pila con los elementos de las posiciones impares de la anterior..." << endl;
  pila_impares.write();
  cout << endl;

  return 0;
}
