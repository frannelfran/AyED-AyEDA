#include <iostream>

#pragma once
using namespace std;

class State {
  public:
   // Constructores de la clase
   State();
   State(bool);

   // Getters
   inline bool GetState() { return this->state_; }

  private:
   bool state_; // Estado actual
};