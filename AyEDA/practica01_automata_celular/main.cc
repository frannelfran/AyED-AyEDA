#include "lattice.h"
#include "options.h"
#include <cassert>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    return EXIT_FAILURE;
  }

  Lattice lattice; // Objeto retículo

  // Verificamos que se haya introducido un fichero para saber si poner la configuración inicial
  if (options.value().has_file) {
    ifstream file (options.value().filename);
    lattice.Build(file, options.value().size);
    file.close(); // Cerrar el fichero
  }
  else { // Sino hacer la configuración inicial
    lattice.Initial(options.value().size);
  }

  // Settear la frontera
  lattice.SetFrontera(options.value().type_border, options.value().fria);

  // Calcular las nuevas generaciones
  char tecla;
  cout << "Retículo introducido: " << lattice;
  cout << "---Evoluciones del retículo--- [ENTER para continuar | n para finalizar]" << endl;
  while (true) {
    lattice.NextGeneration();
    cout << lattice;
    tecla = getchar();
    if (tecla == 'n') {
      break;
    }
    assert (tecla == '\n');
  }
  return 0;
}