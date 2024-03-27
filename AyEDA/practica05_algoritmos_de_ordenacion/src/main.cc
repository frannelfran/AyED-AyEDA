#include "options/options.h"

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }
  
  cout << "Size: " << options->size << endl;
  cout << "Ordenación: " << options->ordenacion << endl;
  cout << "Introduce data: " << options->introduce_data << endl;
  cout << "Fichero: " << options->fichero << endl;
  cout << "Traza: " << options->traza << endl;
  return 0;
}