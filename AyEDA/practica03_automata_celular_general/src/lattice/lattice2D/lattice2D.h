#pragma once
#include "lattice/lattice.h"
#include "cellLife/cellLife.h"
#include "cellLife/cellLife23_3.h"
#include "cellLife/cellLife51_346.h"
#include "factorycell/factorycell.h"

using namespace std;

class Lattice2D : public Lattice {
  public:
   inline Lattice2D() {}
   Lattice2D(int, int, const FactoryCell&); // Constructor por defecto
   Lattice2D(const string&, const string&); // Constructor cuando se le pasa el nombre de un fichero

   // Getters
   inline const Cell& GetCell(const Position& pos) const override { return *reticulo_[pos.GetX()][pos.GetY()]; } // Obtener una célula

   // Setters
   void SetViva() override;

   // Funciones
   size_t Population() const override;
   void NextGeneration() const override; // Calcular la siguiente generación
   void ActualizarCelulas(const vector<int>&) const override; // Actulizar los estados de las células
   void AjustarPosiciones() override; // Ajustar las posiciones de las células
   virtual Cell* FabricarNuevaCelda(Cell*) = 0;
   
   // Sobrecarga de operadores
   ostream& Display(ostream& os) const override;

  protected:
   vector<vector<Cell*>> reticulo_;
};
