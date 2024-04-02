#include "options.h"

/**
 * @brief Manejar las opciones del programa
 * @param argc Número de argumentos
 * @param argv Array donse se almacenan las opciones
 * @return Objeto Options
*/

optional<Options> parse_args(int argc, char* argv[]) {
  if (string(argv[1]) == "-h" || string(argv[1]) == "--help") { // Mostrar la ayuda
    cerr << "Uso: " << argv[0] << " -size <s> -ord <m> -init <i> -trace <y|n>" << endl;
    cerr << "s: Tamaño de la secuencia" << endl;
    cerr << "m: Algoritmo de ordenación" << endl;
    cerr << "i: Método para introducir los datos" << endl;
    cerr << "y: Mostrar la traza" << endl;
    exit(EXIT_SUCCESS);
  }

  if (argc < 9 || argc > 10) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }

  vector<string_view> args(argv + 1, argv + argc);
  Options options;
  for (auto it = args.begin(); it != args.end(); it++) {
    if (*it == "-size") { // Tamaño de la secuencia
      options.size = stoi(string(*(next(it))));
      assert (options.size > 0);
    }
    if (*it == "-ord") { // Algoritmo de ordenación
      options.ordenacion = string(*next(it));
      assert (options.ordenacion == "seleccion" || options.ordenacion == "quicksort" || options.ordenacion == "heapsort" || options.ordenacion == "shellsort" || options.ordenacion == "radixsort");
    }
    if (*it == "-init") {
      options.introduce_data = string(*(next(it)));
      assert (options.introduce_data == "manual" || options.introduce_data == "random" || options.introduce_data == "file");
      if (options.introduce_data == "file") {
        options.fichero = string(*(next(next(it))));
      }
    }
    if (*it == "-trace") {
      if (string(*next(it)) == "y") {
        options.traza = true;
      }
      assert (*next(it) == "y" || *next(it) == "n");
    }
  }
  return options;
}