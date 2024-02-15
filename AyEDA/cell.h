#pragma once
#include <iostream>
#include "position.h"
#include "state.h"
#include "lattice.h"
class Lattice;

using namespace std;


class Cell {
  public:
   // Constructores de la clase
   Cell();
   Cell(const Position&, const State&);

   // Getters
   State GetState() const;
   Position GetPosition() const;

   // Setters
   void SetState(State);

   // Funciones
   int NextState(const Lattice&);

   // Sobrecarga de operadores
   friend ostream& operator<<(ostream& os, const Cell& cell);

  private:
   Position posicion_;
   State estado_;
};