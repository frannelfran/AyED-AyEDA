#include "lattice1D.h"

/**
 * @brief Constructor de la clase Lattice1D
 * @param size Tamaño del retículo
 * @param type_cell Tipo de célula
*/

Lattice1D::Lattice1D(int size, const string& type_cell) {
  assert (size > 0); // Comprobar que el tamaño sea mayor que 0
  reticulo_.resize(size);
  Cell* cell;
  for (int i = 0; i < size; i++) {
    Position pos({i});
    if (type_cell == "Ace100") {
      cell = new CellAce100(pos, State(0));
    }
    else {
      cell = new CellAce30(pos, State(0));
    }
    reticulo_[i] = cell;
  }
  SetViva();
}

/**
 * @brief Constructor de la clase Lattice1D si se introduce un fichero
 * @param filename Nombre del fichero
 * @param type_cell Tipo de célula
*/

Lattice1D::Lattice1D(const string& filename, const string& type_cell) {
  assert (type_cell == "Ace100" || type_cell == "Ace30"); // Comprobar que el tipo de célula sea válido
  ifstream file(filename);
  int size, dim;
  char caracter;
  Cell* cell;
  file >> dim >> size; // Leo la dimensión que ya la había leído y el tamaño del retículo
  assert (size > 0 && dim == 1); // comprobamos que el tamaño sea mayor que 0
  reticulo_.resize(size); // Ajusto las posiciones del retículo
  file.ignore(numeric_limits<streamsize>::max(), '\n'); // Ingnorar el salto de línea después de leer el tamaño
  for (int i = 0; i < size; i++) {
    file.get(caracter);
    State estado = (caracter == 'x') ? State(1) : State(0);
    if (type_cell == "Ace100") {
      cell = new CellAce100(Position({i}), estado);
    }
    else {
      cell = new CellAce30(Position({i}), estado);
    }
    reticulo_[i] = cell;
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
 * @brief Método para construir el retículo
 * @param opciones Opciones para construir el retículo
*/

void Lattice1D::Build(const optional<Options>& opciones) {
  // Establecer el retículo
  if (!opciones.value().has_file) {
    *this = Lattice1D(opciones.value().size, opciones.value().cell_type);
  }
  else {
    *this = Lattice1D(opciones.value().filename, opciones.value().cell_type);
  }
  SetFrontera(opciones);
}


/**
 * @brief Método para establecer la frontera
 * @param type Tipo de frontera
*/

void Lattice1D::SetFrontera(const optional<Options>& opciones) {
  assert (opciones->type_border == "periodic" || opciones->type_border == "open");
  this->frontera_ = opciones->type_border;
  if (frontera_ == "open") {
    State estado = (opciones->fria) ? State(0) : State(1);
    Cell* cell_first, *cell_last;
    assert (opciones->cell_type == "Ace100" || opciones->cell_type == "Ace30"); // Comprobar que el tipo de célula sea válido
    if (opciones->cell_type == "Ace100") {
      cell_first = new CellAce100(Position({0}), estado);
      cell_last = new CellAce100(Position({static_cast<int>(reticulo_.size() + 1)}), estado);

    }
    else {
      cell_first = new CellAce30(Position({0}), estado);
      cell_last = new CellAce30(Position({static_cast<int>(reticulo_.size() + 1)}), estado);
    }
    // Introducir en el retículo
    reticulo_.insert(reticulo_.begin(), cell_first);
    reticulo_.push_back(cell_last);
  }
  AjustarPosiciones();
}

/**
 * @brief Ajustar las posiciones del retículo
*/

void Lattice1D::AjustarPosiciones() {
  for (int i = 0; i < reticulo_.size(); i++) {
    reticulo_[i]->SetPosition(Position({i}));
  }
}

/**
 * @brief Calcular cuántas células vivas hay en el retículo
 * @return Número de células vivas
*/

size_t Lattice1D::Population() const {
  size_t population = 0;
  for (auto& cell : reticulo_) {
    if (cell->GetState().GetData() == 1) {
      population++;
    }
  }
  return population;
}

/**
 * @brief Calcular la siguiente generación
*/

void Lattice1D::NextGeneration() const {
  vector<int> nuevos_estados;
  if (frontera_ == "open") {
    for (int i = 1; i < reticulo_.size() - 1; i++) {
      Cell* celula = reticulo_[i];
      int new_state = celula->NextState(*this);
      nuevos_estados.push_back(new_state);
    }
  }
  else {
    for (int i = 0; i < reticulo_.size(); i++) {
      Cell* celula = reticulo_[i];
      int new_state = celula->NextState(*this);
      nuevos_estados.push_back(new_state);
    }
  }
  ActualizarCelulas(nuevos_estados);
}

/**
 * @brief Actualizar lso estados de las células
 * @param nuevos_estados Nuevos estados de las células
*/

void Lattice1D::ActualizarCelulas(const vector<int>& nuevos_estados) const {
  for (int i = 0; i < reticulo_.size(); i++) {
    reticulo_[i]->SetState(State(nuevos_estados[i]));
  }
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