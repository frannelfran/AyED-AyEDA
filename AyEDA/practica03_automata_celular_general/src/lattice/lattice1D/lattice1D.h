#pragma once
#include "lattice/lattice.h"
#include "cellace/cellace.h"
#include "cellace/cellace110.h"
#include "cellace/cellace30.h"
#include <cassert>

using namespace std;

class Lattice1D : public Lattice {
  public:
   inline Lattice1D() {}
   Lattice1D(int, const string&); // Constructor por defecto
   Lattice1D(const string&, const string&); // Constructor cuando se le pasa el nombre de un fichero

   // Setters
   void SetViva() override;

   // Funciones
   size_t Population() const override;

   // Sobrecarga de operadores
   ostream& Display(ostream& os) const override;

  protected:
   vector<Cell*> reticulo_;
};