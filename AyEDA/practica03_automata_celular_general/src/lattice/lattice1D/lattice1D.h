#pragma once
#include "../lattice.h"
#include "../../cell/cellace/cellace.h"
#include "../../factorycell/factorycell.h"
#include <cassert>
#include <fstream>

using namespace std;

class Lattice1D : public Lattice {
  public:
   inline Lattice1D() {}
   Lattice1D(int, const FactoryCell&); // Constructor por defecto
   Lattice1D(ifstream&, const FactoryCell&); // Constructor cuando se le pasa el nombre de un fichero

   // Setters
   void SetViva() override;

   // Funciones
   size_t Population() const override;

   // Sobrecarga de operadores
   ostream& Display(ostream& os) const override;
   virtual void AgregarFrontera(bool, const FactoryCell&) = 0;

  protected:
   vector<Cell*> reticulo_;
};

// Herencia de la clase Lattice1D

class Lattice1D_Periodic : public Lattice1D {
  public:
   // Constructor de la clase
   Lattice1D_Periodic(int size, const FactoryCell& factory) : Lattice1D(size, factory) {}
   Lattice1D_Periodic(ifstream& file, const FactoryCell& factory) : Lattice1D(file, factory) {}
  
   // Funciones
   void NextGeneration() const override; // Calcular la siguiente generación
   void ActualizarCelulas(const vector<int>&) const override; // Actulizar los estados de las células
   void AgregarFrontera(bool, const FactoryCell&) override {} // Agregar la frontera
   void AjustarPosiciones() override {}
   inline const Cell& GetCell(const Position& pos) const override; // Obtener una célula
};

class Lattice1D_Open : public Lattice1D {
  public:
   // Constructor de la clase
   Lattice1D_Open(int size, const FactoryCell& factory) : Lattice1D(size, factory) {}
   Lattice1D_Open(ifstream& file, const FactoryCell& factory) : Lattice1D(file, factory) {}

   // Funciones
   void NextGeneration() const override; // Calcular la siguiente generación
   void ActualizarCelulas(const vector<int>&) const override; // Actulizar los estados de las células
   void AjustarPosiciones() override; // Ajustar las posiciones de las células
   void AgregarFrontera(bool, const FactoryCell&) override; // Agregar la frontera
   inline const Cell& GetCell(const Position& pos) const override { return *reticulo_.at(pos.GetX()); } // Obtener una célula
};