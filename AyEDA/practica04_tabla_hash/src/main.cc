#include "options/options.h"
#include "nif/nif.h"
#include "dispersion_function/dispersion_function.h"
#include "exploration_function/exploration_function.h"

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  srand(time(nullptr));

  DispersionFunction* dispersion;
  ExplorationFunction* exploracion;

  // Establecer el código de dispersión
  if (options->codigo_dispersion == "mod") {
    dispersion = new DispersionFunctionMod(options->size);
  }
  else if (options->codigo_dispersion == "sum") {
    dispersion = new DispersionFunctionSum(options->size);
  }
  else {
    dispersion = new DispersionFunctionRandom(options->size);
  }

  // Según la técnica de dispersión
  if (options->tecnica == "close") {
    if (options->codigo_exploraracion == "lineal") {
      exploracion = new ExplorationLinear();
    }
    else if (options->codigo_exploraracion == "cuadratica") {
      exploracion = new ExplorationQuadratic();
    }
    else if (options->codigo_exploraracion == "doble") {
      exploracion = new ExplorationDouble(dispersion);
    }
    else {
      exploracion = new ExplorationReDispersion();
    }
  }
  
  





  

  





  return 0;
}