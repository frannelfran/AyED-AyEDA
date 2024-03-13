#include "options/options.h"
#include "key/key.h"
#include "dispersion_function/dispersion_function.h"
#include "sequence/sequence.h"

using namespace std;

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  srand(time(nullptr));

  DispersionFunction* dispersion;
  Sequence* sequence;

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

  // Establecer la secuencia
  if (options->tecnica == "open") {
    sequence = new DinamicSequence(options->size);
  }

  


  





  

  





  return 0;
}