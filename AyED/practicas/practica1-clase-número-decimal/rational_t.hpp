// AUTOR: FRANCO ALLA
// FECHA: 18-02-2023
// EMAIL: alu0101571669@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class RationalT {
public: // Carácteristicas de la clase 
  RationalT(const int = 0, const int = 1); // Constructor 

  // getters
  const int get_numerador();
  const int get_denominador();
  
  // setters
  void set_numerador(const int);
  void set_denominador(const int);

  const double value();

  // FASE II (Funciones booleanas)
  bool is_equal(RationalT&, const double precision = EPSILON);
  bool is_greater(RationalT&, const double precision = EPSILON);
  bool is_less(RationalT&, const double precision = EPSILON);
  bool equal_cero(RationalT&, const double precision = EPSILON);
  bool is_greater_than_one(void) const;
  
  // FASE III
  RationalT add(RationalT&);
  RationalT substract(RationalT&);
  RationalT multiply(RationalT&);
  RationalT divide(RationalT&);
  
  void write(ostream& = cout);
  void read(istream& = cin);
  
private: // Atributos de la clase
  int numerador_, denominador_;
};
