#include "../include/options.h"

/**
 * @brief Manejar las opciones del programa
 * @param argc Número de argumentos
 * @param argv Array donse se almacenan las opciones
 * @return Objeto Options
*/

optional<Options> parse_args(int argc, char* argv[]) {
  if (argc < 5 || argc > 6) {
    cout << "Modo de empleo: ./juego_de_la_vida -size <M> <N> -init <file> -border <b>" << endl;
    exit(EXIT_SUCCESS);
  }

  vector<string_view> args(argv + 1, argv + argc);
  Options options;
  for (auto it = args.begin(); it != args.end(); it++) {
    if (*it == "-size") { // Establecer el tamaño
      it = next(it);
      options.fila = stoi(string(*it));
      it = next(it);
      options.columna = stoi(string(*it));
      assert(options.fila > 0 && options.columna > 0); // El número de las filas y columnas debe ser mayor que 0
    }
    if (*it == "-border") { // Establecer el tipo de frontera
      it = next(it);
      // Frontera abierta
      if (*it == "reflective") {
        options.type_border = *it;
      }
      // Frontera periódica
      else if (*it == "noborder") {
        options.type_border = *it;
      }
    }
    if (*it == "-init") { // Nombre del fichero
      it = next(it);
      options.filename = *it;
      options.has_file = true;
    }
  }
  return options;
}