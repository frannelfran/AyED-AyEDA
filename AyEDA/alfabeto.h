#include <iostream>
#include <set>

#pragma once
using namespace std;

class Alfabeto {
  public:
   Alfabeto(bool); // Constructor de la clase alfabeto

   // Sobrecarga de operadores
   friend ostream& operator<<(ostream& os, const Alfabeto& alf);

  private:
   set<bool> alfabeto_;
};