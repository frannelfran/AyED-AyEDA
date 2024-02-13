#pragma once
#include <iostream>
#include <set>

using namespace std;

class Alfabeto {
  public:
   Alfabeto(int); // Constructor de la clase alfabeto

   // Sobrecarga de operadores
   friend ostream& operator<<(ostream& os, const Alfabeto& alf);

  private:
   set<bool> alfabeto_;
};