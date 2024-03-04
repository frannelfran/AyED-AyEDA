#include "lattice2D.h"

/**
 * @brief Constructor por defecto de la clase Lattice2D
 * @param fila Fila del retículo
 * @param columna Columna del retículo
 * @param type_cell Tipo de célula
*/

Lattice2D::Lattice2D(int fila, int columna, const string& type_cell) {
  assert (fila > 0 && columna > 0); // Comprobar que las filas y columnas son mayores que 0
  assert (type_cell == "Life23_3" || type_cell == "Life51_343");
  reticulo_.resize(fila);
  Cell* cell;
  for (int i = 0; i < fila; i++) {
    reticulo_[i].resize(columna);
    for (int j = 0; j < columna; j++) {
      if (type_cell == "Life23_3") {
        cell = new CellLife23_3(Position({i, j}), State(0));
      }
      else {
        cell = new CellLife51_346(Position({i, j}), State(0));
      }
      reticulo_[i][j] = cell;
    }
  }
  SetViva();
}

/**
 * @brief Constructor de la clase Lattice2D cuando se le introduce un fichero
 * @param filename Nombre del fichero
*/



/**
 * @brief Método para establecer que células están vivas
*/

void Lattice2D::SetViva() {
  int fila, columna, numero;
  cout << "¿Cuantas células vivas quieres ? ";
  cin >> numero;
  assert (numero >= 0); // Verificar que no se introduce un número negativo
  while (numero != 0) {
    cin >> fila >> columna;
    assert (fila >= 0 && columna >= 0 && fila < reticulo_.size() && columna < reticulo_[fila].size()); // Verificar que no se sale del rango de la cuadrícula
    reticulo_[fila][columna]->SetState(State(1)); // Cambio el estado de la célula
    numero--;
  }
}

/**
 * @brief Método para calcular la población de células vivas
 * @return Número de células vivas
*/

size_t Lattice2D::Population() const {
  size_t poblacion = 0;
  for (int i = 0; i < reticulo_.size(); i++) {
    for (int j = 0; j < reticulo_[i].size(); j++) {
      if (reticulo_[i][j]->GetState().GetData() == 1) {
        poblacion++;
      }
    }
  }
  return poblacion;
}

/**
 * @brief Método para calcular la siguiente generación
*/

void Lattice2D::NextGeneration() const {
  vector<int> vec_estados;
  for (int i = 1; i < reticulo_.size() - 1; i++) {
    for (int j = 1; j < reticulo_[i].size() - 1; j++) {
      vec_estados.push_back(reticulo_[i][j]->NextState(*this));
    }
  }
  ActualizarCelulas(vec_estados);
}

/**
 * @brief Método para actualizar los estados de las células
 * @param vec Vector con los estados de las células
*/

void Lattice2D::ActualizarCelulas(const vector<int>& vec) const {
  int k = 0;
  for (int i = 1; i < reticulo_.size() - 1; i++) {
    for (int j = 1; j < reticulo_[i].size() - 1; j++) {
      reticulo_[i][j]->SetState(State(vec[k]));
      k++;
    }
  }
}

/**
 * @brief Método para ajustar las posiciones de las células
*/

void Lattice2D::AjustarPosiciones() {
  for (int i = 0; i < reticulo_.size(); i++) {
    for (int j = 0; j < reticulo_[i].size(); j++) {
      reticulo_[i][j]->SetPosition(Position({i, j}));
    }
  }
}

/**
 * @brief Método para mostrar el retículo
*/

ostream& Lattice2D::Display(ostream& os) const {
  for (auto fila : reticulo_) {
    for (auto cell : fila) {
      os << *cell;
    }
    os << endl;
  }
  return os;
}