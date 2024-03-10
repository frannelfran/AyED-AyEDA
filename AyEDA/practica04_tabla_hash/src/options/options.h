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
  int size; // Tamaño de la tabla hash
  int bloq_size; // Tamaño de los bloques
  string codigo_dispersion; // Código de dispersión a utilizar
  string tecnica; // Técnica de dispersión a utilizar
  string codigo_exploraracion; // Código de exploración a utilizar
};

optional<Options> parse_args(int argc, char* argv[]);