#include <iostream>
#include "lattice/lattice.h"
#include "lattice/lattice1D/lattice1D.h"
#include "lattice/lattice2D/lattice2D.h"
#include "factorycell/factorycell.h" // Fichero con la especificación de la fábrica de células
#include "options/options.h"

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    return EXIT_FAILURE;
  }

  Lattice* latt; // Puntero a retículo
  FactoryCell* factory;

  // Configuración de la fábrica de células según las opciones
  if (options->cell_type == "Ace110") {
    factory = new FactoryCellAce110();
  }
  else if (options->cell_type == "Ace30") {
    factory = new FactoryCellAce30();
  }
  else if (options->cell_type == "Life23_3") {
    factory = new FactoryCellLife23_3();
  }
  else if (options->cell_type == "Life51_346") {
    factory = new FactoryCellLife51_346();
  }

  // Configuración del reticulo según las opciones
  if (!options->has_file) { // si no se ha introducido un fichero
    assert (options->dim == 1 || options->dim == 2);
    if (options->dim == 1 && options->type_border == "open") {
      Lattice1D_Open* latt1D_open = new Lattice1D_Open(options->size, *factory);
      latt1D_open->AgregarFrontera(options->fria, *factory);
      latt = latt1D_open;
    }
    else if (options->dim == 1 && options->type_border == "periodic") {
      latt = new Lattice1D_Periodic(options->size, *factory);
    }
    else if (options->dim == 2 && options->type_border == "reflective") {
      Lattice2D_Reflective* latt2D_reflective = new Lattice2D_Reflective(options->fila, options->columna, *factory);
      latt2D_reflective->AgregarFrontera(*factory);
      latt = latt2D_reflective;
    }
  }
  else { // Cuando se introduce un fichero
    ifstream file(options->filename);
    int dim;
    file >> dim;
    assert (dim == 1 || dim == 2); 
    if (dim == 1) {
      if (options->type_border == "open") { // Establecer cuando la frontera es abierta
        Lattice1D_Open* latt1D_open = new Lattice1D_Open(file, *factory);
        latt1D_open->AgregarFrontera(options->fria, *factory);
        latt = latt1D_open;
      }
      else { // Establecer cuándo la frontera es periódica
        latt = new Lattice1D_Periodic(file, *factory);
      }
    }
    else if (dim == 2) {
      if (options->type_border == "reflective") { // Establecer cuando la frontera es reflectante
        Lattice2D_Reflective* latt2D_reflective = new Lattice2D_Reflective(file, *factory);
        latt2D_reflective->AgregarFrontera(*factory);
        latt = latt2D_reflective;
      }
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
        string filename;
        cout << "Indicar nombre de fichero: ";
        cin >> filename;
        


      break;
    }
  }
}