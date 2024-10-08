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
   inline Lattice() {}
   inline virtual ~Lattice() {}
   // Getters
   virtual const Cell& GetCell(const Position& pos) const = 0; // Obtener la célula según su posición

   virtual void SetViva() = 0; // Método para pedir al usuario una posición para que la célula de la misma se vuelva viva

   // Funciones
   virtual void NextGeneration() const = 0; // Calcular la siguiente generación
   virtual void AjustarPosiciones() const = 0; // Ajustar las posiciones del retículo
   virtual void ActualizarCelulas(const vector<int>&) const = 0; // Actulizar los estados de las células
   virtual size_t Population() const = 0; // Número de células vivas
   virtual void SendToFile(ofstream&) = 0; // Método para enviar los datos del retñiculo a un fichero

   // Sobrecarga de operadores
   inline friend ostream& operator<<(ostream& os, const Lattice& latt) { return latt.Display(os); }

  protected:
   virtual ostream& Display(ostream& os) const = 0;
};