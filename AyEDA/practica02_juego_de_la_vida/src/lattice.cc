#include "../include/lattice.h"

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
    assert (fila >= 0 && columna >= 0 && fila < lattice_.size() && columna < lattice_[fila].size());
    lattice_[fila][columna].SetState(State(1)); // Cambio el estado de la célula
    numero--;
  }
}

/**
 * @brief Constructor de la clase si se le pasa un fichero al programa
 * @param filename Nombre del fichero
*/

Lattice::Lattice(const string& filename) {
  int fila, columna;
  char caracter;
  ifstream file(filename);
  file >> fila >> columna;
  assert (fila > 0 && columna > 0); // comprobar que la fila/columna son mayores que 0
  // Creo el retículo con los datos proporcionados
  lattice_.resize(fila);
  for (int i = 0; i < fila; i++) {
    lattice_[i].resize(columna);
    file.get(caracter); // Saltarse el salto de línea
    for (int j = 0; j < columna; j++) {
      file.get(caracter);
      State estado = (caracter == 'x') ? State(1) : State(0); // Establecer el estado según el carácter
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
  SetFrontera(opciones.value().type_border); // Establecer la frontera
}

/**
 * @brief Establecer la frontera del retículo
 * @param frontera Tipo de frontera
 * @param fria Saber si la frontera es fría o caliente
*/

void Lattice::SetFrontera(const string& frontera) {
  assert (frontera == "reflective" || frontera == "noborder"); // Comprobar que no se introduce otro tipo de frontera
  this->frontera_ = frontera; // Establecemos la frontera
  // Obtengo las dimensiones del retículo
  int filas = lattice_.size();
  int columnas = (filas > 0) ? lattice_[0].size() : 0;
  if (frontera_ == "reflective") {
    // Copiar el estado de las células en los bordes a las células adicionales
    // para simular la frontera reflectiva
    for (int i = 0; i < filas; i++) {
      lattice_[i].insert(lattice_[i].begin(), lattice_[i][0]); // Copiar la primera columna al principio
      lattice_[i].push_back(lattice_[i][columnas]); // Copiar la última columna al final
    }
    // Insertar una fila extra al principio y al final de la cuadricula
    lattice_.insert(lattice_.begin(), lattice_[0]); // Copiar la primera fila al principio
    lattice_.push_back(lattice_[filas]); // Copiar la última fila al final
  }
  else if (frontera_ == "noborder") { // Sino la frontera es "no frontera"
    // Verifico que hay una célula viva en el borde
    if (lattice_[0][0].GetState().GetData() != 0 || lattice_[0][filas - 1].GetState().GetData() != 0 || lattice_[0][columnas - 1].GetState().GetData() != 0 || lattice_[filas - 1][columnas - 1].GetState().GetData() != 0) {
      AgregarFrontera();
    }
  }
  AjustarPosiciones();
}

/**
 * @brief Método para agregar fornteras a la cuadrícula
*/

void Lattice::AgregarFrontera() {
  int filas = lattice_.size();
  int columnas = lattice_[0].size();

  Cell muerta (Position(0, 0), State(0));
  for (int i = 0; i < filas; i++) {
    lattice_[i].insert(lattice_[i].begin(), muerta);
    lattice_[i].push_back(muerta);
  }
  // Poner la frontera en la primera fila del retículo
  vector<Cell> vector_muertas(columnas + 2, muerta);
  lattice_.insert(lattice_.begin(), vector_muertas);

  // Poner la frontera en la última fila del retículo
  lattice_.push_back(vector_muertas);
}

/**
 * @brief Ajustar las posiciones de la cuadrícula
*/

void Lattice::AjustarPosiciones() {
  // Recorro el retículo para ajustar las posiciones una vez agragada la frontera
  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[i].size(); j++) {
      lattice_[i][j].SetPosition(Position(i, j));
    }
  }
}

/**
 * @brief Calcular cuántas células están 'vivas'
 * @return Número de células con estado 1
*/

size_t Lattice::Population() {
  int contador = 0;
  // Recorro la cuadrícula para saber cuántas células hay vivas dentor del retículo
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
  vector<int> nuevos_estados;
  // Cada célula busca cuál es su nuevo estado
  for (int i = 1; i < lattice_.size() - 1; i++) {
    for (int j = 1; j < lattice_[i].size() - 1; j++) {
      Cell& celula = lattice_[i][j];
      int nuevo_estado = celula.NextState(*this);
      nuevos_estados.push_back(nuevo_estado); // Almacenamos los nuevos estados en un vector
    }
  }
  // Las células actualizan su estado
  ActualizarCelulas(nuevos_estados);
  if (frontera_ == "noborder") {
    int num_fila = lattice_.size();
    int num_columna = lattice_[0].size();
    if (lattice_[1][1].GetState().GetData() != 0 || lattice_[num_fila - 1][1].GetState().GetData() != 0 || lattice_[1][num_columna - 1].GetState().GetData() != 0 || lattice_[num_fila - 1][num_columna - 1].GetState().GetData() != 0) {
      AgregarFrontera(); // Agregamos otra frontera
      AjustarPosiciones(); // Ajustamos las posiciones
    }
  }
}

/**
 * @brief Actualizar los estados de las células dentor de la cuadrícula
 * @param nuevos_estados Vector donde están almacenados los nuevos estados de las células
*/

void Lattice::ActualizarCelulas(const vector<int>& nuevos_estados) {
  int it = 0;
    for (int i = 1; i < lattice_.size() - 1; i++) {
      for (int j = 1; j < lattice_[i].size() - 1; j++, it++) {
      Cell& celula = lattice_[i][j];
      celula.SetState(State(nuevos_estados[it]));
    }
  }
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