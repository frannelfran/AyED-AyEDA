#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include "cell.h"
#include "options.h"
class Cell;

using namespace std;

class Lattice {
  public:
   inline Lattice() {}
   Lattice(int N, int M); // Constructor por defecto
   Lattice(const string&); // Constructor si se le pasa un fichero

   // Getters
   inline const string& GetFrontera() const { return this->frontera_; } // Obtener la frontera
   inline const int GetSize() const { return this->lattice_.size(); } // Obtener el número de células del retículo

   // Setters
   void SetFrontera(const string&, bool);
   void SetReticulo(const optional<Options>&); // Verificar si se ha introucido un fichero para configurar el retículo
   void SetViva(); // Método para pedir al usuario una posición para que la célula de la misma se vuelva viva

   // Funciones
   void NextGeneration(); // Calcular la siguiente generación
   size_t Population(); // Número de células vivas

   // Sobrecarga de operadores
   friend ostream& operator<<(ostream& os, const Lattice& latt);

  private:
   vector<vector<Cell>> lattice_; // Conjunto de células
   string frontera_; // Tipo de frontera
};