#include "lattice.h"
#include "cell.h"
#include "position.h"
#include "state.h"
#include "options.h"
#include <cassert>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    return EXIT_FAILURE;
  }

  if (options.value().ayuda) {
    cout << "Modo de empleo: ./automata_celular -size <n> -border <b [v]> -init <file>" << endl;
    exit(EXIT_SUCCESS);
  }

  // Variables del programa
  int posicion = 0;
  vector<Cell> vector_celulas;

  // Verificamos que se haya introducido un fichero para saber si poner la configuración inicial
  if (options.value().has_file) {
    ifstream file (options.value().filename);
    while (options.value().size != 0) {
      int estado;
      file >> estado;
      Position pos(posicion);
      State sta(estado);
      Cell celula(pos, sta);
      vector_celulas.push_back(celula); // Pusheamos las células en el vector de células

      posicion++;
      options.value().size--;
    }
  }

  else {
    cout << "iphiohfiopwe" << endl;

  
  }

  Lattice latt(vector_celulas);
  cout << latt << endl;






  

}