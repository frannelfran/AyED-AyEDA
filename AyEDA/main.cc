#include "lattice.h"
#include "cell.h"
#include "position.h"
#include "state.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  int size{stoi(argv[1]) - 1}, posicion{0};
  ifstream file (argv[2]);
  bool estado;
  vector<Cell> vector_celulas;


  while (size >= 0) {
    file >> estado;
    Position pos(posicion);
    State est(estado);
    Cell celula(pos, est);
    vector_celulas.push_back(celula);
    posicion++;
    size--;
  }
  Lattice latt(vector_celulas);
  cout << latt;
  




}