#pragma once
#include <iostream>

using namespace std;

class State {
  public:
   // Constructores de la clase
   inline State() {}
   inline State(bool state) { this->state_ = state; }

   // Setters
   inline void SetData(bool estado) { this->state_ = estado; }

   // Getters
   inline bool GetData() const { return this->state_; }

  private:
   bool state_; // Estado actual
};