#include "lattice1D_periodic.h"

/**
 * @brief Método para calcular la siguiente generación
*/

void Lattice1D_Periodic::NextGeneration() const {
  vector<int> nuevos_estados;
  for (int i = 0; i < reticulo_.size(); i++) {
    Cell& cell = *reticulo_[i];
    int nuevo_estado = cell.NextState(*this);
    nuevos_estados.push_back(nuevo_estado);
  }
  ActualizarCelulas(nuevos_estados);
}

/**
 * @brief Método para actualizar los estados de las células
 * @param nuevos_estados Vector con los nuevos estados de las células
*/

void Lattice1D_Periodic::ActualizarCelulas(const vector<int>& nuevos_estados) const {
  for (int i = 0; i < reticulo_.size(); i++) {
    reticulo_[i]->SetState(nuevos_estados[i]);
  }
}

/**
 * @brief Método para obetener una célula
 * @param pos Posición de la célula
 * @return Célula
*/

const Cell& Lattice1D_Periodic::GetCell(const Position& pos) const {
  if (pos.GetX() < 0) {
    return *reticulo_.at(reticulo_.size() - 1);
  }
  else if (pos.GetX() >= reticulo_.size()) {
    return *reticulo_.at(0);
  }
  else {
    return *reticulo_.at(pos.GetX());
  }
}