#include "options.h"

/**
 * @brief Manejar las opciones del programa
 * @param argc Número de argumentos
 * @param argv Array donse se almacenan las opciones
 * @return Objeto Options
*/

optional<Options> parse_args(int argc, char* argv[]) {
  if (string(argv[1]) == "-h" || string(argv[1]) == "--help") { // Mostrar la ayuda
    cerr << "Uso: " << argv[0] << "-ab <abe|abb> -init <i> [s][f]" << endl;
    cerr << " -ab <abe|abb> : Tipo de árbol (árbol binario de búsqueda equilibrado o árbol binario de búsqueda)" << endl;
    cerr << " -init <i> : Introducir elementos (manual, random o file)" << endl;
    cerr << " [s] : Tamaño de la secuencia" << endl;
    cerr << " [f] : Fichero con los datos" << endl;
    exit(EXIT_SUCCESS);
  }

  if (argc < 4 || argc > 7) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }

  vector<string_view> args(argv + 1, argv + argc);
  Options options;
  for (auto it = args.begin(); it != args.end(); it++) {
    if (*it == "-ab") {
      options.type_tree = string(*next(it));
      assert (options.type_tree == "abe" || options.type_tree == "abb");
    }
    if (*it == "-init") {
      options.introduce = string(*next(it));
      assert (options.introduce == "manual" || options.introduce == "random" || options.introduce == "file");
      if (options.introduce == "random") {
        options.num_elements = stoi(string(*next(next(it))));
      }
      if (options.introduce == "file") {
        options.num_elements = stoi(string(*next(next(it))));
        options.file = string(*next(next(next(it))));
      }
    }
  }
  return options;
}