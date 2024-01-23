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

#pragma once

#include <iostream>

#include <cassert>

#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class RationalT {
public: // Características de la clase 
  RationalT(const int = 0, const int = 1);
  ~RationalT() {} // Destructor 
  
  // getters
  int get_numerador() const;
  int get_denominador() const;
  
  // setters
  void set_numerador(const int);
  void set_denominador(const int);

  double value(void) const;
  RationalT opposite(void) const;
  RationalT reciprocal(void) const;

  // Comprobaciones 
  bool is_equal(const RationalT&, const double precision = EPSILON) const;
  bool is_greater(const RationalT&, const double precision = EPSILON) const;
  bool is_less(const RationalT&, const double precision = EPSILON) const;

  // Operaciones 
  RationalT add(const RationalT&) const;
  RationalT substract(const RationalT&) const;
  RationalT multiply(const RationalT&) const;
  RationalT divide(const RationalT&) const;

  void write(ostream& os = cout) const;
  void read(istream& is = cin);
  
private: // Atributos de la clase 
  int numerador_, denominador_;
};

// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const RationalT&);
istream& operator>>(istream& is, RationalT&);

// FASE I: operadores
RationalT operator+(const RationalT&, const RationalT&);
RationalT operator-(const RationalT&, const RationalT&);
RationalT operator*(const RationalT&, const RationalT&);
RationalT operator/(const RationalT&, const RationalT&);