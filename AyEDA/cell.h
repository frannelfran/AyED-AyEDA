#include <iostream>
#include "lattice.h"
#include "state.h"
#include "position.h"

using namespace std;

class Cell {
  public:
  Cell(State&, Position&); // Constructor de la clase estado

  // Funciones de la clase
  int NextState(const Lattice&); // Devolver el siguiente estado
  void UpdateState(); // Actualizar el estado de la célula

  // Setters
  void SetState(State);

  friend ostream& operator<<(ostream& os, const Cell& cell);
  
  private:
   State estado_celula;
   Position posicion_;
};