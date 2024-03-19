#include "options/options.h"
#include "key/key.h"
#include "dispersion_function/dispersion_function.h"
#include "exploration_function/exploration_function.h"
#include "sequence/sequence.h"
#include "hash_table/hash_table.h"

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);

  DispersionFunction* dispersion;
  ExplorationFunction* exploracion;
  HashTable* hash_table;

  // Establecer el código de dispersión
  if (options->codigo_dispersion == "mod") {
    dispersion = new DispersionFunctionMod(options->size);
  }
  else if (options->codigo_dispersion == "sum") {
    dispersion = new DispersionFunctionSum(options->size);
  }
  else {
    dispersion = new DispersionFunctionRandom(options->size);
  }

  // Establecer la función de exploración
  if (options->codigo_exploraracion == "linear") {
    exploracion = new LinearExploration;
  }
  else if (options->codigo_exploraracion == "quadratic") {
    exploracion = new QuadraticExploration;
  }
  else if (options->codigo_exploraracion == "double") {
    exploracion = new DoubleDispersionExploration(dispersion);
  }
  else {
    exploracion = new ReDispersionExploration(options->size);
  }

  // Establecer la tabla hash
  if (options->tecnica == "open") {
    hash_table = new OpenHashTable(options->size, dispersion);
  }
  else {
    hash_table = new ClosedHashTable(options->size, dispersion, exploracion, options->bloq_size);
  }

  // Menú del programa
  int opcion, clave;
  do {
    cout << *hash_table << endl;
    cout << "--- Menú ---\n";
    cout << "1. Insertar clave" << endl;
    cout << "2. Buscar clave" << endl;
    cout << "3. Salir" << endl;
    cout << "------------\n";
    cout << "Opción: ";
    cin >> opcion;
    if (opcion == 1) {
      cout << "Introduce la clave: ";
      cin >> clave;
      Key key(clave);
      if (hash_table->Insert(key)) {
        cout << "La clave se ha insertado" << endl;
      }
      else {
        cout << "La clave no se ha insertado" << endl;
      }
    }
    else if (opcion == 2) {
      cout << "Introduce la clave: ";
      cin >> clave;
      Key key(clave);
      if (hash_table->Search(key)) {
        cout << "La clave está en la tabla" << endl;
      }
      else {
        cout << "La clave no está en la tabla" << endl;
      }
    }
    if (opcion != 1 && opcion != 2 && opcion != 3) {
      cout << "Opción no válida" << endl;
      hash_table->Delete();
      return 1;
    }
  } while (opcion != 3);

  // Eliminar objetos
  hash_table->Delete();
  return 0;
}