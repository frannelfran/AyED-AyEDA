#include "lattice.h"
#include "cell.h"
#include "position.h"
#include "state.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  Position pos(0);
  State est(0);
  State cambio(1);
  Cell celula(pos, est);
  celula.SetState(cambio);
  Lattice latt(celula);
  latt.GetCell(0);
  cout << celula << endl;
  ifstream file (argv[1]);

  











}