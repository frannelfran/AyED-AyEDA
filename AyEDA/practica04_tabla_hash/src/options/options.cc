#include "options.h"

/**
 * @brief Manejar las opciones del programa
 * @param argc Número de argumentos
 * @param argv Array donse se almacenan las opciones
 * @return Objeto Options
*/

optional<Options> parse_args(int argc, char* argv[]) {
  if (argc < 3 || argc > 11) {
    cerr << "Uso: " << argv[0] << " -ts <tamaño> -fd <código> -hash <técnica> [-bs <tamaño> -fe <código>]" << endl;
    exit(EXIT_SUCCESS);
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
      }
    }
  }
  return options;
}