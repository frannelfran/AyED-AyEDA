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
  string type_tree; // Tipo de árbol
  string introduce; // Introducir elementos
  string file; // Fichero con los datos
  int num_elements; // Número de elementos a generar
};

optional<Options> parse_args(int argc, char* argv[]);