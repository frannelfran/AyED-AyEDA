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
   inline State GetState() const { return this->estado_; } // Obtener el estado de la célula
   inline Position GetPosition() const { return this->posicion_; } // Obtener la posición de la célula

   // Setters
   inline void SetState(State estado) { estado_.SetData(estado.GetData()); } // Settear el estado
   inline void SetPosicion(Position posicion) { posicion_.SetData(posicion.GetData()); } // Settear la posición

   // Funciones
   int NextState(const Lattice&);
   int CalcularEstado(const State&, const State&); // Aplicar la fórmula para calcular el estado siguiente

   // Sobrecarga de operadores
   friend ostream& operator<<(ostream& os, const Cell& cell);

  private:
   Position posicion_;
   State estado_;
};