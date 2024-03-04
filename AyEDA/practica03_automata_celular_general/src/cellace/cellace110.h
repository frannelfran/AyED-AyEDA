#pragma once
#include "cellace.h"

using namespace std;

class CellAce110 : public CellAce {
  public:
   // Constructor de la clase
   inline CellAce110(const Position& pos, const State& state) : CellAce(pos, state) {}
   // Funciones
   int Rule(const State& celula_l, const State& celula_r) override;
};