// AUTOR: Franco Alla 
// FECHA: 07-03-2023
// EMAIL: alu0101571669@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

RationalT::RationalT(const int numerador, const int denominador)
{
  assert(denominador != 0);
  numerador_ = numerador, denominador_ = denominador;
}

inline int RationalT::get_numerador() const { // Devuelve el valor del atributo de la clase 
  return numerador_;
}

inline int RationalT::get_denominador() const { // Devuelve el valor del atributo de la clase 
  return denominador_;
}
 
void RationalT::set_numerador(const int numerador) { // Le asigna el valor del atributo de la clase a la variable 
  numerador_ = numerador;
}
 
void
RationalT::set_denominador(const int denominador) { // le asigna el valor del atributo de la clase a la variable
  assert(denominador != 0);
  denominador_ = denominador;
}

inline double RationalT::value() const { // Calcula el valor de la fracción 
  return double(get_numerador()) / get_denominador();
}

RationalT RationalT::opposite() const { // Devuelve la fracción contraria 
  return RationalT((-1)*get_numerador(), get_denominador());
}

RationalT RationalT::reciprocal() const { 
  return RationalT(get_denominador(), get_numerador());
}

// comparaciones
bool RationalT::is_equal(const RationalT& r, const double precision) const { // Comprueba si las dos fracciones son iguales 
  return fabs(value() - r.value()) < precision;
}

bool RationalT::is_greater(const RationalT& r, const double precision) const { // Comprueba si una fracción es mayor que otra 
  return (value() - r.value()) > precision;
}

bool RationalT::is_less(const RationalT& r, const double precision) const { // Comprueba si una fracción es menor que la otra 
  return r.is_greater(*this, precision);
}

// operaciones
RationalT RationalT::add(const RationalT& r) const { // Suma de 2 fracciones 
  return RationalT(get_numerador() * r.get_denominador() + get_denominador() * r.get_numerador(), 
                    get_denominador() * r.get_denominador());
}

RationalT RationalT::substract(const RationalT& r) const { // Resta de 2 fracciones 
  return add(r.opposite());
}

RationalT RationalT::multiply(const RationalT& r) const { // Multiplicación de 2 fracciones 
  return RationalT(get_numerador() * r.get_numerador(), get_denominador() * r.get_denominador());
}

RationalT RationalT::divide(const RationalT& r) const { // División de 2 fracciones 
  return multiply(r.reciprocal());
}

// FASE I: operadores de la clase RationalT
RationalT operator+(const RationalT& a, const RationalT& b) { // Sobrecarga del operador "+"
  return RationalT((a.get_numerador() * b.get_denominador() + a.get_denominador() * b.get_numerador()), a.get_denominador() * b.get_denominador());
}

RationalT operator-(const RationalT& a, const RationalT& b) { // Sobrecarga del operador "-"
  return RationalT((b.get_denominador() * a.get_numerador() - b.get_numerador() * a.get_denominador()), a.get_denominador() * b.get_denominador());
}

RationalT operator*(const RationalT& a, const RationalT& b) { // Sobrecarga del operador "*"
  return RationalT(a.get_numerador() * b.get_numerador(), a.get_denominador() * b.get_denominador());
}

RationalT operator/(const RationalT& a, const RationalT& b) { // Sobrecarga del operador "/"
  return RationalT(a.get_numerador() * b.get_denominador(), a.get_denominador() * b.get_numerador());
}

// E/S
void RationalT::write(ostream& os) const { // Escribe la fracción por consola y muestra su resultado 
  os << get_numerador() << "/" << get_denominador() << "=" << value() << endl;
}

void RationalT::read(istream& is) { // Lee el numerador y denominador pasados por consola 
  is >> numerador_ >> denominador_;
  assert(denominador_ != 0);
}

ostream& operator<<(ostream& os, const RationalT& r) { 
  r.write(os);
  return os;
}

istream& operator>>(istream& is, RationalT& r) {
  r.read(is);
  return is;
}