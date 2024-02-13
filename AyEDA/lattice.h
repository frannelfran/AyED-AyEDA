#pragma once
#include <iostream>
#include <vector>
#include "cell.h"

using namespace std;

class Lattice {
  public:
   Lattice(const Cell&); // Constructor de la clase

  
  private:
   vector<Cell> lattice_; // Conjunto de células
};