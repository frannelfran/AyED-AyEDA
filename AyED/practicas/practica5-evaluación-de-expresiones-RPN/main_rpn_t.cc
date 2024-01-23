// AUTOR: Franco Alla 
// FECHA: 28-04-2023
// EMAIL: alu0101571669@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5 
// 

#include <iostream>

#include "stack_l_t.h"
#include "queue_l_t.h"
#include "rpn_t.h"

using namespace std;

int main(void) {
  rpn_t<stack_l_t<int>> calculadora;
  queue_l_t<char> cola;
	
  while (!cin.eof()) 	{
    cin >> ws; // lee los espacios en blanco, que dan problemas
    if (!cin.eof()) {
      char c;
      cin >> c;
      cola.push(c);
    }
  }

  cout << "Expresión a evaluar: ";	
  cola.write();

  int r = calculadora.evaluate(cola);
  cout << "Resultado: " << r << endl;
  
  return 0;
}