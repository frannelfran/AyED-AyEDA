#include "lattice1D.h"

/**
 * @brief Constructor de la clase Lattice1D
 * @param size Tamaño del retículo
 * @param type_cell Tipo de célula
*/

Lattice1D::Lattice1D(int size, const FactoryCell& factory) {
  assert (size > 0); // Comprobar que el tamaño sea mayor que 0
  reticulo_.resize(size);
  Cell* cell;
  for (int i = 0; i < size; i++) {
    Position pos({i});
    reticulo_[i] = factory.createCell(pos, State(0));
  }
  SetViva();
}

/**
 * @brief Constructor de la clase Lattice1D si se introduce un fichero
 * @param filename Nombre del fichero
 * @param type_cell Tipo de célula
*/

Lattice1D::Lattice1D(ifstream& file, const FactoryCell& factory) {
  int size;
  char caracter;
  file >> size;
  cout << size << endl;
  assert (size > 0); // Comprobar que el tamaño sea mayor que 0
  reticulo_.resize(size);
  file.get(caracter); // Saltarse el salto de línea
  for (int i = 0; i < size; i++) {
    file.get(caracter);
    State estado = (caracter == 'x') ? State(1) : State(0);
    Position pos({i});
    reticulo_[i] = factory.createCell(pos, State(estado));
  }
}

/**
 * @brief Método para establecer que células se vuelven vivas
*/

void Lattice1D::SetViva() {
  int numero, posicion;
  cout << "Cuántas células vivas quieres ? ";
  cin >> numero;
  assert (numero <= reticulo_.size()); // Comprobar que el número que se solicita no supere el número de células
  while (numero != 0) {
    cin >> posicion;
    assert (posicion >= 0 && posicion < reticulo_.size()); // Comprobar que la posición sea válida
    reticulo_[posicion]->SetState(State(1));
    numero--;
  }
}

/**
 * @brief Método para enviar los datos del retículo a un fichero
 * @param file Fichero
*/

void Lattice1D::SendToFile(ofstream& file) {
  file << reticulo_.size() << endl;
  for (auto& cell : reticulo_) {
    file << *cell;
  }
}

/**
 * @brief Método para calcular la población
 * @return Población
*/

size_t Lattice1D::Population() const {
  size_t poblacion = 0;
  for (auto& cell : reticulo_) {
    poblacion += cell->GetState().GetData();
  }
  return poblacion;
}

/**
 * @brief Sobrecarga del operador de salida
*/

ostream& Lattice1D::Display(ostream& os) const {
  for (auto& cell : reticulo_) {
    os << *cell;
  }
  os << endl;
  return os;
}

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

void Lattice1D_Open::AgregarFrontera(bool fria, const FactoryCell& factory) {
  Cell* cell_ini, *cell_fin;
  State cell_state = fria ? State(0) : State(1);
  cell_ini = factory.createCell(Position({0}), cell_state);
  cell_fin = factory.createCell(Position({0}), cell_state);
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