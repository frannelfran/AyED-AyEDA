// AUTOR: FRANCO ALLA
// FECHA: 18-02-2023
// EMAIL: alu0101571669@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#include "rational_t.hpp"

RationalT::RationalT(const int numerador, const int denominador) { // Construtor con parámetros
  assert(denominador != 0); // Si el denominador es igual a cero el programa para de ejecutarse
  numerador_ = numerador, denominador_ = denominador;
}

const int RationalT::get_numerador() { // Retorna el valor del atributo
  return numerador_;
}

const int RationalT::get_denominador() { // Retorna el valor del atributo
  return denominador_;
}

void RationalT::set_numerador(const int numerador) { // Procedimiento que asigna el valor del atributo de la clase a la variable 
  numerador_ = numerador;
}

void RationalT::set_denominador(const int denominador) { // Procedimiento que asigna el valor del atributo de la clase a la variable 
  assert(denominador != 0);
  denominador_ = denominador;
}

const double RationalT::value() {  // Valor de la división del numerador y denominador de la fracción
  return double(get_numerador()) / get_denominador();
}

// comparaciones

bool RationalT::is_equal(RationalT& r, const double precision) { // Función booleana que indica si la primera fracción y la segunda son iguales
  bool result = fabs(value() - r.value()) < precision;
  return result;
}

bool RationalT::is_greater(RationalT& r, const double precision) { // Función booleana que indica si la primera fracción es mayor que la otra
  bool result = (value() - r.value()) > precision;
  return result;
}

bool RationalT::is_less(RationalT& r, const double precision) { // Función booleana que indica si la primera fracción es menor que la otra 
  bool result = (r.value() - value()) > precision;
  return result;
}

bool RationalT::equal_cero(RationalT& r, const double precision) { // Función booleana que indica si la primera fracción es igual a cero
  bool result = fabs(value()) < precision;
  return result;
}

bool RationalT::is_greater_than_one() const { 
  bool result = (numerador_ / denominador_) > 1; 
  return result;
}

// operaciones

RationalT RationalT::add(RationalT& r) { // Función que suma los valores de a y b
  return RationalT ((numerador_ * r.get_denominador()) + (denominador_ * r.get_numerador()), denominador_ * r.get_denominador());
}

RationalT RationalT::substract(RationalT& r) { // Función que resta los valores de a y b
  return RationalT ((r.get_denominador() * numerador_) - (r.get_numerador() * denominador_), denominador_ * r.get_denominador());
}

RationalT RationalT::multiply(RationalT& r) { // Funcion que múltiplica los valores de a y b
  return RationalT (numerador_ * r.get_numerador(), denominador_ * r.get_denominador());
}

RationalT RationalT::divide(RationalT& r) { // Función que divide los valores de a y b 
  return RationalT (numerador_ * r.get_denominador(), denominador_ * r.get_numerador());
}

// E/S
void RationalT::write(ostream& os) { // Procedimiento que escribe la fracción y muestra su resultado 
  os << get_numerador() << "/" << get_denominador() << "=" << value() << endl;
}

void RationalT::read(istream& is) { // Procedimiento que le pide al usuario un numerador y un denominador
  cout << "Numerador? ";
  is >> numerador_;
  cout << "Denominador? ";
  is >> denominador_;
  assert(denominador_ != 0); // Si el denominador es igual a cero el programa para de ejecutarse 
}
