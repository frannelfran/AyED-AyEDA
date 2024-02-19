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
  assert (vector_celulas.size() == size);
  SetLattice(vector_celulas);
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
    // Insertamos la células en la parte izquierda
    lattice_.insert(lattice_.begin(), Cell(Position(0), estado_frontera));
    // Insertamos la célula en la parte derecha
    lattice_.push_back(Cell(Position(lattice_.size() - 1), estado_frontera));
  }
  this->frontera_ = frontera; // Establecer el tipo de frontera
}

/**
 * @brief Hacer la configuración inicial del retículo
 * @param size Número de células del retículo
*/

void Lattice::Initial(int size) {
  assert (size > 0); // Comprobamos que el tamaño no sea negativo
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
  vector<int> nuevos_estados;
  // Calcular la siguiente generación cuando la frontera es abierta
  if (frontera_ == "open") {
    // Primera parte
    for (auto it = lattice_.begin() + 1; it != lattice_.end() - 1; it++) {
      Cell& celula =  *it;
      int nuevo_estado = celula.NextState(*this);
      nuevos_estados.push_back(nuevo_estado);
    }
    // Segunda parte
    int i = 0;
    for (auto it = lattice_.begin() + 1; it != lattice_.end() -1; it++, i++) {
      Cell& celula = *it;
      State estado = celula.GetState();
      estado.SetData(nuevos_estados[i]);
      celula.SetState(estado);
    }
  }

  // Calcular cuando la frontera es periódica
  else if (frontera_ == "periodic") {
    // Primera parte
    for (auto it = lattice_.begin(); it != lattice_.end(); it++) {
      Cell& celula = *it;
      int nuevo_estado = celula.NextState(*this);
      nuevos_estados.push_back(nuevo_estado);
    }
    // Segunda parte
    int i = 0;
    for (auto it = lattice_.begin(); it != lattice_.end(); it++, i++) {
      Cell& celula = *it;
      State estado = celula.GetState();
      estado.SetData(nuevos_estados[i]);
      celula.SetState(estado);
    }
  }
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