#pragma once
#include <iostream>

using namespace std;

class Position {
  public:
   // Constructores de la clase
   Position();
   Position(int);

   inline int GetData() const { return this->position_; }

  private:
   int position_;
};