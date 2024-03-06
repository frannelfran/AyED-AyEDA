main:
	@echo "Compilando ficheros..."
	g++ -std=c++20 -I src src/main.cc src/cell/cellace/cellace.cc src/cell/cellLife/cellLife.cc src/options/options.cc src/lattice/lattice1D/lattice1D.cc src/position/position.cc  src/lattice/lattice2D/lattice2D.cc -o automata_celular_general

.PHONY: clean

# Eliminar archivos
clean:
	@echo "Eliminando ficheros compilados..."
	rm -f automata_celular_general