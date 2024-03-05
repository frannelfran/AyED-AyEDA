#pragma once
#include "../lattice.h"
#include "../../cell/cellLife/cellLife.h"
#include "../../factorycell/factorycell.h"

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

// Herencia de la clase Lattice2D

class Lattice2D_Reflective : public Lattice2D {
  public:
   // Constructor de la clase
   Lattice2D_Reflective(int fila, int columna, const FactoryCell& factory) : Lattice2D(fila, columna, factory) {}
   Lattice2D_Reflective(const string& filename, const string& type_cell) : Lattice2D(filename, type_cell) {}
  
   // Funciones
   void AgregarFrontera(const optional<Options>&) override; // Agregar la frontera
   Cell* FabricarNuevaCelda(Cell*) override; // Fabricar una nueva célula
};
