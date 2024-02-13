#pragma once
#include <iostream>
#include "position.h"
#include "state.h"
#include "lattice.h"

using namespace std;


class Cell {
  public:
   // Constructores de la clase
   Cell();
   Cell(const Position&, const State&);

   // Getters
   State GetState() const;

   // Setters
   void SetState(State);

   // Funciones
   int NextState(const Lattice&);

  private:
   Position posicion_;
   State estado_;
};