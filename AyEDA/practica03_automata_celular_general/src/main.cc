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

  Lattice* latt; // Puntero a retículo

  if (options->has_file) {
    int dim;
    ifstream file(options->filename);
    file >> dim;
    assert (dim == 1 || dim == 2); // Comprobar que no se haya puesto otra dimensión
    if (dim == 1 && options->has_file) {
      
  }

  cout << latt1D;







}