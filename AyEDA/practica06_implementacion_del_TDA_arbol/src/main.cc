#include "options/options.h"
#include "key/key.h"
#include "ab/ab.h"

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }

  AB<int>* ab = new ABB<int>();
  cout << *ab;
  if (ab->Insertar(30)) cout << "Insertado 30" << endl;
  if (ab->Insertar(25)) cout << "Insertado 20" << endl;
  if (ab->Insertar(15)) cout << "Insertado 40" << endl;
  if (ab->Insertar(40)) cout << "Insertado 10" << endl;
  ab->Inorder();
  
  return 0;
}