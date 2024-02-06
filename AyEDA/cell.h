#include <iostream>
#include "lattice.h"
#include "state.h"

using namespace std;

class Cell {
  public:
  Cell(State&); // Constructor de la clase estado

  // Funciones de la clase
  int NextState(const Lattice&); // Devolver el siguiente estado
  void UpdateState(); // Actualizar el estado de la célula

  // Setters
  void SetState(State);

  friend ostream& operator<<(ostream& os, const Cell& cell);
  
  private:
  State estado_celula;
};