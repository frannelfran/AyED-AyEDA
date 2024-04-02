#include "options/options.h"
#include "sequence/sequence.h"
#include "key/key.h"
#include "position/position.h"
#include "sortmethod/sortmethod.h"

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }

  Sequence* secuencia = new StaticSequence(options->size);
  SortMethod* metodo;

  if (options->introduce_data == "manual") {
    for (int i = 0; i < options->size; i++) {
      int clave;
      cout << "Introduzca la clave " << i + 1 << ": ";
      cin >> clave;
      secuencia->Insert(Key(clave, Position(i)));
    }
  }

  // Método de ordenación elegido
  if (options->ordenacion == "seleccion") {
    metodo = new SelectionSort(secuencia);
  }

  metodo->Sort();
  secuencia->Print(cout);
  delete secuencia;
  
  return 0;
}