#pragma once
#include "cellLife.h"

using namespace std;

class CellLife51_346 : public CellLife {
  public:
   // Constructor de la clase
   inline CellLife51_346(const Position& pos, const State& state) : CellLife(pos, state) {}

   // Funciones
   int Rule(int) override;
};