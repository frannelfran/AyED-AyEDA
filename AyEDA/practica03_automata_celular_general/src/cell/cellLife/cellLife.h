#pragma once 
#include "../cell.h"

using namespace std;

class CellLife : public Cell {
  public:
   // Constructor de la clase
   inline CellLife(const Position& pos, const State& state) : Cell(pos, state) {}

   // Funciones
   int NextState(const Lattice&) override;
   virtual int Rule(int) = 0;
    
   ostream& Display(ostream& os) const override;
};

// Herencia de la clase CellLife

class CellLife23_3 : public CellLife {
  public:
   // Constructor de la clase
   inline CellLife23_3(const Position& pos, const State& state) : CellLife(pos, state) {}

   // Funciones
   int Rule(int) override;
};

class CellLife51_346 : public CellLife {
  public:
   // Constructor de la clase
   inline CellLife51_346(const Position& pos, const State& state) : CellLife(pos, state) {}

   // Funciones
   int Rule(int) override;
};