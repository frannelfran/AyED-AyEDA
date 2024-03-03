#pragma once
#include "cellace/cellace.h"

using namespace std;

class CellAce110 : public CellAce {
  public:
   // Constructor de la clase
   CellAce110(const Position& pos, const State& state) : CellAce(pos, state) {}
   // Funciones
   int Rule(State&, State&) const override;
};