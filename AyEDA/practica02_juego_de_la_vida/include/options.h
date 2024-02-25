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
  int fila;
  int columna;
  bool has_file = false;
  string type_border;
  string filename;
};

optional<Options> parse_args(int argc, char* argv[]);