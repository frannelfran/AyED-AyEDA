#include <iostream>

#pragma once
using namespace std;

class Position {
  public:
   // Constructores de la clase
   Position();
   Position(int);

   inline int GetPoicion() { return this->position_; }

  private:
   int position_;
};