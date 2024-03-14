#include "options.h"

/**
 * @brief Manejar las opciones del programa
 * @param argc Número de argumentos
 * @param argv Array donse se almacenan las opciones
 * @return Objeto Options
*/

optional<Options> parse_args(int argc, char* argv[]) {
  if (string(argv[1]) == "-h" || string(argv[1]) == "--help") { // Mostrar la ayuda
    cerr << "Uso: " << argv[0] << " -ts <table_size> -fd <código> -hash <técnica> [-bs <bloq_size> -fe <código>]" << endl;
    cerr << "<table_size> Tamaño de la tabla hash" << endl;
    cerr << "<código> Código de dispersión (mod, sum, random)" << endl;
    cerr << "<técnica> Técnica de dispersión (open, close)" << endl;
    cerr << "<bloq_size> Tamaño de los bloques" << endl;
    cerr << "<código> Código de exploración (linear, quadratic, double, re)" << endl;
    exit(EXIT_SUCCESS);
  }

  if (argc < 6 || argc > 11) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }

  vector<string_view> args(argv + 1, argv + argc);
  Options options;
  for (auto it = args.begin(); it != args.end(); it++) {
    if (*it == "-ts") { // Establecer el tamaño de la tabla hash
      options.size = stoi(string(*(next(it))));
      assert (options.size > 0); // Verificar que el tamaño sea mayor a 0
    }
    if (*it == "-fd") { // Establecer el código de dispersión
      options.codigo_dispersion = string (*next(it));
      assert (options.codigo_dispersion == "mod" || options.codigo_dispersion == "sum" || options.codigo_dispersion == "random"); // Verificar que el código de dispersión sea válido
    }
    if (*it == "-hash") { // Técnica de dispersión a utilizar
      options.tecnica = string(*next(it));
      assert (options.tecnica == "open" || options.tecnica == "close"); // Verificar que la técnica sea válida
    }
    if (*it == "-bs" && options.tecnica == "close") { // Tamaño de los bloques
      options.bloq_size = stoi(string(*next(it)));
      assert (options.bloq_size > 0); // Verificar que el tamaño del bloque sea mayor a 0
      if (*next(next(it)) == "-fe") { // Código de exploración a utilizar
        options.codigo_exploraracion = string(*next(next(next(it))));
        assert (options.codigo_exploraracion == "linear" || options.codigo_exploraracion == "quadratic" || options.codigo_exploraracion == "double" || options.codigo_exploraracion == "re"); // Verificar que el código de exploración sea válido
      }
    }
  }
  return options;
}