#pragma once
#include <iostream>
#include <initializer_list>
#include <cassert>

using namespace std;

class Position {
  public:
   // Constructores de la clase
   inline Position() {}
   Position(initializer_list<int>);

   // Getters
   inline int GetX() const { return position_[0]; }
   inline int GetY() const { return position_[1]; }

  private:
   int position_[2];
};