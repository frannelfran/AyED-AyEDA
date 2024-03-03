#include "lattice1D.h"

/**
 * @brief Constructor de la clase Lattice1D
 * @param size Tamaño del retículo
*/

Lattice1D::Lattice1D(int size) {
  assert (size > 0); // Comprobar que el tamaño sea mayor que 0
  reticulo_.resize(size);
  for (int i = 0; i < size; i++) {
    Position pos({i});
    Cell* cell = new CellAce(pos, State(0));
    reticulo_[i] = cell;
  }
  SetViva();
}

/**
 * @brief Método para establecer que células se vuelven vivas
*/

void Lattice1D::SetViva() {
  int numero, posicion;
  cout << "Cuántas células vivas quieres ? ";
  cin >> numero;
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
    *this = Lattice1D(opciones.value().size);
  }
  SetFrontera(opciones);
}


/**
 * @brief Método para establecer la frontera
 * @param type Tipo de frontera
*/

void Lattice1D::SetFrontera(const optional<Options>& opciones) {
}

/**
 * @brief Sobrecarga del operador de salida
*/

ostream& Lattice1D::Display(ostream& os) const {
  for (auto& cell : reticulo_) {
    os << *cell;
  }
  return os;
}

