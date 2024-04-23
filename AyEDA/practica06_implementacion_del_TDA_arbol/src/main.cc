#include "options/options.h"
#include "key/key.h"
#include "ab/ab.h"

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }

  Ab<int>* ab = new Abb<int>();
  if (ab->Insertar(5)) {
    cout << "Nodo insertado" << endl;
  }
  else {
    cout << "Nodo no insertado" << endl;
  }
  
  return 0;
}