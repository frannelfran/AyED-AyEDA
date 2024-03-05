#pragma once
#include "../lattice.h"
#include "../../cell/cellLife/cellLife.h"
#include "../../factorycell/factorycell.h"

using namespace std;

class Lattice2D : public Lattice {
  public:
   inline Lattice2D() {}
   Lattice2D(int, int, const FactoryCell&); // Constructor por defecto
   Lattice2D(ifstream&, const FactoryCell&); // Constructor cuando se le pasa el nombre de un fichero

   // Getters
   inline const Cell& GetCell(const Position& pos) const override { return *reticulo_[pos.GetX()][pos.GetY()]; } // Obtener una célula

   // Setters
   void SetViva() override;

   // Funciones
   size_t Population() const override;
   void NextGeneration() const override; // Calcular la siguiente generación
   void ActualizarCelulas(const vector<int>&) const override; // Actulizar los estados de las células
   void AjustarPosiciones() const override; // Ajustar las posiciones de las células
   virtual void AgregarFrontera(const FactoryCell& factory) = 0;
   void SendToFile(ofstream&) override; // Método para enviar los datos del retñiculo a un fichero
   
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
   Lattice2D_Reflective(ifstream& filename, const FactoryCell& factory) : Lattice2D(filename, factory) {}
  
   // Funciones
   void AgregarFrontera(const FactoryCell&) override; // Agregar la frontera
};

class Lattice2D_Noborder : public Lattice2D {
  public:
   // Constructor de la clase
   Lattice2D_Noborder(int fila, int columna, const FactoryCell& factory) : Lattice2D(fila, columna, factory) {}
   Lattice2D_Noborder(ifstream& filename, const FactoryCell& factory) : Lattice2D(filename, factory) {}

   void AgregarFrontera(const FactoryCell&) override;
};