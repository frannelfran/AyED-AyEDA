#include <iostream>
#include "lattice/lattice.h"
#include "lattice1D/lattice1D.h"
#include "options/options.h"

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    return EXIT_FAILURE;
  }




}