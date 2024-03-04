#include <iostream>
#include "../src/lattice/lattice.h"
#include "lattice/lattice1D/lattice1D_open.h" // Fichero con la especificación de retículo con frontera abierta
#include "lattice/lattice1D/lattice1D_periodic.h" // Fichero con la especificación de retículo con frontera periódica
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
    file.close();
    assert (dim == 1 || dim == 2); // Comprobar que no se haya puesto otra dimensión
    if (dim == 1 && options->type_border == "open") {
      latt = new Lattice1D_Open(options->filename, options->cell_type);
      latt->AgregarFrontera(options->cell_type, options->fria);
    }
    else if (dim == 1 && options->type_border == "periodic") {
      latt = new Lattice1D_Periodic(options->filename, options->cell_type);
    }
  }
  else {
    assert (options->dim == 1 || options->dim == 2); // Comprobar que no se haya puesto otra dimensión
    if (options->dim == 1 && options->type_border == "open") {
      latt = new Lattice1D_Open(options->size, options->cell_type);
      latt->AgregarFrontera(options->cell_type, options->fria);
    }
    else if (options->dim == 1 && options->type_border == "periodic") {
      latt = new Lattice1D_Periodic(options->size, options->cell_type);
    }
  }

  cout << "---Retículo introducido---\n";
  cout << *latt;
  cout << "--------------------------\n";

  char opcion;
  int generacion = 0;
  // Manejar las opciones del menú
  while (true) {
    cin >> opcion;
    assert (opcion == 'x' || opcion == 'n' || opcion == 'L' || opcion == 'c' || opcion == 's'); // Comprobar que no se introducen otras opciones
    switch (opcion) {
      case 'x': // salir del programa
        delete latt;
        return EXIT_SUCCESS;
      break;
      case 'n': // Calcular la siguiente generación
        latt->NextGeneration();
        cout << "---Generación " << ++generacion << "---\n";
        cout << *latt;
        cout << "--------------------------\n";
      break;
      case 'L': // Calcular las siguientes 5 generación
        for (int i = 0; i < 5; i++) {
          latt->NextGeneration();
          cout << "---Generación " << ++generacion << "---\n";
          cout << *latt;
          cout << "--------------------------\n";
        }
      break;
      case 'c': // Contar el número de células vivas
        cout << "Número de células vivas: " << latt->Population() << endl;
      break;
      case 's': // Guardar el retículo en un fichero
        cout << "Indicar nombre de fichero: ";

      break;
    }
  }
}