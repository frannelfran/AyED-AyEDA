#include <iostream>
#include "../include/lattice.h"
#include "../include/options.h"

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
  int generacion = 0;
  string nombre_fichero;

  // Manejar las opciones
  while (true) {
    cin >> opcion;
    assert (opcion == 'x' || opcion == 'n' || opcion == 'L' || opcion == 'c' || opcion == 's');
    switch (opcion) {
      // Salir del programa
      case 'x':
        return EXIT_SUCCESS;
      break;
      // Calcular la siguiente generación
      case 'n':
        cout << "G(" << generacion << ")" << endl;
        latt.NextGeneration();
        cout << latt;
        generacion++;
      break;
      // Calcular las siguientes 5 generaciones de la cuadrícula
      case 'L': {
        int number = 5;
        cout << "---Siguientes 5 generaciones---" << endl;
        while (number != 0) {
          cout << "G(" << generacion << ")" << endl;
          latt.NextGeneration();
          cout << latt;
          generacion++;
          number--;
        }
      }
      break;
      // Calcular el número de células vivas
      case 'c':
        cout << "Número de células vivas: " << latt.Population() << endl;
      break;
      // salvar la cuadrícula actual en un fichero
      case 's':
      cout << "Indicar nombre de fichero: ";
      cin >> nombre_fichero;
      ofstream file(nombre_fichero);
      file << latt.GetFilas() << " " << latt.GetColumnas() << latt;
      cout << "Cuadrícula guardada en " << nombre_fichero << endl;
      break;
    }
  }
}