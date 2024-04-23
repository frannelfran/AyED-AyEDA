#include <random>
#include <ctime>
#include <fstream>
#include "options/options.h"
#include "key/key.h"
#include "ab/ab.h"

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }

  AB<long int>* tree;

  // Crear un árbol binario según la opción seleccionada
  if (options->type_tree == "abb") tree = new ABB<long int>();
  
  

  // Insertar elementos en el árbol según la opción seleccionada
  if (options->introduce == "random") {
    for (int i = 0; i < options->num_elements; i++) {
      mt19937 generator(time(nullptr));
      uniform_int_distribution<long int> distribution(10000000, 99999999);
      tree->Insertar(distribution(generator));
    }
  }
  else if (options->introduce == "file") {
    ifstream file(options->file);
    long int key;
    while (options->num_elements != 0) {
      file >> key;
      tree->Insertar(key);
      options->num_elements--;
    }
  }

  // Menú de opciones
  
  while (true) {
    int opcion;
    cout << *tree << endl;
    cout << "[0] Salir" << endl;
    cout << "[1] Insertar clave" << endl;
    cout << "[2] Buscar clave" << endl;
    cout << "[3] Mostrar recorrido inorder" << endl;
    cin >> opcion;
    switch (opcion) {
      case 0:
        cout << "Saliendo..." << endl;
        delete tree;
        return EXIT_SUCCESS;
      case 1: {
        cout << "Introduzca la clave a insertar: ";
        long int key;
        cin >> key;
        if (tree->Insertar(key)) cout << "Clave insertada correctamente" << endl;
        else cout << "La clave " << key << " ya está en el árbol" << endl;
        break;
      }
      case 2: {
        cout << "Introduzca la clave a buscar: ";
        long int key;
        cin >> key;
        if (tree->Buscar(key)) cout << "La clave " << key << " está en el árbol" << endl;
        else cout << "La clave " << key << " no está en el árbol" << endl;
        break;
      }
      case 3:
        cout << "Recorrido inorder: ";
        tree->Inorder();
        cout << endl;
        break;
      default:
        cout << "Opción no válida" << endl;
    }
  }
  
  return 0;
}