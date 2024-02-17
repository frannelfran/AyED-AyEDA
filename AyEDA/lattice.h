#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include "cell.h"
class Cell;

using namespace std;

class Lattice {
  public:
   Lattice();

   // Getters
   const Cell& GetCell(const Position&) const; // Obtener la célula según su posición
   inline const string& GetFrontera() const { return this->frontera_; }
   inline const int GetSize() const { return this->lattice_.size(); }

   // Setters
   void SetLattice(const vector<Cell>&); // Establecer el retículo
   void SetFrontera(const string&, bool);

   // Funciones
   void NextGeneration(); // Calcular la siguiente generación
   void Initial(int); // Configuración inicial
   void Build(ifstream&, int); // Crear el retículo con los datos del fichero

   // Sobrecarga de operadores
   friend ostream& operator<<(ostream& os, const Lattice& latt);

  private:
   vector<Cell> lattice_; // Conjunto de células
   string frontera_; // Tipo de frontera
};