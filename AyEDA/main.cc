#include "alfabeto.h"
#include "cell.h"
#include "lattice.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  // Parámetros a recibir
  int size = stoi(argv[1]);
  ifstream file (argv[2]);

  int iterator = 0;

  while (size != 0) {
    bool estado;
    file >> estado;
    State state(estado);
    Position posicion(iterator);
    Cell celula(posicion, state);
    Lattice reticulo(celula);
    
    iterator++;
    size--;
  }

  









}