#pragma once
#include <iostream>

using namespace std;

class State {
  public:
   // Constructores de la clase
   State();
   State(int);

   // Getters
   inline int GetState() { return this->state_; }

  private:
   int state_; // Estado actual
};