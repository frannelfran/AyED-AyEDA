#include "lattice.h"
#include "cell.h"
#include "position.h"
#include "state.h"
#include "options.h"
#include <cassert>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    return EXIT_FAILURE;
  }

  if (options.value().ayuda) {
    cout << "Modo de empleo: ./automata_celular -size <n> -border <b [v]> -init <file>" << endl;
    exit(EXIT_SUCCESS);
  }

  Lattice latt; // Objeto retículo
  int save_size = options.value().size; // Guardar el número de células

  // Verificamos que se haya introducido un fichero para saber si poner la configuración inicial
  if (options.value().has_file) {
    ifstream file (options.value().filename);
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
      options.value().size--;
    }
    // Comprobar que el tamaño introducido coincida con el número de células del fichero
    assert(vector_celulas.size() == save_size);
    latt.SetLattice(vector_celulas);
  }

  // Sino hacer la configuración inicial
  else {
    latt.Initial(options.value().size);
  }

  if (options.value().frontera_abierta) {
  }








  cout << latt;
}