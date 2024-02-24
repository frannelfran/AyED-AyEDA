#include <iostream>
#include "lattice.h"
#include "options.h"

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    return EXIT_FAILURE;
  }

  // Establecemos la configuración del retículo según los parámetros
  Lattice latt;
  latt.SetReticulo(*options);
  // Mostrar el retículo introducido
  cout << "---Retículo introducido---\n";
  cout << latt;
  cout << "--------------------------\n";
  char opcion;
  // Manejar las opciones
  do {
    switch (opcion) {
      case 'x':
        return EXIT_SUCCESS;
      break;
      case 'n':
        latt.NextGeneration();
        cout << latt;
      break;
      case 'L': {
        int number = 5;
        while (number != 0) {
          latt.NextGeneration();
          cout << latt;
          number--;
        }
      }
      break;
      case 'c':
        cout << "Número de céulas vivas" << endl;
      break;
      case 's':
      ofstream file("save_board.txt");
      file << latt;
      break;
    }
  } while (cin >> opcion);
  return 0;
}