#include <iostream>
#include "../src/lattice/lattice.h"
#include "lattice/lattice1D/lattice1D.h"
#include "options/options.h"

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    return EXIT_FAILURE;
  }

  Lattice1D latt1D;

  // Retículo unidimensional
  if (options.value().dim == 1) {
    latt1D.Build(options);
    cout << latt1D << endl;
    
  }





}