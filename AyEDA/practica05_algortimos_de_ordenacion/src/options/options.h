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
  int size; // Tamaño de la secuencia
  string ordenacion; // Algoritmo de ordenación
  string introduce_data; // Método para saber la forma de introducir los datos
  string fichero; // Fichero con los datos
  bool traza = false; // Si se quiere mostrar la traza
};

optional<Options> parse_args(int argc, char* argv[]);