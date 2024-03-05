#pragma once
#include "../cell.h"

using namespace std;

class CellAce : public Cell {
  public:
   // Constructor de la clase
   inline CellAce(const Position& pos, const State& state) : Cell(pos, state) {}

   // Funciones
   int NextState(const Lattice&) override;
   virtual int Rule(const State&, const State&) = 0;
   
   ostream& Display(ostream& os) const override;
};

// Herencia de la clase CellAce

class CellAce30 : public CellAce {
  public:
   // Constructor de la clase
   inline CellAce30(const Position& pos, const State& state) : CellAce(pos, state) {}

   // Funciones
   int Rule(const State& celula_l, const State& celula_r) override;
};

class CellAce110 : public CellAce {
  public:
   // Constructor de la clase
   inline CellAce110(const Position& pos, const State& state) : CellAce(pos, state) {}
   
   // Funciones
   int Rule(const State& celula_l, const State& celula_r) override;
};