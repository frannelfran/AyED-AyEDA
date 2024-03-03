main:
	@echo "Compilando ficheros..."
	g++ -std=c++17 -I src src/main.cc src/cell/cell.cc src/cellace/cellace.cc src/options/options.cc src/lattice/lattice1D/lattice1D.cc src/position/position.cc -o automata_celular_general
.PHONY: clean

# Eliminar archivos
clean:
	@echo "Eliminando ficheros compilados..."
	rm -f automata_celular_general