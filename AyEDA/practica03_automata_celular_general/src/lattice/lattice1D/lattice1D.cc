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
    if (type_cell == "Ace110") {
      cell = new CellAce110(pos, State(0));
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
  assert (type_cell == "Ace110" || type_cell == "Ace30"); // Comprobar que el tipo de célula sea válido
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
    if (type_cell == "Ace110") {
      cell = new CellAce110(Position({i}), estado);
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