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
   inline const Cell& GetCell(const Position& pos) const { return lattice_[pos.GetDataM()][pos.GetDataN()]; } // Obtener la célula según su posición

   // Setters
   void SetFrontera(const string&);
   void SetReticulo(const optional<Options>&); // Establecer la configuración según los parámetros establecidos
   void SetViva(); // Método para pedir al usuario una posición para que la célula de la misma se vuelva viva

   // Funciones
   void NextGeneration(); // Calcular la siguiente generación
   void AjustarPosiciones(); // Ajustar las posiciones del retículo
   void ActualizarCelulas(const vector<int>&); // Actulizar los estados de las células
   void AgregarFrontera(); // Agregar frontera
   size_t Population(); // Número de células vivas

   // Sobrecarga de operadores
   friend ostream& operator<<(ostream& os, const Lattice& latt);

  private:
   vector<vector<Cell>> lattice_; // Conjunto de células
   string frontera_; // Tipo de frontera
};