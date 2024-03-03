#pragma once
#include "cellace.h"

using namespace std;

class CellAce100 : public CellAce {
  public:
    // Constructor de la clase
    inline CellAce100(const Position& pos, const State& state) : CellAce(pos, state) {}
    // Funciones
    int Rule(const State& celula_l, const State& celula_r) override {
      int l = celula_l.GetData(), c = estado_.GetData(), r = celula_r.GetData();
      return (c + r + c + r + l * c * r) % 2;
    }
};