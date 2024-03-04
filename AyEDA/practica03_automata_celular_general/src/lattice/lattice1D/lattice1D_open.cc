#include "lattice1D_open.h"

/**
 * @brief Calcular la siguiente generación
*/

void Lattice1D_Open::NextGeneration() const {
  vector<int> nuevos_estados;
  for (int i = 1; i < reticulo_.size() - 1; i++) {
    Cell* celula = reticulo_[i];
    int new_state = celula->NextState(*this);
    nuevos_estados.push_back(new_state);
  }
  ActualizarCelulas(nuevos_estados);
}

/**
 * @brief Actualizar los estados de las células
 * @param nuevos_estados Nuevos estados de las células
*/

void Lattice1D_Open::ActualizarCelulas(const vector<int>& nuevos_estados) const {
  int j = 0;
  for (int i = 1; i < reticulo_.size() - 1; i++, j++) {
    reticulo_[i]->SetState(State(nuevos_estados[j]));
  }
}

/**
 * @brief Método para agregar la frontera
 * @param opciones Opciones del usuario
*/

void Lattice1D_Open::AgregarFrontera(const optional<Options>& opciones) {
  assert (opciones->cell_type == "Ace110" || opciones->cell_type == "Ace30"); // Comprobar que el tipo de célula sea válido
  Cell* cell_ini, *cell_fin;
  State cell_state = opciones->fria ? State(0) : State(1);
  if (opciones->cell_type == "Ace110") {
    cell_ini = new CellAce110(Position({0}), State(cell_state));
    cell_fin = new CellAce110(Position({0}), State(cell_state));
  }
  else if (opciones->cell_type == "Ace30") {
    cell_ini = new CellAce30(Position({0}), State(cell_state));
    cell_fin = new CellAce30(Position({0}), State(cell_state));
  }
  reticulo_.insert(reticulo_.begin(), cell_ini);
  reticulo_.push_back(cell_fin);

  AjustarPosiciones(); // Ajustar las posiciones
}

/**
 * @brief Ajustar posiciones del retículo
*/

void Lattice1D_Open::AjustarPosiciones() {
  for (int i = 0; i < reticulo_.size(); i++) {
    reticulo_[i]->SetPosition(Position({i}));
  }
}