#pragma once 
#include "../cell/cell.h"

using namespace std;

class CellLife : public Cell {
  public:
   // Constructor de la clase
   inline CellLife(const Position& pos, const State& state) : Cell(pos, state) {}

   // Funciones
   int NextState(const Lattice&) override;
   virtual int Rule(int) = 0;
    
   ostream& Display(ostream& os) const override;
};