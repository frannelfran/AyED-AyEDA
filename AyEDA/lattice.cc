#include "lattice.h"

Lattice::Lattice() {}

/**
 * @brief Construir el retículo si se aporta un fichero
 * @param file Fichero con los estados
 * @param size Tamaño del retículo
*/

void Lattice::Build(ifstream& file, int size) {
  int posicion = 0;
  vector<Cell> vector_celulas; // Vector donde se van a almacenar las células
  while (!file.eof()) { // Recorrer hasta llegar al final del fichero
    int estado;
    file >> estado;
    Position pos(posicion);
    State sta(estado);
    Cell celula(pos, sta);
    vector_celulas.push_back(celula); // Pusheamos las células en el vector de células
    posicion++;
  }
  // Comprobar que el tamaño introducido coincida con el número de células del fichero
  assert(vector_celulas.size() == size);
  SetLattice(vector_celulas);
}

/**
 * @brief Asignar el retículo
 * @param vector_celulas Vector que contiene las células
*/

void Lattice::SetLattice(const vector<Cell>& vector_celulas) {
  this->lattice_ = vector_celulas;
}

/**
 * @brief Obtener la célula según su posición
 * @param posicion Posición de la célula a buscar
 * @return Objeto Cell
*/

const Cell& Lattice::GetCell(const Position& posicion) const {
  return lattice_.at(posicion.GetData());
}

/**
 * @brief Establecer la frontera del retículo
 * @param frontera Tipo de frontera
 * @param fria Saber si la frontera es fría o caliente
*/

void Lattice::SetFrontera(const string& frontera, bool fria) {
  assert (frontera == "open" || frontera == "periodic"); // Aseguramos los tipos de frontera
  if (frontera == "open") {
    const State estado_frontera = fria ? State(0) : State(1);
    // Insertamos las células en la parte izquierda
    lattice_.insert(lattice_.begin(), Cell(Position(0), estado_frontera));
    lattice_.push_back(Cell(Position(lattice_.size() - 1), estado_frontera));
    // Ajustamos las posiciones de cada célula
    for (int it = 0; it < lattice_.size(); it++) {
      lattice_[it].SetPosicion(Position(it));
    }
  }
  this->frontera_ = frontera; // Establecer el tipo de frontera
}

/**
 * @brief Hacer la configuración inicial del retículo
 * @param size Número de células del retículo
*/

void Lattice::Initial(int size) {
  int posicion_par = size / 2;
  for (int it = 0; it < size; it++) {
    bool estado = false;
    if (it == posicion_par) {
      estado = true;
    }
    Position pos(it);
    State sta(estado);
    Cell cell(pos, sta);
    lattice_.push_back(cell);
  }
}

void Lattice::NextGeneration() {
  // Primera parte
  Cell celula_c, celula_l, celula_r;
}

/**
 * @overload Sobrecarga del operador <<
*/

ostream& operator<<(ostream& os, const Lattice& latt) {
  for (auto it = latt.lattice_.begin(); it != latt.lattice_.end(); it++) {
    os << *it;
  }
  cout << endl;
  return os;
}