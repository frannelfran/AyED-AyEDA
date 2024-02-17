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

  Lattice lattice; // Objeto retículo

  // Verificamos que se haya introducido un fichero para saber si poner la configuración inicial
  if (options.value().has_file) {
    ifstream file (options.value().filename);
    lattice.Build(file, options.value().size);
    file.close(); // Cerrar el fichero
  }

  // Sino hacer la configuración inicial
  else {
    lattice.Initial(options.value().size);
  }

  // Settear la frontera
  lattice.SetFrontera(options.value().type_border, options.value().fria);

  // Calcular las nuevas generaciones
  string seguir;
  cout << "Retículo introducido: " << lattice;
  while (true) {
    lattice.NextGeneration();
    cout << lattice;
    cout << "seguir ? [y | n] ";
    cin >> seguir;
    if (seguir == "n") {
      break;
    }
  }
  return 0;
}