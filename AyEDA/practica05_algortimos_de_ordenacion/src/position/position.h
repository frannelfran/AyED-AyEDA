#pragma once
#include <iostream>

using namespace std;

class Position {
 public:
  // Constructores
  Position() {}
  Position(int posicion) : posicion_(posicion) {}
    
  // Getters
  int GetData() const { return this->posicion_; }

 private:
  int posicion_;
};