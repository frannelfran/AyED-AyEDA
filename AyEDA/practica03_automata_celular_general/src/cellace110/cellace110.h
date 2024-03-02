#pragma once
#include "../cellace/cellace.h"

using namespace std;

class CellAce110 : public CellAce {
  public:
   // Funciones
   int Rule(State&, State&) const override;
};