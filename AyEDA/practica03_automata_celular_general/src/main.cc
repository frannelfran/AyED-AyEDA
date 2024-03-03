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

  // Retículo unidimensional
  if (options.value().dim == 1) {
    








  }





}