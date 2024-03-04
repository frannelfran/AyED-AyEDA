#pragma once
#include "cellLife.h"

class CellLife23_3 : public CellLife {
  public:
   // Constructor de la clase
   inline CellLife23_3(const Position& pos, const State& state) : CellLife(pos, state) {}

   // Funciones
   int Rule(int) override;
};