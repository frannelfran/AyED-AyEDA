#include <iostream>
#include "lattice.h"
#include "options.h"

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    return EXIT_FAILURE;
  }

  // Establecemos la configuración del retículo según los parámetros
  Lattice latt;
  latt.EstablecerReticulo(*options);














  return 0;
}
