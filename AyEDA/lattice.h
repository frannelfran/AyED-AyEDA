#include <iostream>
#include <vector>

using namespace std;

class Lattice {
  public:
   Lattice(Cell&); // Constructor de la clase

  
  private:
   vector<Cell> celulas_; // Conjunto de células
};