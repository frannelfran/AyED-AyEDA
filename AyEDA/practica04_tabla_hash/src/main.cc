#include "options/options.h"
#include "nif/nif.h"
#include "dispersion_function/dispersion_function.h"

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  srand(time(nullptr));

  DispersionFunction* sopa;
  sopa = new DispersionFunctionRandom(10);
  Nif nif(12345678);

  unsigned nif_disp = (*sopa)(nif);

  cout << nif_disp << endl;





  return 0;
}