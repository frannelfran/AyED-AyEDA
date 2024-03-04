#pragma once
#include "lattice1D.h"

using namespace std;

class Lattice1D_Open : public Lattice1D {
  public:
   // Constructor de la clase
   Lattice1D_Open(int size, const string& type_cell) : Lattice1D(size, type_cell) {}
   Lattice1D_Open(const string& filename, const string& type_cell) : Lattice1D(filename, type_cell) {}

   // Funciones
   void NextGeneration() const override; // Calcular la siguiente generación
   void ActualizarCelulas(const vector<int>&) const override; // Actulizar los estados de las células
   void AjustarPosiciones() override; // Ajustar las posiciones de las células
   void AgregarFrontera(const optional<Options>&) override; // Agregar la frontera
   inline const Cell& GetCell(const Position& pos) const override { return *reticulo_.at(pos.GetX()); } // Obtener una célula
};