#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iterator>
#include <optional>
#include <string_view>
#include <cassert>

struct Options {
  int size;
  bool ayuda = false;
  bool frontera_abierta = false;
  bool fria = false;
  bool has_file = false;
  string filename;
};

/**
 * @brief Manejar las opciones del programa
 * @param argc Número de argumentos
 * @param argv Array donse se almacenan las opciones
 * @return Objeto Options
*/

std::optional<Options> parse_args(int argc, char* argv[]) {
  if (argc < 2 || argc > 8) {
    cerr << "Pruebe [-h | --help] para más información\n";
    return nullopt;
  }

  std::vector<string_view> args(argv + 1, argv + argc);
  Options options;
  for (auto it = args.begin(); it != args.end(); it++) {
    if (*it == "-h" || *it == "--help") { // Mostrar Ayuda
      options.ayuda = true;
    }
    if (*it == "-size") { // Establecer el tamaño
      it = next(it);
      options.size = stoi(string(*it)); 
      assert(options.size > 0); // El número debe ser mayor que 0
    }
    if (*it == "-border") { // Establecer el tipo de frontera
      it = next(it);
      if (*it == "open") { // Leo el tipo de frontera
        options.frontera_abierta = true;
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