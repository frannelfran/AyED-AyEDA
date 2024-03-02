#pragma once
#include "../cell/cell.h"

using namespace std;

class CellAce : public Cell {
  public:
   // Funciones
   int NextState(const Lattice&) override;
   void UpdateState() override;

   virtual int Rule(State&, State&) const = 0;
};