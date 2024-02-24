#include "lattice.h"

/**
 * @brief Constructor por defecto de la clase
 * @param M Número de filas de la matriz
 * @param N Número de columnas de la matriz
*/

Lattice::Lattice(int N, int M) {
  assert (M > 0 && N > 0); // Comprobar que las filas y columnas son mayores que 0
  lattice_.resize(M);
  for (int i = 0; i < M; i++) {
    lattice_[i].resize(N);
    for (int j = 0; j < N; j++) {
      lattice_[i][j] = Cell(Position(i, j), State(0));
    }
  }
  SetViva();
}

/**
 * @brief Función para cambiar el estado de una cálula según su posición
*/

void Lattice::SetViva() {
  int fila, columna, numero;
  cout << "¿Cuantas células quieres modificar? ";
  cin >> numero;
  while (numero != 0) {
    cin >> fila >> columna;
    assert(fila >= 0 && columna >= 0 && fila < lattice_.size() && columna < lattice_[fila].size());
    lattice_[fila][columna].SetState(State(1)); // Cambio el estado de la célula
    numero--;
  }
}

/**
 * @brief Constructor de la clase si se le pasa un fichero al programa
 * @param filename Nombre del fichero
*/

Lattice::Lattice(const string& filename) {
  ifstream file(filename);
  int filas, columnas, estado;
  file >> filas >> columnas;
  lattice_.resize(filas);
  for (int i = 0; i < filas; i++) {
    lattice_[i].resize(columnas);
    for (int j = 0; j < columnas; j++) {
      file >> estado;
      lattice_[i][j] = Cell(Position(i, j), State(estado));
    }
  }
}

/**
 * @brief Método para saber que configuración tendrá el retículo
 * @param inicial Saber que configuración tendrá el retículo
*/

void Lattice::SetReticulo(const optional<Options>& opciones) {
  // Verificar que se hayan introducido un fichero
  if (opciones.value().has_file) {
    *this = Lattice(opciones.value().filename);
  }
  else { // Establecer la configuración inicial
    *this = Lattice(opciones.value().fila, opciones.value().columna);
  }
  SetFrontera(opciones.value().type_border, opciones.value().fria);
}

/**
 * @brief Establecer la frontera del retículo
 * @param frontera Tipo de frontera
 * @param fria Saber si la frontera es fría o caliente
*/

void Lattice::SetFrontera(const string& frontera, bool fria) {
  assert (frontera == "reflective" || frontera == "noborder"); // Comprobar que no se introduce otro tipo de frontera
  this->frontera_ = frontera;
}

/**
 * @brief Calcular cuántas células están 'vivas'
 * @return Número de células en estado 1
*/

size_t Lattice::Population() {
  int contador = 0;
  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[i].size(); j++) {
      if (lattice_[i][j].GetState().GetData() == 1) {
        contador++;
      }
    }
  }
  return contador;
}

/**
 * @brief Establecer la nueva generación
*/

void Lattice::NextGeneration() {
  cout << "hiohefoihwe" << endl;
}

/**
 * @overload Sobrecarga del operador []
*/

const Cell& Lattice::operator[](const Position& pos) const {
  return lattice_[pos.GetDataM()][pos.GetDataN()];
}

/**
 * @overload Sobrecarga del operador <<
*/

ostream& operator<<(ostream& os, const Lattice& latt) {
  for (const auto fila : latt.lattice_) {
    for (const auto celda : fila) {
      os << celda;
    }
    os << endl;
  }
  return os;
}