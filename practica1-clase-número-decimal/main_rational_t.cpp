// AUTOR: FRANCO ALLA
// FECHA: 18-02-2023
// EMAIL: alu0101571669@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g Rational_t.cpp main_rational_t.cpp -o main_rational_t

#include <iostream>
#include <cmath>
#include "rational_t.hpp"

using namespace std;

int main() {
  RationalT a(1, 2), b(3), c;

  // Se muestra el resultado de las fracciones 
  cout << "a.value()= " << a.value() << endl; 
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write(); // Escribe la fracción "a"
  cout << "b: "; 
  b.write(); // Escribe la fracción "b" 

  c.read(); // Se pregunta por consola que valores le quiere poner el usuario al nuemrador y denominador 
  cout << "c: ";
  c.write(); // Escribe la fracción "c" y muestra su resultado

  // FASE II
  RationalT x(1, 3), y(2, 3);
  x.write();
  y.write();
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl; // Muestra por consola si las dos fracciones son iguales
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl; // Muestra por consola si la fracción "x" es menor que la fracción "y"
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl; // Muestra por consola si la fracción "x" es mayor que la fracción "y"
  cout << "x == 0 " << (x.equal_cero(y) ? "true" : "false") << endl; // Muestra por consola si la fracción "x" es igual a cero 
  cout << "Is greater than 1? " << (c.is_greater_than_one() ? "Es mayor que 1" : "Es menor que 1") << endl;
  
  // FASE III
  cout << "a + b: ";
  a.add(b).write(); // Muestra por consola la suma de la fracción "a" con la fracción "b"
  
  cout << "b - a: ";
  b.substract(a).write(); // Muestra por consola la resta de la fracción "a" con la fracción "b"

  cout << "a * b: ";
  a.multiply(b).write(); // Muestra por consola la multiplicación de la fracción "a" con la fracción "b"
  
  cout << "a / b: ";
  a.divide(b).write(); // Muestra por consola la división de la fracción "a" con la fracción "b"

  return 0;
}
