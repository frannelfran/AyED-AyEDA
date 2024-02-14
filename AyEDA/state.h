#pragma once
#include <iostream>

using namespace std;

class State {
  public:
   // Constructores de la clase
   State();
   State(int);

   // Setters
   inline void SetData(int estado) { this->state_ = estado; }

   // Getters
   inline int GetData() { return this->state_; }

  private:
   int state_; // Estado actual
};