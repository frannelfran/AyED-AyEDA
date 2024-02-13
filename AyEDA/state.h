#include <iostream>

using namespace std;

class State {
  public:
   State(bool); // Cosntructor de la clase State

   // Getters
   inline bool GetState() { return this->state_; }

  private:
   bool state_; // Estado actual
};