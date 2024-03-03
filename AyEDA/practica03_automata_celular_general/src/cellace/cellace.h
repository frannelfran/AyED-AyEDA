#pragma once
#include "../cell/cell.h"

using namespace std;

class CellAce : public Cell {
  public:
   // Constructor de la clase
   inline CellAce(const Position& pos, const State& state) : Cell(pos, state) {}

   // Funciones
   int NextState(const Lattice&) override;
   void UpdateState() override {}
   virtual int Rule(const State&, const State&) = 0;
   
   ostream& Display(ostream& os) const override;
};