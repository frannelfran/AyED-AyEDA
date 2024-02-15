#pragma once
#include <iostream>
#include <vector>
#include "cell.h"
class Cell;

using namespace std;

class Lattice {
  public:
   Lattice();
   Lattice(const vector<Cell>&); // Constructor de la clase

   // Getters
   const Cell& GetCell(const Position&) const; // Obtener la célula según su posición

   // Setters
   void SetLattice(const vector<Cell>&); // Establecer el retículo

   // Funciones
   void NextGeneration();
   void Initial(int);

   // Sobrecarga de operadores
   friend ostream& operator<<(ostream& os, const Lattice& latt);

  private:
   vector<Cell> lattice_; // Conjunto de células
};