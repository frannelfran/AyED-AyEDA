#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iterator>
#include <optional>
#include <string_view>
#include <cassert>

using namespace std;

struct Options {
  int size;
  bool fria = false;
  bool has_file = false;
  string type_border;
  string filename;
};

/**
 * @brief Manejar las opciones del programa
 * @param argc Número de argumentos
 * @param argv Array donse se almacenan las opciones
 * @return Objeto Options
*/

std::optional<Options> parse_args(int argc, char* argv[]) {
  if (argc < 5 || argc > 8) {
    cout << "Modo de empleo: ./automata_celular -size <n> -border <b [v]> -init <file>" << endl;
    exit(EXIT_SUCCESS);
  }

  std::vector<string_view> args(argv + 1, argv + argc);
  Options options;
  for (auto it = args.begin(); it != args.end(); it++) {
    if (*it == "-size") { // Establecer el tamaño
      it = next(it);
      options.size = stoi(string(*it)); 
      assert(options.size > 0); // El número debe ser mayor que 0
    }
    if (*it == "-border") { // Establecer el tipo de frontera
      it = next(it);
      // Frontera abierta
      if (*it == "open") {
        options.type_border = *it;
      }
      // Frontera periódica
      if (*it == "periodic") {
        options.type_border = *it;
      }
    }
    if (*it == "0") { // Frontera fría o abierta
      options.fria = true;
    }
    if (*it == "-init") { // Nombre del fichero
      it = next(it);
      options.filename = *it;
      options.has_file = true;
    }
  }
  return options;
}