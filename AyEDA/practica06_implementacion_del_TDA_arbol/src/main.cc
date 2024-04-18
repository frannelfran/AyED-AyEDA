#include "options/options.h"
#include "ab/ab.h"

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }
  cout << "Tipo de árbol: " << options->type_tree << endl;
  cout << "Introducir elementos: " << options->introduce << endl;
  cout << "Número de elementos: " << options->num_elements << endl;
  cout << "Fichero con los datos: " << options->file << endl;
  return 0;
}