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

  Lattice latt; // Objeto retículo

  // Verificamos que se haya introducido un fichero para saber si poner la configuración inicial
  if (options.value().has_file) {
    ifstream file (options.value().filename);
    latt.Build(file, options.value().size);
  }

  // Sino hacer la configuración inicial
  else {
    latt.Initial(options.value().size);
  }

  // Settear la frontera
  latt.SetFrontera(options.value().type_border, options.value().fria);

  cout << latt;
}