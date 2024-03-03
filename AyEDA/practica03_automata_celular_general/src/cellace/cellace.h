#pragma once
#include "../cell/cell.h"

using namespace std;

class CellAce : public Cell {
  public:
   // Constructor de la clase
   inline CellAce(const Position& pos, const State& state) : Cell(pos, state) {}
   // Funciones
   int NextState(const Lattice&) override;
   void UpdateState() override;

   virtual int Rule(State&, State&) const = 0;
};