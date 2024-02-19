#pragma once
#include <iostream>

using namespace std;

class Position {
  public:
   // Constructores de la clase
   inline Position() {}
   inline Position(int position) { this->position_ = position; }

   // Getters
   inline int GetData() const { return this->position_; }

   // Setters
   inline void SetData(int posicion) { this->position_ = posicion; }

  private:
   int position_;
};