#pragma once
#include "lattice/lattice.h"
#include "cellace/cellace.h"
#include <cassert>

using namespace std;

class Lattice1D : public Lattice {
  public:
   inline Lattice1D() {}
   Lattice1D(int); // Constructor por defecto
   Lattice1D(const string&); // Constructor cuando se le pasa el nombre de un fichero

   // Getters
   inline const Cell& GetCell(const Position& pos) const override { return *reticulo_.at(pos.GetX()); }
   
   // Setters
   void SetFrontera(const optional<Options>&) override;
   void SetViva() override;
   void SetReticulo(const optional<Options>&) const override {}

   // Funciones
   void NextGeneration() const override {}
   void AjustarPosiciones() const override {}
   void AgregarFrontera() const override {}
   void ActualizarCelulas(const vector<int>&) const override {}
   void Build(const optional<Options>&) override;
   size_t Population() const override {}

   // Sobrecarga de operadores
   ostream& Display(ostream& os) const override;

  private:
   vector<Cell*> reticulo_;
};