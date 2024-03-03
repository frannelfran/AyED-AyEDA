#pragma once
#include "cellace/cellace.h"

using namespace std;

class CellAce30 : public CellAce {
  public:
    // Constructor de la clase
    inline CellAce30(const Position& pos, const State& state) : CellAce(pos, state) {}
    // Funciones
    int Rule(State&, State&) const override;
};