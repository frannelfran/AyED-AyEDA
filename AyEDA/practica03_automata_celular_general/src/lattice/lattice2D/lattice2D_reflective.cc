#include "lattice2D_reflective.h"

void Lattice2D_Reflective::AgregarFrontera(const optional<Options>& opciones) {
  // Copiar el estado de las células en los bordes a las células adicionales
  Cell* cell;
  // Insertar nuevas células en el borde izquierdo y derecho
  for (int i = 0; i < reticulo_.size(); i++) {
    // Crear nuevas células para el borde izquierdo
    Cell* nueva_celula_izquierda = FabricarNuevaCelda(reticulo_[i][0]);
    reticulo_[i].insert(reticulo_[i].begin(), nueva_celula_izquierda);

    // Crear nuevas células para el borde derecho
    Cell* nueva_celula_derecha = FabricarNuevaCelda(reticulo_[i].back());
    reticulo_[i].push_back(nueva_celula_derecha);
  }

  // Insertar nuevas células en el borde superior e inferior
  // Crear nuevas celdas para el borde superior
  vector<Cell*> nueva_fila_superior;
  for (int j = 0; j < reticulo_[0].size(); j++) {
    Cell* nueva_celula = FabricarNuevaCelda(reticulo_[0][j]);
    nueva_fila_superior.push_back(nueva_celula);
  }
  reticulo_.insert(reticulo_.begin(), nueva_fila_superior);

  // Crear nuevas celdas para el borde inferior
  vector<Cell*> nueva_fila_inferior;
  for (int j = 0; j < reticulo_[0].size(); j++) {
    Cell* nueva_celula = FabricarNuevaCelda(reticulo_.back()[j]);
    nueva_fila_inferior.push_back(nueva_celula);
  }
  reticulo_.push_back(nueva_fila_inferior);
  AjustarPosiciones();
}

Cell* Lattice2D_Reflective::FabricarNuevaCelda(Cell* original) {
  if (dynamic_cast<CellLife23_3*>(original)) {
    return new CellLife23_3(original->GetPosition(), original->GetState());
  }
  else if (dynamic_cast<CellLife51_346*>(original)) {
    return new CellLife51_346(original->GetPosition(), original->GetState());
  }
  else {
    return nullptr;
  }
}