#pragma once
#include <iostream>
#include "../position/position.h"
#include "../state/state.h"
#include "../lattice/lattice.h"
class Lattice;

using namespace std;

class Cell {
  public:
   // Constructores de la clase
   inline Cell() {}
   inline Cell(const Position& posicion, const State& estado) : posicion_(posicion), estado_(estado) {}

   // Getters
   inline State GetState() const { return this->estado_; } // Obtener el estado de la célula
   inline Position GetPosition() const { return this->posicion_; } // Obtener la posición de la célula

   // Setters
   inline void SetState(State estado) { estado_.SetData(estado.GetData()); } // Settear el estado
   inline void SetPosition(Position posicion) { posicion_.SetX(posicion_.GetX()), posicion_.SetY(posicion_.GetY()); } // Settear la posición
   
   // Funciones
   virtual int NextState(const Lattice&) = 0;

   // Sobrecarga de operadores
   inline friend ostream& operator<<(ostream& os, const Cell& cell) { return cell.Display(os); }

  protected:
   virtual ostream& Display(ostream& os) const = 0;
   Position posicion_;
   State estado_;
};