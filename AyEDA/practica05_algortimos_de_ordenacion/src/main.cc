#include <random>
#include <ctime>
#include <fstream>
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

  Sequence<Key<long int>>* secuencia = new StaticSequence<Key<long int>>(options->size, options->traza);
  SortMethod<Key<long int>>* metodo;

  // Como introducir los datos
  if (options->introduce_data == "manual") {
    for (int i = 0; i < options->size; i++) {
      long int clave;
      cout << "Introduzca la clave " << i + 1 << ": ";
      cin >> clave;
      secuencia->Insert(Key<long int>(clave, Position(i)));
    }
  }
  else if (options->introduce_data == "random") {
    mt19937 generator(time(nullptr));
    uniform_int_distribution<int> distribution(10000000, 99999999);
    for (int i = 0; i < options->size; i++) {
      secuencia->Insert(Key<long int>(distribution(generator), Position(i)));
    }
  }
  else if (options->introduce_data == "file") {
    ifstream file(options->fichero);
    long int llave, pos = 0;
    while (file >> llave) {
      secuencia->Insert(Key<long int>(llave, Position(pos)));
      pos++;
      if (secuencia->IsFull()) {
        break;
      }
    }
  }

  // Método de ordenación elegido
  if (options->ordenacion == "seleccion") {
    metodo = new SelectionSort<Key<long int>>(secuencia);
  }
  else if (options->ordenacion == "quicksort") {
    metodo = new QuickSort<Key<long int>>(secuencia);
  }
  else if (options->ordenacion == "heapsort") {
    metodo = new HeapSort<Key<long int>>(secuencia);
  }
  else if (options->ordenacion == "shellsort") {
    metodo = new ShellSort<Key<long int>>(secuencia);
  }
  else if (options->ordenacion == "radixsort") {
    metodo = new RadixSort<Key<long int>>(secuencia);
  }

  cout << "Secuencia introducida: ";
  secuencia->Print(cout);
  if (options->traza) {
    cout << "---Traza de la ordenación---" << endl;
    metodo->Sort();
    cout << "----------------------------" << endl;
  }
  else {
    metodo->Sort();
    cout << "Secuencia ordenada: ";
    secuencia->Print(cout);
  }

  delete secuencia;
  return 0;
}