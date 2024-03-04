#include "lattice2D_reflective.h"

void Lattice2D_Reflective::AgregarFrontera(const optional<Options>& opciones) {
  // Copiar el estado de las células en los bordes a las células adicionales
  // para simular la frontera reflectiva
  for (int i = 0; i < reticulo_.size(); i++) {
    reticulo_[i].insert(reticulo_[i].begin(), reticulo_[i][0]); // Copiar la primera columna al principio
    reticulo_[i].push_back(reticulo_[i].back()); // Copiar la última columna al final
  }
  // Insertar una fila extra al principio y al final de la cuadrícula
  reticulo_.insert(reticulo_.begin(), reticulo_.front()); // Copiar la primera fila al principio
  reticulo_.push_back(reticulo_.back()); // Copiar la última fila al final
  AjustarPosiciones();
}