#include "lattice1D.h"

/**
 * @brief Constructor de la clase Lattice1D
 * @param size Tamaño del retículo
*/

Lattice1D::Lattice1D(int size) {
  assert (size > 0); // Comprobar que el tamaño sea mayor que 0
  reticulo_.resize(size);
  for (int i = 0; i < size; i++) {
    initializer_list<int> coordenadas = {i};
    Position pos(coordenadas);
    reticulo_.push_back(CellAce110(pos, State(0)));
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
    reticulo_.at(posicion).SetState(State(1));
    numero--;
  }
}

/**
 * @brief Método para establecer la frontera
 * @param type Tipo de frontera
*/

void Lattice1D::SetFrontera(const optional<Options>& opciones) {
  








}

