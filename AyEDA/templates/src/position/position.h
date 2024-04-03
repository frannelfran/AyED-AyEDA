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

    // Setters
    void SetData(int posicion) { this->posicion_ = posicion; }

  private:
    int posicion_;
};