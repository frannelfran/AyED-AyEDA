#include <iostream>
#include "lattice.h"
#include "alfabeto.h"

class AutomataCelular {
  public:
   AutomataCelular(Lattice&);

  private:
   Lattice reticulo; // Retículo del autómata
   Alfabeto alfabeto_; // Alfabeto del autómata
};