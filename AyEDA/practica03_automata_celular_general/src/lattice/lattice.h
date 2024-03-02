#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include "../cell/cell.h"
#include "../options/options.h"
class Cell;

using namespace std;

class Lattice {
  public:
   // Getters
   inline const string& GetFrontera() const { return this->frontera_; } // Obtener la frontera
   virtual const Cell& GetCell(const Position& pos) const = 0; // Obtener la célula según su posición

   // Setters
   virtual void SetFrontera(const string&) const = 0;
   virtual void SetReticulo(const optional<Options>&) const = 0; // Establecer la configuración según los parámetros establecidos
   virtual void SetViva() const = 0; // Método para pedir al usuario una posición para que la célula de la misma se vuelva viva

   // Funciones
   virtual void NextGeneration() const = 0; // Calcular la siguiente generación
   virtual void AjustarPosiciones() const = 0; // Ajustar las posiciones del retículo
   virtual void ActualizarCelulas(const vector<int>&) const = 0; // Actulizar los estados de las células
   virtual void AgregarFrontera() const = 0; // Agregar frontera
   virtual size_t Population() const = 0; // Número de células vivas

   // Sobrecarga de operadores
   friend ostream& operator<<(ostream& os, const Lattice& latt);

  protected:
   string frontera_;
   virtual ostream& Display(ostream&) const = 0;
};