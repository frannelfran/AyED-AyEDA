#include "lattice2D.h"

/**
 * @brief Constructor por defecto de la clase Lattice2D
 * @param fila Fila del retículo
 * @param columna Columna del retículo
 * @param factory Fábrica de células
*/

Lattice2D::Lattice2D(int fila, int columna, const FactoryCell& factory) {
  assert (fila > 0 && columna > 0); // Comprobar que las filas y columnas son mayores que 0
  reticulo_.resize(fila);
  for (int i = 0; i < fila; i++) {
    reticulo_[i].resize(columna);
    for (int j = 0; j < columna; j++) {
      reticulo_[i][j] = factory.createCell(Position({i, j}), State(0));
    }
  }
  SetViva();
}

/**
 * @brief Constructor de la clase Lattice2D cuando se le introduce un fichero
 * @param filename Nombre del fichero
*/

Lattice2D::Lattice2D(ifstream& file, const FactoryCell& factory) {
  int fila, columna;
  char caracter;
  file >> fila >> columna;
  assert (fila > 0 && columna > 0); // Comprobar que las filas y columnas son mayores que 0
  reticulo_.resize(fila);
  file.get(caracter); // Saltarse el salto de línea
  for (int i = 0; i < fila; i++) {
    reticulo_[i].resize(columna);
    for (int j = 0; j < reticulo_[i].size(); j++) {
      file.get(caracter); // Leer el caracter
      State estado = (caracter == 'x') ? State(1) : State(0);
      reticulo_[i][j] = factory.createCell(Position({i, j}), estado);
    }
    file.get(caracter); // Saltarse el salto de línea
  }
}

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
 * @brief Método para enviar los datos del retículo a un fichero
 * @param file Fichero
*/

void Lattice2D::SendToFile(ofstream& file) {
  file << reticulo_.size() << " " << reticulo_[0].size() << endl;
  for (auto fila : reticulo_) {
    for (auto cell : fila) {
      file << *cell;
    }
    file << endl;
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

void Lattice2D_Reflective::AgregarFrontera(const FactoryCell& factory) {
  // Copiar el estado de las células en los bordes a las células adicionales
  Cell* cell;
  // Insertar nuevas células en el borde izquierdo y derecho
  for (int i = 0; i < reticulo_.size(); i++) {
    // Crear nuevas células para el borde izquierdo
    Cell* nueva_celula_izquierda = factory.createCell(Position({0, 0}), reticulo_[i][0]->GetState());
    reticulo_[i].insert(reticulo_[i].begin(), nueva_celula_izquierda);

    // Crear nuevas células para el borde derecho
    Cell* nueva_celula_derecha = factory.createCell(Position({0, 0}), reticulo_[i].back()->GetState());
    reticulo_[i].push_back(nueva_celula_derecha);
  }

  // Insertar nuevas células en el borde superior e inferior
  // Crear nuevas celdas para el borde superior
  vector<Cell*> nueva_fila_superior;
  for (int j = 0; j < reticulo_[0].size(); j++) {
    Cell* nueva_celula = factory.createCell(Position({0, 0}), reticulo_[0][j]->GetState());
    nueva_fila_superior.push_back(nueva_celula);
  }
  reticulo_.insert(reticulo_.begin(), nueva_fila_superior);

  // Crear nuevas celdas para el borde inferior
  vector<Cell*> nueva_fila_inferior;
  for (int j = 0; j < reticulo_[0].size(); j++) {
    Cell* nueva_celula = factory.createCell(Position({0, 0}), reticulo_.back()[j]->GetState());
    nueva_fila_inferior.push_back(nueva_celula);
  }
  reticulo_.push_back(nueva_fila_inferior);
  AjustarPosiciones();
}