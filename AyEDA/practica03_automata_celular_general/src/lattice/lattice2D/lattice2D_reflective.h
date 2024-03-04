#pragma once
#include "lattice2D.h"

using namespace std;

class Lattice2D_Reflective : public Lattice2D {
  public:
   // Constructor de la clase
   Lattice2D_Reflective(int fila, int columna, const string& type_cell) : Lattice2D(fila, columna, type_cell) {}
   Lattice2D_Reflective(const string& filename, const string& type_cell) : Lattice2D(filename, type_cell) {}
  
   // Funciones
   void AgregarFrontera(const optional<Options>&) override; // Agregar la frontera
   Cell* FabricarNuevaCelda(Cell*) override; // Fabricar una nueva célula
};