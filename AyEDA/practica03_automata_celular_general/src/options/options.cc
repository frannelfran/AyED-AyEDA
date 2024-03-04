#include "options.h"

/**
 * @brief Manejar las opciones del programa
 * @param argc Número de argumentos
 * @param argv Array donse se almacenan las opciones
 * @return Objeto Options
*/

optional<Options> parse_args(int argc, char* argv[]) {
  if (argc < 4 || argc > 11) {
    cout << "Modo de empleo: ./automata_celular_general -dim <d> -size<N, <...>> -init <file> -cell <t> -border <b> [v]" << endl;
    cout << "d: Dimensión del autómata celular\n";
    cout << "N: Tamaño de las dimensiones del autómata celular\n";
    cout << "file: Nombre del fichero\n";
    cout << "t: Tipo de célula\n";
    cout << "b: Tipo de frontera\n";
    cout << "v: [0|1]\n";
    exit(EXIT_SUCCESS);
  }

  vector<string_view> args(argv + 1, argv + argc);
  Options options;
  for (auto it = args.begin(); it != args.end(); it++) {
    if (*it == "-dim") { // Establecer la dimensión
      it = next(it);
      options.dim = stoi(string(*it));
      assert (options.dim == 1 || options.dim == 2);
    }
    if (*it == "-size" && options.dim == 1) { // Establecer el tamaño unidimensional
      it = next(it);
      options.size = stoi(string(*it));
      assert (options.size > 0);
    }
    else if (*it == "-size" && options.dim == 2) { // Establecer el tamaño bidimensional
      it = next(it);
      options.fila = stoi(string(*it));
      it = next(it);
      options.columna = stoi(string(*it));
      assert (options.fila > 0 && options.columna > 0);
    }
    if (*it == "-border" && options.dim == 1) { // Establecer el tipo de frontera unidimensional
      it = next(it);
      options.type_border = string(*it);
      assert (options.type_border == "open" || options.type_border == "periodic");
      if (options.type_border == "open") { // Establecer el tipo de frontera
        if (stoi(string(*next(it))) == 0) {
          options.fria = true;
        }
      }
    }
    else if (*it == "-border" && options.dim == 2) { // Establecer el tipo de frontera bidimensional
      it = next(it);
      options.type_border = string(*it);
      assert (options.type_border == "reflective" || options.type_border == "noborder" || options.type_border == "reflejada");
    }
    if (*it == "-init") { // Establecer el nombre del fichero
      it = next(it);
      options.filename = string(*it);
      options.has_file = true;
    }
    if (*it == "-cell") { // Establecer el tipo de célula
      it = next(it);
      options.cell_type = string(*it);
      if (options.dim == 1) {
        assert (options.cell_type == "Ace110" || options.cell_type == "Ace30");
      }
      else if (options.dim == 2) {
        assert (options.cell_type == "Life23_3" || options.cell_type == "Life51_346");
      }
    }
    if (*it == "-border") {
      it = next(it);
      options.type_border = string(*it);
      assert (options.type_border == "open" || options.type_border == "periodic" || options.type_border == "reflective" || options.type_border == "noborder");
      if (options.type_border == "open") { // Establecer para el retículo unidimensional
        if (stoi(string(*next(it))) == 0) {
          options.fria = true;
        }
      }
    }
  }
  return options;
}